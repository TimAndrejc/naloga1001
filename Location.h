//
// Created by Tim Andrejc on 15. 5. 24.
//

#ifndef NALOGA1001_LOCATION_H
#define NALOGA1001_LOCATION_H

#include <string>

class Location {
private:
    std::string name;
    std::string street;
    std::string city;
    std::string country;

public:
    Location(const std::string &name, const std::string &street, const std::string &city, const std::string &country);

    const std::string &getName() const;
    void setName(const std::string &name);

    const std::string &getStreet() const;
    void setStreet(const std::string &street);

    const std::string &getCity() const;
    void setCity(const std::string &city);

    const std::string &getCountry() const;
    void setCountry(const std::string &country);

    std::string toString() const;
};

#endif //NALOGA1001_LOCATION_H
