#include <QApplication>
#include "QtWindow.h"
#include "exceptions.h"
#include "DerivedActions.h"

QtWindow::QtWindow(QWidget *parent) : QWidget(parent) {
    this->repoEvent.read_file();
    this->initWidgets();
    this->initSignals();
    this->populate_events();
    this->eventList_csv = std::make_unique<CsvEventList>();
    this->eventList_html = std::make_unique<HtmlEventList>();

}
QtWindow::~QtWindow() {
}

void QtWindow::initWidgets() {

//    Action* act = new AddAct();
//    ve.push_back(act);

    Event e=Event("tare","Frate","20/03/2004",50,"abcd");





    QHBoxLayout* window_layout = new QHBoxLayout;
    window_layout->maximumSize();
    setLayout(window_layout);



    QVBoxLayout* app_layout = new QVBoxLayout;
    QHBoxLayout* options_layout = new QHBoxLayout;
    options_layout->addWidget(this->admin);
    options_layout->addWidget(this->user);
    app_layout->addLayout(options_layout);
    app_layout->addWidget(this->exit);

    QVBoxLayout* admin_layout = new QVBoxLayout;
    admin_layout->addWidget(this->e_add);
    admin_layout->addWidget(this->e_update);
    admin_layout->addWidget(this->e_delete);
    admin_layout->addWidget(this->e_show);
    admin_layout->addWidget(this->e_exit);


    QVBoxLayout* addUpdate_layout = new QVBoxLayout;
    QVBoxLayout* delete_layout = new QVBoxLayout;
    QVBoxLayout* update_layout = new QVBoxLayout;



    QFormLayout* add_update_layout_fields = new QFormLayout;
    QFormLayout* delete_layout_fields = new QFormLayout;

    add_update_layout_fields->addRow(this->e_position,this->le_position);
    add_update_layout_fields->addRow(this->e_title, this->le_title);
    add_update_layout_fields->addRow(this->e_description, this->le_description);
    add_update_layout_fields->addRow(this->e_datetime, this->le_datetime);
    add_update_layout_fields->addRow(this->e_nrPeople, this->le_nrPeople);
    add_update_layout_fields->addRow(this->e_link, this->le_link);

    delete_layout_fields->addRow(this->e_position,this->le_position);

    delete_layout->addLayout(delete_layout_fields);
    delete_layout->addWidget(deleteBtn);
    delete_layout->addWidget(addUpdate_exit);


    addUpdate_layout->addLayout(add_update_layout_fields);
    addUpdate_layout->addWidget(addUpdate_add);
    addUpdate_layout->addWidget(addUpdate_exit);


    update_layout->addLayout(add_update_layout_fields);
    update_layout->addWidget(addUpdate_update);
    update_layout->addWidget(addUpdate_exit);






    ev_list = new QListWidget{};

//    vLayout->addWidget(ev_list);






    QVBoxLayout* user_layout_start = new QVBoxLayout;
    user_layout_start->addWidget(this->user_csv);
    user_layout_start->addWidget(this->user_html);

    user_table = new QTableWidget();

    user_table->setColumnCount(5);
    user_table->setRowCount((int) this->repoEvent.elements.size());
    user_table->setHorizontalHeaderLabels({"Title", "Description", "Datetime", "Nr. People","Link"});
    user_table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);


    populate_user_list();














    position= new QLineEdit(this);
    position->setPlaceholderText("position");
    removeEdit->setPlaceholderText("position");
    monthEdit->setPlaceholderText("month");


    filter = new QPushButton("SEE EVENTS IN A GIVEN MONTH ");
    filter->setFixedHeight(35);
    filtered_list = new QListWidget{};

    filter_group = new QGroupBox("Filter Events");
    filter_form = new QFormLayout;


    filter_form ->addRow(monthEdit);
    filter_form ->addRow(filter);
    filter_form ->addRow(filtered_list);
    filter_group->setLayout(filter_form);



    QVBoxLayout* user_layout = new QVBoxLayout;
    user_layout->addWidget(user_table);
    user_layout->addWidget(user_add);
    user_layout->addWidget(position);
    user_layout->addWidget(this->user_see_events);
    user_layout->addWidget(this->user_remove_event);
    user_layout->addWidget(this->removeEdit);
    user_layout->addWidget(this->filter_group);
    user_layout->addWidget(this->user_exit);

    user_layout->addLayout(user_layout_start);

    QVBoxLayout* adminShow_layout = new QVBoxLayout;
    adminShow_layout->addWidget(this->ev_list);
    adminShow_layout->addWidget(this->adminShow_exit);
    delete_layout->addWidget(this->ev_list);

    this->main_layout->addLayout(app_layout);
    this->main_layout->addLayout(adminShow_layout);
    this->main_layout->addLayout(addUpdate_layout);
    this->main_layout->addLayout(delete_layout);
    this->main_layout->addLayout(update_layout);
    this->main_layout->addLayout(admin_layout);
    this->main_layout->addLayout(user_layout);
    window_layout->addLayout(this->main_layout);

    this->mainMenu();
}

