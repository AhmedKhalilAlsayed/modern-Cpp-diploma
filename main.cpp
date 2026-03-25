#include <iostream>
#include <string.h>
#include <utility>

using namespace std;

class DynamicArray
{
private:
	float resizingRatio;
	int arrSize;
	int *arr;
	int arrLen;

public:
	DynamicArray(int startingSize, float resizingRatio = 2)
	{
		if (startingSize < 1 || resizingRatio < 2)
		{
			cerr << "Fix, should the least value for size is 1" << endl;
			cerr << "Fix, should the least value for ratio is 2" << endl;
			cerr << "Fix, We set to the default values" << endl;
			cerr << endl;
		}

		this->resizingRatio = resizingRatio < 1 ? 2 : resizingRatio;
		this->arrSize = startingSize < 1 ? 1 : startingSize;

		arr = new int[startingSize];
		arrLen = 0;

		if (arr == nullptr)
		{
			cerr << "Failed to create the array!" << endl;
			exit(1);
		}
	}

	DynamicArray(const DynamicArray &copy)
	{
		// deep copy
		this->arrLen = copy.getArrLen();
		this->arrSize = copy.getArrSize();
		this->resizingRatio = copy.getResizeRatio();

		// data
		this->arr = new int[this->arrSize];

		if (this->arr == nullptr)
		{
			cerr << "Failed to create the array from copy ctor!" << endl;
			exit(1);
		}
		for (size_t i = 0; i < this->arrSize; i++)
		{
			this->arr[i] = copy[i];
		}
	}

	DynamicArray &operator=(DynamicArray &copy)
	{

		// self assignment
		if (this == &copy)
			return *this;

		// first when make =, it means that there is already an old array, we should free it
		if (this->arr != nullptr)
		{
			delete[] this->arr;
			this->arr = nullptr;
		}

		this->arrLen = copy.getArrLen();
		this->arrSize = copy.getArrSize();
		this->resizingRatio = copy.getResizeRatio();

		// data
		this->arr = new int[this->arrSize];

		if (this->arr == nullptr)
		{
			cerr << "Failed to create the array from copy ass!" << endl;
			exit(1);
		}
		for (size_t i = 0; i < this->arrSize; i++)
		{
			this->arr[i] = copy[i];
		}

		return *this;
	}

	DynamicArray(DynamicArray &&mv)
		: arr(std::exchange(mv.arr, nullptr)),
		  arrLen(std::exchange(mv.arrLen, 0)),
		  arrSize(std::exchange(mv.arrSize, 0)),
		  resizingRatio(std::exchange(mv.resizingRatio, 0))
	{
		// this->arrLen = mv.getArrLen();
		// this->arrSize = mv.getArrSize();
		// this->resizingRatio = mv.getResizeRatio();

		// this->arr = mv.arr;
		// mv.arr = nullptr;
	}

	DynamicArray &operator=(DynamicArray &&mv)
	{
		// self assigment
		if (this == &mv)
			return *this;

		// first when make =, it means that there is already an old array, we should free it
		delete[] this->arr;
		this->arr = nullptr;

		this->arrLen = mv.getArrLen();
		this->arrSize = mv.getArrSize();
		this->resizingRatio = mv.getResizeRatio();

		this->arr = mv.arr;
		mv.arr = nullptr;

		return *this;
	}

	void pushBack(const int &value)
	{
		// if the arrLen < arrSize, there is free space and you can add the element
		// else 1- means you need to reallocate another block with new arrSize = round(old arrSize * resizingRatio)
		// 2- copy the old array to the new array + add this value
		// 3- delete the old array
		// 4- swap

		if (arrLen < arrSize)
		{
			arr[arrLen++] = value;
		}
		else
		{
			// allocate
			int newArrSize = static_cast<int>(arrSize * resizingRatio);
			int *newArr = new int[newArrSize];

			if (newArr == nullptr)
			{
				cerr << "Failed to create the new array!" << endl;
				exit(1);
			}
			// copy
			for (size_t i = 0; i < arrSize; i++)
			{
				newArr[i] = arr[i];
			}

			// add value
			newArr[arrLen++] = value;

			// delete old arr
			delete[] arr;

			// swap
			arrSize = newArrSize;
			arr = newArr;
			newArr = nullptr;
		}
	}

	void printArr()
	{
		for (size_t i = 0; i < arrLen; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	int getResizeRatio() const
	{
		return resizingRatio;
	}
	int getArrSize() const
	{
		return arrSize;
	}
	int getArrLen() const
	{
		return arrLen;
	}

	// int *getarrPtr() const
	// {
	// 	return arr;
	// }
	~DynamicArray()
	{
		delete[] arr;
		arr = nullptr;
	};
	int &operator[](size_t index) const
	{
		if (index >= arrLen)
		{
			cerr << "index " << index << ": Out of scope!" << endl;
			exit(1);
		}

		return arr[index];
	}
};

int main()
{
	DynamicArray arr(1);
	arr.pushBack(15);
	arr.pushBack(10);
	arr.pushBack(60);

	// int x = arr[0];
	arr[0] = -1;

	arr.printArr();

	return 0;
}