#include <iostream>
#include "Event.h"
#include "EventOrganizer.h"
#include "Date.h"
#include "Location.h"
#include "Concert.h"

bool ascendingTime(Event *a, Event *b) {
    return a->getDate() > b->getDate();
}

bool ascendingPrice(Event *a, Event *b) {
    return a->getPrice() > b->getPrice();
}

bool isForOver18(Event *a) {
    if (a->getAgeGroup() == EventAgeGroup::Senior || a->getAgeGroup() == EventAgeGroup::Adult)
        return true;
    return false;
}

int main() {
    EventOrganizer eventOrganizer("Ime", "SpletnaStran.com");
    Location *lokacija1 = new Location("Vista", "Jezero", "Velenje", "Slovenija");

    eventOrganizer.addEvent(new Event(1, "Koncert, ki je kul!", 20.99, 150,
                                      lokacija1, Date(15, 11, 2024),
                                      EventAgeGroup::All));
    eventOrganizer.addEvent(new Event(2, "Koncert, ki ni kul!", 4236462362.10, 150,
                                      lokacija1, Date(14, 11, 2024),
                                      EventAgeGroup::Senior));
    eventOrganizer.addEvent(new Concert(3, "Koncert, ki ni kul!", 785329525.24, 150,
                                        lokacija1, Date(16, 11, 2024),
                                        EventAgeGroup::Adult, "ne Siddharta", ConcertType::Classical));
    eventOrganizer.addEvent(new Concert(4, "Koncert, ki je kul!", 20.99, 150,
                                        lokacija1, Date(15, 11, 2024),
                                        EventAgeGroup::All, "Siddharta", ConcertType::Rock));
    cout << eventOrganizer.toString() << endl;
    eventOrganizer.sort(ascendingTime);
    cout << eventOrganizer.toString();

    std::cout << "\n\nEvents for 18+ \n";
    Event *eventOver18 = eventOrganizer.find(isForOver18);
    if (eventOver18 != nullptr)
        std::cout << eventOver18->toString();
    else
        std::cout << "no events";
    cout << endl << endl << "Concerts: " << endl;

    PrintIfConcert concert;
    eventOrganizer.printEvents(concert);

    delete lokacija1;
    return 0;
}