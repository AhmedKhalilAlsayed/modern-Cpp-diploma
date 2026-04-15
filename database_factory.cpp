#include <iostream>
#include <memory>

//
class IConnection
{
public:
	virtual void connect() = 0;
	virtual ~IConnection() = default;
};
class MySQLConnection final : public IConnection
{
public:
	void connect() override
	{
		std::cout << "MySQL Connection" << std::endl;
	}
};
class PostgreSQLConnection final : public IConnection
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
class MySQLCommand final : public ICommand
{
public:
	void cmd() override
	{
		std::cout << "MySQL cmd" << std::endl;
	}
};
class PostgreSQLCommand final : public ICommand
{
public:
	void cmd() override
	{
		std::cout << "PostgreSQL cmd" << std::endl;
	}
};

class ITransaction
{
public:
	virtual void begin() = 0;
	virtual void commit() = 0;
	virtual void rollback() = 0;
	virtual ~ITransaction() = default;
};

class MySQLTransaction final : public ITransaction
{
public:
	void begin() override
	{
		std::cout << "MySQLTransaction" << std::endl;
	};
	void commit() override
	{
		std::cout << "MySQLTransaction" << std::endl;
	};
	void rollback() override
	{
		std::cout << "MySQLTransaction" << std::endl;
	}
};

class PostgreSQLTransaction final : public ITransaction
{
public:
	void begin() override
	{
		std::cout << "PostgreSQLTransaction" << std::endl;
	};
	void commit() override
	{
		std::cout << "PostgreSQLTransaction" << std::endl;
	};
	void rollback() override
	{
		std::cout << "PostgreSQLTransaction" << std::endl;
	}
};

//
class IDatabaseConnectionFactory
{
public:
	virtual std::unique_ptr<IConnection> createConnection() = 0;
	virtual std::unique_ptr<ICommand> createCommand() = 0;
	virtual std::unique_ptr<ITransaction> createTransaction() = 0;

	virtual ~IDatabaseConnectionFactory() = default;
};

class MySQLDatabaseConnectionFactory final : public IDatabaseConnectionFactory
{
public:
	std::unique_ptr<IConnection> createConnection() override
	{
		return std::make_unique<MySQLConnection>();
	}
	std::unique_ptr<ICommand> createCommand() override
	{
		return std::make_unique<MySQLCommand>();
	}
	std::unique_ptr<ITransaction> createTransaction() override
	{
		return std::make_unique<MySQLTransaction>();
	};
};

class PostgreSQLDatabaseConnectionFactory final : public IDatabaseConnectionFactory
{
public:
	std::unique_ptr<IConnection> createConnection() override
	{
		return std::make_unique<PostgreSQLConnection>();
	}
	std::unique_ptr<ICommand> createCommand() override
	{
		return std::make_unique<PostgreSQLCommand>();
	}
	std::unique_ptr<ITransaction> createTransaction() override
	{
		return std::make_unique<PostgreSQLTransaction>();
	};
};
