#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <unordered_map>
#include <algorithm>
using namespace std;

class DailySleep {
public:
    int day;
    string sleep_time;
};

class Inmate {
public:
    string name;
    int ear_id;
    int minutes;
    vector<DailySleep> daily_sleep;
    int members;
    string dorm_name;
    vector<int> music_channels;
    vector<string> music_per_channel;
    bool asleep;
};

void displayInmates(const Inmate& inmate) {
    cout << endl;
    cout << "Name: " << inmate.name << endl;
    cout << "Ear ID: " << inmate.ear_id << endl;
    cout << "Minutes: " << inmate.minutes << endl;
    cout << "Daily Sleep Time:" << endl;
    for (const auto& daily : inmate.daily_sleep) {
        cout << "Day " << daily.day << ": " << daily.sleep_time << endl;
    }
    cout << "Dormitory: " << inmate.dorm_name << endl;
    cout << "Music Channels: ";
    for (const auto& channel : inmate.music_channels) {
        cout << channel << " ";
    }
    cout << endl;
    cout << "Music Per Channel: ";
    for (const auto& music : inmate.music_per_channel) {
        cout << music << " ";
    }
    cout << endl;
}

void inputDataFromFile(vector<Inmate>& inmatesList, const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Unable to open file" << endl;
        return;
    }

    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;

        Inmate inmate;
        stringstream ss(line);
        string token;

        getline(ss, inmate.name, ',');
        getline(ss, token, ',');
        inmate.ear_id = stoi(token);

        for (int day = 1; day <= 7; ++day) {
            DailySleep daily;
            getline(ss, daily.sleep_time, ',');
            daily.day = day;
            inmate.daily_sleep.push_back(daily);
        }

        getline(ss, token, ',');
        inmate.minutes = stoi(token);

        getline(ss, inmate.dorm_name, ',');

        while (getline(ss, token, ',')) {
            int channel = stoi(token);
            inmate.music_channels.push_back(channel);

            getline(ss, token, ',');
            inmate.music_per_channel.push_back(token);
        }

        inmate.asleep = false;
        inmatesList.push_back(inmate);
    }

    fin.close();
    cout << "Total inmates: " << inmatesList.size() << endl;
}

void assignDorm(vector<Inmate>& inmatesList, unordered_map<string, vector<Inmate>>& dormitories) {
    for (const auto& inmate : inmatesList) {
        dormitories[inmate.dorm_name].push_back(inmate);
    }

    for (auto& dorm : dormitories) {
        sort(dorm.second.begin(), dorm.second.end(), [](const Inmate& a, const Inmate& b) {
            return a.minutes < b.minutes;
        });
    }

    for (auto& dorm : dormitories) {
        cout << "Dormitory: " << dorm.first << endl;
        for (auto& inmate : dorm.second) {
            cout << "Assigned inmate " << inmate.name << " with fall-asleep time " << inmate.minutes << endl;
        }
        cout << endl;
    }
}

void activateChannels(vector<Inmate>& inmates, int max_sleep_time) {
    for (auto& inmate : inmates) {
        if (!inmate.asleep) {
            cout << "Activating music channel for inmate " << inmate.name << " in dorm " << inmate.dorm_name << endl;
        }
    }

    cout << "Music playing in dorm " << inmates[0].dorm_name << " for " << max_sleep_time << " minutes" << endl;

    for (auto& inmate : inmates) {
        if (inmate.asleep) {
            cout << "Deactivating music channel for inmate " << inmate.name << " in dorm " << inmate.dorm_name << endl;
            cout << "Activating music channel for inmate " << inmate.name << " in dorm " << inmate.dorm_name << " after "<<inmate.minutes<<" minutes"<<endl;
        }
    }
}

void simulateSleep(vector<Inmate>& inmatesList, const string& dorm_name) {
    vector<Inmate>& dorm = inmatesList;
    int max_sleep_time = 0;

    for (auto& inmate : dorm) {
        inmate.asleep = true;
        if (inmate.minutes > max_sleep_time) {
            max_sleep_time = inmate.minutes;
        }
    }

    for (auto& inmate : dorm) {
        if (inmate.asleep) {
            cout << "Deactivating music channel for inmate " << inmate.name << " in dorm " << inmate.dorm_name << endl;
        }
    }

    activateChannels(dorm, max_sleep_time);
}

int main() {
    vector<Inmate> inmatesList;
    unordered_map<string, vector<Inmate>> dormitories;

    inputDataFromFile(inmatesList, "cap3.txt");

    for (const auto& inmate : inmatesList) {
        displayInmates(inmate);
    }

    assignDorm(inmatesList, dormitories);

    for (auto& dorm : dormitories) {
        simulateSleep(dorm.second, dorm.first);
    }

    return 0;
}
