#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <sstream>
#include <fstream>
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
    string room_name;
    int num_music_channels;
    vector<vector<int>> music_per_channels;
    vector<Inmate_detail> inmates;
};

void readInmateFile(vector<Inmate_detail>& inmate_list, const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Unable to open inmate file" << endl;
        return;
    }

    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;

        Inmate_detail inmate;
        stringstream rr(line);
        string token;

        getline(rr, inmate.name, ',');
        getline(rr, token, ',');
        inmate.ear_id = stoi(token);

       int w_day=1;
       while(w_day<=7)
       {
          d_sleep daily;
            getline(rr, daily.sleeping_time, ',');
            daily.w_day = w_day;
            inmate.daily_sleep.push_back(daily);
            w_day++;
       }

        getline(rr, token, ',');
        inmate.minutes = stoi(token);

        inmate_list.push_back(inmate);
    }

    fin.close();
    cout << "Total Students: " << inmate_list.size() << endl;
}
void writeInmatefile(vector<Inmate_detail>&inmate_list,const string &file){
        ofstream fout1(file);
        if(!fout1.is_open())
        {
           cout<<"Error to open file"<<endl;
           return;
        }
        for(const auto& per:inmate_list)
        {
            fout1<<per.name<<","<<per.ear_id<<",";
            for(const auto& per1:per.daily_sleep)
            {
                fout1<<per1.sleeping_time<<",";
            }
            fout1<<per.minutes<<endl;
        }
        fout1.close();

}

void displayInmates( vector<Inmate_detail>& inmate_list) {
    cout << "Inmates record" << endl;
    for ( auto& inmate : inmate_list) {
        cout << endl << "Name: " << inmate.name << endl;
        cout << "Ear ID: " << inmate.ear_id << endl;
        cout << "Minutes: " << inmate.minutes << endl;
        cout << "Daily Sleep Time:" << endl;
        auto iterator=begin(inmate.daily_sleep);
          while(iterator!=end(inmate.daily_sleep))
       {
            auto &d1=*iterator;
            cout<<"Day "<<d1.w_day<<": "<<d1.sleeping_time<<endl;
            iterator++;
       }
        cout << endl;
    }
}


void readDormFile(unordered_map<string, Dorm_detail>& big_rooms, const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Unable to open dorm file" << endl;
        return;
    }

    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;

        Dorm_detail room;
        stringstream rr(line);
        string token;

        getline(rr, room.room_name, ',');
        getline(rr, token, ',');
        room.num_music_channels = stoi(token);
        int j=0;
        while(j<room.num_music_channels)
        {
            getline(rr, token, ',');
            stringstream music_rr(token);
            vector<int> per_channel_music;
            while (getline(music_rr, token, ',')) {
                per_channel_music.push_back(stoi(token));
            }
            room.music_per_channels.push_back(per_channel_music);
            j++;
        }
        big_rooms[room.room_name] = room;
    }

    fin.close();
}

void writeDormfiles(const unordered_map<string, Dorm_detail>& big_rooms, const string& filename) {
    ofstream fout(filename);
    if (!fout.is_open()) {
        cout << "Unable to open dorm file for writing" << endl;
        return;
    }

    for (const auto& pairing_of_rooms : big_rooms) {
        const Dorm_detail& room = pairing_of_rooms.second;
        fout << room.room_name << "," << room.num_music_channels << ",";
        for (const auto& music_per_channel : room.music_per_channels) {
            for (const auto& music_id : music_per_channel) {
                fout << music_id << ",";
            }
            fout << ",";
        }
        fout << endl;
    }

    fout.close();
}

