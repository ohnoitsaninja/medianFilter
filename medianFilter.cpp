#include "Arduino.h"
#include "medianFilter.h"

MedianFilter::MedianFilter(int preFill)
{
  for (int i = 0; i < _medianSize; i++) {
    *(_buffer + i) = preFill;
  }
}

int MedianFilter::filter(int newData)
{
  MedianFilter::update(newData);
  return _buffer[halfSize];
}

int MedianFilter::get(int r)
{
  return _buffer[r];
}

void MedianFilter::update(int newData)
{
  MedianFilter::mySort(newData);
}

void MedianFilter::mySort(int newData) {
  if (newData < _buffer[halfSize]) {  // if less than median
    if (newData <= _buffer[0]) {        // if less than lowest reading
      for (int f = 0; f < _medianSize - 2; f++) {
        _buffer[f + 1] = _buffer[f];
      }
      _buffer[0] = newData;
    }
    else {              // find insertion point from mid to low
      int q = halfSize-1;
      while (newData < _buffer[q]) {
        q--;
      }
      int w = q;
        for (int f = q; f > 0; f--) {
        _buffer[f - 1] = _buffer[f];
      }
      _buffer[w] = newData;
    }
  }
  else {                                            // if above median
    if (newData >= _buffer[_medianSize - 1]) {        // if greater than highest reading
        for (int f = _medianSize - 1; f > 0; f--) {
        _buffer[f - 1] = _buffer[f];
      }
      _buffer[_medianSize - 1] = newData;
    }
    else {                                            // find insertion point from mid to high
      int q = halfSize;
      while (newData > _buffer[q]) {
        q++;
      }
      int w = q;
        for (int f = q; f < _medianSize - 2; f++) {
        _buffer[f + 1] = _buffer[f];
  }
      _buffer[w] = newData;
    }
  }
}

/*
  void MedianFilter::mySort(int newData){
  if (newData<=_buffer[0]){
    for (int q = 0; q<_medianSize-2; q++){
      _buffer[q+1] = _buffer[q];
    }
    _buffer[0] = newData;
  }
  else if (newData>=_buffer[_medianSize-1]){
    for (int q = _medianSize-1; q > 0; q--){
      _buffer[q-1] = _buffer[q];
    }
    _buffer[_medianSize-1] = newData;
  }
  else {
    int q = 1;
    while (newData > _buffer[q]){
      q++;
    }
    int w = q;
     for (; q<_medianSize-2; q++){
      _buffer[q+1] = _buffer[q];
    }
    _buffer[w] = newData;
  }
  }
*/

