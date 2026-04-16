#include <iostream>
#include <memory>
#include <stdint.h>
#include "singleton_parking.cpp"
#include "widget_factory.cpp"
#include "robo_factory.cpp"
#include "builder.cpp"

int main()
{
	auto computerBuilder = std::make_unique<GeneralComputerBuilder>();

	Computer c = computerBuilder->addCPU().addRAM().build();

	return 0;
}