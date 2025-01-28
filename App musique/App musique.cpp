#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

#include "./source/Guitar.hpp"
#include "./source/Piano.hpp"
#include "./source/Xylophone.hpp"
#include "./source/Instrument.hpp"

using namespace std;

map<string, float> readMusicFile(const string& filename) {
    map<string, float> note_to_duration;
    ifstream file(filename);
    string line;
    if (!file.is_open()) {
        cerr << "Impossible d'ouvrir le fichier " << filename << endl;
        return note_to_duration;
    }
    while (getline(file, line)) {
        stringstream ss(line);
        string note;
        float duration;
        ss >> note >> duration;
        if (!note.empty()) {
            note_to_duration[note] = duration;
        }
    }
    file.close();
    return note_to_duration;
}

void playMusic(Instrument& instrument, const vector<pair<string, float>>& music_notes) {
    for (const auto& note_duration : music_notes) {
        cout << "Instrument joue: " << note_duration.first << " avec une durée de "
            << note_duration.second << " secondes" << endl;
        instrument.play(note_duration.first, note_duration.second);
    }
}

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
    cout << "Entrez le nom du fichier de partition (par exemple, 'partition.txt'):\n";
    string filename;
    cin >> filename;
    map<string, float> note_to_duration = readMusicFile(filename);
    if (note_to_duration.empty()) {
        cout << "Erreur lors de la lecture du fichier ou fichier vide.\n";
        return 1;
    }
    Instrument* instrument;
    switch (choix) {
    case 1: instrument = new Piano(); break;
    case 2: instrument = new Xylophone(); break;
    case 3: instrument = new Guitare(); break;
    default:
        cout << "Choix invalide. Piano par défaut.\n";
        instrument = new Piano();
        break;
    }
    vector<pair<string, float>> music_notes;
    for (const auto& entry : note_to_duration) {
        music_notes.push_back(entry);
    }
    playMusic(*instrument, music_notes);
    return 0;
}
