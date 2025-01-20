#include "Servicekraft.h"

int Servicekraft::kundennr = 1000; // Initialisierung der statischen Kundennummer

Servicekraft::Servicekraft(string name, string anschrift, string telefon, int persNr, double monatsgehalt, Warteschlange* queue, std::list<Pizza*> karte)
    : Festangestellter(name, anschrift, telefon, persNr, monatsgehalt) {
    this->queue = queue;
    this->karte = karte;
}

Kunde* Servicekraft::registriereKunde() {
    // Registrierung eines neuen Kunden
    int kn = kundennr;
    Kunde* neuKunde = new Kunde("Norbert", "Wallenhorst", "06737872836387", kn);
    kundennr++; // Erhöhung der Kundennummer für den nächsten Kunden
    return neuKunde;
}

void Servicekraft::beauftrageKoch(Bestellung* b) {
    // Beauftragung des Kochs mit der Bestellung
    if (queue->getGeoeffnet() && queue->getAnzahlBestellungen() < queue->getMaxBestellungen()) {
        queue->einfuegen(b); // Bestellung zur Warteschlange hinzufügen
    }
}

Bestellung* Servicekraft::aufnehmenBestellung() {
    // Aufnehmen einer Bestellung
    Bestellung* bestellung = new Bestellung();
    char antwort;

    do {
        cout << "Welche Pizza wollen Sie bestellen? --> Margherita \n"
            << "Margherita -> 1 \n"
            << "Hawaii -> 2 \n"
            << "Funghi -> 3 \n"
            << "Vegetaria -> 4" << endl;

        int pNR = 1; // Beispielhafte Pizza-Nummer
        cout << "Wie viele von diesen Pizzen? 2x" << endl;

        int menge = 2; // Beispielhafte Menge

        bestellung->hinzufuegenBestellposition(Pizza::getPizza(pNR, karte), menge);
        cout << "Wollen Sie noch eine Pizza bestellen? (j/n) --> n" << endl;

        antwort = 'n'; // Beispielhafte Antwort
    } while (antwort != 'n');

    cout << "Vielen Dank fuer Ihre Bestellung!" << endl << endl;
    return bestellung; // Rückgabe der aufgenommenen Bestellung
}

void Servicekraft::run() {
    // Aufnehmen neuer Bestellungen solange die Warteschlange geöffnet ist
    while (queue->getGeoeffnet() && queue->getAnzahlBestellungen() < queue->getMaxBestellungen()) {
        queue->einfuegen(aufnehmenBestellung()); // Neue Bestellung aufnehmen und zur Warteschlange hinzufügen
    }
}