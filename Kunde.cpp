#include "Kunde.h"

// Konstruktor
Kunde::Kunde(string name, string anschrift, string telefon, int kundenNr)
    : Person(name, anschrift, telefon) {
    this->kundenNr = kundenNr; // Kundennummer zuweisen
}

void Kunde::aufgebenBestellung() {
    // Wenn der Kunde noch keine Kundennummer hat, wird er registriert
    if (this->kundenNr == 0) {
        servicekraft->registriereKunde();
    }

    // Erstellen einer neuen Bestellung
    Bestellung* b = new Bestellung();

    // Hinzuf�gen einer Bestellposition (z.B. 3 Pizzen vom Typ 1)
    b->hinzufuegenBestellposition(Pizza::getPizza(1, karte), 3); // Beispielhafte Pizza
}

double Kunde::bezahlen(Rechnung* r) {
    // �berpr�fen, ob die Rechnung g�ltig ist
    if (r != nullptr) {
        return r->getBetrag(); // R�ckgabe des Betrags der Rechnung
    }
    return 0.0; // R�ckgabe 0, wenn die Rechnung ung�ltig ist
}