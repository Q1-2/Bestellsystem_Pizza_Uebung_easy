#pragma once
#include "Mitarbeiter.h"

class Aushilfskraft : public Mitarbeiter
{
protected: 
	double stundenlohn;

public:
	Aushilfskraft(string name, string anschrift, string telefon, int persNr, double stundenlohn);
};

