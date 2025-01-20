#pragma once
#include <iostream>
#include <string>
#include "Pizza.h"
using namespace std;

class Bestellposition
{
private:
	int _posNr;
	int _menge;
	Pizza* _pizza;

public:
// ToDo
	Pizza* getPizza() const;
	int getMenge() const;

	// toString-Methode für die Bestellposition
	std::string toString() {
		//return "Position: " + to_string(_posNr) + ", Pizza: " + _pizza->getBezeichnung() + ", Menge: " + to_string(_menge);
		return " "; // für die bessere Übersicht
	}
};