void QtWindow::initSignals() {
    QObject::connect(this->admin, &QPushButton::clicked, this, [=]() { this->adminMenu(); });
    QObject::connect(this->e_exit, &QPushButton::clicked, this, [=]() { this->mainMenu(); });
    QObject::connect(this->e_add, &QPushButton::clicked, this, [=]() { this->addMenu(); });
    QObject::connect(this->e_delete, &QPushButton::clicked, this, [=]() { this->removeMenu(); });
    QObject::connect(this->e_update, &QPushButton::clicked, this, [=]() { this->updateMenu(); });
    QObject::connect(this->addUpdate_add, &QPushButton::clicked, this, [=]() { this->addEvent(); });
    QObject::connect(this->addUpdate_update, &QPushButton::clicked, this, [=]() { this->updateEvent(); });
    QObject::connect(this->deleteBtn, &QPushButton::clicked, this, [=]() { this->removeEvent(); });
    QObject::connect(this->addUpdate_exit, &QPushButton::clicked, this, [=]() { this->adminMenu(); });
    QObject::connect(this->e_show, &QPushButton::clicked, this, [=]() { this->showList(); });
    QObject::connect(this->adminShow_exit, &QPushButton::clicked, this, [=]() { this->adminMenu(); });
    QObject::connect(this->user, &QPushButton::clicked, this, [=]() { this->userMenuOptions(); });
    QObject::connect(this->user_exit, &QPushButton::clicked, this, [=]() { this->mainMenu(); });
    QObject::connect(this->user_html, &QPushButton::clicked, this, [=]() {
        this->option = 2;
        this->userMenu(); });
    QObject::connect(this->user_csv, &QPushButton::clicked, this, [=]() {
        this->option = 1;
        this->userMenu(); });
    QObject::connect(this->user_add, &QPushButton::clicked, this, [=]() { this->user_add_event();});
    QObject::connect(this->user_see_events, &QPushButton::clicked, this, [=]() { this->openEventsFile(); });
    QObject::connect(this->exit, &QPushButton::clicked, this, &QApplication::quit);
    QObject::connect(this->filter, &QPushButton::clicked, this, [=]() { this->populate_filteredList(); });
    QObject::connect(this->user_remove_event, &QPushButton::clicked, this, [=]() { this->user_remove(); });
//    QObject::connect(this->user_table, &QTableWidget::cellDoubleClicked, this, &~QtWindow::);
//    QObject::connect(this, SIGNAL(listUpdated()), this, SLOT(populate()));


}


void QtWindow::mainMenu() {
    this->admin->setVisible(true);
    this->user->setVisible(true);
    this->exit->setVisible(true);
    this->ev_list->setVisible(false);
    this->adminShow_exit->setVisible(false);
    this->hideAdminMenu();
    this->hideUserMenu();
    this->hideAddMenu();
    this->hideUpdateMenu();
    this->hideRemoveMenu();

}

void QtWindow::hideMainMenu() {

    this->admin->setVisible(false);
    this->user->setVisible(false);
    this->exit->setVisible(false);

}

void QtWindow::adminMenu() {

    this->hideMainMenu();
    this->hideAddMenu();
    this->hideUpdateMenu();
    this->hideRemoveMenu();
    this->ev_list->setVisible(false);
    this->adminShow_exit->setVisible(false);
    this->e_add->setVisible(true);
    this->e_delete->setVisible(true);
    this->e_update->setVisible(true);
    this->e_show->setVisible(true);
    this->e_exit->setVisible(true);
}

void QtWindow::hideAdminMenu() {
    this->e_add->setVisible(false);
    this->e_delete->setVisible(false);
    this->e_update->setVisible(false);
    this->e_show->setVisible(false);
    this->e_exit->setVisible(false);
}

