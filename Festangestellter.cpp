#include "Festangestellter.h"

Festangestellter::Festangestellter(string name, string anschrift, string telefon, int persNr, double monatsgehalt)
	: Mitarbeiter(name, anschrift, telefon, persNr)
{
	this->monatsgehalt = monatsgehalt;
}
