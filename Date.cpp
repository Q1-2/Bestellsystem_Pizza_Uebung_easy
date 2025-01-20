#pragma once
#include <ctime> 
#include <string>
#include <iostream>
#include <chrono>
#include <sstream>
#include <stdexcept>

#include "Date.h"

Date::Date() {
    time_t now = time(nullptr);
    struct tm localTime;
    localtime_s(&localTime, &now); // Verwendung von localtime_s
    tag = localTime.tm_mday;
    monat = localTime.tm_mon + 1;
    jahr = localTime.tm_year + 1900;
}

Date::Date(const Date& datum) {
    validateDate(datum.tag, datum.monat, datum.jahr);
    tag = datum.tag;
    monat = datum.monat;
    jahr = datum.jahr;
}

Date::Date(int tag1, int monat1, int jahr1) {
    validateDate(tag1, monat1, jahr1);
    tag = tag1;
    monat = monat1;
    jahr = jahr1;
}

Date::Date(const std::string& datum) {
    std::istringstream ss(datum);
    std::string teilstring;
    int tag1 = 0, monat1 = 0, jahr1 = 0;

    // Datum im Format "Tag.Monat.Jahr" parsen
    if (std::getline(ss, teilstring, '.')) {
        tag1 = std::stoi(teilstring);
    }
    if (std::getline(ss, teilstring, '.')) {
        monat1 = std::stoi(teilstring);
    }
    if (std::getline(ss, teilstring)) {
        jahr1 = std::stoi(teilstring);
    }

    // Validierung des Datums
    validateDate(tag1, monat1, jahr1);

    // Zuweisung der Membervariablen
    tag = tag1;
    monat = monat1;
    jahr = jahr1;
}

void Date::validateDate(int tag1, int monat1, int jahr1) {
    // Überprüfung auf gültige Monate
    if (monat1 < 1 || monat1 > 12) {
        throw std::invalid_argument("Ungültiger Monat");
    }

    // Überprüfung auf gültige Jahre
    if (jahr1 < 0) {
        throw std::invalid_argument("Ungültiges Jahr");
    }

    // Überprüfung auf gültige Tage
    bool istSchaltjahr = (jahr1 % 4 == 0 && jahr1 % 100 != 0) || (jahr1 % 400 == 0);
    int maxTag = 31;

    if (monat1 == 2) {
        maxTag = istSchaltjahr ? 29 : 28;
    }
    else if (monat1 == 4 || monat1 == 6 || monat1 == 9 || monat1 == 11) {
        maxTag = 30;
    }

    if (tag1 < 1 || tag1 > maxTag) {
        throw std::invalid_argument("Ungültiger Tag");
    }
}

int Date::getTag() const {
    return tag;
}

int Date::getMonat() const {
    return monat;
}

int Date::getJahr() const {
    return jahr;
}

void Date::getDatum(int& tag1, int& monat1, int& jahr1) const {
    tag1 = tag;
    monat1 = monat;
    jahr1 = jahr;
}

std::string Date::getStringDatum() const {
    return std::to_string(tag) + "." + std::to_string(monat) + "." + std::to_string(jahr);
}

std::string Date::toString() const {
    return getStringDatum();
}

void Date::setTag(int tag1) {
    validateDate(tag1, monat, jahr);
    tag = tag1;
}

void Date::setMonat(int monat1) {
    validateDate(tag, monat1, jahr);
    monat = monat1;
}

void Date::setJahr(int jahr1) {
    validateDate(tag, monat, jahr1);
    jahr = jahr1;
}

void Date::setStringDatum(const std::string& datum) {
    std::istringstream ss(datum);
    std::string teilstring;
    int tag1 = 0, monat1 = 0, jahr1 = 0;

    // Datum im Format "Tag.Monat.Jahr" parsen
    if (std::getline(ss, teilstring, '.')) {
        tag1 = std::stoi(teilstring);
    }
    if (std::getline(ss, teilstring, '.')) {
        monat1 = std::stoi(teilstring);
    }
    if (std::getline(ss, teilstring)) {
        jahr1 = std::stoi(teilstring);
    }

    // Validierung des Datums
    validateDate(tag1, monat1, jahr1);

    // Zuweisung der Membervariablen
    tag = tag1;
    monat = monat1;
    jahr = jahr1;
}

void Date::setDatum(int tag1, int monat1, int jahr1) {
    validateDate(tag1, monat1, jahr1);
    tag = tag1;
    monat = monat1;
    jahr = jahr1;
}

Date Date::addDays(int days) const {
    std::tm x = {};
    x.tm_year = jahr - 1900;
    x.tm_mon = monat - 1;
    x.tm_mday = tag;
    std::mktime(&x);
    x.tm_mday += days;
    std::mktime(&x); // Normalize the date
    return Date(x.tm_mday, x.tm_mon + 1, x.tm_year + 1900);
}

bool Date::isBefore(const Date& d) const {
    if (jahr < d.jahr) {
        return true; // Dieses Datum ist vor dem anderen Jahr
    }
    else if (jahr == d.jahr) {
        if (monat < d.monat) {
            return true; // Dieses Datum ist vor dem anderen Monat
        }
        else if (monat == d.monat) {
            return tag < d.tag; // Vergleiche die Tage
        }
    }
    return false; // Dieses Datum ist nicht vor dem anderen
}

bool Date::isAfter(const Date& d) const {
    if (jahr > d.jahr) {
        return true; // Dieses Datum ist nach dem anderen Jahr
    }
    else if (jahr == d.jahr) {
        if (monat > d.monat) {
            return true; // Dieses Datum ist nach dem anderen Monat
        }
        else if (monat == d.monat) {
            return tag > d.tag; // Vergleiche die Tage
        }
    }
    return false; // Dieses Datum ist nicht nach dem anderen
}

bool Date::isBetween(const Date& first, const Date& second) const {
    return (isBefore(second) && isAfter(first)) || (isBefore(first) && isAfter(second));
}