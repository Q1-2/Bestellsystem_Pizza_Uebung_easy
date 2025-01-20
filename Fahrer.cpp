#include "Fahrer.h"

// Konstruktor
Fahrer::Fahrer(string name, string anschrift, string telefon, int persNr, double stundenlohn, string fuehrerscheinklasse, Warteschlange* queue)
    : Aushilfskraft(name, anschrift, telefon, persNr, stundenlohn) {
    this->fuehrerscheinklasse = fuehrerscheinklasse; // F�hrerscheinklasse zuweisen
    this->queue = queue; // Warteschlange zuweisen
}

void Fahrer::druckeLieferschein(Bestellung* b) {
    // TODO: Implementierung der Drucklogik f�r den Lieferschein
    cout << "Drucke Lieferschein f�r: " << b->toString() << endl;
}

void Fahrer::liefern(Bestellung* b) {
    if (b != nullptr) {
        cout << "Lieferung der Bestellung: " << b->toString() << endl;
        queue->entnehmen(); // Bestellung aus der Warteschlange entfernen (als geliefert markieren)
    }
    else {
        cout << "Keine g�ltige Bestellung zum Liefern." << endl; // Fehlerbehandlung f�r ung�ltige Bestellungen
    }
}

bool Fahrer::kassieren(Rechnung* r, double betrag) {
    // �berpr�fen, ob der Betrag mit der Rechnung �bereinstimmt
    if (r != nullptr && r->getBetrag() == betrag) {
        cout << "Zahlung erfolgreich." << endl; // Erfolgreiche Zahlung
        return true;
    }
    else {
        cout << "Zahlung fehlgeschlagen." << endl; // Fehlerbehandlung f�r falsche Betr�ge
        return false;
    }
}