//
// Created by andre on 4/7/2021.
//

#ifndef A45_ANDRENYKY_UI_H
#define A45_ANDRENYKY_UI_H
#include "Services.h"
#include "Event.h"
#include "DynamicVector.h"
#include "repoEvent.h"
#include "validators.h"
#include "tests.h"
#include <cstring>
#include "eventList.h"
#include <cstdlib>
#include "memory"

using namespace std;

class UI {
private:
    Validator validator;
    RepoEvent repoEvent;
    unique_ptr<EventList> eventList = nullptr;
public:
    void validate_date(const string& datetime, int& OK);
    void ui_add_event();
    void ui_show_events(vector<Event> &ve);
    void ui_update();
    void ui_remove();
    void ui_user_see_events( vector<Event> &user_list);
    void ui_user_remove( vector <Event> &user_list);
    int admin_menu();
    int user_menu();
    int main_menu();
    void read_file();
    void user_data_store(int& data);
    void show_stored_data(int data);

};
//void validate_date(string datetime, int& OK);
//void ui_add_event(DynamicVector<Event> &ve);
//void ui_show_events(DynamicVector<Event> &ve);
//void ui_update(DynamicVector<Event> &ve);
//void ui_remove(DynamicVector<Event> &ve);
//void ui_user_see_events(DynamicVector<Event> &ve, DynamicVector<Event> &user_list,DynamicVector<Event> &event_list);
//void ui_user_remove(DynamicVector<Event> &ve, DynamicVector<Event> &user_list);
//int admin_menu(DynamicVector<Event> &ve);
//int user_menu(DynamicVector<Event>&ve);
//int main_menu();



#endif //A45_ANDRENYKY_UI_H
