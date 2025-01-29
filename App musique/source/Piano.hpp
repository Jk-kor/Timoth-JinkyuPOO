#ifndef PIANO
#define PIANO
#include "./Instrument.hpp"

class Piano : public Instrument {
public:
    void play(const string& note, float duration) override;
};

#endif