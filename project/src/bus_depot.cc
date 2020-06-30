/**
 * @file bus_depot.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/bus_depot.h"

#include <stdio.h>
#include <time.h>
#include <string>
#include <iostream>

Context::Context() {
  time_t timer;
  struct tm * timeinfo;
  time(&timer);
  timeinfo = localtime(&timer);
  int hour = timeinfo->tm_hour;
  if (hour >= 6 && hour < 8) {
    HT_ = HT_A;
  } else if (hour >= 8 && hour < 15) {
    HT_ = HT_B;
  } else if (hour >= 15 && hour < 20) {
    HT_ = HT_C;
  } else {
    HT_ = HT_D;
  }
  switch (HT_) {
    case HT_A:
      strategy_ = new ConcreteStrategyA();
      break;
    case HT_B:
      strategy_ = new ConcreteStrategyB();
      break;
    case HT_C:
      strategy_ = new ConcreteStrategyC();
      break;
    case HT_D:
      strategy_ = new ConcreteStrategyD();
    default:
      break;
  }
}
void Context::set_strategy(HourType HT) {
    switch (HT) {
    case HT_A:
      strategy_ = new ConcreteStrategyA();
      break;
    case HT_B:
      strategy_ = new ConcreteStrategyB();
      break;
    case HT_C:
      strategy_ = new ConcreteStrategyC();
      break;
    case HT_D:
      strategy_ = new ConcreteStrategyD();
    default:
      break;
  }
}
void Context::set_HT(int hour) {
    HourType HT;
    if (hour >= 6 && hour < 8) {
      HT = HT_A;
    } else if (hour >= 8 && hour < 15) {
      HT = HT_B;
    } else if (hour >= 15 && hour < 20) {
      HT = HT_C;
    } else {
      HT = HT_D;
  }
  if (HT == HT_) {
    return;
  }
  set_strategy(HT);
}

void Context::report() {
    std::string str;
    switch (HT_) {
    case HT_A:
      str = "Strategy 1";
      break;
    case HT_B:
      str = "Strategy 2";
      break;
    case HT_C:
      str = "Strategy 3";
      break;
    case HT_D:
      str = "small";
    default:
      break;
  }
  std::cout << "~~~~~~~~~~ Current strategy is " << str;
  std::cout << "~~~~~~~~~~" << std::endl;
}

BusType Context::Do() const {
  BusType type = this->strategy_->DoAlgorithm();
  std::string str;
  switch (type) {
  case BT_small:
    str = "Small Bus";
    break;
  case BT_regular:
    str = "Regular Bus";
    break;
  case BT_large:
    str = "Large Bus";
    break;
  default:
    break;
  }
  std::cout << "~~~~~~~~~~ Current Bus is " << str;
  std::cout << "~~~~~~~~~~" << std::endl;
  return type;
}

BusType ConcreteStrategyA::DoAlgorithm() {
  BusType typ;
  switch (state) {
  case 1:
    typ = BT_small;
    state = 2;
    break;
  case 2:
    typ = BT_regular;
    state = 1;
    break;
  default:
    break;
  }
  return typ;
}

BusType ConcreteStrategyB::DoAlgorithm() {
  BusType typ;
  switch (state) {
  case 1:
    typ = BT_regular;
    state = 2;
    break;
  case 2:
    typ = BT_large;
    state = 1;
    break;
  default:
    break;
  }
  return typ;
}

BusType ConcreteStrategyC::DoAlgorithm() {
  BusType typ;
  switch (state) {
  case 1:
    typ = BT_small;
    state = 2;
    break;
  case 2:
    typ = BT_regular;
    state  = 3;
    break;
  case 3:
    typ = BT_large;
    state = 1;
    break;
  default:
    break;
  }
  return typ;
}

BusType ConcreteStrategyD::DoAlgorithm() {
  return BT_small;
}
