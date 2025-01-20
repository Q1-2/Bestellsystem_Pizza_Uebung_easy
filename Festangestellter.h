#pragma once
#include "Mitarbeiter.h"

class Festangestellter : public Mitarbeiter
{
protected: 
	double monatsgehalt;

public:
	Festangestellter(string name, string anschrift, string telefon, int persNr, double monatsgehalt);
};

