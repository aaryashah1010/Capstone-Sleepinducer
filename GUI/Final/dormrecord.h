#ifndef DORMRECORD_H
#define DORMRECORD_H

#include <string>

class DormRecord {
private:
    std::string dormName;
    int numberOfChannels;
    int numberOfSongs;

public:
    // Constructors
    DormRecord();
    DormRecord(const std::string& name, int channels, int songs);

    // Accessors
    std::string getDormName() const;
    int getNumberOfChannels() const;
    int getNumberOfSongs() const;

    // Mutators
    void setDormName(const std::string& name);
    void setNumberOfChannels(int channels);
    void setNumberOfSongs(int songs);

    // Method to parse string and set values
    void parseAndSet(const std::string& data);
};

#endif // DORMRECORD_H
