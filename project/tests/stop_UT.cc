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
#include "../src/bus.h"
#include "../src/stop.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class StopTests : public ::testing::Test {
protected:

  Stop *stop1, *stop2;
  Passenger *passenger1;
  virtual void SetUp() {
    stop1 = new Stop(233, 233.3, 233.33);
    passenger1 = new Passenger(233, "Qi");
    stop2 = new Stop(123, 123.3, 123.33);
  }

  virtual void TearDown() {
    delete stop1;
    delete stop2;
    delete passenger1;
    stop1 = NULL;
    stop2 = NULL;
    passenger1 = NULL;
  }
};

TEST_F(StopTests, ConstructorTest){

  EXPECT_EQ(stop1->GetId(), 233);
  EXPECT_EQ(stop1->GetLongitude(), 233.3);
  EXPECT_EQ(stop1->GetLatitude(), 233.33);
  EXPECT_EQ(stop1->GetNumPassengersPresent(), 0);

  // stop2 = new Stop(123, 123.3, 123.33);
  // EXPECT_EQ(stop2->GetId(), 123);
  // EXPECT_EQ(stop2->GetLongitude(), 123.3);
  // EXPECT_EQ(stop2->GetLatitude(), 123.33);
  // EXPECT_EQ(stop2->GetNumPassengersPresent(), 0);
}

TEST_F(StopTests, AddPassengersTest){
  //stop1 = new Stop(233, 233.3, 233.33);

  EXPECT_EQ(stop1->GetNumPassengersPresent(), 0);
  stop1->AddPassengers(passenger1);
  EXPECT_EQ(stop1->GetNumPassengersPresent(), 1);
  stop1->AddPassengers(passenger1);
  EXPECT_EQ(stop1->GetNumPassengersPresent(), 2);
  stop1->AddPassengers(passenger1);
  stop1->AddPassengers(passenger1);
  EXPECT_EQ(stop1->GetNumPassengersPresent(), 4);
}

TEST_F(StopTests, ReportTest){
  //stop1 = new Stop(233, 233.3, 233.33);
  testing::internal::CaptureStdout();
  stop1->Report(cout);
  EXPECT_GE(testing::internal::GetCapturedStdout().find("ID: 233"),0);


  //passenger1 = new Passenger(233, "Qi");
  testing::internal::CaptureStdout();
  stop2->Report(cout);
  stop1->AddPassengers(passenger1);
  EXPECT_GE(testing::internal::GetCapturedStdout().find("Passengers waiting: 1"),0);

}
