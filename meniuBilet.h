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

int ruleazaMeniuBilete(string optiuniBilete, int nrOptiuni)
{
	int optiune = 0;
	cout << endl << optiuniBilete;
	cin >> optiune;
	while (optiune > nrOptiuni || optiune < 0)
	{
		cout << "Te rog introdu o optiune valida!" << endl;
		cout << optiuniBilete;
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
	int nrBilete = citesteTotalBileteInt("Total.txt");
	do
	{
		optiune = ruleazaMeniuBilete(optiuniBilete, nrOptiuniBilete);
		{
			switch (optiune) {
			case 0:
				break;
			case 1:
			{
				if (testTipFisier(fileBilete) == 1)
				{
					afisareBilete(nrBilete, fileBilete);
				}
				else cout << "Nu exista bilete salvate.\n";
				if (meniuAnteriorBilet() != 1) optiune = 0;
			}
			break;
			case 2:

				adaugaBilet(adaugaBiletConsola(), nrBilete, fileBilete);
				modificaBilete(nrBilete, "Total.txt");
				if (meniuAnteriorBilet() != 1) optiune = 0;
				break;
			case 3:
				cout << "Introdu id-ul biletului: ";
				cin >> ws;
				getline(cin, buffer);
				while (stringToInt(buffer) == 0)
				{
					cout << "Id-ul introdus nu este valid. Introdu un id valid (numar intreg pozitiv): ";
					getline(cin, buffer);
				}
				if (gasesteBilet(stringToInt(buffer), nrBilete, fileBilete).getNumeBilet() == "Negasit") cout << endl << "Biletul nu a fost gasit.";
				else cout << endl << gasesteBilet(stringToInt(buffer), nrBilete, fileBilete);
				if (meniuAnteriorBilet() != 1) optiune = 0;
				break;
			case 4:
				cout << "Introdu id-ul biletului pe care vrei sa il actualizezi: ";
				cin >> ws;
				getline(cin, buffer);
				while (stringToInt(buffer) == 0)
				{
					cout << "Id-ul introdus nu este valid. Introdu un id valid (numar intreg pozitiv): ";
					getline(cin, buffer);
				}
				if (gasesteBilet(stringToInt(buffer), nrBilete, fileBilete).getNumeBilet() == "Negasit")cout << endl << "Biletul nu a fost gasit.";
				else
				{
					cout << "Biletul curent este: " << endl;
					cout << gasesteBilet(stringToInt(buffer), nrBilete, fileBilete) << endl;
					cout << "Introdu noile atribute pentru biletul selectat: " << endl;
					actualizareBilet(stringToInt(buffer), adaugaBiletConsola(), nrBilete, fileBilete);
				}
				if (meniuAnteriorBilet() != 1) optiune = 0;
				break;
			case 5:
				cout << "Introdu id-ul biletului pe care vrei sa il stergi: ";
				cin >> ws;
				getline(cin, buffer);
				while (stringToInt(buffer) == 0)
				{
					cout << "Id-ul introdus nu este valid. Introdu un id valid (numar intreg pozitiv): ";
					getline(cin, buffer);
				}
				if (gasesteBilet(stringToInt(buffer), nrBilete, fileBilete).getNumeBilet() == "Negasit")cout << endl << "Biletul nu a fost gasit.";
				else
				{
					stergeBilet(stringToInt(buffer), nrBilete, fileBilete);
					modificaBilete(nrBilete, "Total.txt");
				}
				if (meniuAnteriorBilet() != 1) optiune = 0;
				break;
			deafult:
				break;
			}
		}
	} while (optiune != 0);
}