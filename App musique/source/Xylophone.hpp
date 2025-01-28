#ifndef XYLOPHONE
#define XYLOPHONE
#include <iostream>
#include <string>
#include "./Instrument.hpp"

class Xylophone : public Instrument {
public:
    void play(const string& note, float duration) override {
        cout << "Xylophone joue: " << note << " avec une durée de " << duration << " secondes" << endl;
    }
};

#endif