#include "gtest/gtest.h"

#include <iostream>
#include <math.h>
#include <ctime>

#include "date.h"


class DateTest : public ::testing::Test {
 public:
  void SetUp( ) { 
    // code here will execute just before the test ensues 
	first_day = Date(2018, 9, 4);
	last_day = Date(2018, 12, 11);
  }
 protected:
  Date first_day;          // first day of classes
  Date last_day;           // last day of classes
};



TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, GetDateTests){         
  Date data_9011(1900, 01, 01); 
  Date data_010110(1901, 01, 10);              
  Date data_011001(1901, 10, 01);            
  Date data_991231(9999, 12, 31);
  Date data_000910(1000, 9, 10);
  Date data_001009(1000, 10, 9);

  EXPECT_EQ(data_9011.GetDate(), "1900-01-01") << "data_9011 GetDate() failure";
  EXPECT_EQ(data_010110.GetDate(), "1901-01-10") << "data_010110 GetDate() failure";
  EXPECT_EQ(data_011001.GetDate(), "1901-10-01") << "data_011001 GetDate() failure";
  EXPECT_EQ(data_991231.GetDate(), "9999-12-31") << "data_991231 GetDate() failure";
  EXPECT_EQ(data_000910.GetDate(), "1000-09-10") << "data_000910 GetDate() failure";
  EXPECT_EQ(data_001009.GetDate(), "1000-10-09") << "data_001009 GetDate() failure";
  EXPECT_EQ(first_day.GetDate(),"2018-09-04") << "first_day.GetDate() incorrect";
  EXPECT_EQ(last_day.GetDate(),"2018-12-11") << "last_day.GetDate() incorrect";
}

TEST_F(DateTest, GetUSDateTests){
  //Date date4(0, 0, 0);              
  //Date date5(9999, 99, 99);            
  Date data_9011(1900, 01, 01); 
  Date data_010110(1901, 01, 10);              
  Date data_011001(1901, 10, 01);            
  Date data_991231(9999, 12, 31);
  Date data_000910(1000, 9, 10);
  Date data_001009(1000, 10, 9);

  EXPECT_EQ(data_9011.GetUsDate(), "01-01-1900") << "data_9011 GeUsDate() failure";
  EXPECT_EQ(data_010110.GetUsDate(), "01-10-1901") << "data_010110 GetUsDate() failure";
  EXPECT_EQ(data_011001.GetUsDate(), "10-01-1901") << "data_011001 GetUsDate() failure";
  EXPECT_EQ(data_991231.GetUsDate(), "12-31-9999") << "data_991231 GetUsDate() failure";
  EXPECT_EQ(data_000910.GetUsDate(), "09-10-1000") << "data_000910 GetUsDate() failure";
  EXPECT_EQ(data_001009.GetUsDate(), "10-09-1000") << "data_001009 GetUsDate() failure";
  EXPECT_EQ(first_day.GetUsDate(),"09-04-2018") << "first_day GetUsDate() failure";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "last_day GetUsDate() failure";
}


TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

/**
  *
  * Note, this is the only provided test case which actually uses our test fixture
  * 
  * However, it is illegal to mix TEST() and TEST_F() in the same test case (file).
  *
  */
  
TEST_F(DateTest, DaysBetweenTests) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly";
  EXPECT_EQ(last_day.DaysBetween(last_day), 0) << "last day to last day incorrect in DaysBetween()";

  Date date1(2015, 12, 31);
  Date date2(2016, 12, 31);
  Date date3(2017, 12, 31);

  EXPECT_EQ(date1.DaysBetween(date2), 366) << "date1 to date2 failure for DaysBetween()";
  EXPECT_EQ(date2.DaysBetween(date3), 365) << "date2 to date3  failure in DaysBetween()";
  EXPECT_EQ(date1.DaysBetween(date3), 731) << "date1 to date3 failure in DaysBetween()";  
}

TEST_F(DateTest, PlusOperatorTest){
  Date first_day_plus = first_day + 3;
  EXPECT_EQ(first_day_plus.GetDate(),"2018-09-07") << "plus operator incorrect (standard)";

  first_day_plus = first_day + -1;
  EXPECT_EQ(first_day_plus.GetDate(),"2018-09-03") << "plus operator incorrect (sneaky negative)";

  first_day_plus = first_day + 7.5;//should automatically truncate float
  EXPECT_EQ(first_day_plus.GetDate(),"2018-09-11") << "plus operator incorrect (float)";

  first_day_plus = first_day + 30;
  EXPECT_EQ(first_day_plus.GetDate(),"2018-10-04") << "plus operator incorrect (add month)";

  first_day_plus = first_day + 0;
  EXPECT_EQ(first_day_plus.GetDate(),"2018-09-04") << "plus operator incorrect (zero)";
}

