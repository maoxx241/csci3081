/**
 * @file bus_decorator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_DECORATOR_H_
#define SRC_BUS_DECORATOR_H_

#include"src/bus.h"

class BusDecorator: public BusInt {
 protected:
  BusInt *m_bus;
 public:
  explicit BusDecorator(BusInt *bus): m_bus(bus) {}
  /**
  * @brief set the color
  *
  * This function will be used for simulation purposes.
  *
  */
  void SetColor();
};
#endif  // SRC_BUS_DECORATOR_H_
