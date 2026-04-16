#include <iostream>
#include <memory>
#include <stdint.h>
#include "singleton_parking.cpp"
#include "widget_factory.cpp"
#include "robo_factory.cpp"

int main()
{
	uint32_t type;
	std::unique_ptr<RobotBuilder> robotBuilder;
	std::unique_ptr<IRobotFactory> roboFactory;

	std::cout << "Please enter you robo type,\n"
			  << std::flush;
	std::cout << "1 for Basic, 2 for Advanced\n"
			  << std::flush;

	std::cin >> type;

	// if (!std::cin >> type)
	// {
	// 	std::cerr << "Error! \n";
	// 	exit(-1);
	// }

	switch (type)
	{
	case 1:
		// roboFactory = std::make_unique<BasicRobotFactory>();
		robotBuilder = std::make_unique<RobotBuilder>(std::make_unique<BasicRobotFactory>());
		break;
	case 2:
		// roboFactory = std::make_unique<AdvancedRobotFactory>();
		robotBuilder = std::make_unique<RobotBuilder>(std::make_unique<AdvancedRobotFactory>());
		break;
	default:
		std::cerr << "Error! \n";
		exit(-1);
	}
	

	robotBuilder->buildAndTest();
	


	return 0;
}