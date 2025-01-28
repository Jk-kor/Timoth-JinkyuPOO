#ifndef GUITAR
#define GUITAR
#include <iostream>
#include <string>
#include "./Instrument.hpp"

class Guitar : public Instrument {
public:
    void playNote(const string& note) const override {
        cout << "Guitar: " << note << endl;
    }

    void display() const override {
        cout << "You are playing the Guitar!" << endl;
    }
};

#endif