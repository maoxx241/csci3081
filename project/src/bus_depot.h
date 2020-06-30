/**
 * @file bus_depot.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_DEPOT_H_
#define SRC_BUS_DEPOT_H_
#include "src/bus_factory.h"

enum HourType {
  HT_A, HT_B, HT_C, HT_D
};
class Strategy {
 public:
  virtual ~Strategy() {}
  virtual BusType DoAlgorithm() = 0;
};

/**
 * The Context defines the interface of interest to clients.
 */

class Context {
    /**
     * @var Strategy The Context maintains a reference to one of the Strategy
     * objects. The Context does not know the concrete class of a strategy. It
     * should work with all strategies via the Strategy interface.
     */
 private:
  Strategy *strategy_;
  HourType HT_;
    /**
     * Usually, the Context accepts a strategy through the constructor, but also
     * provides a setter to change it at runtime.
     */
 public:
  Context();
    /**
     * Usually, the Context allows replacing a Strategy object at runtime.
     */
  void set_strategy(Strategy *strategy) {
    strategy_ = strategy;
  }
  /**
  * @brief set strategy
  *
  * This function will be used for strategy purposes.
  *
  * @param[in] HT for hour
  */
  void set_strategy(HourType HT);
  /**
  * @brief set hour
  *
  * This function will be used for strategy purposes.
  *
  * @param[in] hour for hour
  */
  void set_HT(int hour);
  /**
  * @brief report strategy state
  *
  * This function will be used for simulation purposes.
  */
  void report();
    /**
     * The Context delegates some work to the Strategy object instead of
     * implementing +multiple versions of the algorithm on its own.
     */
  BusType Do() const;
};

/**
 * Concrete Strategies implement the algorithm while following the base Strategy
 * interface. The interface makes them interchangeable in the Context.
 */
class ConcreteStrategyA : public Strategy {
 public:
  ConcreteStrategyA() {}
  BusType DoAlgorithm() override;
 private:
  int state = 1;
};
class ConcreteStrategyB : public Strategy {
 public:
  ConcreteStrategyB() {}
  BusType DoAlgorithm() override;

 private:
  int state = 1;
};

class ConcreteStrategyC : public Strategy {
 public:
  ConcreteStrategyC() {}
  BusType DoAlgorithm() override;

 private:
  int state = 1;
};

class ConcreteStrategyD : public Strategy {
 public:
  ConcreteStrategyD() {}
  BusType DoAlgorithm() override;
};
#endif  // SRC_BUS_DEPOT_H_
