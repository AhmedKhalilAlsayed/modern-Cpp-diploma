#include <utility>

class UniquePtr
{
public:
	UniquePtr(int *ptr = nullptr)
		: ptr(ptr)
	{
	}

	// exclusive resource
	UniquePtr(const UniquePtr &copy) = delete;
	UniquePtr &operator=(const UniquePtr &copy) = delete;

	// it is a ctor, no self assig! check
	UniquePtr(UniquePtr &&mv)
		: ptr(std::exchange(mv.ptr, nullptr))
	{
	}

	UniquePtr &operator=(UniquePtr &&mv)
	{
		if (this != &mv)
		{
			// clean myself
			delete ptr;
			// ptr = nullptr;

			// then steal
			ptr = std::exchange(mv.ptr, nullptr);
		}
		return *this;
	}

	~UniquePtr()
	{
		delete ptr;
		ptr = nullptr;
	}

	int &operator*()
	{
		return *ptr;
	}

	int *operator->()
	{
		return ptr;
	}

	explicit operator bool() const
	{
		return ptr != nullptr;
	}

	// to get the ptr
	int *get()
	{
		return ptr;
	}

	// release the resource to be as a raw ptr
	int *release()
	{
		return std::exchange(ptr, nullptr);
	}

	// take another resource
	void reset(int *p)
	{
		delete ptr;
		ptr = p;
	}

private:
	int *ptr = nullptr;

};