void QtWindow::userMenu() {
    this->populate_events();
    this->hideUserMenuOptions();
    this->user_table->setVisible(true);

    this->user_see_events->setVisible(true);
    this->user_remove_event->setVisible(true);
    this->user_exit->setVisible(true);
    this->user_add->setVisible(true);
    this->position->setVisible(true);
    this->filter_group->setVisible(true);
    this->removeEdit->setVisible(true);

}

void QtWindow::hideUserMenu() {
    this->hideUserMenuOptions();
    this->user_table->setVisible(false);
    this->user_see_events->setVisible(false);
    this->user_remove_event->setVisible(false);
    this->user_exit->setVisible(false);
    this->user_add->setVisible(false);
    this->position->setVisible(false);
    this->filter_group->setVisible(false);
    this->removeEdit->setVisible(false);
}

void QtWindow::userMenuOptions() {
    this->hideMainMenu();
    this->user_csv->setVisible(true);
    this->user_html->setVisible(true);
}

void QtWindow::hideUserMenuOptions() {

    this->user_csv->setVisible(false);
    this->user_html->setVisible(false);

}

void QtWindow::populate_events() {

        ev_list->clear();
        for(const auto& c: this->repoEvent.elements) {
            ev_list->addItem(QString::fromStdString(c.title + ";" + c.description + ";" + c.datetime + ";" + std::to_string(c.nr_people) + ";" + c.link));

        }

}

void QtWindow::showList() {
    this->hideAdminMenu();
    ev_list->clear();
    for(const auto& c: this->repoEvent.elements) {
        ev_list->addItem(QString::fromStdString(c.title + ";" + c.description + ";" + c.datetime + ";" + std::to_string(c.nr_people) + ";" + c.link));
    }
    this->ev_list->setVisible(true);
    this->adminShow_exit->setVisible(true);
}

void QtWindow::hideAddMenu() {
//    new_description->setPlaceholderText("Description");
//    new_title->setPlaceholderText("Title");
//    new_datetime->setPlaceholderText("Date");
//    new_nrPeople->setPlaceholderText("Number of People");
//    new_link->setPlaceholderText("Link");

    this->e_title->setVisible(false);
    this->le_title->setVisible(false);
    this->e_description->setVisible(false);
    this->le_description->setVisible(false);
    this->e_datetime->setVisible(false);
    this->le_datetime->setVisible(false);
    this->e_nrPeople->setVisible(false);
    this->le_nrPeople->setVisible(false);
    this->e_link->setVisible(false);
    this->le_link->setVisible(false);
    addUpdate_exit->setVisible(false);
    addUpdate_add->setVisible(false);

}

void QtWindow::addMenu() {
    this->hideAdminMenu();
    this->e_title->setVisible(true);
    this->le_title->setVisible(true);
    this->e_description->setVisible(true);
    this->le_description->setVisible(true);
    this->e_datetime->setVisible(true);
    this->le_datetime->setVisible(true);
    this->e_nrPeople->setVisible(true);
    this->le_nrPeople->setVisible(true);
    this->e_link->setVisible(true);
    this->le_link->setVisible(true);
    addUpdate_exit->setVisible(true);
    addUpdate_add->setVisible(true);
}

void QtWindow::addEvent() {

Event e;

 try { int OK=1;
     validator.isDate(le_datetime->text().toStdString(),OK);
     string nrPeople = le_nrPeople->text().toStdString();
     validator.isNumber(nrPeople);
     e.setTitle(le_title->text().toStdString());
     e.setDescription(le_description->text().toStdString());
     e.setDateTime(le_datetime->text().toStdString());
     int nrPeople_int = stoi(nrPeople);
     e.setNr_people(nrPeople_int);
     e.setLink(le_link->text().toStdString());
    if(OK==1)
    {
     this->repoEvent.elements.push_back(e);
        this->repoEvent.write_to_file();

     le_title->clear();
     le_description->clear();
     le_datetime->clear();
     le_nrPeople->clear();
     le_link->clear();
        this->adminMenu();
    }
 }
 catch (EventException& e)
 {
     QMessageBox::critical(this, "Error", e.what());
 }

}

