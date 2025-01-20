#pragma once
#include "Person.h"

class Mitarbeiter : public Person
{
protected:
	int persNr;

public:
	Mitarbeiter(string name, string anschrift, string telefon, int persNr);
	bool anmelden(string user, string pw);
};

