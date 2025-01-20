#include "Warteschlange.h"

Warteschlange::Warteschlange(int maxBestellungen) {
    this->maxBestellungen = maxBestellungen;
    anfang = nullptr;
    ende = nullptr;
    geoeffnet = true;
    anzahlBestellungen = 0;
}

bool Warteschlange::einfuegen(Bestellung* neu) {
    // ToDo

    return false; // Warteschlange geschlossen oder maximale Kapazit�t erreicht
}

Bestellung* Warteschlange::entnehmen() {
 // ToDo
    return nullptr;
}

void Warteschlange::schlie�en() {
    geoeffnet = false; // Warteschlange schlie�en
}

bool Warteschlange::getGeoeffnet() {
    return geoeffnet; // Gibt zur�ck, ob die Warteschlange ge�ffnet ist
}

int Warteschlange::getAnzahlBestellungen() {
    return anzahlBestellungen; // Gibt die Anzahl der Bestellungen zur�ck
}

int Warteschlange::getMaxBestellungen() {
    return maxBestellungen; // Gibt die maximale Anzahl der Bestellungen zur�ck
}

Bestellung* Warteschlange::getEnde() {
    return ende; // Gibt die letzte Bestellung zur�ck
}

// Ausgabe der Warteschlange (nicht in der Abi-Aufgabenstellung enthalten)
void Warteschlange::ausgabeListe() {
    Bestellung* cursor = anfang;
    cout << "Warteliste-Anfang: BestellNr ";
    while (cursor != nullptr) {
        cout << cursor->toString() << " "; // Ausgabe der Bestellnummer
        cursor = cursor->getNaechste(); // N�chste Bestellung
    }
    cout << "Warteliste-Ende" << endl; // Ende der Warteschlange
}