void QtWindow::updateEvent()
{
    Event e;

    try { int OK=1;
        if(le_datetime->text().toStdString() !="#")
        validator.isDate(le_datetime->text().toStdString(),OK);
        string nrPeople = le_nrPeople->text().toStdString();
        if(nrPeople[0] != '-') {
            validator.isNumber(nrPeople);
        }
        e.setTitle(le_title->text().toStdString());
        e.setDescription(le_description->text().toStdString());
        e.setDateTime(le_datetime->text().toStdString());
        int nrPeople_int = stoi(nrPeople);
        e.setNr_people(nrPeople_int);
        e.setLink(le_link->text().toStdString());
        int position = le_position->text().toInt();
        if(position<0 || position > this->repoEvent.elements.size())
        {
            QMessageBox::critical(this, "Error", "Wrong index");
            OK=0;
        }
        if(OK==1)
        {
            this->repoEvent.update_event(position,e.title,e.description,e.datetime,e.link,e.nr_people);
            this->repoEvent.write_to_file();
            le_position->clear();
            le_title->clear();
            le_description->clear();
            le_datetime->clear();
            le_nrPeople->clear();
            le_link->clear();
            this->adminMenu();
        }
    }
    catch (EventException& e)
    {
        QMessageBox::critical(this, "Error", e.what());
    }
}

void QtWindow::removeEvent()
{   int OK = 1;
    int position = le_position->text().toInt();
    if(position<0 || position > this->repoEvent.elements.size())
    {
        QMessageBox::critical(this, "Error", "Wrong index");
        OK=0;
    }
    if(OK==1)
    {
        this->repoEvent.remove_event(position);
        this->repoEvent.write_to_file();
        le_position->clear();
        this->adminMenu();
    }
}

void QtWindow::hideUpdateMenu() {
    this->e_position->setVisible(false);
    this->le_position->setVisible(false);
    this->e_title->setVisible(false);
    this->le_title->setVisible(false);
    this->e_description->setVisible(false);
    this->le_description->setVisible(false);
    this->e_datetime->setVisible(false);
    this->le_datetime->setVisible(false);
    this->e_nrPeople->setVisible(false);
    this->le_nrPeople->setVisible(false);
    this->e_link->setVisible(false);
    this->le_link->setVisible(false);
    addUpdate_exit->setVisible(false);
    addUpdate_update->setVisible(false);
}

void QtWindow::updateMenu() {
    this->hideAdminMenu();
    this->e_position->setVisible(true);
    this->le_position->setVisible(true);
    this->e_title->setVisible(true);
    this->le_title->setVisible(true);
    this->e_description->setVisible(true);
    this->le_description->setVisible(true);
    this->e_datetime->setVisible(true);
    this->le_datetime->setVisible(true);
    this->e_nrPeople->setVisible(true);
    this->le_nrPeople->setVisible(true);
    this->e_link->setVisible(true);
    this->le_link->setVisible(true);
    addUpdate_update->setVisible(true);
    addUpdate_exit->setVisible(true);

}

void QtWindow::hideRemoveMenu() {
    this->ev_list->setVisible(false);
    this->e_position->setVisible(false);
    this->le_position->setVisible(false);
    deleteBtn->setVisible(false);
    addUpdate_exit->setVisible(false);
}

void QtWindow::removeMenu() {
        this->hideAdminMenu();
        this->ev_list->setVisible(true);
        this->e_position->setVisible(true);
        this->le_position->setVisible(true);
        deleteBtn->setVisible(true);
        addUpdate_exit->setVisible(true);

}
void QtWindow::populate_user_list() {
    user_table->setRowCount((int) this->repoEvent.elements.size());
    int currentRow = 0;
    for (auto const &e: this->repoEvent.elements) {

        auto title = new QLabel();
        title->setFixedHeight(30);
        title->setText(QString::fromStdString(e.title));
        title->setAlignment(Qt::AlignCenter);
        user_table->setCellWidget(currentRow, 0, title);

        auto description = new QLabel();
        description->setFixedHeight(30);
        description->setText(QString::fromStdString(e.description));
        description->setAlignment(Qt::AlignCenter);
        user_table->setCellWidget(currentRow, 1,description);

        auto datetime = new QLabel();
        datetime ->setFixedHeight(30);
        datetime->setText(QString::fromStdString(e.datetime));
        datetime ->setAlignment(Qt::AlignCenter);
        user_table->setCellWidget(currentRow, 2,datetime );

        auto nrPeople = new QLabel();
        nrPeople->setFixedHeight(30);
        nrPeople->setText(QString::number(e.nr_people));
        nrPeople ->setAlignment(Qt::AlignCenter);
        user_table->setCellWidget(currentRow, 3,nrPeople );

        auto link = new QLabel();
        link->setFixedHeight(30);
        link->setText(QString::fromStdString(e.link));
        link->setAlignment(Qt::AlignCenter);
        user_table->setCellWidget(currentRow, 4,link  );

        currentRow++;
    }
    user_table->resizeColumnsToContents();
};


