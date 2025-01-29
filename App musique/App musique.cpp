#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "./source/Guitar.hpp"
#include "./source/Piano.hpp"
#include "./source/Xylophone.hpp"
using namespace std;

vector<pair<string, float>> readMusicFile(const string& filename) {
    vector<pair<string, float>> notes;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Impossible d'ouvrir le fichier " << filename << endl;
        return notes;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string note;
        float duration;
        if (ss >> note >> duration) {
            notes.emplace_back(note, duration);
        }
    }
    file.close();
    return notes;
}

void playMusic(Instrument& instrument, const vector<pair<string, float>>& music_notes) {
    for (const auto& note_duration : music_notes) {
        instrument.play(note_duration.first, note_duration.second);
    }
}

int main() {
    cout << "Choisi un instrument:\n1. Piano\n2. Xylophone\n3. Guitare\n";
    int choix;
    cin >> choix;
    cout << "Entrez le nom du fichier de partition (ex: partition.txt): ";
    string filename;
    cin >> filename;

    vector<pair<string, float>> music_notes = readMusicFile(filename);
    if (music_notes.empty()) {
        cout << "Erreur lors de la lecture du fichier ou fichier vide.\n";
        return 1;
    }

    Instrument* instrument = nullptr;
    switch (choix) {
    case 1: instrument = new Piano(); break;
    case 2: instrument = new Xylophone(); break;
    case 3: instrument = new Guitare(); break;
    default: cout << "Choix invalide. Piano par défaut.\n"; instrument = new Piano(); break;
    }

    playMusic(*instrument, music_notes);
    delete instrument;
    return 0;
}