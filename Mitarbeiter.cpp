#include "Mitarbeiter.h"

Mitarbeiter::Mitarbeiter(string name, string anschrift, string telefon, int persNr) : Person(name, anschrift, telefon)
{
	this->persNr = persNr;
}

bool Mitarbeiter::anmelden(string user, string pw)		//damit sich Mitarbeiter anmelden können
{
	if (name == user && pw == anschrift)
		return true;

	else return false;
}
