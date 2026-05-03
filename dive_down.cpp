#include <bits/stdc++.h>
using namespace std;

#include <conio.h>

struct weightDetails { string name; float value; };
vector<weightDetails> weights = {
    {"Brick", 6.44}, {"Dumbbell", 8.4}, {"Plate", 10.64},
    {"Barbell", 13.72}, {"Anvil", 17.36}, {"Anchor", 21.84},
    {"Boulder", 26.88}, {"Torpedo", 33.04}, {"Trident", 37.8},
    {"Thick Log", 42.0}, {"Heavy Shell", 44.8}, {"Pipe", 49.0},
    {"Kraken Eye", 53.76}, {"Megalodon Anchor", 58.8}, {"Ice Cube", 64.4},
    {"Jellyfish Core", 70.0}, {"Steampunk Relic", 82.6}, {"Tombstone", 89.6},
    {"Prehistoric Amber", 96.6}
};

struct oxygenDetails { string name; float value; };
vector<oxygenDetails> oxygens = {
    {"Starter Oxygen Tank", 19}, {"Double Oxygen Tank", 24}, {"Aqua Oxygen Tank", 29},
    {"Coral Oxygen Tank", 35}, {"Seaweed Oxygen Tank", 42}, {"Ore Oxygen Tank", 49},
    {"Beach Oxygen Tank", 58}, {"Golden Oxygen Tank", 67}, {"Candy Oxygen Tank", 77},
    {"Trench Oxygen Tank", 81}, {"Atlantis Oxygen Tank", 87}, {"Forest Oxygen Tank", 93},
    {"Shell Oxygen Tank", 100}, {"Sewer Oxygen Tank", 118}, {"Kraken Oxygen Tank", 134},
    {"Megalodon Oxygen Tank", 149}, {"Ice Oxygen Tank", 160}, {"Jellyfish Oxygen Tank", 172},
    {"Steampunk Oxygen Tank", 202}, {"Graveyard Oxygen Tank", 221}, {"Dinosaur Oxygen Tank", 240}
};

struct finDetails { string name; float value; };
vector<finDetails> fins = {
    {"Starter Fins", 6.72}, {"Aqua Fins", 8.12}, {"Coral Fins", 9.8},
    {"Seaweed Fins", 11.76}, {"Ore Fins", 14.28}, {"Beach Fins", 17.36},
    {"Golden Fins", 20.44}, {"Candy Fins", 23.24}, {"Trench Fins", 26.32},
    {"Atlantis Fins", 29.4}, {"Forest Fins", 31.92}, {"Shell Fins", 34.44},
    {"Sewer Fins", 36.96}, {"Kraken Fins", 39.48}, {"Megalodon Fins", 42},
    {"Ice Fins", 45.36}, {"Jellyfish Fins", 48.44}, {"Steampunk Fins", 56.56},
    {"Graveyard Fins", 61.32}, {"Dinosaur Fins", 66.64}
};

struct zoneDetails { string name; float value; };
vector<zoneDetails> zones = {
    {"Sunlight Zone", 48}, {"Coral Reef", 112}, {"Twilight Zone", 200},
    {"Deep Ocean", 310}, {"The Deep Dark", 580}, {"The Trenches", 700},
    {"Atlantis", 760}, {"Aqua Forest", 860}, {"Shell Reef", 960},
    {"Kraken World", 1080}, {"Megalodon Lair", 1200}, {"Ice Area", 1300},
    {"Jelly Field", 1440}, {"Steampunk Zone", 1580}, {"Dead Waters", 1700},
    {"Pre-Historic", 1830}
};

template <typename T>
int selectMenu(string title, const vector<T>& items) {
    int selected = 0;
    int n = items.size();

    while (true) {
        system("cls");
        cout << "==== " << title << " ====" << endl;
        cout << "[Arrow Up/Down to Navigate, Enter to Select]" << endl;
        for (int i = 0; i < 30; i++) cout << "-"; cout << endl;

        for (int i = 0; i < n; i++) {
            if (i == selected) {
                cout << " > " << items[i].name << " < " << endl;
            } else {
                cout << "   " << items[i].name << endl;
            }
        }
        for (int i = 0; i < 30; i++) cout << "-"; cout << endl;

        int key = _getch();
        if (key == 224) {
            key = _getch();
            if (key == 72) selected = (selected - 1 + n) % n;
            if (key == 80) selected = (selected + 1) % n;
        } else if (key == 13) {
            return selected;
        }
    }
}

int main() {
    int curr_weight = selectMenu("SELECT CURRENT WEIGHT", weights);
    int curr_oxygen = selectMenu("SELECT OXYGEN TANK", oxygens);
    int curr_fin    = selectMenu("SELECT CURRENT FIN", fins);
    int target_zone = selectMenu("SELECT TARGET ZONE", zones);

    float target_depth = zones[target_zone].value;
    float weightVal    = weights[curr_weight].value;
    float oxygenVal    = oxygens[curr_oxygen].value;
    float finVal       = fins[curr_fin].value;

    float downTime       = target_depth / weightVal;
    float downPercentage = downTime / (oxygenVal / 100);
    float upTime         = target_depth / finVal;
    float upPercentage   = upTime / (oxygenVal / 100);
    float catchTime      = oxygenVal - (downTime + upTime);
    float catchPercentage = catchTime / (oxygenVal / 100);

    system("cls");
    cout << "========= SUMMARY =========" << endl;
    cout << "Weight : " << weights[curr_weight].name << endl;
    cout << "Oxygen : " << oxygens[curr_oxygen].name << endl;
    cout << "Fin    : " << fins[curr_fin].name << endl;
    cout << "Target : " << zones[target_zone].name << " (" << target_depth << "m)" << endl;
    for (int i = 0; i < 27; i++) cout << "-"; cout << endl;

    cout << "Go down for      : " << downTime << "s (" << downPercentage << "%)" << endl;
    cout << "Catching for     : " << catchTime << "s (" << catchPercentage << "%)" << endl;
    cout << "Go up for        : " << upTime << "s (" << upPercentage << "%)" << endl;
    for (int i = 0; i < 27; i++) cout << "-"; cout << endl;

    cout << "Must reach target at   : " << 100 - downPercentage << "%" << endl;
    cout << "Must stop catching at  : " << upPercentage << "%" << endl;
    for (int i = 0; i < 27; i++) cout << "-"; cout << endl;

    cout << "\nPress any key to exit...";
    _getch();

    return 0;
};
