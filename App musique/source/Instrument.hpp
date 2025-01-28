#ifndef INSTRUMENT
#define INSTRUMENT
#include <iostream>
#include <string>
using namespace std;

class Instrument {
public:
    virtual ~Instrument() = default;

    virtual void playNote(const string& note) const = 0;

    virtual void display() const = 0;
};

#endif