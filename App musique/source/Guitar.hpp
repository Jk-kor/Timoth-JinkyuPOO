#ifndef GUITARE
#define GUITARE
#include "./Instrument.hpp"

class Guitare : public Instrument {
public:
	void play(const string& note, float duration) override;
};
#endif