#pragma once
#include "Warteschlange.h"
#include "Festangestellter.h"
#include "Kunde.h"
#include <list>
#include <iostream>

class Kunde; // Vorwärtsdeklaration

class Servicekraft : public Festangestellter {
private:
    Warteschlange* queue; // Warteschlange für Bestellungen
    std::list<Pizza*> karte; // Liste von verfügbaren Pizzen

    Bestellung* aufnehmenBestellung(); // Methode zum Aufnehmen einer Bestellung

public:
    static int kundennr; // Statische Kundennummer für neue Kunden

    // Konstruktor
    Servicekraft(string name, string anschrift, string telefon, int persNr, double monatsgehalt, Warteschlange* queue, std::list<Pizza*> karte);

    Kunde* registriereKunde(); // Methode zur Registrierung eines neuen Kunden
    void beauftrageKoch(Bestellung* b); // Methode zur Beauftragung des Kochs
    void run(); // Methode zum Aufnehmen neuer Bestellungen
};

