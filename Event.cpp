//
// Created by Tim Andrejc on 1. 4. 24.
//

#include "Event.h"
#include <iostream>
#include "Location.h"
#include "Date.h"


Event::Event(int id, const string &title, float price, unsigned int numTickets,
             Location *location, const Date &date, EventAgeGroup ageGroup) {
    this->id = id;
    this->title = title;
    this->price = price;
    this->numTickets = numTickets;
    this->location = location;
    this->date = date;
    this->ageGroup = ageGroup;
}

Event::Event() = default;

int Event::getId() const {
    return id;
}

void Event::setId(int id) {
    this->id = id;
}

string Event::getTitle() const {
    return title;
}

void Event::setTitle(const string &title) {
    this->title = title;
}

float Event::getPrice() const {
    return price;
}

void Event::setPrice(float price) {
    this->price = price;
}

unsigned int Event::getNumTickets() const {
    return numTickets;
}

void Event::setNumTickets(unsigned int num) {
    this->numTickets = num;
}

Location *Event::getLocation() const {
    return this->location;
}

void Event::setLocation(Location *location) {
    this->location = location;
}

Date Event::getDate() const {
    return this->date;
}

void Event::setDate(const Date &date) {
    this->date = date;
}

EventAgeGroup Event::getAgeGroup() const {
    return this->ageGroup;
}

void Event::setAgeGroup(const EventAgeGroup ageGroup) {
    this->ageGroup = ageGroup;
}

bool Event::sellTicket() {
    if (numTickets > 0) {
        numTickets--;
        return true;
    }
    return false;
}

string Event::toString() const {
    string age;
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
           + to_string(numTickets) + ", " + location->toString() + ", " + date.toString() + ", " + age;
}

void Event::print() const {
    cout << this->toString() + ".";
}