#include<iostream>
#include<string>
#include "sala.h"

using namespace std;

int main()
{
															//TESTARE CLASA SALA
	//	test constructor implicit

	sala A;
	cout << "		CONSTRUCTOR IMPLICIT" << endl;
	if (A.getNumeSala() == "") { cout << "Corect Numele Sala" << endl; }			else { cout << "Gresit Numele Sala" << endl; }
	if (A.getTipSala() == nullptr) { cout << "Corect Tip Sala" << endl; }				else { cout << "Gresit Tip Sala" << endl; }
	if (A.getTotalSala() == 0) { cout << "Corect Total Sala" << endl; }				else { cout << "Gresit Total Sala" << endl; }
	if (A.getTotalLocuri() == nullptr) { cout << "Corect Total Locuri" << endl; }	else { cout << "Gresit Total Locuri" << endl; }
	if (A.getNrLibere() == 0) { cout << "Corect Numar Locuri" << endl; }			else { cout << "Gresit Numar Locuri" << endl; }
	if (A.getNrRezervate() == 0) { cout << "Corect Nr Rezervate" << endl; }			else { cout << "Gresit Numar Rezervate" << endl; }
	if (A.getNrCumparate() == 0) { cout << "Corect Nr Cumparate" << endl; }			else { cout << "Gresit Numar Cumparate" << endl; }

	//test counstructor cu parametri
	cout << "		CONSTRUCTOR CU PARAMETRI" << endl;
	int totalSalaMain = 0, nrRezervateMain = 0, nrCumparateMain = 0, nrLocuriOcupate;
	int* locuriAlese = nullptr;

	cout << "Numarul total sala: ";
	cin >> totalSalaMain;
	cout << "Numarul locuri rezervate: ";
	cin >> nrRezervateMain;
	cout << "Numar locuri cumparate de la casa: ";
	cin >> nrCumparateMain;
	nrLocuriOcupate = nrCumparateMain + nrRezervateMain;
	locuriAlese = new int[nrLocuriOcupate];
	cout << "Introduceti scaunele rezervate: " << endl;
	for (int i = 0; i < nrRezervateMain; i++)
	{
		cin >> locuriAlese[i];
		for (int j = 0; j < i; j++)
		{
			if (locuriAlese[j] == locuriAlese[i])
			{
				cout << "Loc Ocupat!" << " Alege altul: " << endl;
				cin >> locuriAlese[i];
			}
		}
	}	
	cout << "Introduceti scaunele cumparate: " << endl;
	for (int i = nrRezervateMain; i < nrLocuriOcupate; i++)
	{
		cin >> locuriAlese[i];
		for (int j = 0; j < i; j++)
		{
			if (locuriAlese[j] == locuriAlese[i])
			{
				cout << "Loc Ocupat!" << " Alege altul: " << endl;
				cin >> locuriAlese[i];
			}
		}
	}
	char tipSalaMain[] = "2D";
	sala B("B", tipSalaMain, totalSalaMain, locuriAlese, nrRezervateMain, nrCumparateMain);
	
	if (B.getNumeSala() == "B") { cout << "Corect Numele Sala" << endl; }					else { cout << "Gresit Numele Sala" << endl; }
	if (B.getTipSala() == "2D") { cout << "Corect Tip Sala" << endl; }						else { cout << "Gresit Tip Sala" << endl; }
	if (B.getTotalSala() == totalSalaMain) { cout << "Corect Total Sala" << endl; }			else { cout << "Gresit Total Sala" << endl; }
	for (int i = 0; i < nrLocuriOcupate; i++)	
	{
		if(B.getTotalLocuri()[i] == locuriAlese[i])
		{
			cout << "Corect Total Locuri" << endl;
		}
		else { cout << "Gresit Total Locuri" << endl; }
	}	
	if (B.getNrLibere() == (totalSalaMain - nrLocuriOcupate)) { cout << "Corect Numar Locuri" << endl; }		else { cout << "Gresit Numar Locuri" << endl; }
	if (B.getNrRezervate() == nrRezervateMain) { cout << "Corect Nr Rezervate" << endl; }	else { cout << "Gresit Numar Rezervate" << endl; }
	if (B.getNrCumparate() == nrCumparateMain) { cout << "Corect Nr Cumparate" << endl; }	else { cout << "Gresit Numar Cumparate" << endl; }
	
	cout << "		CONSTRUCTOR DE COPIERE SI OPERATORUL =" << endl;
	sala C("C", tipSalaMain, totalSalaMain, locuriAlese, nrRezervateMain, nrCumparateMain);

	sala D = C;
	sala E;
	sala F = E = D;
	if (F.getNumeSala() == "C") { cout << "Corect Numele Sala" << endl; }			else { cout << "Gresit Numele Sala" << endl; }
	if (F.getTipSala() == "3D") { cout << "Corect Tip Sala" << endl; }				else { cout << "Gresit Tip Sala" << endl; }
	if (F.getTotalSala() == totalSalaMain) { cout << "Corect Total Sala" << endl; }	else { cout << "Gresit Total Sala" << endl; }
	for (int i = 0; i < nrLocuriOcupate; i++)
	{
		if (F.getTotalLocuri()[i] == locuriAlese[i])
		{
			cout << "Corect Total Locuri" << endl;
		}
		else { cout << "Gresit Total Locuri" << endl; }
	}
	if (F.getNrLibere() == (totalSalaMain - nrLocuriOcupate)) { cout << "Corect Numar Locuri" << endl; }	else { cout << "Gresit Numar Locuri" << endl; }
	if (F.getNrRezervate() == nrRezervateMain) { cout << "Corect Nr Rezervate" << endl; }					else { cout << "Gresit Numar Rezervate" << endl; }
	if (F.getNrCumparate() == nrCumparateMain) { cout << "Corect Nr Cumparate" << endl; }					else { cout << "Gresit Numar Cumparate" << endl; }

	cout << "		SUPRAINCARCAREA OPERATORULUI<<" << endl;
	cout << A;

	cout << "		SUPRAINCARCAREA OPERATORULUI>>" << endl;
	cin >> A;
	cout << endl << "		Afisare obiect introdus anterior" << endl << A;
	cout << "Locul cu indexul 1: " << A[1] << endl;

	cout << "		SUPRAINCARCAREA OPERATORULUI+" << endl; // nu functioneaza corect functia de anulate a biletelor
	int locuriSuplimentare = 0;
	cout << "INAINTE de adaugarea locurilor SUPLIMENTATE: " << A.getTotalSala() << endl;
	cout << "Locuri Suplimentate: "; cin >> locuriSuplimentare;
	A = A + locuriSuplimentare;
	cout << "Dupa adaugarea locurilor SUPLIMENTATE: " << A.getTotalSala() << endl;

	cout << "		SUPRAINCARCAREA OPERATORULUI!" << endl;
	if (!A)	{		cout << "Sunt locuri ocupate!" << endl;	}	
	else	{		cout << "NU sunt locuri ocupate!" << endl;	}

	cout << "		SUPRAINCARCAREA OPERATORULUI!" << endl;
	if (A < B)	{		cout << "TRUE " << A.getTotalLocuri() << " < " << B.getTotalLocuri();	}	
	else		{		cout << "FALSE " << A.getNrLibere() << " > " << B.getNrLibere();		}

	cout << "		SUPRAINCARCAREA OPERATORULUI==" << endl;
	if (A == B)	{		cout << "TRUE! Obiecte identice" << endl;	}
	else		{		cout << "FALSE! Obiecte DIFERITE" << endl;	}
	sala G = A;
	if (A == G)	{		cout << "TRUE! Obiecte identice" << endl;	}
	else		{		cout << "FALSE! Obiecte DIFERITE" << endl;	}

	cout << "		SUPRAINCARCAREA OPERATORULUI++" << endl;
	cout << "Total locuri inainte de INCREMENTARE: " << A.getTotalSala()<< endl;
	cout << "Total locuri  PRE-INCREMENTARE : " << A++ << endl;
	cout << "Total locuri DUPA PRE-INCREMENTARE: " << A.getTotalSala() << endl;
	cout << "Total locuri POST-INCREMENTARE: " << ++A << endl;
	cout << "Total locuri DUPA POST-INCREMENTARE: " << A.getTotalSala() << endl;

	cout << "		Operatorul de CAST IMPLICIT si EXPLICIT" << endl;
	int locuriLibere = (int)A;
	cout << "Locuri libere sala " << A() << " " << locuriLibere << endl;

	cout << "		campul STATIC" << endl;
	sala H;
	cout << "Numele Cinematografului: " << H.getNumeCinematograf() << endl;
	string numeCinematografMain;
	cout << "Numele Cinematografului: "; cin >> numeCinematografMain;
	H.setNumeCinematograf(numeCinematografMain);
	cout << "Numele Cinematografului: " << H.getNumeCinematograf() << endl;
	
	return 0;
}