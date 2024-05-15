//
// Created by Tim Andrejc on 15. 5. 24.
//

#ifndef NALOGA1001_CONCERT_H
#define NALOGA1001_CONCERT_H

#include "EventOrganizer.h"
#include <string>

using namespace std;

enum class ConcertType {
    Rock,
    Pop,
    Classical,
    Metal
};

class Concert : public Event {
private:
    string performer;
    ConcertType type;
public:
    Concert(int id, const string &title, float price, unsigned int numTickets, Location *location,
            const Date &date, EventAgeGroup ageGroup, const string &performer, ConcertType type);

    string toString() const override;

    string getPerformer() const;

    void setPerfomer(string performer);

    string getConcertType() const;

    void setConcertType(ConcertType);

};

#endif //NALOGA1001_CONCERT_H
