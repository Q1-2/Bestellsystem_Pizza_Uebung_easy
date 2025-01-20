#pragma once
#include "Aushilfskraft.h"
#include "Bestellung.h"
#include "Rechnung.h"
#include "Warteschlange.h"

class Fahrer : private Aushilfskraft {
private:
    string fuehrerscheinklasse; // Führerscheinklasse des Fahrers
    Warteschlange* queue; // Warteschlange für Bestellungen

public:
    // Konstruktor
    Fahrer(string name, string anschrift, string telefon, int persNr, double stundenlohn, string fuehrerscheinklasse, Warteschlange* queue);

    void druckeLieferschein(Bestellung* b); // Methode zum Drucken des Lieferscheins
    void liefern(Bestellung* b); // Methode zur Lieferung einer Bestellung
    bool kassieren(Rechnung* r, double betrag); // Methode zur Kassierung
};