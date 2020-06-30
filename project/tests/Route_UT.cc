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
#include "../src/route.h"
#include "../src/random_passenger_generator.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class RouteTests : public ::testing::Test {
protected:

  Stop *stop1,*stop2;
  Stop **stops1,**stops2;
  Route *route1, *route2;
  RandomPassengerGenerator *generator1,*generator2;
  double distances1[2];
  double distances2[1];
  list<double> prob1;
  list<Stop *> stopl1;
  list<Stop *> stopl2;


  virtual void SetUp() {
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
  }

  virtual void TearDown() {
    delete stop1;
    delete stop2;
    delete stops1;
    delete stops2;
    delete generator1;
    delete generator2;
    delete route1;
    delete route2;
    stop1 = NULL;
    stop2 = NULL;
    stops2 =NULL;
    stops1 = NULL;
    route1 = NULL;
    route2 = NULL;
    generator1 = NULL;
    generator2 = NULL;
  }
};

TEST_F(RouteTests, Constructor){
  route1 = new Route("Mao", stops1, distances1, 2, generator1);
  std::list<Stop *> stops_1;
  stops_1.push_back(stop1);
  stops_1.push_back(stop2);
  EXPECT_EQ(route1->GetName(), "Mao");
  EXPECT_EQ(route1->GetStops(), stops_1);

  route2 = new Route("Qi", stops2, distances2, 1, generator2);
  std::list<Stop *> stops_2;
  stops_2.push_back(stop1);
  EXPECT_EQ(route2->GetName(), "Qi");
  EXPECT_EQ(route2->GetStops(), stops_2);

}

TEST_F(RouteTests, IsAtEnd){
  bool flag;
  route1 = new Route("Mao", stops1, distances1, 2, generator1);
  flag=route1->IsAtEnd();
  EXPECT_EQ(flag, false);
  route1->NextStop();
  flag=route1->IsAtEnd();
  EXPECT_EQ(flag, false);
  route1->NextStop();
  flag=route1->IsAtEnd();
  EXPECT_EQ(flag, true);


}
