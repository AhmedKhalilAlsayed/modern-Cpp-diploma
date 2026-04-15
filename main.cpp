#include <stdint.h>
#include "singleton_parking.cpp"
#include "widget_factory.cpp"
#include "database_factory.cpp"

int main()
{
	std::unique_ptr<IDatabaseConnectionFactory> databaseFactory = std::make_unique<PostgreSQLDatabaseConnectionFactory>();

	std::unique_ptr<IConnection> connection = databaseFactory.get()->createConnection();
	connection.get()->connect();
	return 0;
}