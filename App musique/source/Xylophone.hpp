#ifndef XYLOPHONE
#define XYLOPHONE
#include "./Instrument.hpp"

class Xylophone : public Instrument {
public:
    void play(const string& note, float duration) override;
};

#endif