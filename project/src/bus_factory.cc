/**
 * @file passenger_factory.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include "src/bus_factory.h"

Bus *BusFactory::Generate(std::string id, Route *out, Route *in, BusType type,
                          double speed) {
  Bus *busPtr = NULL;
  switch (type) {
  case BT_small:
    busPtr = new SmallBus(id, out, in,
                          speed);
    break;
  case BT_regular:
    busPtr = new RegularBus(id, out, in,
                            speed);
    break;
  case BT_large:
    busPtr = new LargeBus(id, out, in,
                          speed);
    break;
  default:
    break;
  }
  return busPtr;
}
