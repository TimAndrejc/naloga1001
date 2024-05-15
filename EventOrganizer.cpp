//
// Created by Tim Andrejc on 1. 4. 24.
//

#include "EventOrganizer.h"
#include "Event.h"
#include <string>

using namespace std;

EventOrganizer::EventOrganizer(const std::string &name, const std::string &webAddress) :
        name(name), webAddress(webAddress) {}

EventOrganizer::EventOrganizer() = default;

EventOrganizer::~EventOrganizer() {
    for (auto *event: events) {
        delete event;
    }
    events.clear();
}

void EventOrganizer::addEvent(Event *event) {
    events.push_back(event);
}


void EventOrganizer::sellTicket(int id) {
    for (Event *event: events) {
        if (event->getId() == id) {
            event->sellTicket();
            return;
        }
    }
}

string EventOrganizer::toString() const {
    string ret = name + " " + webAddress + "\n";
    for (Event *const event: events) {
        ret += event->toString() + "\n";
    }
    return ret;
}

string EventOrganizer::getName() const {
    return name;
}

void EventOrganizer::setName(const string &name) {
    this->name = name;
}

string EventOrganizer::getWebAddress() const {
    return webAddress;
}

void EventOrganizer::setWebAddress(const string &webAddress) {
    this->webAddress = webAddress;
}

vector<Event *> EventOrganizer::findEventsByLocation(const Location *location) const {
    vector<Event *> ret;
    for (Event *const event: events) {
        if (event->getLocation() == location) {
            ret.push_back(event);
        }
    }
    return ret;
}
