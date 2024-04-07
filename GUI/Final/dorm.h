#ifndef DORM_H
#define DORM_H

#include <QString>
#include <vector>

struct Dorm_detail {
    QString name;
    int num_music_channels;
    int property;
    std::vector<Inmate_detail> inmates;
};

#endif // DORM_H
