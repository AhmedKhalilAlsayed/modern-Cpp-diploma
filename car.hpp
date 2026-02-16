
#ifndef CAR_HPP
#define CAR_HPP

class Car
{
private:
	int id;

public:
	int *tearsSpeed = nullptr;
	Car(int id);

	Car(const Car &copy);
	~Car();
};
#endif