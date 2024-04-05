#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class ThirdWindow;
}

class ThirdWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ThirdWindow(QWidget *parent = nullptr);
    ~ThirdWindow();

private:
    Ui::ThirdWindow *ui;
    QStandardItemModel *m_model;
    void loadDataFromFile(const QString& fileName);
};

#endif // THIRDWINDOW_H
