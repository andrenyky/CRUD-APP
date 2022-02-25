//
// Created by andre on 5/12/2021.
//

#ifndef A45_ANDRENYKY_QTWINDOW_H
#define A45_ANDRENYKY_QTWINDOW_H
#include <QWidget>
#include <QListWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QMessageBox>
#include <QTextEdit>
#include <QRadioButton>
#include <QTableWidget>
#include "repoEvent.h"
#include "validators.h"
#include "eventList.h"
#include "TableModel.h"
#include "Action.h"
#include "ServiceVect.h"
class QtWindow : public QWidget {
private:
    RepoEvent repoEvent;
    vector<Action*> ve;
    Validator validator;
    ServiceVect* srv;
public:
    QtWindow(QWidget *parent = Q_NULLPTR);
    ~QtWindow();
    int option = -1;
    EventList eventList;
    std::unique_ptr<EventList> eventList_csv = nullptr;
    std::unique_ptr<EventList> eventList_html = nullptr;
private:

    QPushButton* admin = new QPushButton{"ADMIN"};
    QPushButton* user = new QPushButton{"USER"};
    QPushButton* exit = new QPushButton{ "EXIT" };
    QPushButton* e_add = new QPushButton{ "ADD EVENT" };
    QPushButton* e_delete = new QPushButton{ "DELETE EVENT" };
    QPushButton* e_update = new QPushButton{ "UPDATE EVENT" };
    QPushButton* e_show = new QPushButton{ "SHOW EVENTS" };
    QPushButton *undobutton = new QPushButton{"UNDO"};
    QPushButton *redobutton = new QPushButton{"REDO"};
    QPushButton* e_exit = new QPushButton{ "EXIT" };

    QLabel* e_position = new QLabel{ "Position: " };
    QLineEdit* le_position = new QLineEdit{};
    QLabel* e_title = new QLabel{ "Title: " };
    QLineEdit* le_title = new QLineEdit{};
    QLabel* e_description = new QLabel{ "Description: " };
    QLineEdit* le_description = new QLineEdit{};
    QLabel* e_datetime = new QLabel{ "Date: " };
    QLineEdit* le_datetime = new QLineEdit{};
    QLabel* e_nrPeople = new QLabel{ "Number of People: " };
    QLineEdit* le_nrPeople = new QLineEdit{};
    QLabel* e_link = new QLabel{ "Link: " };
    QLineEdit* le_link = new QLineEdit{};

    QPushButton* addUpdate_add = new QPushButton{"ADD"};
    QPushButton* addUpdate_update= new QPushButton{"UPDATE"};
    QPushButton* addUpdate_exit = new QPushButton{"BACK"};


    QPushButton* filter;
    QListWidget* filtered_list;
    QFormLayout* filter_form;
    QGroupBox* filter_group;


    QListWidget* ev_list;
    QTableWidget* user_table;
    QLineEdit* position;
    QLineEdit* monthEdit = new QLineEdit{};
    QLineEdit* removeEdit = new QLineEdit{};
    QPushButton* adminShow_exit = new QPushButton{"BACK"};
    QVBoxLayout* vLayout;
    QPushButton* deleteBtn = new QPushButton{"DELETE"};
    QPushButton* user_html = new QPushButton{ "SAVE AS HTML" };
    QPushButton* user_csv = new QPushButton{ "SAVE AS CSV" };
    QPushButton* user_add= new QPushButton{"ADD EVENT"};
    QPushButton* user_see_events = new QPushButton{ "SEE THE EVENTS YOU'RE INTERESTED IN" };
    QPushButton* user_remove_event = new QPushButton{ "REMOVE EVENT" };
    QPushButton* user_exit = new QPushButton{ "Exit" };
    QVBoxLayout* main_layout = new QVBoxLayout;
    QTableView *ev_interested;
    void populate_events();
    void initWidgets();
    void showList();
    void addMenu();
    void initSignals();
    void mainMenu();
    void hideMainMenu();
    void adminMenu();
    void hideAdminMenu();
    void userMenu();
    void addEvent();
    void updateEvent();
    void hideUserMenu();
    void userMenuOptions();
    void hideUserMenuOptions();
    void hideAddMenu();
    void updateMenu();
    void hideUpdateMenu();
    void hideRemoveMenu();
    void removeMenu();
    void removeEvent();
    void populate_user_list();
    void user_add_event();
    void openEventsFile();
    void populate_filteredList();
    void user_remove();


};

#endif //A45_ANDRENYKY_QTWINDOW_H
