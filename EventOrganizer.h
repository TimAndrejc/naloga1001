//
// Created by Tim Andrejc on 15. 5. 24.
//

#ifndef NALOGA1001_EVENTORGANIZER_H
#define NALOGA1001_EVENTORGANIZER_H

#include <string>
#include "Event.h"
#include <vector>

using namespace std;


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

};

#endif //NALOGA1001_EVENTORGANIZER_H
