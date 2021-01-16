#pragma once
#include <fstream>
#include <iostream>
#include<string>
#include "helpersCRUD.h"
#include "sala.h"
using namespace std;

string optiuniSali = "1 - Afiseaza toate salile disponibile\n2 - Adauga o sala\n3 - Cauta o sala dupa id - ul unic\n4 - Actualizeaza o sala\n5 - Sterge o sala\n0 - Revino la meniul anterior\n";
int nrOptiuniSali = 6; //nu include optiunea de returnare la meniul anterior (0)
string fileSali = "sali.bin";

int ruleazaMeniuSala(string optiuniSali, int nrOptiuni)
{
	int optiune = 0;
	cout << endl << optiuniSali;
	cin >> optiune;
	while (optiune > nrOptiuni || optiune < 0)
	{
		cout << "Te rog introdu o optiune valida!" << endl;
		cout << optiuniSali;
		cin >> optiune;
	}
	return optiune;
}
int meniuAnteriorSala()
{
	cout << endl << "Vrei sa revii la meniul anterior?" << endl << endl << "1 - Da" << endl << "0 - Nu" << endl;
	int tmp = 0;
	do
	{
		cin >> tmp;
		if (tmp == 0 || tmp == 1) return tmp;
	} while (tmp != 0 && tmp != 1);
}

void meniuSala()
{
	int optiune;
	string buffer;
	int nrSala = citesteTotalSaliInt("Total.txt");
	do
	{
		optiune = ruleazaMeniuSala(optiuniSali, nrOptiuniSali);
		{
			switch (optiune) {
			case 0:
				break;
			case 1:
			{
				afisareSali(nrSala, fileSali);
				if (meniuAnteriorSala() != 1) optiune = 0;
			}
			break;
			case 2:

				adaugaSala(adaugaSalaConsola(), nrSala, fileSali);
				modificaSali(nrSala, "Total.txt");
				if (meniuAnteriorSala() != 1) optiune = 0;
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
				cout << endl << gasesteSala(stringToInt(buffer), nrSala, fileSali);
				if (meniuAnteriorSala() != 1) optiune = 0;
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
				cout << gasesteSala(stringToInt(buffer), nrSala, fileSali) << endl;
				cout << "Introdu noile atribute pentru alimentul selectat: " << endl;
				actualizareSala(stringToInt(buffer), adaugaSalaConsola(), nrSala, fileSali);
				if (meniuAnteriorSala() != 1) optiune = 0;
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
				stergeSala(stringToInt(buffer), nrSala, fileSali);
				modificaAlimente(nrSala, "Total.txt");
				if (meniuAnteriorSala() != 1) optiune = 0;
				break;
			deafult:
				break;
			}
		}
	} while (optiune != 0);
}