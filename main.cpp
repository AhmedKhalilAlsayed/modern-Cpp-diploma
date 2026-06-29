#include <iostream>
#include <memory>
#include <unistd.h>
#include <vector>
#include <string>

// without composite

class File
{
public:
	std::string name;
	File(std::string name) : name(name) {}

	void display()
	{
		std::cout << "File: " << this->name << std::endl;
	}
};

class Folder
{
	std::vector<std::unique_ptr<Folder>> folders;
	std::vector<std::unique_ptr<File>> files;
	std::string name;

public:
	Folder(std::string name)
		: name(name) {}

	Folder &addFolder(std::unique_ptr<Folder> folder)
	{
		folders.push_back(std::move(folder));

		return *this;
	}
	

	Folder &addFile(std::unique_ptr<File> file)
	{
		files.push_back(std::move(file));

		return *this;
	}

	void display(size_t indent = 0)
	{
		// std::cout << ">" << std::endl;

		std::cout << std::string(indent, '.');

		std::cout << "Folder: " << name << std::endl;

		for (const auto &folder : folders)
		{
			// std::cout << "Folder: " << folder.name << std::endl;
			folder->display(indent + 2);
		}

		for (const auto &file : files)
		{
			std::cout << std::string(indent + 2, '.');
			file->display();
		}

		// std::cout << std::string(0, '.');
		// std::cout << "<" << std::endl;
	}
};

int main()
{
	auto root = std::make_unique<Folder>("/");

	auto bin = std::make_unique<Folder>("bin/");
	bin->addFile(std::make_unique<File>("ls"));

	root->addFolder(std::move(bin))
		.addFolder(std::make_unique<Folder>("usr/"));

	root->display();

	return 0;
}