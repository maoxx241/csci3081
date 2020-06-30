/**
 * @file large_bus.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/large_bus.h"
void LargeBus::Report(std::ostream &out) {
  out << "This is a large size bus" << std::endl;
  Bus::Report(out);
}
