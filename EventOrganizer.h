//
// Created by Tim Andrejc on 15. 5. 24.
//

#ifndef NALOGA1001_EVENTORGANIZER_H
#define NALOGA1001_EVENTORGANIZER_H

#include <string>
#include "Concert.h"
#include <vector>

using namespace std;

class PrintIfConcert {
public:
    void operator()(Event *e) {
        if (dynamic_cast<Concert *>(e)) {
            cout << dynamic_cast<Concert *>(e)->toString() << "\n";
        }
    }
};


class EventOrganizer {
private:
    string name;
    string webAddress;
    vector<Event *> events;
public:
    EventOrganizer(const string &name, const string &webAddress);

    EventOrganizer();

    ~EventOrganizer();

    void addEvent(Event *event);

    void sellTicket(int id);

    string getName() const;

    void setName(const string &name);

    string getWebAddress() const;

    void setWebAddress(const string &webAddress);

    string toString() const;

    vector<Event *> findEventsByLocation(const Location *location) const;

    void sort(bool (*f)(Event *, Event *));

    Event *find(bool (*f)(Event *)) const;

    void printEvents(PrintIfConcert f);

};

#endif //NALOGA1001_EVENTORGANIZER_H
