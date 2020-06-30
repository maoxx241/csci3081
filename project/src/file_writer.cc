/**
 * @file file_writer.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include "src/util.h"
#include "src/passenger_unloader.h"
#include "src/file_writer_manager.h"
#include "src/file_writer.h"

class Util;
void FileWriter::Write(std::string filename, std::vector<std::string> outstr) {
  std::ofstream myfile;
  myfile.open(filename, std::ios::app);
  for (int i = 0; i < outstr.size(); i++) {
    myfile << outstr[i] << std::endl;
  }
  myfile.close();
}
