/**
 * @file bus_factory.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_FACTORY_H_
#define SRC_BUS_FACTORY_H_

#include <random>
#include <string>

#include "src/bus.h"
#include "src/regular_bus.h"
#include "src/small_bus.h"
#include "src/large_bus.h"

enum BusType {
  BT_large, BT_regular, BT_small
};

class BusFactory {
 public:
  /**
  * @brief Add bus with id and out route and in rout and bus type and speed =1.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] id bus id
  * @param[in] out outbound route
  * @param[in] in inbound route
  * @param[in] type bustype
  * @param[in] speed bus speed
  */
  Bus * Generate(std::string id, Route * out, Route * in, BusType type,
                              double speed = 1);
};
#endif  // SRC_BUS_FACTORY_H_
