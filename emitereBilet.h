#pragma once
#include<iostream>
#include<string>
#include<fstream>

#include "helpersCRUD.h"
#include "aliment.h"
#include "bilet.h"
#include "film.h"
#include "sala.h"

int selectiefilm() //returneaza id-ul filmului din fisier //done, tested
{
	film f;
	string fileTotal = "Total.txt";
	string fileFilm = "Filme.bin";
	int nrFilme = citesteTotalFilmeInt(fileTotal);
	int id=0;
	cout << "Filmele disponibile sunt: " << endl;
	//afisare filme pentru selectie
	afisareFilme(nrFilme, fileFilm);
	do
	{
		string buffer;
		cout << endl << "Alege filmul introducand id-ul: ";
		cin >> ws;
		getline(cin, buffer);
		while (stringToInt(buffer) == 0)
		{
			cout << "Id-ul introdus nu este valid. Reintrodu id-ul: ";
			cin >> ws;
			getline(cin, buffer);
		}
		id = stringToInt(buffer);
		f = gasesteFilm(id, nrFilme, fileFilm);
		if (f.getNumeFilm() == "Negasit") cout << "Filmul cu id-ul introdus nu a fost gasit." << endl;
	} while (f.getNumeFilm() == "" || f.getNumeFilm() == "Negasit");
	return id;
}
int selectieProgramFilm(film f) //indexul stringului din program ales //done, testat
{
	int nrRulari = f.getNrRulari();
	string* program = new string[nrRulari];
	program = f.getProgram();
	cout << "Programul pentru disponibil pentru filmul " << f.getNumeFilm() << " este: ";
	for (int i = 0; i < nrRulari; i++)
	{
		cout << i + 1 << " - " << program[i] << endl;
	}
	cout << "Alege una din optiuni: ";
	string buffer;
	getline(cin, buffer);
	while (stringToInt(buffer) == 0 || stringToInt(buffer)>nrRulari)
	{
		cout << "Optiunea introdusa nu este valid. Alege optiunea: ";
		cin >> ws;
		getline(cin, buffer);
	}
	return stringToInt(buffer) - 1;
}
int selectieSala() //returneaza id-ul salii //done, testat
{
	sala s;
	string fileTotal = "Total.txt";
	string fileSala = "Sali.bin";
	int nrSali = citesteTotalSaliInt(fileTotal);
	int id = 0;
	cout << endl << "Salile disponinbile sunt: " << endl;
	afisareSali(nrSali, fileSala);
	cout << endl;
	do
	{
		string buffer;
		cout << endl << "Alege sala introducand id-ul: ";
		cin >> ws;
		getline(cin, buffer);
		while (stringToInt(buffer) == 0)
		{
			cout << "Id-ul introdus nu este valid. Reintrodu id-ul: ";
			cin >> ws;
			getline(cin, buffer);
		}
		id = stringToInt(buffer);
		s = gasesteSala(id, nrSali, fileSala);
		if (s.getNumeSala() == "Negasit") cout << "Sala cu id-ul introdus nu a fost gasita." << endl;
	} while (s.getNumeSala() == "" || s.getNumeSala() == "Negasit");
	return id;
}
int selectieNrLocuri(sala s) //returneaza nr de locuri alese //done, testat
{
	string buffer;
	cout << endl << "Sunt " << s.getNrLibere() << " locuri libere." << endl << "Introdu numarul de locuri: ";
	cin >> ws;
	getline(cin, buffer);
	while (stringToInt(buffer) <= 0 && stringToInt(buffer) > s.getNrLibere())
	{
		cout << "Numarul de locuri trebuie sa fie un numar intrg mai mare decat 0 si mai mic decat " << s.getNrLibere() << "."
			<< endl << "Reintrodu numarul de locuri: ";
		cin >> ws;
		getline(cin, buffer);
	}
	return stringToInt(buffer);
}

