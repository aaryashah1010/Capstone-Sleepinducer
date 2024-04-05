#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <unordered_map>
using namespace std;

class DailySleep {
public:
    int day;
    string sleep_time;
};

class InmateRecord {
public:
    string name;
    int ear_id;
    int minutes;
    vector<DailySleep> daily_sleep;
};

class DormRecord {
public:
    string dorm_name;
    int num_music_channels;
    vector<vector<int>> music_per_channels;
    vector<InmateRecord> inmates;
};

void inputDataFromInmateFile(vector<InmateRecord>& inmatesList, const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Unable to open inmate file" << endl;
        return;
    }

    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;

        InmateRecord inmate;
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

        inmatesList.push_back(inmate);
    }

    fin.close();
}

void displayInmates(const vector<InmateRecord>& inmatesList) {
    for (const auto& inmate : inmatesList) {
        cout << endl << "Name: " << inmate.name << endl;
        cout << "Ear ID: " << inmate.ear_id << endl;
        cout << "Minutes: " << inmate.minutes << endl;
        cout << "Daily Sleep Time:" << endl;
        for (const auto& daily : inmate.daily_sleep) {
            cout << "Day " << daily.day << ": " << daily.sleep_time << endl;
        }
        cout << endl;
    }
}

void inputDataFromDormFile(unordered_map<string, DormRecord>& dormitories, const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Unable to open dorm file" << endl;
        return;
    }

    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;

        DormRecord dorm;
        stringstream ss(line);
        string token;

        getline(ss, dorm.dorm_name, ',');
        getline(ss, token, ',');
        dorm.num_music_channels = stoi(token);
        
        for (int i = 0; i < dorm.num_music_channels; ++i) {
            getline(ss, token, ',');
            stringstream music_ss(token);
            vector<int> per_channel_music;
            while (getline(music_ss, token, ',')) {
                per_channel_music.push_back(stoi(token));
            }
            dorm.music_per_channels.push_back(per_channel_music);
        }

        dormitories[dorm.dorm_name] = dorm;
    }

    fin.close();  
}

void distributeInmatesToDorms(const vector<InmateRecord>& inmatesList, unordered_map<string, DormRecord>& dormitories) {
    int maxInmatesPerDorm = 2;

    for (const auto& inmate : inmatesList) {
        bool assigned = false;
        for (auto& dormPair : dormitories) {
            DormRecord& dorm = dormPair.second;
            if (dorm.inmates.size() < maxInmatesPerDorm) {
                dorm.inmates.push_back(inmate);
                assigned = true;
                break;
            }
        }
        if (!assigned) {
            cout << "Insufficient space in the dorm. Need to input new dorms." << endl;
            break;
        }
    }
}

void displayDormitories(const unordered_map<string, DormRecord>& dormitories) {
    int num = 0;
    int occupiedCount = 0;
    int vacantCount = 0;
    for (const auto& dormPair : dormitories) {
        const string& dormName = dormPair.first;
        const DormRecord& dorm = dormPair.second;

        cout << endl << "Dorm Name: " << dormName << endl;

        cout << "Music channels: ";
        for (int i = 1; i <= dorm.num_music_channels; ++i) {
            cout << i+num << " ";
        }
        num=num+2;
        cout << endl;

        cout << "Music per channels: ";
        for (const auto& music_per_channel : dorm.music_per_channels) {
            for (const auto& music_id : music_per_channel) {
                cout << music_id << " ";
            }
        }
        cout << endl;

        cout << "Assigned Inmates: " << endl;
        if (dorm.inmates.empty()) {
            cout << "No inmates assigned.It is empty" << endl;
            vacantCount++;
        } else {
            for (const auto& inmate : dorm.inmates) {
                cout << "Name: " << inmate.name << endl;
            }
            occupiedCount++;
        }
        cout << endl;
    }
    cout<<"Total Dormitories: "<<occupiedCount+vacantCount<<endl;
    cout << "Occupied Dormitories: " << occupiedCount << endl;
    cout << "Vacant Dormitories: " << vacantCount << endl;
    cout<<endl;
}

void playMusicForInmate(const InmateRecord& inmate, int day) {

    cout << "Activating music channel of earpod id:"<<inmate.ear_id <<" for "<< inmate.name << " at " << inmate.daily_sleep[day - 1].sleep_time << endl;

    stringstream ss(inmate.daily_sleep[day - 1].sleep_time);
    int hour, minute;
    char colon;
    string am_pm;
    ss >> hour >> colon >> minute >> am_pm;

    int start_hour = hour;
    if (am_pm == "PM" && hour != 12) {
        start_hour += 12;
    }

    int end_hour = (start_hour * 60 + minute + inmate.minutes) / 60;
    int end_minute = (start_hour * 60 + minute + inmate.minutes) % 60;

    if (end_hour >= 24) {
        end_hour -= 24;
    }

    cout << "Deactivating music channel of earpod id: "<<inmate.ear_id<<" for "<< inmate.name << " at ";

    if (am_pm == "PM") {
        end_hour += (end_hour == 12) ? 12 : 0;
    } else {
        end_hour %= 12;
    }

    if (end_hour < start_hour) {
        if (am_pm == "AM")
            am_pm = "PM";
        else
            am_pm = "AM";
    }

    int end_hour_12hr = end_hour % 12 == 0 ? 12 : end_hour % 12;
    string end_am_pm = (end_hour < 12 || end_hour == 24) ? "AM" : "PM";

    cout << setw(2) << setfill('0') << end_hour_12hr << ":" << setw(2) << setfill('0') << end_minute << " " << end_am_pm;
    cout << endl;
}

void sleepMusicRoutine(const unordered_map<string, DormRecord>& dormitories) {
    cout<<"Day wise sleeping records for each dorms:- "<<endl<<endl;
    for (const auto& dormPair : dormitories) {
        const DormRecord& dorm = dormPair.second;
        if (dorm.inmates.empty()) {
            cout << dorm.dorm_name <<" is empty"<< endl << endl;
            continue; 
        }
        for (int day = 1; day <= 7; ++day) {
            cout << "Day " << day << " in dormitory: " << dorm.dorm_name << endl;
            
            vector<InmateRecord> sortedInmates = dorm.inmates;
            
            sort(sortedInmates.begin(), sortedInmates.end(), [day](const InmateRecord& a, const InmateRecord& b) {
                stringstream ss_a(a.daily_sleep[day - 1].sleep_time);
                stringstream ss_b(b.daily_sleep[day - 1].sleep_time);
                
                int hour_a, hour_b, minute_a, minute_b;
                char colon_a, colon_b;
                string am_pm_a, am_pm_b;
                
                ss_a >> hour_a >> colon_a >> minute_a >> am_pm_a;
                ss_b >> hour_b >> colon_b >> minute_b >> am_pm_b;
                
                if (am_pm_a != am_pm_b) {
                    return am_pm_a > am_pm_b;
                }
                
                if (hour_a == hour_b) {
                    return minute_a < minute_b;
                }
                return hour_a < hour_b;
            });
            
            for (const auto& inmate : sortedInmates) {
                playMusicForInmate(inmate, day);
            }
            cout << endl;
        }
    }
}

int main() {
    vector<InmateRecord> inmatesList;
    inputDataFromInmateFile(inmatesList, "inmates.txt");

    unordered_map<string, DormRecord> dormitories;
    inputDataFromDormFile(dormitories, "dorm.txt");

    distributeInmatesToDorms(inmatesList, dormitories);

    displayDormitories(dormitories);

    sleepMusicRoutine(dormitories);

    return 0;
}
