#ifndef INSTRUMENT
#define INSTRUMENT
#include <iostream>
#include <string>
using namespace std;

class Instrument {
public:
    virtual void play(const string& note, float duration) = 0;
    virtual ~Instrument() = default;
};

#endif