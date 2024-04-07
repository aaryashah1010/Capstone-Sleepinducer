#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <unordered_map>
using namespace std;

class d_sleep {
public:
    int w_day;
    string sleeping_time;
};

class Inmate_detail{
public:
    string name;
    int ear_id;
    int minutes;
    vector<d_sleep> daily_sleep;
};

class Dorm_detail{
public:
    string dorm_name;
    int num_music_channels;
    vector<vector<int>> music_per_channels;
    vector<Inmate_detail> inmates;
};

void readInmateFile(vector<Inmate_detail>& inmatesList, const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Unable to open inmate file" << endl;
        return;
    }

    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;

        Inmate_detail inmate;
        stringstream ss(line);
        string token;

        getline(ss, inmate.name, ',');
        getline(ss, token, ',');
        inmate.ear_id = stoi(token);

        for (int w_day = 1; w_day <= 7; ++w_day) {
            d_sleep daily;
            getline(ss, daily.sleeping_time, ',');
            daily.w_day = w_day;
            inmate.daily_sleep.push_back(daily);
        }

        getline(ss, token, ',');
        inmate.minutes = stoi(token);

        inmatesList.push_back(inmate);
    }

    fin.close();
    cout << "Total inmates: " << inmatesList.size() << endl;
}

void displayInmates( vector<Inmate_detail>& inmatesList) {
    cout << "Inmates record" << endl;
    for ( auto& inmate : inmatesList) {
        cout << endl << "Name: " << inmate.name << endl;
        cout << "Ear ID: " << inmate.ear_id << endl;
        cout << "Minutes: " << inmate.minutes << endl;
        cout << "Daily Sleep Time:" << endl;
        for ( auto& daily : inmate.daily_sleep) {
            cout << "Day " << daily.w_day << ": " << daily.sleeping_time << endl;
        }
        cout << endl;
    }
}


void readDormFile(unordered_map<string, Dorm_detail>& dormitories, const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Unable to open dorm file" << endl;
        return;
    }

    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;

        Dorm_detail dorm;
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

void writeDormfiles(const unordered_map<string, Dorm_detail>& dormitories, const string& filename) {
    ofstream fout(filename);
    if (!fout.is_open()) {
        cout << "Unable to open dorm file for writing" << endl;
        return;
    }

    for (const auto& dormPair : dormitories) {
        const Dorm_detail& dorm = dormPair.second;
        fout << dorm.dorm_name << "," << dorm.num_music_channels << ",";
        for (const auto& music_per_channel : dorm.music_per_channels) {
            for (const auto& music_id : music_per_channel) {
                fout << music_id << ",";
            }
            fout << ",";
        }
        fout << endl;
    }

    fout.close();
}

