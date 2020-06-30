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

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class PassengerTests : public ::testing::Test {
protected:
  PassengerLoader* pass_loader;
  PassengerUnloader* pass_unloader;
  Passenger *passenger, *passenger1, *passenger2;

  virtual void SetUp() {
    pass_loader = new PassengerLoader();
    pass_unloader = new PassengerUnloader();
  }

  virtual void TearDown() {
    delete pass_loader;
    delete pass_unloader;
    delete passenger;
    passenger = NULL;
    pass_loader = NULL;
    pass_unloader = NULL;
  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(PassengerTests, Constructor) {
  passenger = new Passenger(233,"Qi");
  EXPECT_EQ(passenger->GetDestination(), 233);
  EXPECT_EQ(passenger->IsOnBus(), false);
  EXPECT_EQ(passenger->GetTotalWait(), 0);

  passenger1 = new Passenger(123,"Mao");
  EXPECT_EQ(passenger1->GetDestination(), 123);
  EXPECT_EQ(passenger1->IsOnBus(), false);
  EXPECT_EQ(passenger1->GetTotalWait(), 0);
};
<<<<<<< HEAD


TEST_F(PassengerTests, IsOnBus){
  passenger = new Passenger(233, "Qi");
  passenger->GetOnBus();
  EXPECT_EQ(passenger->IsOnBus(),true);
  passenger = new Passenger(233, "Mao");
  EXPECT_EQ(passenger->IsOnBus(),false);
}

TEST_F(PassengerTests, GetOnBus){
  passenger = new Passenger(233, "Qi");
  EXPECT_EQ(passenger->GetTotalWait(), 0);
  passenger->GetOnBus();
  EXPECT_EQ(passenger->GetTotalWait(), 1);
}

TEST_F(PassengerTests, GetTotalWait){
  passenger = new Passenger(233, "Qi");
  EXPECT_EQ(passenger->GetTotalWait(), 0);
  passenger->GetOnBus();
  EXPECT_EQ(passenger->GetTotalWait(), 1);
}

TEST_F(PassengerTests, Update){
  passenger = new Passenger(233, "Qi");
  passenger->Update();
  EXPECT_EQ(passenger->GetTotalWait(), 1);
  passenger->Update();
  EXPECT_EQ(passenger->GetTotalWait(), 2);
}



TEST_F(PassengerTests, GetDestination){
  passenger = new Passenger(233, "Qi");
  EXPECT_EQ(passenger->GetDestination(),233);
  passenger = new Passenger(123, "Mao");
  EXPECT_EQ(passenger->GetDestination(),123);
}


TEST_F(PassengerTests, Report){
 passenger = new Passenger(233, "Qi");
 testing::internal::CaptureStdout();
 passenger->Report(cout);
 EXPECT_GE(testing::internal::GetCapturedStdout().find("Name: Qi"),0);

 passenger1 = new Passenger(233,"Eric");
 testing::internal::CaptureStdout();
 passenger1->Report(cout);
 EXPECT_GE(testing::internal::GetCapturedStdout().find("Destination: 233"),0);

 passenger2 = new Passenger(123, "Mao");
 testing::internal::CaptureStdout();
 passenger2->GetOnBus();
 passenger2->Report(cout);
 EXPECT_GE(testing::internal::GetCapturedStdout().find("\tTime on bus: 1"),0);
}
=======
>>>>>>> 83c26aadf027a4b312c8fa38dcbe4146483de6fb
