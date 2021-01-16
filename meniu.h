#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "helpersCRUD.h"
#include "meniuSala.h"
#include "meniuAliment.h"
#include "meniuFilm.h"
#include "meniuBilet.h"
#include "meniuAngajat.h"

using namespace std;

string optiuniUtilizatore = "1 - Film\n2 - Sala\n3 - Bilete\n4 - Aliment\n5 - Angajat\n0 - Revino la meniul anterior\n";
int nrOptiuniUtilizator = 5; //nu include optiunea de returnare la meniul anterior (0)

int ruleazaMeniuUtilizator(string optiuniUtilizator, int nrOptiuniUtilizator)
{
	int optiune = 0;
	cout << endl << optiuniUtilizatore;
	cin >> optiune;
	while (optiune > nrOptiuni || optiune < 0)
	{
		cout << "Te rog introdu o optiune valida!" << endl;
		cout << optiuniUtilizatore;
		cin >> optiune;
	}
	return optiune;
}
int meniuAnteriorUtilizator()
{
	cout << endl << "Vrei sa revii la meniul anterior?" << endl << endl << "1 - Da" << endl << "0 - Nu" << endl;
	int tmp = 0;
	do
	{
		cin >> tmp;
		if (tmp == 0 || tmp == 1) return tmp;
	} while (tmp != 0 && tmp != 1);
}

void meniu()
{
	if (testareExistentaFisiere() == 0)
	{
		cout << "Baza de date are probleme";
	}
	else
	{

		int optiune;
		string buffer;
		
		int alegereCategorie = 0;
		int alegereSubmeniu1 = 0;
		do
		{
			cout << "Alegeti!" << endl << "1. Client" << endl;
			cout << "2. Utilizator" << endl;
			cin >> alegereCategorie;
			switch (alegereCategorie)
			{
			case 1:
				break;
			case 2:
			{
				do
				{
					optiune = ruleazaMeniuUtilizator(optiuniFilme, nrOptiuniFilme);
					{
						switch (optiune) {
						case 0:
							break;
						case 1: //film
						{
							meniuFilm();
							if (meniuAnteriorFilm() != 1) optiune = 0;
						}
						break;
						case 2://sala
						{
							meniuSala();
							if (meniuAnteriorFilm() != 1) optiune = 0;
						}
						break;

						case 3://bilet
						{
							meniuBilet();
							if (meniuAnteriorFilm() != 1) optiune = 0;
						}
						break;
						case 4: //aliment
						{
							meniuAliment();
							if (meniuAnteriorFilm() != 1) optiune = 0;
						}
						break;
						case 5://angajat
						{
							meniuAngajat();
							if (meniuAnteriorFilm() != 1) optiune = 0;
						}
						break;
					deafult:
						break;
						}
					}
				} while (optiune != 0);
			}
			}
		} while (alegereCategorie != 1 || alegereCategorie != 2);

		/*
		cout << endl << "1. Client" << endl;
		cout << "2. Utilizator" << endl;
		int alegereCategorie = 0;
		int alegereSubmeniu1 = 0;
		cin >> alegereCategorie;
		do
		{
			switch (alegereCategorie)
			{
			case 1:
				break;
			case 2:
			{
				cout << endl << "1. Film" << endl;
				cout << "2. Sala" << endl;
				cout << "3. Bilet" << endl;
				cout << "4. Aliment" << endl;
				cout << "5. Angajat" << endl;
				cout << "6. Inapoi" << endl;
				cin >> alegereSubmeniu1;
				do
				{
					switch (alegereSubmeniu1)
					{
					case 1:	//film
						meniuFilm();
						break;
					case 2: //sala
						meniuSala();
						break;
					case 3://bilete
						meniuBilet();
						break;
					case 4:
						//aliment
						meniuAliment();
						break;
					case 5:
						//angajat
						meniuAngajat();
						break;
					case 6:
						//intorce la meniul principal
						meniu();
						break;
					default:
						cout << "Ati ales o categorie gresita! Incercati din nou!" << endl;
						cin >> alegereSubmeniu1;
						break;
					}
				} while (alegereSubmeniu1 >= 1 || alegereSubmeniu1 <= 6);
				break;
			}
			default:
				cout << "Ati ales o categorie gresita! Incercati din nou!" << endl;
				cin >> alegereCategorie;
				break;
			}
		}
	}
	*/
	}
}

