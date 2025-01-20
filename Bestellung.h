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
    int posNr; // Positionnummer f�r Bestellpositionen
    Bestellung* naechste; // Zeiger auf die n�chste Bestellung

    list<Bestellposition*> positionen; // Eine Bestellung besteht aus Bestellpositionen

public:
    Bestellung(); // Standardkonstruktor
    ~Bestellung(); // Destruktor zum Freigeben von Ressourcen

    void hinzufuegenBestellposition(Pizza* pizza, int menge); // F�gt eine Bestellposition hinzu
    double berechneSumme(); // Berechnet die Gesamtsumme der Bestellung

    void setNaechste(Bestellung* naechste); // Setzt die n�chste Bestellung
    Bestellung* getNaechste(); // Gibt die n�chste Bestellung zur�ck

    string toString(); // Gibt eine string-Repr�sentation der Bestellung zur�ck
};