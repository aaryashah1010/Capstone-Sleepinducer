#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class DailySleep {
public:
    vector<string> sleep_times;
};

class MusicPer_channels {
public:
    vector<string> music_id;
};

class Inmate {
public:
    string name;
    string ear_id;
    string minutes;
    DailySleep daily_sleep;
};

class Dorm {
public:
    string dorm_name;
    string music_channels;
    MusicPer_channels music_per_channel;
};

vector<Inmate> readCSV(const string& filename) {
    vector<Inmate> inmates;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return inmates;
    }

    string line;
    // Skip the header line
    getline(file, line);

    while (getline(file, line)) {
        Inmate inmate;
        stringstream ss(line);
        string token;

        // Read data fields separated by commas
        getline(ss, inmate.name, ',');
        getline(ss, inmate.ear_id, ',');
        getline(ss, inmate.minutes, ',');
        getline(ss, token); // Read Daily Sleep Times

        // Remove double quotes from token
        token.erase(remove(token.begin(), token.end(), '\"'), token.end());

        // Parse daily sleep times separated by commas
        stringstream sleep_ss(token);
        string sleep_time;
        while (getline(sleep_ss, sleep_time, ',')) {
            inmate.daily_sleep.sleep_times.push_back(sleep_time);
        }

        inmates.push_back(inmate);
    }

    file.close();
    return inmates;
}

vector<Dorm> readCsv1(const string& filename) {
    vector<Dorm> dormitories;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return dormitories;
    }

    string line;
    // Skip the header line
    getline(file, line);

    while (getline(file, line)) {
        Dorm dorm;
        stringstream ss(line);

        // Read data fields separated by tabs
        getline(ss, dorm.dorm_name, '\t');
        getline(ss, dorm.music_channels, '\t');

        string tokens;
        getline(ss, tokens, '\t');

        tokens.erase(remove(tokens.begin(), tokens.end(), '\"'), tokens.end());
        stringstream music_ss(tokens);
        string music;
        while (getline(music_ss, music, ',')) {
            dorm.music_per_channel.music_id.push_back(music);
        }

        dormitories.push_back(dorm);
    }

    file.close();
    return dormitories;
}

void displayInmates(const vector<Inmate>& inmates) {
    cout << "Inmates Information:" << endl;
    for (const auto& inmate : inmates) {
        if (inmate.name.empty()) {
            continue; // Skip printing if the name is empty
        }

        cout << "Name: " << inmate.name << endl;
        cout << "Ear ID: " << inmate.ear_id << endl;
        cout << "Minutes: " << inmate.minutes << endl;
        cout << "Daily Sleep Times:" << endl;
        for (size_t i = 0; i < inmate.daily_sleep.sleep_times.size(); ++i) {
            cout << "Day " << (i + 1) << ": " << inmate.daily_sleep.sleep_times[i] << endl;
        }
        cout << endl;
    }
}

void displayDorms(const vector<Dorm>& dormitories) {
    cout << "Dormitories Information:" << endl;
    for (const auto& dorm : dormitories) {
        if (dorm.dorm_name.empty()) {
            continue;
        }
        cout << "Dorm name: " << dorm.dorm_name << endl;
        cout << "Music channels: " << dorm.music_channels << endl;
        cout << "Music per channels:" << endl;
        if (!dorm.music_per_channel.music_id.empty()) {
            for (const auto& music : dorm.music_per_channel.music_id) {
                cout << music << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    vector<Inmate> inmates = readCSV("inmates1.csv");
    vector<Dorm> dormitories = readCsv1("dorm.csv");

    displayInmates(inmates);
    displayDorms(dormitories);

    return 0;
}
