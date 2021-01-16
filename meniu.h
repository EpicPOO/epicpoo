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

void meniu()
{
	if (testareExistentaFisiere() == 0)
	{
		cout << "Baza de date are probleme";
	}
	else
	{
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
					case 1:
						//film
						meniuFilm();
						break;
					case 2:
						meniuSala();
						//sala
						break;
					case 3:
						//bilete
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
		} while (alegereCategorie != 1 || alegereCategorie != 2);
	}
}

