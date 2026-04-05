#include <iostream>
#include <utility>

class SharedPtr
{
public:
	SharedPtr(int *ptr)
		: ptr_(ptr),
		  counter_(new int{1}) {}

	SharedPtr(const SharedPtr &copy)
	{
		takeResource(copy);
	}

	SharedPtr &operator=(const SharedPtr &copy)
	{
		if (this != &copy)
		{
			// cleanup
			giveResource();

			// take
			takeResource(copy);
		}

		return *this;
	}

	SharedPtr(SharedPtr &&mv)
		: ptr_(std::exchange(mv.ptr_, nullptr)),
		  counter_(std::exchange(mv.counter_, nullptr))
	{
	}

	SharedPtr &operator=(SharedPtr &&mv)
	{
		if (this != &mv)
		{
			// cleanup
			giveResource();

			// take
			ptr_ = std::exchange(mv.ptr_, nullptr);
			counter_ = std::exchange(mv.counter_, nullptr);
		}
		return *this;
	}

	~SharedPtr()
	{
		giveResource();
	}

	int &operator*()
	{
		return *ptr_;
	}

	int *operator->()
	{
		return ptr_;
	}

	int *get()
	{
		return ptr_;
	}

	void reset(int *ptr)
	{
		giveResource();

		this->ptr_ = ptr;
		if (ptr != nullptr)
		{
			this->counter_ = new int{1};
		}
	}

	int getCount()
	{
		return *counter_;
	}

	// we can't turn it to a raw ptr, but can make it nullptr
	void release()
	{
		reset(nullptr);
	}

private:
	int *ptr_ = nullptr;
	int *counter_ = nullptr;

	void takeResource(const SharedPtr &res)
	{

		ptr_ = res.ptr_;
		counter_ = res.counter_;

		if (counter_ == nullptr || ptr_ == nullptr)
		{
			std::cerr << "counter/ptr is null" << std::endl;
			return;
		}

		(*counter_)++;
	}

	void giveResource()
	{
		if (counter_ == nullptr || ptr_ == nullptr)
		{
			std::cerr << "counter/ptr is null" << std::endl;
			return;
		}

		(*counter_)--;

		// no one has it
		if (!*counter_)
		{
			delete ptr_;
			delete counter_;

			ptr_ = counter_ = nullptr;
		}
	}
};