#include "fifthwindow.h"
#include "ui_fifthwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QRegularExpression>

FifthWindow::FifthWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FifthWindow),
    final(nullptr)
{
    ui->setupUi(this);

    listView = new QListView(this);
    model = new QStringListModel(this);
    listView->setModel(model);

    this->setFixedSize(500, 400);

    listView->setFixedSize(400, 300);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(listView);

    QPushButton *pushButton = new QPushButton("Next", this);

    layout->addWidget(pushButton);

    setLayout(layout);

    loadData();

    connect(pushButton, &QPushButton::clicked, this, &FifthWindow::on_pushButton_clicked);
}


FifthWindow::~FifthWindow()
{
    delete ui;
    delete final;
}

void FifthWindow::loadData()
{
    QFile inmatesFile(":/Text/Text/inmates.txt");
    if (!inmatesFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Failed to open inmates.txt");
        return;
    }
    QTextStream inInmates(&inmatesFile);

    std::vector<Inmate_detail> inmateList;
    int lineNumber = 0;
    while (!inInmates.atEnd()) {
        lineNumber++;
        QString line = inInmates.readLine();

        QRegularExpression regex("^\"?(\\w+),(\\d+),(\\d{1,2}:\\d{2} [AP]M),(\\d{1,2}:\\d{2} [AP]M),(\\d{1,2}:\\d{2} [AP]M),(\\d{1,2}:\\d{2} [AP]M),(\\d{1,2}:\\d{2} [AP]M),(\\d{1,2}:\\d{2} [AP]M),(\\d{1,2}:\\d{2} [AP]M),(\\d+)$");
        QRegularExpressionMatch match = regex.match(line);

        if (match.hasMatch()) {
            Inmate_detail inmate;
            inmate.name = match.captured(1);
            inmate.id = match.captured(2);
            inmate.monday = match.captured(3);
            inmate.tuesday = match.captured(4);
            inmate.wednesday = match.captured(5);
            inmate.thursday = match.captured(6);
            inmate.friday = match.captured(7);
            inmate.saturday = match.captured(8);
            inmate.sunday = match.captured(9);
            inmateList.push_back(inmate);
        } else {
            qDebug() << "Invalid data format in inmates.txt at line" << lineNumber << ": " << line;
        }
    }
    inmatesFile.close();

    // Load data from dorms.txt
    QFile dormsFile(":/Text/Text/dorm.txt");
    if (!dormsFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Failed to open dorms.txt");
        return;
    }
    QTextStream inDorms(&dormsFile);

    std::unordered_map<QString, Dorm_detail> bigRooms;
    while (!inDorms.atEnd()) {
        QString line = inDorms.readLine();
        QStringList parts = line.split(',');
        if (parts.size() == 3) {
            Dorm_detail dorm;
            dorm.name = parts[0];
            dorm.num_music_channels = parts[1].toInt();
            bigRooms[dorm.name] = dorm;
        } else {
            qDebug() << "Invalid data format in dorms.txt";
        }
    }
    dormsFile.close();

    distributeInmatesToDorms(inmateList, bigRooms);
    displayDormitories(bigRooms);
}

void FifthWindow::distributeInmatesToDorms(const std::vector<Inmate_detail>& inmate_list, std::unordered_map<QString, Dorm_detail>& big_rooms)
{
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
            qDebug() << "Insufficient space in the dorm. Need to input new dorms.";
        }
    }
}

void FifthWindow::displayDormitories(const std::unordered_map<QString, Dorm_detail>& big_rooms)
{
    QStringList dormitoriesList;

    for (const auto& pairing_of_rooms : big_rooms) {
        const QString& dormName = pairing_of_rooms.first;
        const Dorm_detail& room = pairing_of_rooms.second;

        QString assignedMembers;
        for (const auto& inmate : room.inmates) {
            assignedMembers += inmate.name + ", ";
        }
        assignedMembers.chop(2);

        dormitoriesList << dormName + " :- " + assignedMembers;
    }

    model->setStringList(dormitoriesList);
}

void FifthWindow::on_pushButton_clicked()
{
    hide();
    final = new FinalWindow(this);
    final->show();
}
