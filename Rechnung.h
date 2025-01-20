#pragma once
#include "Bestellung.h"

class Rechnung {
private:
    double betrag; // Betrag der Rechnung
    Bestellung* bestellung; // Zeiger auf die zugehörige Bestellung

public:
    // Konstruktor, der eine Bestellung entgegennimmt
    Rechnung(Bestellung* b);

    // Getter für den Betrag
    double getBetrag();
};

