/**
 * @file isubject.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_ISUBJECT_H_
#define SRC_ISUBJECT_H_


#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>

#include "src/data_structs.h"
#include "src/iobserver.h"

template<class T>
class ISubject {
 public:
  void RegosterObserver(IObserver<T> *observer);
  /**
  * @brief Clear Observers
  *
  * This function will be used for simulation purposes.
  */
  void ClearObservers();
  /**
  * @brief update infomation
  *
  * This function will be used for simulation purposes.
  */
  void NotifyObservers(T *info);
 private:
  std::vector<IObserver<T>*> observer_;
};

#endif  // SRC_ISUBJECT_H_
