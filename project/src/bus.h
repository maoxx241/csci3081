/**
 * @file bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_H_
#define SRC_BUS_H_

#include <iostream>
#include <list>
#include <string>


#include "src/data_structs.h"
#include "src/passenger.h"
#include "src/passenger_loader.h"
#include "src/passenger_unloader.h"
#include "src/route.h"
#include "src/stop.h"
#include "src/isubject.h"

class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;

class BusInt : public ISubject<BusData>{
 public:
  virtual void SetColor() = 0;
  virtual ~BusInt() {}
};

class Bus : public BusInt{
 public:
  /**
  * @brief Add bus with id and out route and in rout and capacity=60 and speed =1.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] name bus name
  * @param[in] out outbound route
  * @param[in] in inbound route
  * @param[in] capacity bus capacity
  * @param[in] speed bus speed
  */
  Bus(std::string name, Route * out, Route * in, int capacity = 60,
                                                 double speed = 1);
  /**
  * @brief Check if the trip is complete
  *
  * This function will be used for simulation purposes.
  *
  */
  bool IsTripComplete();
  bool LoadPassenger(Passenger *);  // returning revenue delta
  /**
  * @brief move bus to next stop
  *
  * This function will be used for simulation purposes.
  *
  */
  bool Move();
  /**
  * @brief update bus state
  *
  * This function will be used for simulation purposes.
  *
  */
  void Update();
  /**
  * @brief report bus state
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] ostream for output
  */
  virtual void Report(std::ostream&);
  /**
  * @brief report bus state
  *
  * This function will be used for csv file.
  *
  * @param[in] ostream for output
  */
  void Tocsv(std::ostream&);

  // Vis Getters
  void UpdateBusData();
  void SetColor();
  BusData GetBusData() const;
  std::string GetName() const { return name_; }
  Stop * GetNextStop() const { return next_stop_; }
  size_t GetNumPassengers() const { return passengers_.size(); }
  int GetCapacity() const { return passenger_max_capacity_; }

 private:
  int UnloadPassengers();  // returning revenue delta
  // bool Refuel();
  PassengerUnloader * unloader_;
  PassengerLoader * loader_;
  std::list<Passenger *> passengers_;
  int passenger_max_capacity_;
  // double revenue_; // revenue collected from passengers, doesn't include
                      // passengers who pay on deboard
  // double fuel_;   // may not be necessary for our simulation
  // double max_fuel_;
  std::string name_;
  double speed_;  // could also be called "distance travelled in one time step"
  Route * outgoing_route_;
  Route * incoming_route_;
  double distance_remaining_;  // when negative?, unload/load procedure occurs
  int total_passenger;
                              // AND next stop set
  Stop * next_stop_;
  // bool trip_complete_;  // [DERIVED data] when BOTH routes are at end, trip
  // is complete

  // Vis data for bus
  BusData bus_data_;
};
#endif  // SRC_BUS_H_
