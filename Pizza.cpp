#include "Pizza.h"

Pizza::Pizza(int pizzaNr, string bezeichnung, double preis)
	: _pizzaNr(pizzaNr), _bezeichnung(bezeichnung), _preis(preis) {}


int Pizza::getPizzaNr() const
{
	return _pizzaNr;
}

double Pizza::getPreis() const
{
	return _preis;
}

Pizza* Pizza::getPizza(int nr, list<Pizza*> karte)
{
	for (Pizza* i : karte)
	{
		if (i->getPizzaNr() == nr)
			return i;

	}
	return nullptr;
}

string Pizza::getBezeichnung() const
{
	return _bezeichnung;
}
