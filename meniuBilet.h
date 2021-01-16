#pragma once
#include <fstream>
#include <iostream>
#include<string>
#include "helpersCRUD.h"
#include "bilet.h"
using namespace std;

string optiuniBilete = "1 - Afiseaza toate bilete disponibile\n2 - Adauga un bilet\n3 - Cauta un bilet dupa id - ul unic\n4 - Actualizeaza un bilet\n5 - Sterge un bilet\n0 - Revino la meniul anterior\n";
int nrOptiuniBilete = 5; //nu include optiunea de returnare la meniul anterior (0)
string fileBilete = "bilete.bin";

int ruleazaMeniuBilete(string optiuniFilme, int nrOptiuni)
{
	int optiune = 0;
	cout << endl << optiuniFilme;
	cin >> optiune;
	while (optiune > nrOptiuni || optiune < 0)
	{
		cout << "Te rog introdu o optiune valida!" << endl;
		cout << optiuniFilme;
		cin >> optiune;
	}
	return optiune;
}
int meniuAnteriorBilet()
{
	cout << endl << "Vrei sa revii la meniul anterior?" << endl << endl << "1 - Da" << endl << "0 - Nu" << endl;
	int tmp = 0;
	do
	{
		cin >> tmp;
		if (tmp == 0 || tmp == 1) return tmp;
	} while (tmp != 0 && tmp != 1);
}

void meniuBilet()
{
	int optiune;
	string buffer;
	int nrFilm = citesteTotalBileteInt("Total.txt");
	do
	{
		optiune = ruleazaMeniuBilete(optiuniBilete, nrOptiuniBilete);
		{
			switch (optiune) {
			case 0:
				break;
			case 1:
			{
				afisareBilete(nrFilm, fileBilete);
				if (meniuAnteriorBilet() != 1) optiune = 0;
			}
			break;
			case 2:

				adaugaBilet(adaugaBiletConsola(), nrFilm, fileBilete);
				modificaBilete(nrFilm, "Total.txt");
				if (meniuAnteriorBilet() != 1) optiune = 0;
				break;
			case 3:
				cout << "Introdu id-ul alimentului: ";
				cin >> ws;
				getline(cin, buffer);
				while (stringToInt(buffer) == 0)
				{
					cout << "Id-ul introdus nu este valid. Introdu un id valid (numar intreg pozitiv): ";
					getline(cin, buffer);
				}
				cout << endl << gasesteBilet(stringToInt(buffer), nrFilm, fileBilete);
				if (meniuAnteriorBilet() != 1) optiune = 0;
				break;
			case 4:
				cout << "Introdu id-ul alimentului pe care vrei sa il actualizezi: ";
				cin >> ws;
				getline(cin, buffer);
				while (stringToInt(buffer) == 0)
				{
					cout << "Id-ul introdus nu este valid. Introdu un id valid (numar intreg pozitiv): ";
					getline(cin, buffer);
				}
				cout << "Alimentul curent este: " << endl;
				cout << gasesteBilet(stringToInt(buffer), nrFilm, fileBilete) << endl;
				cout << "Introdu noile atribute pentru alimentul selectat: " << endl;
				actualizareBilet(stringToInt(buffer), adaugaBiletConsola(), nrFilm, fileBilete);
				if (meniuAnteriorBilet() != 1) optiune = 0;
				break;
			case 5:
				cout << "Introdu id-ul alimentului pe care vrei sa il stergi: ";
				cin >> ws;
				getline(cin, buffer);
				while (stringToInt(buffer) == 0)
				{
					cout << "Id-ul introdus nu este valid. Introdu un id valid (numar intreg pozitiv): ";
					getline(cin, buffer);
				}
				stergeBilet(stringToInt(buffer), nrFilm, fileBilete);
				modificaBilete(nrFilm, "Total.txt");
				if (meniuAnteriorBilet() != 1) optiune = 0;
				break;
			deafult:
				break;
			}
		}
	} while (optiune != 0);
}