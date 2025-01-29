#include <iostream>
#include "Piano.hpp"
void Piano::play(const string& note, float duration) {
    cout << "Piano: " << note << ", " << duration << endl;
}