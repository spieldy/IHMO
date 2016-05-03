#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "advert.h"
#include "advert_dialog.h"
#include <iostream>
#include <Qdir>
#include <QList>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <limits>


using namespace std;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    QList<Advert*> advert_tab;
    QList<Advert*> last_advert_tab;
    QList<Advert*> sale_tab;
    QList<Advert*> saled_tab;
    QList<Advert*> rent_tab;
    QList<Advert*> rented_tab;
    QList<Advert*> search_tab;

private slots:
    void on_btn_add_advert_clicked();

    void on_btn_search_clicked();

    void on_le_price_min_textEdited(const QString &arg1);

    void on_le_price_max_textEdited(const QString &arg1);

    void on_le_rooms_min_textEdited(const QString &arg1);

    void on_le_rooms_max_textEdited(const QString &arg1);

    void on_le_size_min_textEdited(const QString &arg1);

    void on_le_size_max_textEdited(const QString &arg1);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_btn_suppress_add_clicked();

private:
    Ui::MainWindow* ui;
    QStandardItemModel* model;
    bool Save();
    bool Charge();
    bool FillAllAdvert(QList<Advert*> tab);
    bool CheckLE();
    bool isLEValide(QLineEdit *le);
    void UpdateTab();
    int current_id = 0;

};

#endif // MAINWINDOW_H
