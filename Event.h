//
// Created by Tim Andrejc on 15. 5. 24.
//

#ifndef NALOGA1001_EVENT_H
#define NALOGA1001_EVENT_H
#include <string>
#include "Date.h"
#include "Location.h"

enum class EventAgeGroup {
    Child,
    Adult,
    Senior,
    All
};

using namespace std;

class Event {
protected:
    int id;
    string title;
    float price;
    unsigned int numTickets;
    Location *location;
    Date date;
    EventAgeGroup ageGroup;
public:

    Event(int id, const string &title, float price, unsigned int numTickets,
          Location *location, const Date &date, EventAgeGroup ageGroup);

    Event();

    int getId() const;

    void setId(int id);

    string getTitle() const;

    void setTitle(const string &title);

    float getPrice() const;

    void setPrice(float price);

    unsigned int getNumTickets() const;

    void setNumTickets(unsigned int num);

    Location *getLocation() const;

    void setLocation(Location *location);

    Date getDate() const;

    void setDate(const Date &date);

    EventAgeGroup getAgeGroup() const;

    void setAgeGroup(EventAgeGroup ageGroup);

    virtual bool sellTicket();

    virtual string toString() const;

    void print() const;

};

#endif //NALOGA1001_EVENT_H
