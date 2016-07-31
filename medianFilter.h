#ifndef MedianFilter_h
#define MedianFilter_h
#define _medianSize 8
#define halfSize _medianSize/2

#include "Arduino.h"

class MedianFilter
{
  public:
    MedianFilter(int preFill=0);
    int filter(int newData); // use this, takes in new data , returns new median);
    int getMedian(); // returns last median without adding data
    int getFromBuffer(int); // if you need to debug the buffer data
  private:
    int _buffer[_medianSize];
    void shiftBufUp(int q=0);
    void shiftBufDown(int q=_medianSize-1);
};

#endif
