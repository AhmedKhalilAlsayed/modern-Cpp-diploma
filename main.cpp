
#include <algorithm>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>

// State Pattern

// forward declaration
class TrafficLight;
class RedState;
class GreenState;
class YellowState;

//
class IState {
protected:
  TrafficLight &light_;

public:
  IState(TrafficLight &t) : light_(t) {}

  virtual void next() = 0;
  virtual std::string getState() = 0;

  virtual ~IState() = default;
};
//
class RedState : public IState {
public:
  RedState(TrafficLight &t) : IState(t) {}

  void next() override;
  std::string getState() override { return "RED"; }
};

class GreenState : public IState {
public:
  GreenState(TrafficLight &t) : IState(t) {}
  void next() override;
  std::string getState() override { return "GREEN"; }
};

class YellowState : public IState {
public:
  YellowState(TrafficLight &t) : IState(t) {}
  void next() override;
  std::string getState() override { return "YELLOW"; }
};

//
class TrafficLight {

  std::unique_ptr<IState> state_;

public:
  TrafficLight() { state_ = std::make_unique<RedState>(*this); }

  void setState(std::unique_ptr<IState> newState) {
    state_ = std::move(newState);
  }

  void next() {
    // if red, make it yellow
    // if yellow make it green
    // and so on
    state_->next();
  }

  // get the state name
  void getState() {
    std::cout << "Current State: " << state_->getState() << std::endl;
  }
};

// State method definitions
void RedState::next() {
  std::cout << "Transitioning from RED to GREEN..." << std::endl;
  light_.setState(std::make_unique<GreenState>(light_));
}

void GreenState::next() {
  std::cout << "Transitioning from GREEN to YELLOW..." << std::endl;
  light_.setState(std::make_unique<YellowState>(light_));
}

void YellowState::next() {
  std::cout << "Transitioning from YELLOW to RED..." << std::endl;
  light_.setState(std::make_unique<RedState>(light_));
}

int main() {
  TrafficLight light;

  light.getState(); // Initial state

  light.next();
  light.getState();

  light.next();
  light.getState();

  light.next();
  light.getState();

  return 0;
}