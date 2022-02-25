#include "Event.h"
#include "DynamicVector.h"
#include "Services.h"
#include "exceptions.h"
#include "UI.h"
#include "tests.h"
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;



void UI::read_file() {
    string line;
    ifstream myfile("C:\\Users\\andre\\Documents\\GitHub\\a45-andrenyky\\Project\\input.txt");
    while (true){
        if (myfile.eof()) {
            break;
        }
        Event e;

        try {
            myfile>>e;
            this->repoEvent.add_event(e, false);
        }
        catch (...){

        }

    }
    myfile.close();
}

void UI::validate_date(const string& datetime, int& OK)
{   char alphabet[] = { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    if(datetime.length()!=10) {
        OK = 0;
        cout<<"INPUT A VALID DATE\n";
    }

    string days,month,year;

    if(OK==1) {
        days = datetime.substr(0, 2);
        month = datetime.substr(3, 2);
        year = datetime.substr(6, 4);
    }
    if(OK == 1)
    {
        for (char day : days)
            if (strchr(alphabet, day) && OK == 1)
            {
                cout<<"INPUT A VALID DATE\n";
                OK = 0;
            }
        for (char i : month)
            if (strchr(alphabet, i) && OK==1)
            {
                cout<<"INPUT A VALID DATE\n";
                OK = 0;
            }
        for (char i : year)
            if (strchr(alphabet, i) && OK == 1)
            {
                cout<<"INPUT A VALID DATE\n";
                OK = 0;
            }


        int days_int = stoi(days);
        int month_int = stoi(month);
        int year_int = stoi(year);
        if ((month_int <= 0 || month_int > 12) && OK == 1)
        {
            printf("INPUT A VALID MONTH\n");

            OK = 0;
        }
        if ((days_int <= 0 || days_int > 31) && OK == 1)
        {
            printf("INPUT A VALID DAY\n");
            OK = 0;
        }
    }
}




void UI::ui_add_event()
{
    string title,description,datetime,link;

    string nr_people;
    int OK=1;

    cout<<"ENTER TITLE:";
    cin.ignore();
    getline(cin,title);
    cout<<"ENTER DESCRIPTION:";
    getline(cin,description);
    cout<<"ENTER DATE(DD/MM/YYYY):";
    getline(cin,datetime);
    cout<<"ENTER LINK OF THE EVENT:";
    getline(cin,link);
    cout<<"NUMBER OF PEOPLE WHO ARE GOING TO THIS EVENT:";
    getline(cin,nr_people);


    try {
        this->validator.isDate(datetime, OK);
        this->validator.isNumber(nr_people);
        int nr_people_int = stoi(nr_people);
        if (this->repoEvent.elements.size() != 0) {
            for (int i = 0; i < this->repoEvent.elements.size(); i++) {
                if (link == this->repoEvent.elements[i].getLink()) {
                    OK = 0;
                    cout << "EVENT ALREADY EXISTS";
                }
            }
        }

        if (OK == 1) {
            Event new_event{title, description, datetime, nr_people_int, link};
            this->repoEvent.add_event(new_event);
            cout << "EVENT ADDED\n";
        }
    }
    catch (EventException& ex)
    {
        cout<<ex.what()<<endl;
    }
}


void UI::ui_show_events(vector<Event> &ve)
{
    for(int i=0;i<ve.size();i++)
    {cout<<"EVENT NR "<<i<<":"<<ve[i];
        cout<<endl;}
}

void UI::ui_update()
{
    string title,description,datetime,link,nr_people;

    int OK=1;
    int pos=-1;
    ui_show_events(this->repoEvent.elements);
    cout<<"UPDATE EVENT AT POSITION:";
    cin>>pos;

    if( OK == 1) {
        cout << "NEW TITLE(# to omit):";
        cin.ignore();
        getline(cin, title);
        cout << "NEW DESCRIPTION(# to omit):";
        getline(cin, description);
        cout << "NEW DATE(DD/MM/YYYY)(# to omit):";
        getline(cin, datetime);
        cout << "NEW LINK OF THE EVENT(# to omit):";
        getline(cin, link);
        cout << "NEW NUMBER OF PEOPLE WHO ARE GOING TO THIS EVENT(negative number to omit):";
        getline(cin,nr_people);

        if (datetime != "#")
            try {
                this->validator.isDate(datetime, OK);
            }
            catch (EventException& ex)
            {
                cout<<ex.what()<<endl;
            }
        if (nr_people[0] != '-')
            try {
                this->validator.isNumber(nr_people);
            }
            catch (EventException& ex)
            {
                cout<<ex.what()<<endl;
            }
                if (OK == 1) {
                    int nr_people_int = stoi(nr_people);
                    this->repoEvent.update_event(pos,title,description,datetime,link,nr_people_int);
                    cout << "EVENT UPDATED\n";



            }

    }
}


void UI::ui_remove()
{

    int OK=1;
    int pos=-1;
    ui_show_events(this->repoEvent.elements);
    cout<<"REMOVE EVENT AT POSITION:";
    cin>>pos;

    if(pos<0 || pos>=this->repoEvent.elements.size())
    {
        OK=0;
        throw EventException("INDEX OUT OF RANGE");
    }

    if(OK == 1) {
        this->repoEvent.remove_event(pos);
        cout<<"EVENT REMOVED\n";
    }
}



////////////////////////////////////// USER



void UI::ui_user_see_events( vector<Event> &user_list) {
    int month = 0;
    int OK = 1;
    DynamicVector<Event> event_list;
    cout << "SEE THE EVENTS IN MONTH(0 to display all):";
    cin >> month;

    if (month < 0 || month > 12) {
        cout << "TYPE A VALID MONTH\n";
        OK = 0;
    }

    if (OK == 1) {
        if (month != 0) {
            for (int i = 0; i < this->repoEvent.elements.size(); i++) {
                string month_str = this->repoEvent.elements[i].datetime.substr(3, 2);
                int month_int = stoi(month_str);
                if (month == month_int)
                    event_list.add(this->repoEvent.elements[i]);
            }
        } else {
            for (int i = 0; i < this->repoEvent.elements.size(); i++)
                event_list.add(this->repoEvent.elements[i]);
            int size_list = event_list.getSize();
            sort(event_list.elems,event_list.elems+size_list,compare);

        }
        int opt = 0;
        while(opt!=4) {
            int i=0;
            while(i<event_list.getSize())
            {   int option = 0;
                cout<<event_list.elems[i];
                string link = event_list.elems[i].getLink();
                system(std::string("start " + link).c_str());

                cout<<endl;
                cout<<"1.NEXT\n";
                cout<<"2.ADD EVENT\n";
                cout<<"3.RETURN\n";
                cout<<"CHOOSE OPTION:";
                cin>>option;

                if(option == 1)
                {
                    if(i<event_list.getSize()-1)
                        i++;
                    else
                        i=0;
                }

                else if(option == 2) {
                    int OK1 = 1;
                    for (int j = 0; j < user_list.size(); j++) {
                        if (user_list[j].link == event_list.elems[i].link) {
                            cout << "EVENT ALREADY ADDED\n";
                            OK1 = 0;
                        }
                    }
                    if (OK1 == 1) {
                        user_list.push_back(event_list.elems[i]);
                        eventList->getEventList().push_back(event_list.elems[i]);
                        this->eventList->write();
                        for (int k = 0; k < this->repoEvent.elements.size(); k++) {
                            if (this->repoEvent.elements[k].link == event_list.elems[i].link)
                                this->repoEvent.elements[k].nr_people++;
                                this->repoEvent.write_to_file();
                        }
                    }
                }
                else if(option == 3) {
                    opt = 4;
                    i=event_list.getSize()+1;
                }


            }
            break;

        }

    }
}


void UI::ui_user_remove( vector<Event> &user_list)
{
    int OK=1;
    int pos=-1;
    ui_show_events(user_list);
    cout<<"REMOVE EVENT AT POSITION:";
    cin>>pos;

    if(pos<0 || pos>=user_list.size())
    {
        OK=0;
        cout<<"INDEX OUT OF RANGE\n";
    }

    if(OK == 1) {
        for(int i=0;i<this->repoEvent.elements.size();i++)
            if(this->repoEvent.elements[i].link == user_list[pos].link) {
                this->repoEvent.elements[i].nr_people--;
                this->repoEvent.write_to_file();
            }
        eventList->eventList.erase(eventList->eventList.begin()+pos);
        this->eventList->write();
        user_list.erase(user_list.begin()+pos);
        cout<<"EVENT REMOVED\n";
    }
}

int UI::admin_menu() {
    int option = 0;
    cout<<"\tADMIN MENU\n";
    while(true) {
        cout<<"1.ADD EVENT\n";
        cout<<"2.UPDATE EVENT\n";
        cout<<"3.REMOVE EVENT\n";
        cout<<"4.SHOW EVENTS\n";
        cout<<"5.EXIT\n";
        cout<< "CHOOSE OPTION:";
        cin>>option;
        try {
        switch(option) {
            case 1:
                    ui_add_event();
                    break;
            case 2:
                ui_update();
                break;
            case 3:
                ui_remove();
                break;
            case 4:
                ui_show_events(this->repoEvent.elements);
                break;
            case 5:
                cout<<"BYE!";
                return 0;
            default:
                cout<<"INPUT A VALID COMMAND\n";
        }

    }
        catch (EventException& ex)
        {
            cout<<ex.what()<<endl;
        }
    }
}


void UI::user_data_store(int& data) {
    cout<<"1.Save in CSV format"<<endl;
    cout<<"2.Save in HTML format"<<endl;

    int option = 0;
    cout<<"CHOOSE OPTION:";
    cin>>option;
    if (option == 1)
    {   data = 1;
        this->eventList = make_unique<CsvEventList>();
    }
    else if (option == 2)
    {   data = 2;
        this->eventList = make_unique<HtmlEventList>();
    }

}

void UI::show_stored_data(int data) {
    if (this->eventList->getEventList().empty())
        cout<<"\nEvent list is empty.\n\n";
    else{
        if (data == 1){
            system("start C:\\Users\\andre\\Documents\\GitHub\\a45-andrenyky\\Project\\user1.csv");
            cout<<endl;
        } else{
            system("start C:\\Users\\andre\\Documents\\GitHub\\a45-andrenyky\\Project\\user2.html");
            cout<<endl;
        }
    }
}

int UI::user_menu()
{   vector<Event> user_list;
    int option = 0;
    int data = 0;
        this->user_data_store(data);

    cout<<"\tUSER MENU\n";
    while(true) {
        cout<<"1.SEE EVENTS IN A GIVEN MONTH\n";
        cout<<"2.SEE THE EVENTS YOU'RE INTERESTED IN\n";
        cout<<"3.REMOVE EVENT\n";
        cout<<"4.EXIT\n";
        cout<< "CHOOSE OPTION:";
        cin>>option;
        switch(option) {
            case 1:
                ui_user_see_events(user_list);
                break;
            case 2:
                show_stored_data(data);
                break;
            case 3:
                ui_user_remove(user_list);
                break;
            case 4:
                cout<<"BYE!";
                return 0;
            default:
                cout<<"INPUT A VALID COMMAND\n";
        }
    }
    }




int UI::main_menu()
{
    this->repoEvent.read_file();
    int option = 0;
    cout << "1.ADMIN\n";
    cout << "2.USER\n";
    cout<<"3.EXIT\n";
    cout << "CHOOSE OPTION:";
    cin >> option;
    switch (option) {
        case 1:
            admin_menu();
            break;
        case 2:
            user_menu();
            break;
        case 3:
            cout<<"BYE!";
            return 0;
    }
    ofstream myfile(" C:\\Users\\andre\\Documents\\GitHub\\a45-andrenyky\\Project\\user2.html");
    myfile.close();
    ofstream myfile1(" C:\\Users\\andre\\Documents\\GitHub\\a45-andrenyky\\Project\\user1.csv");
    myfile.close();

    return 0;
}
