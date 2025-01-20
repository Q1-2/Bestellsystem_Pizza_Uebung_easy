#pragma once
#include "Person.h"
#include "Rechnung.h"
#include "Servicekraft.h"
#include <list>

class Servicekraft; // Vorw�rtsdeklaration der Servicekraft-Klasse

class Kunde : public Person {
private:
    int kundenNr; // Eindeutige Kundennummer
    Servicekraft* servicekraft; // Zeiger auf die zugeh�rige Servicekraft
    std::list<Pizza*> karte; // Liste der verf�gbaren Pizzen

public:
    // Konstruktor
    Kunde(string name, string anschrift, string telefon, int kundenNr);

    void aufgebenBestellung(); // Methode zum Aufgeben einer Bestellung
    double bezahlen(Rechnung* r); // Methode zur Bezahlung einer Rechnung
};