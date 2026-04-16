#include <iostream>
#include <memory>

// product
class Pizza
{
public:
	void getPizza()
	{
		std::cout << "dough_ " << dough_ << std::endl;
		std::cout << "sauce_ " << sauce_ << std::endl;
		std::cout << "topping_ " << topping_ << std::endl;
		std::cout << "cheese_ " << cheese_ << std::endl;
	}

private:
	Pizza() {}
	std::string dough_, sauce_, topping_, cheese_;

	void setDough(const std::string &d)
	{
		dough_ = d;
	}
	void setSauce(const std::string &s)
	{
		sauce_ = s;
	}
	void setTopping(const std::string &t)
	{
		topping_ = t;
	}
	void setChesse(const std::string &c)
	{
		cheese_ = c;
	}

	// friend builders
	friend class PizzaBuilder;
};

class IPizzaBuilder
{
public:
	virtual IPizzaBuilder &addDough(const std::string &) = 0;
	virtual IPizzaBuilder &addSauce(const std::string &) = 0;
	virtual IPizzaBuilder &addTopping(const std::string &) = 0;
	virtual IPizzaBuilder &addCheese(const std::string &) = 0;
	virtual Pizza build() = 0;
	virtual ~IPizzaBuilder() = default;
};

class PizzaBuilder final : public IPizzaBuilder
{
private:
	Pizza pizza;

public:
	IPizzaBuilder &addDough(const std::string &d) override
	{
		pizza.setDough(d);
		return *this;
	}
	IPizzaBuilder &addSauce(const std::string &s) override
	{
		pizza.setSauce(s);
		return *this;
	}
	IPizzaBuilder &addTopping(const std::string &t) override
	{
		pizza.setTopping(t);
		return *this;
	}
	IPizzaBuilder &addCheese(const std::string &c) override
	{
		pizza.setChesse(c);
		return *this;
	}
	Pizza build() override
	{
		Pizza temp = std::move(pizza);
		pizza = Pizza(); // rest, to be sure for next use for the same builder
		return temp;
	}
};

class PizzaDirector
{

public:
	typedef enum
	{
		Margherita,
		Pepperoni
	} PizzaType;

	Pizza make(IPizzaBuilder &builder, PizzaType type)
	{
		switch (type)
		{
		case Margherita:
			return builder.addTopping("Margherita").build();
			break;
		case Pepperoni:
			return builder.addCheese("Pepperoni").addDough("Pepperoni").addSauce("Pepperoni").addTopping("Pepperoni").build();
			break;
		default:
			return builder.addCheese("").addDough("").addSauce("").addTopping("").build();
			break;
		}
	}
};