#ifndef PIANO
#define PIANO
#include <iostream>
#include <string>
#include "./Instrument.hpp"

class Piano : public Instrument {
public:
    void play(const string& note, float duration) override {
        cout << "Piano joue: " << note << " avec une durée de " << duration << " secondes" << endl;
    }
};

#endif