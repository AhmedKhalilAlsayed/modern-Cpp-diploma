#include <algorithm>
#include <cstddef>
#include <iostream> // This header is typically found. If not, check your compiler setup.
#include <memory>
#include <ostream>
#include <string>
#include <unistd.h>
#include <vector>

// composite

// component interface

class IFileSystemNode {
public:
  virtual void display(int indent = 0) = 0;
  virtual size_t getSize() = 0;

  virtual ~IFileSystemNode() = default;
};

// leaf
class File : public IFileSystemNode {

  std::string name_;
  size_t size_;

public:
  File(const std::string &name, const size_t &size)
      : name_(name), size_(size) {}

  void display(int indent = 0) override {
    std::cout << std::string(indent, ' ');
    std::cout << name_ << " " << size_ << "KB" << std::endl;
  }

  size_t getSize() override { return size_; }
};

// composite, group of objects
class Folder : public IFileSystemNode {
  std::string name_;
  std::vector<std::unique_ptr<IFileSystemNode>> childern_;

public:
  Folder(const std::string &name) : name_(name) {}

  // add node, file folder ... any type
  IFileSystemNode &add(std::unique_ptr<IFileSystemNode> child) {
    childern_.push_back(std::move(child));
    return *this;
  }

  void display(int indent = 0) override {

    std::cout << std::string(indent, ' ');
    std::cout << name_ << std::endl;

    for (auto &c : childern_) {
      c->display(indent + 2);
    }
  }

  size_t getSize() override {
    size_t size = 0;
    for (auto &c : childern_) {
      size += c->getSize();
    }
    return size;
  }
};

int main() {

  // composites
  auto root = std::make_unique<Folder>("/");
  auto docs = std::make_unique<Folder>("docs/");
  auto img = std::make_unique<Folder>("img/");
  auto usr = std::make_unique<Folder>("usr/");
  auto ahmedkhalil = std::make_unique<Folder>("ahmedkhalil/");

  // build
  root->add(std::move(usr));
  // usr now is nullptr! you can't use it
  usr->add(std::move(ahmedkhalil));
  ahmedkhalil->add(std::move(docs));
  ahmedkhalil->add(std::move(img));

  root->display();
  //   std::cout << root.getSize() << std::endl;

  return 0;
}