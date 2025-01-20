#pragma once
#include "Warteschlange.h"
#include "Festangestellter.h"

class Koch : public Festangestellter {
private:
    Warteschlange* queue; // Warteschlange für Bestellungen

    bool zubereiten(Bestellung* bestellung); // Methode zur Zubereitung einer Bestellung

public:
    // Konstruktor
    Koch(string name, string anschrift, string telefon, int persNr, double monatsgehalt, Warteschlange* queue);

    void druckeBestellschein(Bestellung* b); // Methode zum Drucken des Bestellscheins (erweiterung durch 1.5.2)
    void run(); // Methode, die die Zubereitung der Bestellungen steuert
};
