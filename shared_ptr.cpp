#include <iostream>
#include <utility>

class SharedPtr
{
public:
	SharedPtr(int *ptr)
		: ptr(ptr),
		  counter(new int{1}) {}

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
		: ptr(std::exchange(mv.ptr, nullptr)),
		  counter(std::exchange(mv.counter, nullptr))
	{
	}

	SharedPtr &operator=(SharedPtr &&mv)
	{
		if (this != &mv)
		{
			// cleanup
			giveResource();

			// take
			ptr = std::exchange(mv.ptr, nullptr);
			counter = std::exchange(mv.counter, nullptr);
		}
		return *this;
	}

	~SharedPtr()
	{
		giveResource();
	}

	int &operator*()
	{
		return *ptr;
	}

	int *operator->()
	{
		return ptr;
	}

	int *get()
	{
		return ptr;
	}

	void reset(int *ptr)
	{
		giveResource();

		this->ptr = ptr;
		if (ptr != nullptr)
		{
			this->counter = new int{1};
		}
	}

	int getCount()
	{
		return *counter;
	}

	// we can't turn it to a raw ptr, but can make it nullptr
	void release()
	{
		reset(nullptr);
	}

private:
	int *ptr = nullptr;
	int *counter = nullptr;

	void takeResource(const SharedPtr &res)
	{

		ptr = res.ptr;
		counter = res.counter;

		if (counter == nullptr)
		{
			std::cerr << "counter/ptr is null" << std::endl;
			return;
		}

		(*counter)++;
	}

	void giveResource()
	{
		if (counter == nullptr)
		{
			std::cerr << "counter/ptr is null" << std::endl;
			return;
		}

		(*counter)--;

		// no one has it
		if (!*counter)
		{
			delete ptr;
			delete counter;

			ptr = counter = nullptr;
		}
	}
};