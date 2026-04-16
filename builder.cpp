#include <iostream>
#include <memory>

// product
class Computer
{
private:
	Computer()
	{
	}
	void setCPU(const std::string &cpu)
	{
		cpu_ = cpu;
	}
	void setStorage(const std::string &storage)
	{
		storage_ = storage;
	}
	void setRAM(const uint32_t &ram)
	{
		ram_ = ram;
	}
	void setGPU(const bool &gpu)
	{
		hasGPU_ = gpu;
	}
	void show()
	{
		std::cout << "Computer: " << cpu_ << ", " << ram_ << "GB RAM, "
				  << storage_ << ", GPU: " << (hasGPU_ ? "yes" : "no") << std::endl;
	}

	std::string cpu_ = "";
	std::string storage_ = "";
	int32_t ram_ = 0;
	bool hasGPU_ = false;

	// friend class IComputerBuilder; XXXXXXXXXXX
	friend class GeneralComputerBuilder;
	friend class GamingComputerBuilder;
};

class IComputerBuilder
{
public:
	virtual IComputerBuilder &addCPU() = 0;
	virtual IComputerBuilder &addStorage() = 0;
	virtual IComputerBuilder &addRAM() = 0;
	virtual IComputerBuilder &addGPU() = 0;
	virtual Computer build() = 0; // == getResult()
	virtual ~IComputerBuilder() = default;
};

class GeneralComputerBuilder final : public IComputerBuilder
{
private:
	Computer c;

public:
	GeneralComputerBuilder &addCPU() override
	{
		c.setCPU("Intel");
		return *this;
	}
	GeneralComputerBuilder &addStorage() override
	{
		c.setStorage("SSD");
		return *this;
	}
	GeneralComputerBuilder &addRAM() override
	{
		c.setRAM(16);
		return *this;
	}
	GeneralComputerBuilder &addGPU() override
	{
		std::cout << "AddGPU\n";
		c.setGPU(true);
		return *this;
	}
	// == getResult()
	Computer build() override
	{
		std::cout << "GeneralComputerBuilder\n";
		std::cout << "Validating ...\nDone...\n\n";
		return c;
	}
};

class GamingComputerBuilder final : public IComputerBuilder
{
private:
	Computer c;

public:
	GamingComputerBuilder &addCPU() override
	{
		c.setCPU("Intel Gaming");
		return *this;
	}
	GamingComputerBuilder &addStorage() override
	{
		c.setStorage("NMe");
		return *this;
	}
	GamingComputerBuilder &addRAM() override
	{
		c.setRAM(64);
		return *this;
	}
	GamingComputerBuilder &addGPU() override
	{
		std::cout << "AddGPU\n";
		c.setGPU(true);
		return *this;
	}
	// == getResult()
	Computer build() override
	{
		std::cout << "GamingComputerBuilder\n";
		std::cout << "Validating ...\nDone...\n\n";
		return c;
	}
};

// can add many builder ...