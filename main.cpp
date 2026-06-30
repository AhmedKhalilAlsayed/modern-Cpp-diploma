#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <string>
#include <unistd.h>
#include <vector>

// base interface
class ICoffe {
public:
  virtual std::string getDescription() = 0;
  virtual double getCost() = 0;

  virtual ~ICoffe() = default;
};

// base impl
class Coffe : public ICoffe {

public:
  std::string getDescription() override { return "Simple Coffe"; }

  double getCost() override { return 20; }
};

// decor, decoration, interface
class IDecor : public ICoffe {
protected:
  std::unique_ptr<ICoffe> coffe_; // base

public:
  IDecor(std::unique_ptr<ICoffe> c) : coffe_(std::move(c)) {}
};

// decorators
class Milk : public IDecor {
public:
  Milk(std::unique_ptr<ICoffe> c) : IDecor(std::move(c)) {}

  std::string getDescription() override {
    return coffe_->getDescription() + " + Milk";
  }

  double getCost() override { return coffe_->getCost() + 10; }
};

class Caramel : public IDecor {
public:
  Caramel(std::unique_ptr<ICoffe> c) : IDecor(std::move(c)) {}

  std::string getDescription() override {
    return coffe_->getDescription() + " + Caramel";
  }

  double getCost() override { return coffe_->getCost() + 8; }
};

int main() {

  auto coffe = std::make_unique<Coffe>();
  auto order = std::make_unique<Caramel>(std::move(coffe));
  auto order0 = std::make_unique<Milk>(std::move(order));

  std::cout << order0->getDescription() << std::endl;
  std::cout << order0->getCost() << std::endl;

  return 0;
}

int main_() {
  std::cout << "Asdasd" << std::endl;
  std::cout << std::string(1, ' ');
  std::cout << "Asdasd" << std::endl;
  std::cout << "Asdasd" << std::endl;

  return 0;
}