int* selectieLocuri(sala s, int nrLocuri) //returneaza vectorul de locuri alese //done, testat
{
	string fileTotal = "Total.txt";
	string fileSala = "Sali.bin";
	string buffer;
	sala sCopie = s;
	int* locuri = new int[nrLocuri]; //locurile selectate
	cout << endl << "Locurile disponibile sunt: ";
	int nrLocuriSala = s.getTotalSala();
	int* locuriSala = new int[nrLocuriSala];
	locuriSala = s.getTotalLocuri();
	for (int i = 0; i < s.getTotalSala(); i++)
	{
		if (locuriSala[i] == 0) cout << i+1 << " ";
	}
	cout << endl << "Introdu locurile alese din cele disponibile: ";
	for (int i = 0; i < nrLocuri; i++)
	{
		cout << endl << "Introdu locul (" << i+1 << "): ";
		cin >> ws;
		getline(cin, buffer);
		do
		{
			while (stringToInt(buffer) == 0 || stringToInt(buffer) > nrLocuriSala+1 || locuriSala[stringToInt(buffer)-1] != 0)
			{
				cout << "Locul trebuie sa fie un intreg pozitiv dintre cele disponibile. Reintrodu locul: ";
				cin >> ws;
				getline(cin, buffer);
			}
			for (int j = 0; j <= i; j++)
			{
				if (locuri[j] == (stringToInt(buffer)))
				{
					buffer = "gresit";
					cout << endl << "Ai ales deja acest loc." << endl;
				}
			}
		} while (buffer == "gresit");
		locuri[i] = stringToInt(buffer);
	}
	cout << "Ai ales locurile ";
	for (int i = 0; i < nrLocuri -1; i++)
	{
		cout<< locuri[i] << ", ";
	}
	cout << locuri[nrLocuri - 1] << "." << endl;
	for (int j = 0; j < nrLocuri; j++)
	{
		int loc = locuri[j];
		locuriSala[loc -1] = loc;
	}
	sCopie.setTotalLocuri(locuriSala, nrLocuriSala);
	int nrCump = sCopie.getNrCumparate();
	sCopie.setNrCumparate(nrCump+nrLocuri);
	actualizareSala(s.getIdSala(), sCopie,citesteTotalSaliInt(fileTotal),fileSala);
	return locuri;
}

void emitereBilet()
{
	string fileTotal = "Total.txt";
	string fileBilet = "Bilete.bin";
	string fileSala = "Sali.bin";
	string fileFilme = "Filme.bin";
	if (testTipFisier(fileSala) == 0)
	{
		cout << "Nu exista sali salvate in fisier.\n";
	}

	if (testTipFisier(fileFilm) == 0)
	{
		cout << "Nu exista filme salvate in fisier.\n";
	}
	if(testTipFisier(fileSala) == 0 || testTipFisier(fileFilm) == 0)
	
	{
		cout << "Nu se poate emite bilet.\n";
	}
	else
	{
		bilet b;

		int nrTotalFilme = citesteTotalFilmeInt(fileTotal);
		int nrBilete = citesteTotalBileteInt(fileTotal);
		int nrTotalSali = citesteTotalSaliInt(fileTotal);
		string buffer;

		int idFilm = selectiefilm();
		film f = gasesteFilm(idFilm, nrTotalFilme, fileFilme);

		int idSala = selectieSala();
		sala s = gasesteSala(idSala, nrTotalSali, fileSala);
		int oraBilet = selectieProgramFilm(f);


		int nrLocuri = selectieNrLocuri(s);
		int* locuri = new int[nrLocuri];
		locuri = selectieLocuri(s, nrLocuri);
		cout << "Introdu pretul biletului: ";
		getline(cin, buffer);
		while (stringToInt(buffer) == 0)
		{
			cout << "Pretul introdus nu este valid. Te rog sa pretul total al biletului: " << endl;
			getline(cin, buffer);
		}
		cout << endl;
		int nrRulari = f.getNrRulari();
		string* program = new string[nrRulari];
		program = f.getProgram();
		string oraSelectata = program[oraBilet];

		b.setNumeBilet(f.getNumeFilm());
		b.setNrLocuri(nrLocuri);
		b.setLocuriBilet(locuri, nrLocuri);
		b.setOraBilet((char*)oraSelectata.c_str());
		b.setPretTotal(stof(buffer)); //pret in float

		adaugaBilet(b, nrBilete, fileBilet);
		modificaBilete(nrBilete, fileTotal);
		adaugaBiletTxt(b.getIdBilet(), nrBilete, fileBilet);
	}
	
}
