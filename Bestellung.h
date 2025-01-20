#pragma once
#include <iostream>
#include <list>
#include "Date.h"
#include "Bestellposition.h"

using namespace std;

class Bestellung {
private:
    int bestellNr; // Eindeutige Bestellnummer
    Date* datum; // Datum der Bestellung
    static int nrGlobal; // Globale Bestellnummer, um eindeutige Bestellnummern zu generieren
    int posNr; // Positionnummer für Bestellpositionen
    Bestellung* naechste; // Zeiger auf die nächste Bestellung

    list<Bestellposition*> positionen; // Eine Bestellung besteht aus Bestellpositionen

public:
    Bestellung(); // Standardkonstruktor
    ~Bestellung(); // Destruktor zum Freigeben von Ressourcen

    void hinzufuegenBestellposition(Pizza* pizza, int menge); // Fügt eine Bestellposition hinzu
    double berechneSumme(); // Berechnet die Gesamtsumme der Bestellung

    void setNaechste(Bestellung* naechste); // Setzt die nächste Bestellung
    Bestellung* getNaechste(); // Gibt die nächste Bestellung zurück

    string toString(); // Gibt eine string-Repräsentation der Bestellung zurück
};