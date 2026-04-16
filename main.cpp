#include <iostream>
#include <memory>
#include <stdint.h>
#include "singleton_parking.cpp"
#include "widget_factory.cpp"
#include "robo_factory.cpp"
#include "builder.cpp"

int main()
{

	auto pizzaBuilder = PizzaBuilder();
	auto director = PizzaDirector();

	Pizza pizza1 = director.make(pizzaBuilder, PizzaDirector::Pepperoni);
	Pizza pizza2 = director.make(pizzaBuilder, PizzaDirector::Margherita);
	Pizza pizza3 = director.make(pizzaBuilder, PizzaDirector::Pepperoni);

	pizza1.getPizza();
	std::cout << "\n";
	pizza2.getPizza();
	std::cout << "\n";
	pizza3.getPizza();
	return 0;
}