void distributeInmatesToDorms(const vector<Inmate_detail>& inmate_list, unordered_map<string, Dorm_detail>& big_rooms) {
    int maximumInmates = 2;

    for (const auto& inmate : inmate_list) {
        bool assigned = false;
        for (auto& pairing_of_rooms : big_rooms) {
            Dorm_detail& room = pairing_of_rooms.second;
            if (room.inmates.size() < maximumInmates) {
                room.inmates.push_back(inmate);
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

void displayDormitories(const unordered_map<string, Dorm_detail>& big_rooms) {
    cout << "Dormitories record" << endl;
    int num = 0;
    int filled_rooms = 0;
    int empty_rooms = 0;
    for (const auto& pairing_of_rooms : big_rooms) {
        const string& dormName = pairing_of_rooms.first;
        const Dorm_detail& room = pairing_of_rooms.second;

        cout << endl << "Dorm Name: " << dormName << endl;

        cout << "Music channels: ";
       
		int i=1;
		while(i<=room.num_music_channels){
			cout<<i+num<<" ";
			i++;
		}
			
        num = num + 2;
        cout << endl;

        cout << "Music per channels: ";
        for (const auto& music_per_channel : room.music_per_channels) {
            for (const auto& music_id : music_per_channel) {
                cout << music_id << " ";
            }
        }
        cout << endl;

        cout << "Assigned Inmates: " << endl;
        if (room.inmates.empty()) {
            cout << "No inmates assigned. It is empty" << endl;
            empty_rooms++;
        } else {
            for (const auto& inmate : room.inmates) {
                cout << "Name: " << inmate.name << endl;
            }
            filled_rooms++;
        }
        cout << endl;
    }
    cout << "Total Dormitories: " << filled_rooms + empty_rooms << endl;
    cout << "Filled Dormitories: " << filled_rooms << endl;
    cout << "Empty Dormitories: " << empty_rooms << endl;
    cout << endl;
}

void music_playing(const Inmate_detail& inmate, int w_day) {
    cout << "Activating music channel of earpod id:\t " << inmate.ear_id << " for " << inmate.name << " at " << inmate.daily_sleep[w_day - 1].sleeping_time << endl;

    stringstream rr(inmate.daily_sleep[w_day - 1].sleeping_time);
    int hour, minute;
    char col;
    string a_p;
    rr >> hour >> col >> minute >> a_p;

    int start_hour = hour;
    if (a_p == "PM" && hour != 12) {
        start_hour += 12;
    }

    int end_h = ((start_hour * 60 )+ minute + inmate.minutes) / 60;
    int end_minute = ((start_hour * 60) + minute + inmate.minutes) % 60;

    if (end_h >= 24) {
        end_h -= 24;
    }

    cout << "Deactivating music channel of earpod id: " << inmate.ear_id << " for " << inmate.name << " at ";

	if(a_p=="PM")
	{
	   if(end_h==12)
	   {
		   end_h=end_h+12;
	   }
	   else{
		   end_h=end_h+0;
	   }
	}

    if (end_h < start_hour) {
        if (a_p == "AM")
            a_p = "PM";
        else
            a_p = "AM";
    }

int end_h_12_hr;
if(end_h%12==0)
{
    end_h_12_hr=12;
}
else{
    end_h_12_hr=end_h%12;
}
 	
    string end_a_p;
if(end_h<12 || end_h==24)
{
    end_a_p="AM";
}
else{
    end_a_p="PM";
}
    cout << setw(2) << setfill('0') <<end_h_12_hr << ":" << setw(2) << setfill('0') << end_minute << " " << end_a_p;
    cout << endl;
}

void sleepMusicRoutine(const unordered_map<string, Dorm_detail>& big_rooms) {
    cout << "Day wise sleeping records for each dorm:- " << endl << endl;
    for (const auto& pairing_of_rooms : big_rooms) {
        const Dorm_detail& room = pairing_of_rooms.second;
        if (room.inmates.empty()) {
            cout << room.room_name << " -Empty" << endl << endl;
            continue;
        }
        int w_day=1;
          while(w_day<=7){
               cout << "Day " << w_day << " In the Dorm: " << room.room_name << endl;

            vector<Inmate_detail> sortedInmates = room.inmates;

            sort(sortedInmates.begin(), sortedInmates.end(), [w_day](const Inmate_detail& a, const Inmate_detail& b) {
                stringstream rr_a(a.daily_sleep[w_day - 1].sleeping_time);
                stringstream rr_b(b.daily_sleep[w_day - 1].sleeping_time);

                int hr_a; 
				int hr_b; 
				int min_a; 
				int min_b;
                char col_a;
				char col_b;
                string mor_noon_a, mor_noon_b;

                rr_a >> hr_a >> col_a >> min_a >> mor_noon_a;
                rr_b >> hr_b >> col_b >> min_b >> mor_noon_b;

                if(mor_noon_a=="PM" && hr_a!=12)
               {
                  hr_a=hr_a + 12;
               }
                if(mor_noon_b=="PM"&& hr_b!=12)
              {
                  hr_b=hr_b + 12;
              }
                if(mor_noon_a=="AM" && hr_a==12)
            {
     hr_a=0;
 }
 if(mor_noon_b=="AM" && hr_b==12)
 {
     hr_b=0;
 }

                if (mor_noon_a != mor_noon_b) {
                    return mor_noon_a > mor_noon_b;
                }

                if (hr_a == hr_b) {
                    return min_a < min_b;
                }
                return hr_a < hr_b;
            });

            for (const auto& inmate : sortedInmates) {
                music_playing(inmate, w_day);
            }
            cout << endl;
            w_day++;
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
            cout << "Do you want to see the Changed time? (yes/no) ";
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
    vector<Inmate_detail> inmate_list;
    readInmateFile(inmate_list, "inmates.txt");
    displayInmates(inmate_list);

    unordered_map<string, Dorm_detail> big_rooms;
    readDormFile(big_rooms, "dorm.txt");

    // Distribute inmates to dorms
    distributeInmatesToDorms(inmate_list, big_rooms);

    // Display dorms
    displayDormitories(big_rooms);

    // Play music routine
    sleepMusicRoutine(big_rooms);

    int n;
    cout << "Enter 1 for updation of the daily schedule of any inmate and 0 if you dont want to update: ";
    cin >> n;
    if (n == 1) {
        while (true) {
            cout << "Please enter the ear id of the student to change the sleeping time: ";
            int earID;
            cin >> earID;
            int check = update(inmate_list, earID);
            if (check == 1) {
                cout << "Do you want to see the updated sleep music time for all inmates (yes/no): ";
                string result;
                cin >> result;
				if (result == "yes")
				{
			    cout << "Here is the data for all the sleeping inmates in each dorm after updation of time" << endl << endl;
                     writeInmatefile(inmate_list, "inmates.txt");
                     writeDormfiles(big_rooms, "dorm.txt");
                     readInmateFile(inmate_list,"inmate.txt");
                     readDormFile(big_rooms,"dorm.txt");
                     distributeInmatesToDorms(inmate_list, big_rooms);
                     sleepMusicRoutine(big_rooms);
                }
				if (result == "Yes")
				{
			    cout << "Here is the data for all the sleeping inmates in each dorm after updation of time" << endl << endl;
                     writeInmatefile(inmate_list, "inmates.txt");
                     writeDormfiles(big_rooms, "dorm.txt");
                     readInmateFile(inmate_list,"inmate.txt");
                     readDormFile(big_rooms,"dorm.txt");
                     distributeInmatesToDorms(inmate_list, big_rooms);
                     sleepMusicRoutine(big_rooms);
                }
					
            			
                 else {
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
    cout << "Thank you." << endl;

    return 0;
}