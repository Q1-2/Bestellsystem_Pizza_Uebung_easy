#pragma once
#include <iostream>
#include "List.h"
using namespace std;

class Pizza
{
private:
	int _pizzaNr;
	string _bezeichnung;
	double _preis;

public:
	Pizza(int pizzaNr, string bezeichnung, double preis);
	int getPizzaNr() const;
	double getPreis() const;
	static Pizza* getPizza(int nr, list<Pizza*> karte);
	string getBezeichnung() const;
};

