#pragma once
#include <string>
#include <iostream>
#include <chrono>

class Date {
private:
    int tag, monat, jahr;

public:
    // Konstruktoren und Destruktor
    Date();
    Date(const Date& datum); // Kopierkonstruktor
    Date(int tag1, int monat1, int jahr1);
    Date(const std::string& datum);
    ~Date() = default;

    // Getter
    int getTag() const;
    int getMonat() const;
    int getJahr() const;
    void getDatum(int& tag1, int& monat1, int& jahr1) const;
    std::string getStringDatum() const;
    std::string toString() const;

    // Setter
    void setTag(int tag1);
    void setMonat(int monat1);
    void setJahr(int jahr1);
    void setStringDatum(const std::string& datum);
    void setDatum(int tag1, int monat1, int jahr1);

    Date addDays(int days) const;
    bool isBefore(const Date& d) const;
    bool isAfter(const Date& d) const;
    bool isBetween(const Date& first, const Date& second) const;

private:
    void validateDate(int tag1, int monat1, int jahr1);
};