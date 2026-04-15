#include <iostream>
#include <memory>

//
class IConnection
{
public:
	virtual void connect() = 0;
	virtual ~IConnection() = default;
};
class MySQLConnection : public IConnection
{
public:
	void connect() override
	{
		std::cout << "MySQL Connection" << std::endl;
	}
};
class PostgreSQLConnection : public IConnection
{
public:
	void connect() override
	{
		std::cout << "PostgreSQL Connection" << std::endl;
	}
};

//
class ICommand
{
public:
	virtual void cmd() = 0;
	virtual ~ICommand() = default;
};
class MySQLCommand : public ICommand
{
public:
	void cmd() override
	{
		std::cout << "MySQL cmd" << std::endl;
	}
};
class PostgreSQLCommand : public ICommand
{
public:
	void cmd() override
	{
		std::cout << "PostgreSQL cmd" << std::endl;
	}
};

//
class IDatabaseConnectionFactory
{
public:
	virtual std::unique_ptr<IConnection> createConnection() = 0;
	virtual std::unique_ptr<ICommand> createCommand() = 0;
};

class MySQLDatabaseConnectionFactory : public IDatabaseConnectionFactory
{
public:
	virtual std::unique_ptr<IConnection> createConnection() override
	{
		return std::make_unique<MySQLConnection>();
	}
	virtual std::unique_ptr<ICommand> createCommand() override
	{
		return std::make_unique<MySQLCommand>();
	}
};

class PostgreSQLDatabaseConnectionFactory : public IDatabaseConnectionFactory
{
public:
	virtual std::unique_ptr<IConnection> createConnection() override
	{
		return std::make_unique<PostgreSQLConnection>();
	}
	virtual std::unique_ptr<ICommand> createCommand() override
	{
		return std::make_unique<PostgreSQLCommand>();
	}
};
