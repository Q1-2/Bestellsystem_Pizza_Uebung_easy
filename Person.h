#pragma once
#include <iostream>
using namespace std;

class Person
{
protected:
	string name;
	string anschrift;
	string telefon;

public:
	Person(string name, string anschrift, string telefon);
};

