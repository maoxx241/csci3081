/**
 * @file file_writer.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_FILE_WRITER_H_
#define SRC_FILE_WRITER_H_

#include <string>
#include <vector>
#include <fstream>
#include "src/file_writer.h"
#include "src/util.h"

class FileWriter{
 public:
  /**
  * @brief write string vector to csvfile
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] std::vector<std::string> for outstring
  * @param[in] std::string
  */
  void Write(std::string, std::vector<std::string>);
};
#endif  // SRC_FILE_WRITER_H_
