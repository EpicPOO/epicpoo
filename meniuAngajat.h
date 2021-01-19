#pragma once
#include <fstream>
#include <iostream>
#include<string>
#include "helpersCRUD.h"
#include "angajati.h"
using namespace std;

string optiuniAngajat = "1 - Afiseaza toti angajatii disponibili\n2 - Adauga un angajat\n3 - Cauta un angajat dupa id - ul unic\n4 - Actualizeaza un angajat\n5 - Sterge un angajat\n0 - Revino la meniul anterior\n";
int nrOptiuniAngajat = 5; //nu include optiunea de returnare la meniul anterior (0)
string fileAngajati = "angajati.bin";

int ruleazaMeniuAngajat(string optiuniAngajati, int nrOptiuni)
{
	int optiune = 0;
	cout << endl << optiuniAngajati;
	cin >> optiune;
	while (optiune > nrOptiuni || optiune < 0)
	{
		cout << "Te rog introdu o optiune valida!" << endl;
		cout << optiuniAngajati;
		cin >> optiune;
	}
	return optiune;
}
int meniuAnteriorAngajat()
{
	cout << endl << "Vrei sa revii la meniul anterior?" << endl << endl << "1 - Da" << endl << "0 - Nu" << endl;
	int tmp = 0;
	do
	{
		cin >> tmp;
		if (tmp == 0 || tmp == 1) return tmp;
	} while (tmp != 0 && tmp != 1);
}

void meniuAngajat()
{
		int optiune;
		string buffer;
		int nrAngajat = citesteTotalAngajatiInt("Total.txt");
		string numeAngajat;
		do
		{
			optiune = ruleazaMeniuAngajat(optiuniAngajat, nrOptiuniAngajat);
			{
				switch (optiune) {
				case 0:
					break;
				case 1:
				{
					if (testTipFisier(fileAngajati) == 1)
					{
						afisareAngajati(nrAngajat, fileAngajati);
					}
					else cout << "Nu exista angajati salvati.\n";
					if (meniuAnteriorAngajat() != 1) optiune = 0;
				}
				break;
				case 2:

					adaugaAngajat(adaugaAngajatConsola(), nrAngajat, fileAngajati);
					modificaAngajati(nrAngajat, "Total.txt");
					if (meniuAnteriorAngajat() != 1) optiune = 0;
					break;
				case 3:
					cout << "Introdu id-ul angajatului: ";
					cin >> ws;
					getline(cin, buffer);
					while (stringToInt(buffer) == 0)
					{
						cout << "Id-ul introdus nu este valid. Introdu un id valid (numar intreg pozitiv): ";
						getline(cin, buffer);
					}
					numeAngajat = gasesteAngajat(stringToInt(buffer), nrAngajat, fileAngajati).getNume();
					if (numeAngajat == "Negasit") cout << endl << "Angajatul nu a fost gasit.";
					else
					cout << endl << gasesteAngajat(stringToInt(buffer), nrAngajat, fileAngajati);
					if (meniuAnteriorAngajat() != 1) optiune = 0;
					break;
				case 4:
					cout << "Introdu id-ul angajatului pe care vrei sa il actualizezi: ";
					cin >> ws;
					getline(cin, buffer);
					while (stringToInt(buffer) == 0)
					{
						cout << "Id-ul introdus nu este valid. Introdu un id valid (numar intreg pozitiv): ";
						getline(cin, buffer);
					}
					numeAngajat = gasesteAngajat(stringToInt(buffer), nrAngajat, fileAngajati).getNume();
					if (numeAngajat == "Negasit")cout << endl << "Angajatul nu a fost gasit.";
					else
					{
						cout << "Angajatul curent este: " << endl;
						cout << gasesteAngajat(stringToInt(buffer), nrAngajat, fileAngajati) << endl;
						cout << "Introdu noile atribute pentru angajatul selectat: " << endl;
						actualizareAngajat(stringToInt(buffer), adaugaAngajatConsola(), nrAngajat, fileAngajati);
					}
					if (meniuAnteriorAngajat() != 1) optiune = 0;
					break;
				case 5:
					cout << "Introdu id-ul angajatului pe care vrei sa il stergi: ";
					cin >> ws;
					getline(cin, buffer);
					while (stringToInt(buffer) == 0)
					{
						cout << "Id-ul introdus nu este valid. Introdu un id valid (numar intreg pozitiv): ";
						getline(cin, buffer);
					}
					numeAngajat = gasesteAngajat(stringToInt(buffer), nrAngajat, fileAngajati).getNume();
					if (numeAngajat == "Negasit")cout << endl << "Angajatul nu a fost gasit.";
					else
					{
						stergeAngajat(stringToInt(buffer), nrAngajat, fileAngajati);
						modificaAngajati(nrAngajat, "Total.txt");
					}
					if (meniuAnteriorAngajat() != 1) optiune = 0;
					break;
				deafult:
					break;
				}
			}
		} while (optiune != 0);
}
