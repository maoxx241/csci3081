/**
 * @file isubject.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>

#include "src/isubject.h"

template<class T>
void ISubject<T>::RegosterObserver(IObserver<T> *observer) {
  observer_.push_back(observer);
}

template<class T>
void ISubject<T>::ClearObservers() {
  observer_.clear();
}

template<class T>
void ISubject<T>::NotifyObservers(T *info) {
  for (typename std::vector<IObserver<T> *>::
    const_iterator iter = observer_.begin();
    iter != observer_.end(); ++iter) {
      if (*iter != 0) {
        (*iter)->Notify(info);
      }
  }
}

template class ISubject<BusData>;
template class ISubject<StopData>;
