#ifndef FIFTHWINDOW_H
#define FIFTHWINDOW_H

#include <QDialog>
#include <QListView>
#include <QStringListModel>
#include <vector>
#include <unordered_map>
#include "inmate.h"
#include "dorm.h"
#include "music.h"

namespace Ui {
class FifthWindow;
}

class FifthWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FifthWindow(QWidget *parent = nullptr);
    ~FifthWindow();

private slots:
    void on_pushButton_clicked();

private:
    void loadData();
    void distributeInmatesToDorms(const std::vector<Inmate_detail>& inmate_list, std::unordered_map<QString, Dorm_detail>& big_rooms);
    void displayDormitories(const std::unordered_map<QString, Dorm_detail>& big_rooms);

    Ui::FifthWindow *ui;
    music *next;
    QListView *listView;
    QStringListModel *model;
};

#endif // FIFTHWINDOW_H
