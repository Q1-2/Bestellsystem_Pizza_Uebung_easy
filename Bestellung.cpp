
#include "Bestellung.h"

// ToDo // Initialisierung der statischen Variablen

Bestellung::Bestellung() {
    // ToDo
}

Bestellung::~Bestellung() {
    // Ressourcen freigeben
    delete datum; // Datum freigeben
    for (Bestellposition* p : positionen) {
        delete p; // Alle Bestellpositionen freigeben
    }
}

void Bestellung::hinzufuegenBestellposition(Pizza* pizza, int menge) {
    // ToDo
}

double Bestellung::berechneSumme() {
    // ToDo
    return 0;
}

void Bestellung::setNaechste(Bestellung* naechste) {
    this->naechste = naechste; // Nächste Bestellung setzen
}

Bestellung* Bestellung::getNaechste() {
    return naechste; // Nächste Bestellung zurückgeben
}

//string Bestellung::toString() {
//    string text = "Bestellnummer: " + to_string(bestellNr) + "\n";
//    text += "Datum: " + datum->getStringDatum() + "\n"; // Datum hinzufügen
//    text += "Bestellpositionen:\n";
//
//    for (Bestellposition* p : positionen) {
//        text += p->toString() + "\n"; // Jede Bestellposition zur Ausgabe hinzufügen
//    }
//
//    text += "Gesamtsumme: " + to_string(berechneSumme()) + "\n"; // Gesamtsumme hinzufügen
//    return text; // Rückgabe der string-Repräsentation
//}

string Bestellung::toString() {
    
    return to_string(bestellNr);
}