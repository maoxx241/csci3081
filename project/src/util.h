/**
 * @file util.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_UTIL_H_
#define SRC_UTIL_H_

#include <string>
#include <vector>
#include <sstream>
#include <regex>

#include "src/data_structs.h"
class Util{
 public:
  /**
  * @brief write string stream to stringvector
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] std::vector<std::string> for outstring
  */
  std::vector<std::string> processOutput(std::ostringstream *tostring){
    std::vector<std::string> lst;
    std::string str = tostring->str();
    std::regex reg("\\s+");
    std::sregex_token_iterator iter(str.begin(), str.end(), reg, -1);
    std::sregex_token_iterator end;
    std::vector<std::string> vec(iter, end);
    return vec;
  }
};

#endif  // SRC_UTIL_H_
