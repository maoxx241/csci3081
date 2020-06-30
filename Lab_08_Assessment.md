### Assessment for Lab 08

#### Total score: _95.75_ / _100_

Run on February 25, 18:16:38 PM.


#### System Files and Lab Directory Structure

+ Pass: Check that directory "googletest" exists.

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab08_google_tests" exists.

+ Pass: Make directory "Lab08_Testing".

+ Pass: Change into directory "Lab08_Testing".


#### Essential Files Exist

+ Pass: Check that file "../labs/lab08_google_tests/date_unittest.cc" exists.


### Testing correct implementation

+ Pass: Copy directory "Lab08 files.".



+ Pass: Copy directory "Files for correct version".



+ Pass: Change into directory "correct".

+ Pass: Check that make compiles.



+ Pass: Check that file "date_unittest" exists.

+ Pass: Get all google tests.
    10 tests found.




#### Results

+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.PrintDateTests.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.GetDateTests.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.GetUSDateTests.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.PrintDateTestsWithoutNewline.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.DaysBetweenTests.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.PlusOperatorTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.MinusOperatorTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.ConstructorVoidTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.ConstructorEpochTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.ConstructorThreeIntsTest.



+  _50_ / _50_ : Pass: 100.0% of the tests passed. Expected at least 100%.


### Testing Mutants


#### Testing Mutant 1 for failure

+ Pass: At least one test failed for Mutant 1


#### Testing Mutant 2 for failure

+ Pass: At least one test failed for Mutant 2


#### Testing Mutant 3 for failure

+ Pass: At least one test failed for Mutant 3


#### Testing Mutant 4 for failure

+ Pass: At least one test failed for Mutant 4


#### Testing Mutant 5 for failure

+ Pass: At least one test failed for Mutant 5


#### Testing Mutant 6 for failure

+ Pass: At least one test failed for Mutant 6


#### Testing Mutant 7 for failure

+ Pass: At least one test failed for Mutant 7


#### Testing Mutant 8 for failure

+ Pass: At least one test failed for Mutant 8


#### Testing Mutant 9 for failure

+ Pass: At least one test failed for Mutant 9


#### Testing Mutant 10 for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - 3/1/2016 - 2 should be 2/28/2016, but this version prints 2016-02-27


#### Testing Mutant 11 for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - 2016-02-27 + 2 should be 2016-02-29, but this version prints 2016-03-01


#### Testing Mutant 12 for failure

+ Pass: At least one test failed for Mutant 12


#### Testing Mutant 13 for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - Some dates don't have leading zeroes


#### Testing Mutant 14 for failure

+ Pass: At least one test failed for Mutant 14


#### Testing Mutant 15 for failure

+ Pass: At least one test failed for Mutant 15


#### Testing Mutant 16 for failure

+ Pass: At least one test failed for Mutant 16


#### Testing Mutant 17 for failure

+ Pass: At least one test failed for Mutant 17


#### Results

+  _45.75_ / _50_ : Fail: 82.35% of the tests passed, but the target is 90.0%.

#### Total score: _95.75_ / _100_

