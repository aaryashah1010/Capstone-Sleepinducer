#include "dormrecord.h"
#include <sstream>

// Constructors
DormRecord::DormRecord() : numberOfChannels(0), numberOfSongs(0) {}

DormRecord::DormRecord(const std::string& name, int channels, int songs)
    : dormName(name), numberOfChannels(channels), numberOfSongs(songs) {}

// Accessors
std::string DormRecord::getDormName() const {
    return dormName;
}

int DormRecord::getNumberOfChannels() const {
    return numberOfChannels;
}

int DormRecord::getNumberOfSongs() const {
    return numberOfSongs;
}

// Mutators
void DormRecord::setDormName(const std::string& name) {
    dormName = name;
}

void DormRecord::setNumberOfChannels(int channels) {
    numberOfChannels = channels;
}

void DormRecord::setNumberOfSongs(int songs) {
    numberOfSongs = songs;
}

// Method to parse string and set values
void DormRecord::parseAndSet(const std::string& data) {
    std::istringstream iss(data);
    char comma;
    iss >> dormName >> comma >> numberOfChannels >> comma >> numberOfSongs;
}
