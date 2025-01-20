#pragma once
#include <iostream>
#include "Bestellung.h"

using namespace std;

class Warteschlange {
private:
    int anzahlBestellungen; // Aktuelle Anzahl der Bestellungen in der Warteschlange
    int maxBestellungen;    // Maximale Anzahl der Bestellungen, die die Warteschlange halten kann
    bool geoeffnet;         // Gibt an, ob die Warteschlange geöffnet ist
    Bestellung* anfang;     // Zeiger auf die erste Bestellung in der Warteschlange
    Bestellung* ende;       // Zeiger auf die letzte Bestellung in der Warteschlange

public:
    // Konstruktor
    Warteschlange(int maxBestellungen);

    // Methoden
    bool einfuegen(Bestellung* neu); // Fügt eine neue Bestellung in die Warteschlange ein
    Bestellung* entnehmen();           // Entfernt und gibt die erste Bestellung zurück
    void schließen();                  // Schließt die Warteschlange

    // Getter-Methoden
    bool getGeoeffnet();
    int getAnzahlBestellungen();
    int getMaxBestellungen();
    Bestellung* getEnde();

    // Ausgabe der Warteschlange (nicht in der Abi-Aufgabenstellung enthalten)
    void ausgabeListe();
};