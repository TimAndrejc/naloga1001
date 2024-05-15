//
// Created by Tim Andrejc on 15. 5. 24.
//
#include "Concert.h"

Concert::Concert(int id, const std::string &title, float price, unsigned int numTickets, Location *location,
                 const Date &date, EventAgeGroup ageGroup, const std::string &performer, ConcertType type) :
        Event(id, title, price, numTickets, location, date, ageGroup),
        performer(performer), type(type) {

}

string Concert::getPerformer() const {
    return performer;
}

void Concert::setPerfomer(string performer) {
    this->performer = performer;
}

string Concert::getConcertType() const {
    string ret;
    switch (type) {
        case ConcertType::Rock:
            ret = "Rock";
            break;
        case ConcertType::Pop:
            ret = "Pop";
            break;
        case ConcertType::Classical:
            ret = "Classical";
            break;
        default:
            ret = "Metal";
            break;
    }
    return ret;
}

void Concert::setConcertType(ConcertType type) {
    this->type = type;
}

string Concert::toString() const {
    string stringType;
    string age;
    switch (this->type) {
        case ConcertType::Rock:
            stringType = "Rock";
            break;
        case ConcertType::Pop:
            stringType = "Pop";
            break;
        case ConcertType::Classical:
            stringType = "Classical";
            break;
        default:
            stringType = "Metal";
            break;
    }
    switch (ageGroup) {
        case EventAgeGroup::Child:
            age = "Child";
            break;
        case EventAgeGroup::Adult:
            age = "Adult";
            break;
        case EventAgeGroup::Senior:
            age = "Senior";
            break;
        default:
            age = "All";
            break;
    }

    return "ID: " + to_string(id) + ", " + title + ", " + to_string(price) + "€, "
           + to_string(numTickets) + ", " + location->toString() + ", " + date.toString() + ", " + age +
           ", " + performer + ", " + stringType;
}