void distributeInmatesToDorms(const vector<Inmate_detail>& inmatesList, unordered_map<string, Dorm_detail>& dormitories) {
    int maximumInmates = 2;

    for (const auto& inmate : inmatesList) {
        bool assigned = false;
        for (auto& dormPair : dormitories) {
            Dorm_detail& dorm = dormPair.second;
            if (dorm.inmates.size() < maximumInmates) {
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

void displayDormitories(const unordered_map<string, Dorm_detail>& dormitories) {
    cout << "Dormitories record" << endl;
    int num = 0;
    int occupiedCount = 0;
    int vacantCount = 0;
    for (const auto& dormPair : dormitories) {
        const string& dormName = dormPair.first;
        const Dorm_detail& dorm = dormPair.second;

        cout << endl << "Dorm Name: " << dormName << endl;

        cout << "Music channels: ";
        for (int i = 1; i <= dorm.num_music_channels; ++i) {
            cout << i + num << " ";
        }
        num = num + 2;
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
            cout << "No inmates assigned. It is empty" << endl;
            vacantCount++;
        } else {
            for (const auto& inmate : dorm.inmates) {
                cout << "Name: " << inmate.name << endl;
            }
            occupiedCount++;
        }
        cout << endl;
    }
    cout << "Total Dormitories: " << occupiedCount + vacantCount << endl;
    cout << "Occupied Dormitories: " << occupiedCount << endl;
    cout << "Vacant Dormitories: " << vacantCount << endl;
    cout << endl;
}

void music_playing(const Inmate_detail& inmate, int w_day) {
    cout << "Activating music channel of earpod id:" << inmate.ear_id << " for " << inmate.name << " at " << inmate.daily_sleep[w_day - 1].sleeping_time << endl;

    stringstream ss(inmate.daily_sleep[w_day - 1].sleeping_time);
    int hour, minute;
    char colon;
    string a_p;
    ss >> hour >> colon >> minute >> a_p;

    int start_hour = hour;
    if (a_p == "PM" && hour != 12) {
        start_hour += 12;
    }

    int end_hour = (start_hour * 60 + minute + inmate.minutes) / 60;
    int end_minute = (start_hour * 60 + minute + inmate.minutes) % 60;

    if (end_hour >= 24) {
        end_hour -= 24;
    }

    cout << "Deactivating music channel of earpod id: " << inmate.ear_id << " for " << inmate.name << " at ";

    if (a_p == "PM") {
        end_hour += (end_hour == 12) ? 12 : 0;
    } else {
        end_hour %= 12;
    }

    if (end_hour < start_hour) {
        if (a_p == "AM")
            a_p = "PM";
        else
            a_p = "AM";
    }

    int end_hour_12hrformat = end_hour % 12 == 0 ? 12 : end_hour % 12;
    string end_am_pm = (end_hour < 12 || end_hour == 24) ? "AM" : "PM";

    cout << setw(2) << setfill('0') <<end_hour_12hrformat << ":" << setw(2) << setfill('0') << end_minute << " " << end_am_pm;
    cout << endl;
}

void sleepMusicRoutine(const unordered_map<string, Dorm_detail>& dormitories) {
    cout << "Day wise sleeping records for each dorms:- " << endl << endl;
    for (const auto& dormPair : dormitories) {
        const Dorm_detail& dorm = dormPair.second;
        if (dorm.inmates.empty()) {
            cout << dorm.dorm_name << " is empty" << endl << endl;
            continue;
        }
        for (int w_day = 1; w_day <= 7; ++w_day) {
            cout << "Day " << w_day << " in dormitory: " << dorm.dorm_name << endl;

            vector<Inmate_detail> sortedInmates = dorm.inmates;

            sort(sortedInmates.begin(), sortedInmates.end(), [w_day](const Inmate_detail& a, const Inmate_detail& b) {
                stringstream ss_a(a.daily_sleep[w_day - 1].sleeping_time);
                stringstream ss_b(b.daily_sleep[w_day - 1].sleeping_time);

                int hour_a, hour_b, minute_a, minute_b;
                char colon_a, colon_b;
                string am_pm_a, am_pm_b;

                ss_a >> hour_a >> colon_a >> minute_a >> am_pm_a;
                ss_b >> hour_b >> colon_b >> minute_b >> am_pm_b;

                if (am_pm_a == "PM" && hour_a != 12) hour_a += 12;
                if (am_pm_b == "PM" && hour_b != 12) hour_b += 12;
                if (am_pm_a == "AM" && hour_a == 12) hour_a = 0;
                if (am_pm_b == "AM" && hour_b == 12) hour_b = 0;

                if (am_pm_a != am_pm_b) {
                    return am_pm_a > am_pm_b;
                }

                if (hour_a == hour_b) {
                    return minute_a < minute_b;
                }
                return hour_a < hour_b;
            });

            for (const auto& inmate : sortedInmates) {
                music_playing(inmate, w_day);
            }
            cout << endl;
        }
    }
}

int update(vector<Inmate_detail>& inmateList, int earId) {
    bool validEarId = false;
    for (auto& inmate : inmateList) {
        if (inmate.ear_id == earId) {
            validEarId = true;
            while (true) {
                cout << "Enter the day you want to change: ";
                int dayToUpdate;
                cin >> dayToUpdate;
                if (dayToUpdate < 1 || dayToUpdate > 7) {
                    cout << "Invalid day. Day should be between 1 and 7." << endl;
                    continue;
                }

                cout << "Enter the new sleep time for day " << dayToUpdate << ": ";
                string newSleepTime;
                cin.ignore(); 
                getline(cin, newSleepTime);

                inmate.daily_sleep[dayToUpdate - 1].sleeping_time = newSleepTime;
                cout << "New sleep time updated successfully." << endl;

                cout << "Do you want to update the sleep time for another day? (yes/no): ";
                string ans;
                cin >> ans;
                if (ans != "yes" && ans != "YES") {
                    break;
                }
            }
            cout << "Do you want to see the updated display time? (yes/no): ";
            string ans;
            cin >> ans;
            if (ans == "yes" || ans == "YES") {
                displayInmates(inmateList);
            }
            return 1;
        }
    }
    if (!validEarId) {
        cout << "Please enter a valid ear id." << endl;
    }
    return 0;
}

int main() {
    vector<Inmate_detail> inmatesList;
    readInmateFile(inmatesList, "inmates.txt");
    displayInmates(inmatesList);

    unordered_map<string, Dorm_detail> dormitories;
    readDormFile(dormitories, "dorm.txt");

    // Distribute inmates to dormitories
    distributeInmatesToDorms(inmatesList, dormitories);

    // Display dormitories
    displayDormitories(dormitories);

    // Play music routine
    sleepMusicRoutine(dormitories);

    int n;
    cout << "Enter 1 for updation of the daily schedule of any inmate and 0 if you dont want to update: ";
    cin >> n;
    if (n == 1) {
        while (true) {
            cout << "Please enter the ear id of the student to change the sleeping time: ";
            int earID;
            cin >> earID;
            int check = update(inmatesList, earID);
            if (check == 1) {
                cout << "Do you want to find the sleepMusicRoutine after updation (yes/no): ";
                string result;
                cin >> result;
                if (result == "yes" || result == "Yes") {
                    cout << "Here is the data for all the sleeping inmates in each dorm after updation of time" << endl << endl;
                    sleepMusicRoutine(dormitories);
                } else {
                    cout << "Do you want to change any other inmate data? (yes/no): ";
                    string result1;
                    cin >> result1;
                    if (result1 == "yes" || result1 == "YES") {
                        continue;
                    } else {
                        break;
                    }
                }
            }
        }
    }

    cout << "Updating files..." << endl;

    // Write updated data back to files
   // writeInmatesfile(inmatesList, "inmates.txt");
    writeDormfiles(dormitories, "dorm.txt");
    cout << "Files updated successfully." << endl;
   //   sleepMusicRoutine(dormitories);
    cout << "Thank you." << endl;

    return 0;
}