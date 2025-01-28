#ifndef GUITARE
#define GUITARE
#include <iostream>
#include <string>
#include "./Instrument.hpp"

class Guitare : public Instrument {
public:
    void play(const string& note, float duration) override {
        cout << "Guitare joue: " << note << " avec une durée de " << duration << " secondes" << endl;
    }
};
#endif