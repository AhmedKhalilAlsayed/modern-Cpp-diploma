#include <stdint.h>

class ParkingMeyerSingleton
{
public:
	static ParkingMeyerSingleton &getInstance()
	{
		static ParkingMeyerSingleton instance;
		return instance;
	}

private:
	ParkingMeyerSingleton();
	uint32_t counter = 0;
};

///////////////////////////////////////////////////////
class ParkingObjectSingleton
{
public:
	static ParkingObjectSingleton &getInstance()
	{
		return instance;
	}

private:
	ParkingObjectSingleton();
	static ParkingObjectSingleton instance;
	uint32_t counter = 0;
};

////////////////////////////////////////////////////////
class ParkingPointerSinglton
{
public:
	static ParkingPointerSinglton *getInstance()
	{
		if (instance == nullptr)
		{
			instance = new ParkingPointerSinglton();
		}

		return instance;
	}

	int32_t getCounter() { return counter; }
	void incCounter() { counter++; }

private:
	ParkingPointerSinglton();
	~ParkingPointerSinglton()
	{
		delete instance;
	}
	// declaration, should add the defenition
	static ParkingPointerSinglton *instance;
	int32_t counter = 0;
};

static ParkingPointerSinglton *instance;