#pragma once
#include <fstream>
#include <iostream>
#include<string>
#include "helpersCRUD.h"
#include "film.h"
using namespace std;

string optiuniFilme = "1 - Afiseaza toate filme disponibile\n2 - Adauga un film\n3 - Cauta un film dupa id - ul unic\n4 - Actualizeaza un film\n5 - Sterge un film\n0 - Revino la meniul anterior\n";
int nrOptiuniFilme = 5; //nu include optiunea de returnare la meniul anterior (0)
string fileFilm = "filme.bin";

int ruleazaMeniuFilm(string optiuniFilme, int nrOptiuni)
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
int meniuAnteriorFilm()
{
	cout << endl << "Vrei sa revii la meniul anterior?" << endl << endl << "1 - Da" << endl << "0 - Nu" << endl;
	int tmp = 0;
	do
	{
		cin >> tmp;
		if (tmp == 0 || tmp == 1) return tmp;
	} while (tmp != 0 && tmp != 1);
}

void meniuFilm()
{
	int optiune;
	string buffer;
	int nrFilm = citesteTotalFilmeInt("Total.txt");
	do
	{
		optiune = ruleazaMeniuFilm(optiuniFilme, nrOptiuniFilme);
		{
			switch (optiune) {
			case 0:
				break;
			case 1:
			{
				if (testTipFisier(fileFilm) == 1)
				{
					afisareFilme(nrFilm, fileFilm);
				}
				else cout << "Nu exista filme salvate.\n";
				if (meniuAnteriorFilm() != 1) optiune = 0;
			}
			break;
			case 2:
				adaugaFilm(adaugaFilmConsola(), nrFilm, fileFilm);
				modificaFilme(nrFilm, "Total.txt");
				if (meniuAnteriorFilm() != 1) optiune = 0;
				break;
			case 3:
				cout << "Introdu id-ul filmului: ";
				cin >> ws;
				getline(cin, buffer);
				while (stringToInt(buffer) == 0)
				{
					cout << "Id-ul introdus nu este valid. Introdu un id valid (numar intreg pozitiv): ";
					getline(cin, buffer);
				}
				if (gasesteFilm(stringToInt(buffer), nrFilm, fileFilm).getNumeFilm() == "Negasit") cout << endl << "Filmul nu a fost gasit.";
				else cout << endl << gasesteFilm(stringToInt(buffer), nrFilm, fileFilm);
				if (meniuAnteriorFilm() != 1) optiune = 0;
				break;
			case 4:
				cout << "Introdu id-ul filmului pe care vrei sa il actualizezi: ";
				cin >> ws;
				getline(cin, buffer);
				while (stringToInt(buffer) == 0)
				{
					cout << "Id-ul introdus nu este valid. Introdu un id valid (numar intreg pozitiv): ";
					getline(cin, buffer);
				}
				if (gasesteFilm(stringToInt(buffer), nrFilm, fileFilm).getNumeFilm() == "Negasit") cout << endl << "Filmul nu a fost gasit.";
				else
				{
					cout << "Filmul curent este: " << endl;
					cout << gasesteFilm(stringToInt(buffer), nrFilm, fileFilm) << endl;
					cout << "Introdu noile atribute pentru filmul selectat: " << endl;
					actualizareFilm(stringToInt(buffer), adaugaFilmConsola(), nrFilm, fileFilm);
				}
				if (meniuAnteriorFilm() != 1) optiune = 0;
				break;
			case 5:
				cout << "Introdu id-ul filmului pe care vrei sa il stergi: ";
				cin >> ws;
				getline(cin, buffer);
				while (stringToInt(buffer) == 0)
				{
					cout << "Id-ul introdus nu este valid. Introdu un id valid (numar intreg pozitiv): ";
					getline(cin, buffer);
				}
				if (gasesteFilm(stringToInt(buffer), nrFilm, fileFilm).getNumeFilm() == "Negasit") cout << endl << "Filmul nu a fost gasit.";
				else
				{
					stergeFilm(stringToInt(buffer), nrFilm, fileFilm);
					modificaFilme(nrFilm, "Total.txt");
				}
				if (meniuAnteriorFilm() != 1) optiune = 0;
				break;
			deafult:
				break;
			}
		}
	} while (optiune != 0);
}