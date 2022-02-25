#include <assert.h>
#include "DynamicVector.h"
#include "Services.h"
#include "Event.h"

void test() {

    DynamicVector<Event> ve;

    assert(ve.getSize() == 0);
    assert(ve.capacity == 10);
    ve.init();
    assert(ve.getSize() == 10);
    Event e{"Super", "description", "20/03/2005", 20, "abcd"};
    ve.add(e);
    assert(ve.capacity == 20);
    assert(e.title == "Super");
    assert(e.description == "description");
    assert(e.datetime == "20/03/2005");
    assert(e.link == "https://www.abcd");
    e.setTitle("Nou");
    assert(e.title == "Nou");
    e.setDateTime("21/04/2013");
    assert(e.datetime == "21/04/2013");
    e.setNr_people(-20);
    assert(e.nr_people == 20);
    Event e1{"Super", "description", "21/03/2005", 20, "1234"};
    bool comp = compare(e, e1);
    assert(comp == 0);
    update(ve, 0, "uno", "dos", "23/10/2019", "yooo", 50);
    assert(ve.elems[0].title == "uno");
    assert(ve.elems[0].description == "dos");
    assert(ve.elems[0].datetime == "23/10/2019");
    assert(ve.elems[0].link == "https://www.yooo");
    assert(ve.elems[0].nr_people == 50);
    ve.removeElem(0);
    assert(ve.getSize() == 10);
    assert(ve.elems[0].title == "Eematico");
    assert(ve.elems[0].description == "Activitati pentru copii");
    assert(ve.elems[0].datetime == "23/07/2021");
    assert(ve.elems[0].nr_people == 70);
    assert(ve.elems[0].link == "https://www.zilesinopti.ro/locuri/11311/eematico");
    ve.elems[0] = ve.elems[1];
    assert(ve.elems[0].title == "Star Wars");
    // Event e1{"Super","description","21/03/2005",20,"1234"};
    e1.setTitle("#");
    assert(e1.title == "Super");
    e1.setDateTime("#");
    assert(e1.datetime == "21/03/2005");
    e1.setNr_people(50);
    assert(e1.nr_people == 50);

    assert(e1.getLink() == "https://www.1234");
    string title = e1.getTitle();
    assert(title == "Super");
    assert(e1.getNr_people() == 50);
    assert(e1.getDatetime() == "21/03/2005");
    assert(e1.getDescription() == "description");
    Event e2{"Super", "description", "21/03/2007", 20, "1234"};
    Event e3{"Super", "description", "21/03/2005", 20, "1234"};

    bool compar = compare(e3, e2);
    assert(compar == 1);
    Event e4{"Super", "description", "21/02/2005", 20, "1234"};
    Event e5{"Super", "description", "21/03/2005", 20, "1234"};
    assert(compare(e4, e5) == 1);

    Event e6{"Super", "description", "22/03/2005", 20, "1234"};
    Event e7{"Super", "description", "21/03/2005", 20, "1234"};

    assert(compare(e6, e7) == 0);

    Event e8{"Super", "description", "19/03/2005", 20, "1234"};
    Event e9{"Super", "description", "21/03/2005", 20, "1234"};
    assert(compare(e8, e9) == 1);

}