//- operator test
TEST_F(DateTest, MinusOperatorTest){
  Date first_day_minus = first_day - 1;
  EXPECT_EQ(first_day_minus.GetDate(),"2018-09-03") << "minus operator incorrect (standard)";

  first_day_minus = first_day - (0-2);
  EXPECT_EQ(first_day_minus.GetDate(),"2018-09-06") << "minus operator incorrect (sneaky negative)";

  first_day_minus = first_day - 3.5;//should automatically truncate float
  EXPECT_EQ(first_day_minus.GetDate(),"2018-09-01") << "minus operator incorrect (float)";

  first_day_minus = first_day - 31;
  EXPECT_EQ(first_day_minus.GetDate(),"2018-08-04") << "minus operator incorrect (subtract month)";

  first_day_minus = first_day - 0;
  EXPECT_EQ(first_day_minus.GetDate(),"2018-09-04") << "minus operator incorrect (zero)";
}

TEST_F(DateTest, ConstructorVoidTest){
  //these two should almost always get the same time, since time_t only
  //stores down to the second and the CPU is faster than that
  Date current_date_actual;

  //the following is taken or inspired by the given code,
  //written by Professor Amy Larson
  std::time_t t = std::time(0);
  std::tm* now = std::localtime(&t);
  Date current_date_expected(now->tm_year+1900,now->tm_mon+1,now->tm_mday);

  EXPECT_EQ(current_date_actual.GetDate(),current_date_expected.GetDate()) << "void constructor incorrect (standard)";
}

//constructor test: epoch
TEST_F(DateTest, ConstructorEpochTest){
  Date data_zero(0);
  Date data_negative(-100000);
  Date data_float(230000.6);
  Date data_standard(10000000);
  Date data_maxint(2147483647);
  Date data_minint(-2147483648);

  EXPECT_EQ(data_zero.GetDate(),"1970-01-01") << "epoch constructor incorrect ";
  EXPECT_EQ(data_negative.GetDate(),"1969-12-30") << "epoch constructor incorrect ";
  EXPECT_EQ(data_float.GetDate(),"1970-01-03") << "epoch constructor incorrect ";
  EXPECT_EQ(data_standard.GetDate(),"1970-04-26") << "epoch constructor incorrect ";
  EXPECT_EQ(data_maxint.GetDate(),"2038-01-19") << "epoch constructor incorrect ";
  EXPECT_EQ(data_minint.GetDate(),"1901-12-13") << "epoch constructor incorrect ";
}

//constructor test: 3 ints
TEST_F(DateTest, ConstructorThreeIntsTest){
  //year mutations
  Date year_zero(0,1,1);
  Date year_negative (-6, 1,1);
  Date year_float(6.1,1,1);
  EXPECT_EQ(year_zero.GetDate(),"0-01-01") << "three ints constructor incorrect ";
  EXPECT_EQ(year_negative.GetDate(),"-6-01-01") << "three ints constructor incorrect ";
  EXPECT_EQ(year_float.GetDate(),"6-01-01") << "three ints constructor incorrect ";
  //month mutations
  Date month_zero(1997,0,1);
  Date month_negative(1997,-6,1);
  Date month_float(1997,6.1,1);
  EXPECT_EQ(month_zero.GetDate(),"1997-00-01") << "three ints constructor incorrect ";
  EXPECT_EQ(month_negative.GetDate(),"1997-0-6-01") << "three ints constructor incorrect ";
  EXPECT_EQ(month_float.GetDate(),"1997-06-01") << "three ints constructor incorrect ";
  Date day1(1997,1,0);
  Date day2(1997,1,-6);
  Date day3(1997,1,6.1);
  EXPECT_EQ(day1.GetDate(), "1997-01-00") << "three ints constructor incorrect ";
  EXPECT_EQ(day2.GetDate(), "1997-01-0-6")  << "three ints constructor incorrect ";
  EXPECT_EQ(day3.GetDate(), "1997-01-06") << "three ints constructor incorrect ";
}
/**
  *
  * NOPE!  Can't test PRIVATE methods
  *
  */
/*
TEST(DateTest, ConvertFromDays) {
	Date convert_first_day = ConvertToDays(2458365);
	EXPECT_STREQ(convert_first_day.GetUsDate(), "09-04-2018");
}
*/
