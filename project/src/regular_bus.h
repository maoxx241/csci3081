/**
 * @file regular_bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <string>
#include "src/bus.h"
#ifndef SRC_REGULAR_BUS_H_
#define SRC_REGULAR_BUS_H_
class RegularBus : public Bus{
 public:
  /**
  * @brief Add regular bus with id and out route and in rout and capacity=60 and speed =1.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] name bus name
  * @param[in] out outbound route
  * @param[in] in inbound route
  * @param[in] speed bus speed
  */
  RegularBus(std::string name, Route *out, Route *in,
            double speed = 1) : Bus(name, out, in, 60, speed) {}
  /**
  * @brief report bus state
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] ostream for output
  */
  void Report(std::ostream &) override;
};
#endif  // SRC_REGULAR_BUS_H_
