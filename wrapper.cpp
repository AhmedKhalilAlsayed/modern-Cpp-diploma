
class Wrapper
{
public:
	Wrapper(int *ptr)
		: ptr(ptr)
	{
	}

	~Wrapper()
	{
		delete ptr;
		ptr = nullptr;
	}

private:
	int *ptr = nullptr;
};
