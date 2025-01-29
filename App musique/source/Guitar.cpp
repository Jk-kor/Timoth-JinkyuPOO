#include <iostream>
#include "Guitare.hpp"
void Guitare::play(const string& note, float duration) {
    cout << "Guitare: " << note << ", " << duration << endl;
}