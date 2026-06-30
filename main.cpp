#include <algorithm>
#include <cstddef>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <unistd.h>
#include <vector>

// menu system: items, and some of them is another internal menu

// component
class IMenuItem {
  // actions
public:
  std::string name_;

  IMenuItem(const std::string &n) : name_(n) {}

  virtual void execute() = 0;
  virtual void show(int indent = 0) = 0;

  virtual ~IMenuItem() = default;
};

// leaf, item
class Item : public IMenuItem {

public:
  Item(std::string n) : IMenuItem(n) {}

  void show(int indent = 0) override {
    std::cout << std::string(indent, ' ') << name_ << std::endl;
  }

  void execute() override {
    std::cout << name_ << " option execute ..." << std::endl;
  }
};

// composite, menu
class Menu : public IMenuItem {
  std::vector<std::unique_ptr<IMenuItem>> items;

public:
  Menu(std::string n) : IMenuItem(n) {}

  void execute() override {

    // Menu opens/show itself
    std::cout << "Opening menu: " << name_ << std::endl;

    show(2);
  }

  IMenuItem &getChild(size_t index) {

    if (index >= items.size()) {
      throw std::out_of_range("index out of range");
    }
    return *items[index];
  }

  bool executeChild(const std::string &name) {
    for (auto &item : items) {
      if (item->name_ == name) {
        item->execute();
        return true;
      }
    }
    return false;
  }

  void show(int indent = 0) override {

    std::cout << std::string(indent, ' ') << name_ << std::endl;

    for (auto &i : items) {
      i->show(indent + 2);
    }
  }

  void add(std::unique_ptr<IMenuItem> item) {
    items.push_back(std::move(item));
  }

  //   std::unique_ptr<IMenuItem> &click(size_t index) { return items.at(index);
  //   }
};

int main() {

  // leavs
  auto mainMenu = std::make_unique<Menu>("Main");
  auto exit = std::make_unique<Item>("exit");

  auto soundMenu = std::make_unique<Menu>("Sound Menu");
  auto soundLow = std::make_unique<Item>("Lower");
  auto soundHigh = std::make_unique<Item>("Higher");

  auto mouseMenu = std::make_unique<Menu>("Mouse Menu");
  auto mouseSlow = std::make_unique<Item>("Slower");
  auto mouseFast = std::make_unique<Item>("Faster");

  // composite
  mouseMenu->add(std::move(mouseSlow));
  mouseMenu->add(std::move(mouseFast));

  soundMenu->add(std::move(soundLow));
  soundMenu->add(std::move(soundHigh));

  mainMenu->add(std::move(mouseMenu));
  mainMenu->add(std::move(soundMenu));

  mainMenu->add(std::move(exit));

  // show the tree
  mainMenu->show();
  std::cout << std::endl;

//   static_cast<Menu&>(mainMenu->getChild(0)).execute();
  std::cout << std::endl;

  //   mainMenu->getChild(0).execute();
  //   std::cout << std::endl;

  return 0;
}

int main_() {
  std::cout << "Asdasd" << std::endl;
  std::cout << std::string(1, ' ');
  std::cout << "Asdasd" << std::endl;
  std::cout << "Asdasd" << std::endl;

  return 0;
}