#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
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
    string dorm_name;
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

        inmatesList.push_back(inmate);
    }

    fin.close();
    cout << "Total inmates: " << inmatesList.size() << endl;
}

void playMusicForInmate(const Inmate& inmate, int day) {
    cout << "Day " << day << ", ";
    cout << "Starting music for inmate: " << inmate.name << " at " << inmate.daily_sleep[day - 1].sleep_time << endl;
    
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

    cout << "Day " << day << ", ";
    cout << "Stopping music for inmate: " << inmate.name << " at ";
    
    // Adjust end time to match the same period (AM/PM) as start time
    if (am_pm == "PM") {
        end_hour += (end_hour == 12) ? 12 : 0;
    } else {
        end_hour += (end_hour == 12) ? 0 : 12;
    }
    
    int end_hour_12hr = end_hour % 12 == 0 ? 12 : end_hour % 12;
    string end_am_pm = (end_hour < 12 || end_hour == 24) ? "AM" : "PM";
    
    cout << setw(2) << setfill('0') << end_hour_12hr << ":" << setw(2) << setfill('0') << end_minute << " " << end_am_pm;
    cout << endl;
}

void sleepMusicRoutine(const vector<vector<Inmate>>& dormitories) {
    for (const auto& dorm : dormitories) {
        for (int day = 1; day <= 7; ++day) {
            cout << "Day " << day << " in dormitory: " << dorm[0].dorm_name << endl;
            
            vector<Inmate> sortedInmates = dorm;
            
            sort(sortedInmates.begin(), sortedInmates.end(), [day](const Inmate& a, const Inmate& b) {
                stringstream ss_a(a.daily_sleep[day - 1].sleep_time);
                stringstream ss_b(b.daily_sleep[day - 1].sleep_time);
                
                int hour_a, hour_b, minute_a, minute_b;
                char colon_a, colon_b;
                string am_pm_a, am_pm_b;
                
                ss_a >> hour_a >> colon_a >> minute_a >> am_pm_a;
                ss_b >> hour_b >> colon_b >> minute_b >> am_pm_b;
                
                // Convert to 24-hour format for comparison
                if (am_pm_a == "PM" && hour_a != 12) hour_a += 12;
                if (am_pm_b == "PM" && hour_b != 12) hour_b += 12;
                if (am_pm_a == "AM" && hour_a == 12) hour_a = 0;
                if (am_pm_b == "AM" && hour_b == 12) hour_b = 0;
                
                // Prioritize PM sleep times
                if (am_pm_a != am_pm_b) {
                    return am_pm_a > am_pm_b;
                }
                
                // Compare times
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
    vector<Inmate> inmatesList;

    inputDataFromFile(inmatesList, "cap3.txt");

    for (const auto& inmate : inmatesList) {
        displayInmates(inmate);
    }

    vector<vector<Inmate>> dormitories;
    for (const auto& inmate : inmatesList) {
        bool found = false;
        for (auto& dorm : dormitories) {
            if (dorm[0].dorm_name == inmate.dorm_name) {
                dorm.push_back(inmate);
                found = true;
                break;
            }
        }
        if (!found) {
            dormitories.push_back({inmate});
        }
    }
 
    sleepMusicRoutine(dormitories);
    
    return 0;
}
