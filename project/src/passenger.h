/**
 * @file passenger.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_PASSENGER_H_
#define SRC_PASSENGER_H_

#include <iostream>
#include <string>

class Passenger {  // : public Reporter {
 public:
  /**
  * @brief Add passenger with destination_stop_id = -1 and name = nobody
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] destination_stop_id destination stop Id, left bound (not-inclusive)
  * @param[in] name passenger name, right bound (inclusive)
  */
  explicit Passenger(int = -1, std::string = "Nobody");
  /**
  * @brief update passenger state
  *
  * This function will be used for simulation purposes.
  *
  */
  void Update();
  void GetOnBus();
  int GetTotalWait() const;
  /**
  * @brief Check destination
  *
  * @return bool.
  */
  bool IsOnBus() const;
  /**
  * @brief Check destination
  *
  * @return int.
  */
  int GetDestination() const;
  /**
  * @brief report passenger state
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] ostream for output
  */
  void Report(std::ostream&) const;
  /**
  * @brief report bus state
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] ostream for output
  */
  void Tocsv(std::ostream&) const;

 private:
  std::string name_;
  int destination_stop_id_;
  int wait_at_stop_;
  int time_on_bus_;
  int id_;
  static int count_;  // global count, used to set ID for new instances
};
#endif  // SRC_PASSENGER_H_
