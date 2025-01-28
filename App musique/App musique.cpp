#include <iostream>
#include <string>
#include <vector>
#include "./source/Guitar.hpp"
#include "./source/Piano.hpp"
#include "./source/Xylophone.hpp"
#include "./source/Instrument.hpp"
using namespace std;


int main() {
    cout << "Choisi un instrument:\n";
    cout << "1. Piano\n2. Xylophone\n3. Guitare\n";
    int choix;
    cin >> choix;

    cout << "Choisi un rythme:\n";
    cout << "1. Lent\n2. Normal\n3. Rapide\n";
    int Choixrythme;
    cin >> Choixrythme;
    cin.ignore();
    cout << "Entrer la musique avec une serie de lettres et chiffres (ex: C4 E4 G4):\n";
    string musique;
    getline(cin, musique);

    for (int i = 0; i <= musique.size(); i++) {
        if (musique[i] == 'A') {
            cout << "La ";
            i += 2;
        }
        else if (musique[i] == 'B') {
            cout << "Si ";
            i += 2;
        }
        else if (musique[i] == 'C') {
            cout << "Do ";
            i += 2;
        }
        else if (musique[i] == 'D') {
            cout << "Re ";
            i += 2;
        }
        else if (musique[i] == 'E') {
            cout << "Mi ";
            i += 2;
        }
        else if (musique[i] == 'F') {
            cout << "Fa ";
            i += 2;
        }
        else if (musique[i] == 'G') {
            cout << "Sol ";
            i += 2;
        }
    }
    return 0;
}