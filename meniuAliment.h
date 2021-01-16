#pragma once
#include <fstream>
#include <iostream>
#include<string>
#include "helpersCRUD.h"
#include "aliment.h"
using namespace std;

string optiuniAlimente = "1 - Afiseaza toate alimentele disponibile\n2 - Adauga un aliment\n3 - Cauta un aliment dupa id - ul unic\n4 - Actualizeaza un aliment\n5 - Sterge un aliment\n0 - Revino la meniul anterior\n";
int nrOptiuni = 5; //nu include optiunea de returnare la meniul anterior (0)
string fileAliment = "Aliment.bin";

int ruleazaMeniu(string optiuniAlimente, int nrOptiuni)
{
	int optiune = 0;
	cout << endl << optiuniAlimente;
	cin >> optiune;
	while (optiune > nrOptiuni || optiune < 0)
	{
		cout << "Te rog introdu o optiune valida!" << endl;
		cout << optiuniAlimente;
		cin >> optiune;
	}
	return optiune;
}
int meniuAnterior()
{
	cout<<endl << "Vrei sa revii la meniul anterior?" << endl << endl << "1 - Da" << endl << "0 - Nu" << endl;
	int tmp = 0;
	do
	{
		cin >> tmp;
		if (tmp == 0 || tmp == 1) return tmp;
	} while (tmp != 0 && tmp != 1);
}

void meniuAliment()
{
	int optiune;
	string buffer;
	int nrAlim = citesteTotalAlimenteInt("Total.txt");
	do
	{
		optiune = ruleazaMeniu(optiuniAlimente, nrOptiuni);
		{
			switch (optiune) {
			case 0:
				break;
			case 1:
			{
				afisareAlimente(nrAlim, fileAliment);
				if (meniuAnterior() != 1) optiune = 0;
			}
				break;
			case 2:
				
				adaugaAliment(adaugaAlimentConsola(), nrAlim, fileAliment);
				modificaAlimente(nrAlim,"Total.txt");
				if (meniuAnterior() != 1) optiune = 0;
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
				cout<<endl<<gasesteAliment(stringToInt(buffer), nrAlim, fileAliment);
				if (meniuAnterior() != 1) optiune = 0;
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
				cout << gasesteAliment(stringToInt(buffer), nrAlim, fileAliment) << endl;
				cout << "Introdu noile atribute pentru alimentul selectat: " << endl;
				actualizareAliment(stringToInt(buffer), adaugaAlimentConsola(), nrAlim, fileAliment);
				if (meniuAnterior() != 1) optiune = 0;
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
				stergeAliment(stringToInt(buffer), nrAlim, fileAliment);
				modificaAlimente(nrAlim, "Total.txt");
				if (meniuAnterior() != 1) optiune = 0;
				break;
			deafult:
				break;
			}
		}
	} while (optiune != 0);
}