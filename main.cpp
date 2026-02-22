#include <iostream>
#include <string.h>

using namespace std;

#define SIZE 1
class Integer
{
private:
	int *m_pInt = nullptr;

public:
	Integer() : Integer(0)
	{
		cout << "ctor" << endl;
	}
	Integer(int val)
	{
		cout << "ctor()" << endl;
		m_pInt = new int[SIZE];
		for (size_t i = 0; i < SIZE; i++)
		{
			m_pInt[i] = val;
		}
		// *m_pInt = val;
	}
	// copy ctor
	// take care about deep copy
	Integer(const Integer &copy)
	{
		cout << "ctor &" << endl;
		m_pInt = new int[SIZE];
		for (size_t i = 0; i < SIZE; i++)
		{
			m_pInt[i] = *copy.m_pInt;
		}
	}
	// copy ass
	Integer &operator=(const Integer &copy)
	{
		cout << "copy=" << endl;

		// avoid self assign, compare the addr
		//
		if (this != &copy)
		{
			// you should copy new resources
			// what about the <old> resources!!!

			// free old resoueces
			if (m_pInt != nullptr)
			{
				delete[] m_pInt;
				m_pInt = nullptr;
			}

			// allocate new resources
			m_pInt = new int[SIZE];

			for (size_t i = 0; i < SIZE; i++)
			{
				m_pInt[i] = *copy.m_pInt;
			}
		}
		return *this;
	}
	// mv ass
	Integer &operator=(Integer &&rvalue)
	{
		cout << "mv=" << endl;

		if (this != &rvalue)
		{
			// free old resouces
			if (m_pInt != nullptr)
			{
				delete[] m_pInt;
				m_pInt = nullptr;
			}
			// steal the rvalue resource
			m_pInt = rvalue.m_pInt;

			// forget it to rvalue
			rvalue.m_pInt = nullptr;
		}
		return *this;
	}

	Integer(Integer &&mv)
	{
		cout << "ctor &&" << endl;
		m_pInt = mv.m_pInt;
		mv.m_pInt = nullptr;
	}

	~Integer()
	{
		cout << "dtor" << endl;
		if (m_pInt != nullptr)
		{
			delete[] m_pInt;
			m_pInt = nullptr;
		}
	}
	// non-members functions
	friend ostream &operator<<(ostream &o, Integer &obj);
};
ostream &operator<<(ostream &o, Integer &obj)
{
	if (obj.m_pInt != nullptr)
	{
		o << *obj.m_pInt << endl;
	}
	return o;
}
Integer get(bool bb)
{

	Integer a(130);
	Integer b(140);
	if (bb)
		return a;
	else
		return b;
}

int main()
{
	Integer a = 5;
	return 0;
}