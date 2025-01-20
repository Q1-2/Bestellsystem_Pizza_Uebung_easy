#pragma once
#include "Bestellung.h"

class Rechnung {
private:
    double betrag; // Betrag der Rechnung
    Bestellung* bestellung; // Zeiger auf die zugeh�rige Bestellung

public:
    // Konstruktor, der eine Bestellung entgegennimmt
    Rechnung(Bestellung* b);

    // Getter f�r den Betrag
    double getBetrag();
};

