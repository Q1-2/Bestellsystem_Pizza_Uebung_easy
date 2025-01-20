#include "Aushilfskraft.h"

Aushilfskraft::Aushilfskraft(string name, string anschrift, string telefon, int persNr, double stundenlohn) 
	: Mitarbeiter(name, anschrift, telefon, persNr)
{
	this->stundenlohn = stundenlohn;
}
