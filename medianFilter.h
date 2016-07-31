#ifndef MedianFilter_h
#define MedianFilter_h

#include "Arduino.h"

#define _medianSize 64
#define halfSize _medianSize/2
class MedianFilter
{
  public:
    MedianFilter(int preFill=0);
    int filter(int newData); // use this, takes in new data reading, returns new median);
    int get(int r=halfSize);
    void update(int newData); // adds new data to buffer without 
  private:
    int _buffer[_medianSize];
    void mySort(int newData);
    void shiftBufUp(int q=0);
    void shiftBufDown(int q=_medianSize-1);
};

#endif
