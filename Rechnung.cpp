#include "Rechnung.h"

// Konstruktor
Rechnung::Rechnung(Bestellung* b) {
    this->bestellung = b; // Bestellung zuweisen
    if (bestellung != nullptr) {
        this->betrag = bestellung->berechneSumme(); // Betrag berechnen
    }
    else {
        this->betrag = 0.0; // Betrag auf 0 setzen, wenn keine Bestellung vorhanden ist
    }
}

// Getter f�r den Betrag
double Rechnung::getBetrag() {
    return betrag; // R�ckgabe des Betrags
}