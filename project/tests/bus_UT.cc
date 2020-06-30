/*
 * Students: Use this file as a guide to writing your own unit tests.
 * See the project instructions for more information on which classes
 * and methods must be tested.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>
#include <string>

#include "../src/passenger_loader.h"
#include "../src/passenger_unloader.h"
#include "../src/passenger.h"
#include "../src/stop.h"
#include "../src/route.h"
#include "../src/bus.h"
#include "../src/random_passenger_generator.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class BusTests : public ::testing::Test {
protected:
  Passenger *passenger;
  Stop *stop1,*stop2;
  Stop **stops1,**stops2;
  Route *route1, *route2;
  RandomPassengerGenerator *generator1,*generator2;
  double distances1[2];
  double distances2[1];
  list<double> prob1;
  list<Stop *> stopl1;
  list<Stop *> stopl2;
  Bus *bus1, *bus2, *bus3;

  virtual void SetUp() {
    passenger = new Passenger(233, "Qi");
    stop1 = new Stop(233, 233.3, 233.33);
    stop2 = new Stop(123, 123.3, 123.33);
    stops1 = new Stop*[2];
    stops2 = new Stop*[1];
    stops1[0] = stop1;
    stops1[1] = stop2;
    stops2[0] = stop1;
    distances1[0] = 233;
    distances2[0] = 233;
    distances1[1] = 123;
    prob1.push_back(20);
    stopl1.push_back(stop1);
    stopl1.push_back(stop2);
    stopl2.push_back(stop1);
    generator1 = new RandomPassengerGenerator(prob1, stopl1);
    generator2 = new RandomPassengerGenerator(prob1, stopl2);
    route1 = new Route("Mao", stops1, distances1, 2, generator1);
    route2 = new Route("Qi", stops2, distances2, 1, generator2);
    bus1=new Bus("Qi",route1,route1,60,1.0);
    bus2=new Bus("Mao",route1,route2,100,1.0);
    bus3=new Bus("Eric",route2,route2,1,1.0);
  }

  virtual void TearDown() {
    delete passenger;
    delete stop1;
    delete stop2;
    delete stops1;
    delete stops2;
    delete generator1;
    delete generator2;
    delete route1;
    delete route2;
    delete bus1;
    delete bus2;
    delete bus3;
    passenger = NULL;
    stop1 = NULL;
    stop2 = NULL;
    stops2 =NULL;
    stops1 = NULL;
    route1 = NULL;
    route2 = NULL;
    generator1 = NULL;
    generator2 = NULL;
    bus1= NULL;
    bus2 = NULL;
    bus3 = NULL;
  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(BusTests, ConstructorTest) {
  //bus1=new Bus("Qi",route1,route1,60,1.0);
  EXPECT_EQ(bus1->GetName(), "Qi");
  EXPECT_EQ(bus1->GetNextStop(), stop1);
  EXPECT_EQ(bus1->GetCapacity(), 60);
  EXPECT_EQ(bus1->GetNumPassengers(), 0);

  // bus2=new Bus("Mao",route2,route2,100,1.0);
  EXPECT_EQ(bus2->GetName(), "Mao");
  EXPECT_EQ(bus2->GetNextStop(), stop1);
  EXPECT_EQ(bus2->GetCapacity(), 100);
  EXPECT_EQ(bus2->GetNumPassengers(), 0);
};

TEST_F(BusTests, IsTripCompleteTest) {
  //bus2=new Bus("Mao",route2,route2,100,1.0);
  EXPECT_EQ(bus3->IsTripComplete(), false);
  bus3->Move();
  bus3->Move();
  bus3->Move();
  EXPECT_EQ(bus2->IsTripComplete(), true);


};

TEST_F(BusTests, MoveTest) {
  bool flag;

  flag=bus2->Move();
  EXPECT_EQ(flag, false);
  flag=bus2->Move();
  EXPECT_EQ(flag, true);
  // flag=bus2->Move();
  // EXPECT_EQ(flag, true);
};

TEST_F(BusTests, LoadPassengerTest) {
  bool flag;
  bus1=new Bus("Qi",route1,route1,0,1.0);
  flag=bus1->LoadPassenger(passenger);
  EXPECT_EQ(flag, false);
  //bus2=new Bus("Mao",route2,route2,100,1.0);
  flag=bus2->LoadPassenger(passenger);
  EXPECT_EQ(flag, true);
};
