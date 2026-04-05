#include <utility>

class UniquePtr
{
public:
	UniquePtr(int *ptr = nullptr)
		: ptr_(ptr)
	{
	}

	// exclusive resource
	UniquePtr(const UniquePtr &copy) = delete;
	UniquePtr &operator=(const UniquePtr &copy) = delete;

	// it is a ctor, no self assig! check
	UniquePtr(UniquePtr &&mv)
		: ptr_(std::exchange(mv.ptr_, nullptr))
	{
	}

	UniquePtr &operator=(UniquePtr &&mv)
	{
		if (this != &mv)
		{
			// clean myself
			delete ptr_;
			
			// ptr = nullptr;

			// then steal
			ptr_ = std::exchange(mv.ptr_, nullptr);
		}
		return *this;
	}

	~UniquePtr()
	{
		delete ptr_;
		ptr_ = nullptr;
	}

	int &operator*()
	{
		return *ptr_;
	}

	int *operator->()
	{
		return ptr_;
	}

	explicit operator bool() const
	{
		return ptr_ != nullptr;
	}

	// to get the ptr
	int *get()
	{
		return ptr_;
	}

	// release the resource to be as a raw ptr
	int *release()
	{
		return std::exchange(ptr_, nullptr);
	}

	// take another resource
	void reset(int *p)
	{
		delete ptr_;
		ptr_ = p;
	}

private:
	int *ptr_ = nullptr;

};
