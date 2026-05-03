#include <bits/stdc++.h>
using namespace std;

struct weightDetails {
    string weightName;
    float weightValue;
};
vector<weightDetails> weights = {
    {"Brick", 6.44}, {"Dumbbell", 8.4}, {"Plate", 10.64},
    {"Barbell", 13.72}, {"Anvil", 17.36}, {"Anchor", 21.84},
    {"Boulder", 26.88}, {"Torpedo", 33.04}, {"Trident", 37.8},
    {"Thick Log", 42.0}, {"Heavy Shell", 44.8}, {"Pipe", 49.0},
    {"Kraken Eye", 53.76}, {"Megalodon Anchor", 58.8}, {"Ice Cube", 64.4},
    {"Jellyfish Core", 70.0}, {"Steampunk Relic", 82.6}, {"Tombstone", 89.6},
    {"Prehistoric Amber", 96.6}
};

struct oxygenDetails {
    string oxygenName;
    float oxygenValue;
};
vector<oxygenDetails> oxygens = {
    {"Starter Oxygen Tank", 19}, {"Double Oxygen Tank", 24}, {"Aqua Oxygen Tank", 29},
    {"Coral Oxygen Tank", 35}, {"Seaweed Oxygen Tank", 42}, {"Ore Oxygen Tank", 49},
    {"Beach Oxygen Tank", 58}, {"Golden Oxygen Tank", 67}, {"Candy Oxygen Tank", 77},
    {"Trench Oxygen Tank", 81}, {"Atlantis Oxygen Tank", 87}, {"Forest Oxygen Tank", 93},
    {"Shell Oxygen Tank", 100}, {"Sewer Oxygen Tank", 118}, {"Kraken Oxygen Tank", 134},
    {"Megalodon Oxygen Tank", 149}, {"Ice Oxygen Tank", 160}, {"Jellyfish Oxygen Tank", 172},
    {"Steampunk Oxygen Tank", 202}, {"Graveyard Oxygen Tank", 221}, {"Dinosaur Oxygen Tank", 240}
};

struct finDetails {
    string finName;
    float finValue;
};
vector<finDetails> fins = {
    {"Starter Fins", 6.72}, {"Aqua Fins", 8.12}, {"Coral Fins", 9.8},
    {"Seaweed Fins", 11.76}, {"Ore Fins", 14.28}, {"Beach Fins", 17.36},
    {"Golden Fins", 20.44}, {"Candy Fins", 23.24}, {"Trench Fins", 26.32},
    {"Atlantis Fins", 29.4}, {"Forest Fins", 31.92}, {"Shell Fins", 34.44},
    {"Sewer Fins", 36.96}, {"Kraken Fins", 39.48}, {"Megalodon Fins", 42},
    {"Ice Fins", 45.36}, {"Jellyfish Fins", 48.44}, {"Steampunk Fins", 56.56},
    {"Graveyard Fins", 61.32}, {"Dinosaur Fins", 66.64}
};

int main() {
    for (int i = 0; i < weights.size(); i++) cout << i + 1 << ") " << weights[i].weightName << endl;
    for (int i = 0; i < 20; i++) cout << "-";
    cout << "\nCurrent weight: ";
    int curr_weight; cin >> curr_weight; curr_weight--;
    for (int i = 0; i < 20; i++) cout << "-"; cout << endl;
    
    for (int i = 0; i < oxygens.size(); i++) cout << i + 1 << ") " << oxygens[i].oxygenName << endl;
    for (int i = 0; i < 20; i++) cout << "-";
    cout << "\nCurrent oxygen tank: ";
    int curr_oxygen; cin >> curr_oxygen; curr_oxygen--;
    for (int i = 0; i < 20; i++) cout << "-"; cout << endl;
    
    for (int i = 0; i < fins.size(); i++) cout << i + 1 << ") " << fins[i].finName << endl;
    for (int i = 0; i < 20; i++) cout << "-";
    cout << "\nCurrent fin: ";
    int curr_fin; cin >> curr_fin; curr_fin--;
    for (int i = 0; i < 20; i++) cout << "-"; cout << endl;

    cout << "Target depth: ";
    int target_depth; cin >> target_depth;
    for (int i = 0; i < 20; i++) cout << "-"; cout << endl;

    float downTime = target_depth / weights[curr_weight].weightValue;
    float downPercentage = downTime / (oxygens[curr_oxygen].oxygenValue / 100);
    float upTime = target_depth / fins[curr_fin].finValue;
    float upPercentage = upTime / (oxygens[curr_oxygen].oxygenValue / 100);
    float catchTime = oxygens[curr_oxygen].oxygenValue - (downTime + upTime);
    float catchPercentage = catchTime / (oxygens[curr_oxygen].oxygenValue / 100);

    cout << "Go down for " << downTime << "s - " << downPercentage << "%" << endl;
    cout << "Catching for " << catchTime << "s - " << catchPercentage << "%" << endl;
    cout << "Go up for " << upTime << "s - " << upPercentage << "%" << endl;
    for (int i = 0; i < 20; i++) cout << "-"; cout << endl;

    cout << "Must reach the target depth at " << 100 - downPercentage << "%" << endl;
    cout << "Must stop catching at " << upPercentage << "%" << endl;
    for (int i = 0; i < 20; i++) cout << "-"; cout << endl;

    return 0;
};