void QtWindow::user_add_event() {

        int pos  = position->text().toInt()-1;
        int OK=1;
        if(pos<0||pos>=this->repoEvent.elements.size())
        {
            QMessageBox::critical(this, "Error", "Index out of range");
            OK = 0;
        }
        else {

            if(option == 1)
            {
                for(auto &e: this->eventList_csv->getEventList())
                {
                        if(e.link == this->repoEvent.elements[pos].link)
                        {
                            QMessageBox::critical(this, "Error", "Event already exists in list");
                            OK = 0;
                        }
                }
            }
            if(option == 2)
            {
                for(auto &e: this->eventList_html->getEventList())
                {
                    if(e.link == this->repoEvent.elements[pos].link)
                    {
                        QMessageBox::critical(this, "Error", "Event already exists in list");
                        OK = 0;
                    }
                }
            }
            if( OK == 1) {
                eventList_html->getEventList().push_back(this->repoEvent.elements[pos]);
                eventList_csv->getEventList().push_back(this->repoEvent.elements[pos]);
                eventList.eventList.push_back(this->repoEvent.elements[pos]);
                this->repoEvent.elements[pos].nr_people++;
                this->repoEvent.write_to_file();
                eventList_csv->write();
                eventList_html->write();
                position->clear();
                system(std::string("start " + this->repoEvent.elements[pos].link).c_str());
//                emit listUpdated();
            }
        }


}

void QtWindow::openEventsFile()
{
    if (this->eventList.eventList.empty()) {
        QMessageBox::critical(this, "Error", "No events in the list");
    }
    else {

        auto *model = new TableModel(this->eventList);
        this->ev_interested = new QTableView{};;
        this->ev_interested->setModel(model);
        this->ev_interested->setFixedSize(383, 600);
        if (this->option == 1)
            system("start C:\\Users\\andre\\Documents\\GitHub\\a45-andrenyky\\Project\\user1.csv");
        if (this->option == 2)
            system("start C:\\Users\\andre\\Documents\\GitHub\\a45-andrenyky\\Project\\user2.html");
        this->ev_interested->show();
    }
}
void QtWindow::populate_filteredList(){
    filtered_list->clear();
    int month = monthEdit->text().toInt();
    std::vector<Event> event_temp = repoEvent.getElements();
    if(month<-1 || month>12)
    {
        QMessageBox::critical(this, "Error", "Wrong month input");
    }
    else {
        for (const auto &e: event_temp) {

            string month_str = e.datetime.substr(3, 2);
            int month_int = stoi(month_str);
            if (month == month_int) {
                filtered_list->addItem(QString::fromStdString(
                        e.title + ";" + e.description + ";" + e.datetime + ";" + std::to_string(e.nr_people) + ";" +
                        e.link));
            }
        }
    }

}

void QtWindow::user_remove() {
    int pos  = removeEdit->text().toInt()-1;
    int OK = 1;
    if (option == 1)
    {
        if(pos<0||pos>=this->eventList_csv->getEventList().size())
        {
            QMessageBox::critical(this, "Error", "Index out of range");
            OK = 0;
        }
        if(OK == 1)
        {
            for(int i=0;i<this->repoEvent.elements.size();i++)
                if(this->repoEvent.elements[i].link == eventList_csv->eventList[pos].link) {
                    this->repoEvent.elements[i].nr_people--;
                    this->repoEvent.write_to_file();
                }
            eventList_csv->eventList.erase(eventList_csv->eventList.begin()+pos);
                eventList.eventList.erase(eventList.eventList.begin()+pos);
            this->eventList_csv->write();
            removeEdit->clear();
        }
    }
    if (option == 2)
    {
        if(pos<0||pos>=this->eventList_csv->getEventList().size())
        {
            QMessageBox::critical(this, "Error", "Index out of range");
            OK = 0;
        }
        if(OK == 1)
        {
            for(int i=0;i<this->repoEvent.elements.size();i++)
                if(this->repoEvent.elements[i].link == eventList_html->eventList[pos].link) {
                    this->repoEvent.elements[i].nr_people--;
                    this->repoEvent.write_to_file();
                }
            eventList_html->eventList.erase(eventList_html->eventList.begin()+pos);
            eventList.eventList.erase(eventList.eventList.begin()+pos);
            this->eventList_html->write();
            removeEdit->clear();
        }
    }
}