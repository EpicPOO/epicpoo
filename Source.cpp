#include<iostream>
#include<string>
#include "sala.h"
#include "film.h"
#include "aliment.h"

using namespace std;

int main()
{
	//TESTARE CLASA SALA
	//test constructor implicit

	sala A;
	cout << "		CONSTRUCTOR IMPLICIT" << endl;
	if (A.getNumeSala() == "") { cout << "Corect Numele Sala" << endl; }
	else { cout << "Gresit Numele Sala" << endl; }
	if (A.getTipSala() == nullptr) { cout << "Corect Tip Sala" << endl; }
	else { cout << "Gresit Tip Sala" << endl; }
	if (A.getTotalSala() == 0) { cout << "Corect Total Sala" << endl; }
	else { cout << "Gresit Total Sala" << endl; }
	if (A.getTotalLocuri() == nullptr) { cout << "Corect Total Locuri" << endl; }
	else { cout << "Gresit Total Locuri" << endl; }
	if (A.getNrLibere() == 0) { cout << "Corect Numar Locuri" << endl; }
	else { cout << "Gresit Numar Locuri" << endl; }
	if (A.getNrRezervate() == 0) { cout << "Corect Nr Rezervate" << endl; }
	else { cout << "Gresit Numar Rezervate" << endl; }
	if (A.getNrCumparate() == 0) { cout << "Corect Nr Cumparate" << endl; }
	else { cout << "Gresit Numar Cumparate" << endl; }

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

	if (B.getNumeSala() == "B") { cout << "Corect Numele Sala" << endl; }
	else { cout << "Gresit Numele Sala" << endl; }
	if (B.getTipSala() == "2D") { cout << "Corect Tip Sala" << endl; }
	else { cout << "Gresit Tip Sala" << endl; }
	if (B.getTotalSala() == totalSalaMain) { cout << "Corect Total Sala" << endl; }
	else { cout << "Gresit Total Sala" << endl; }
	for (int i = 0; i < nrLocuriOcupate; i++)
	{
		if (B.getTotalLocuri()[i] == locuriAlese[i])
		{
			cout << "Corect Total Locuri" << endl;
		}
		else { cout << "Gresit Total Locuri" << endl; }
	}
	if (B.getNrLibere() == (totalSalaMain - nrLocuriOcupate)) { cout << "Corect Numar Locuri" << endl; }
	else { cout << "Gresit Numar Locuri" << endl; }
	if (B.getNrRezervate() == nrRezervateMain) { cout << "Corect Nr Rezervate" << endl; }
	else { cout << "Gresit Numar Rezervate" << endl; }
	if (B.getNrCumparate() == nrCumparateMain) { cout << "Corect Nr Cumparate" << endl; }
	else { cout << "Gresit Numar Cumparate" << endl; }

	cout << "		CONSTRUCTOR DE COPIERE SI OPERATORUL =" << endl;
	sala C("C", tipSalaMain, totalSalaMain, locuriAlese, nrRezervateMain, nrCumparateMain);

	sala D = C;
	sala E;
	sala F = E = D;
	if (F.getNumeSala() == "C") { cout << "Corect Numele Sala" << endl; }
	else { cout << "Gresit Numele Sala" << endl; }
	if (F.getTipSala() == "3D") { cout << "Corect Tip Sala" << endl; }
	else { cout << "Gresit Tip Sala" << endl; }
	if (F.getTotalSala() == totalSalaMain) { cout << "Corect Total Sala" << endl; }
	else { cout << "Gresit Total Sala" << endl; }
	for (int i = 0; i < nrLocuriOcupate; i++)
	{
		if (F.getTotalLocuri()[i] == locuriAlese[i])
		{
			cout << "Corect Total Locuri" << endl;
		}
		else { cout << "Gresit Total Locuri" << endl; }
	}
	if (F.getNrLibere() == (totalSalaMain - nrLocuriOcupate)) { cout << "Corect Numar Locuri" << endl; }
	else { cout << "Gresit Numar Locuri" << endl; }
	if (F.getNrRezervate() == nrRezervateMain) { cout << "Corect Nr Rezervate" << endl; }
	else { cout << "Gresit Numar Rezervate" << endl; }
	if (F.getNrCumparate() == nrCumparateMain) { cout << "Corect Nr Cumparate" << endl; }
	else { cout << "Gresit Numar Cumparate" << endl; }

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
	if (!A) { cout << "Sunt locuri ocupate!" << endl; }
	else { cout << "NU sunt locuri ocupate!" << endl; }

	cout << "		SUPRAINCARCAREA OPERATORULUI!" << endl;
	if (A < B) { cout << "TRUE " << A.getTotalLocuri() << " < " << B.getTotalLocuri(); }
	else { cout << "FALSE " << A.getNrLibere() << " > " << B.getNrLibere(); }

	cout << "		SUPRAINCARCAREA OPERATORULUI==" << endl;
	if (A == B) { cout << "TRUE! Obiecte identice" << endl; }
	else { cout << "FALSE! Obiecte DIFERITE" << endl; }
	sala G = A;
	if (A == G) { cout << "TRUE! Obiecte identice" << endl; }
	else { cout << "FALSE! Obiecte DIFERITE" << endl; }

	cout << "		SUPRAINCARCAREA OPERATORULUI++" << endl;
	cout << "Total locuri inainte de INCREMENTARE: " << A.getTotalSala() << endl;
	cout << "Total locuri  PRE-INCREMENTARE : " << A++ << endl;
	cout << "Total locuri DUPA PRE-INCREMENTARE: " << A.getTotalSala() << endl;
	cout << "Total locuri POST-INCREMENTARE: " << ++A << endl;
	cout << "Total locuri DUPA POST-INCREMENTARE: " << A.getTotalSala() << endl;

	cout << "		Operatorul de CAST IMPLICIT si EXPLICIT" << endl;
	int locuriLibere = (int)A;
	cout << "Locuri libere sala " << A() << " " << locuriLibere << endl;









	//TESTE Andrei -> pentru film.h

	film f1;
	cout << "Test constructor implicit:\n";
	cout << f1 << "\n\n";

	string stringuri[2];
	stringuri[0] = "15.10 15:30 - 17:30";
	stringuri[1] = "16.10 15:50 - 17:50";
	string nume = "Avengers";
	char tip[] = "3D";
	int varsta = 14, nr = 2;

	film f2(nume, tip, varsta, nr, stringuri);
	cout << "Test constructor cu parametri:\n" << f2 << "\n\n";

	film f3;
	f3.setNumeFilm(nume);
	f3.setTipFilm(tip);
	f3.setNrRulari(nr);
	f3.setVarstaMin(varsta);
	f3.setProgram(stringuri, nr);

	cout << "Test setteri" << f3 << "\n\n";

	bool t = true;

	if (f3.getNumeFilm() == nume && f3.getTipFilm()[0] == tip[0] && f3.getTipFilm()[1] == tip[1] && f3.getVarstaMin() == varsta && f3.getNrRulari() == nr) {
		for (int i = 0; i < nr; i++)
			if (f3.getProgram()[i] != stringuri[i]) { t = false; break; }
	}
	else t = false;
	if (t == true)
		cout << "Getteri corecti" << "\n\n";
	else cout << "Getteri incorecti" << "\n\n";

	film f4(f1);
	film f5 = f1;
	film f6;
	f6 = f1;

	cout << "Test constructor de copiere:\n" << f4 << endl << f5 << "\n\n";

	cout << "Test operator = :\n" << f6 << "\n\n";

	f6 = f6 + 1;
	cout << "Test operator +: " << f6 << "\n\n";

	cout << "Testare cast explicit la int: " << (int)f6 << "\n\n";

	string testMyName = f2();
	cout << "Testare cast implicit la string: " << testMyName << "\n\n";

	cout << "Testare operator !: ";
	if (!f2) cout << "functioneaza\n\n";
	else cout << "nu functioneaza\n\n";

	cout << "Testare operator <: ";
	if (f1 < f2) cout << "functioneaza\n\n";
	else cout << "nu functioneaza\n\n";

	cout << "Testare operator ==: ";
	if (f2 == f3) cout << "functioneaza\n\n";
	else cout << "nu functioneaza\n\n";


	film f7;
	cout << "Test operator ++: ";
	if ((f7++).getVarstaMin() == 0) cout << "functioneaza\n\n";
	else cout << "nu functioneaza\n\n";

	cout << "Test operator pre ++: ";
	if ((++f7).getVarstaMin() == 2) cout << "functioneaza\n\n";
	else cout << "nu functioneaza\n\n";

	film f9(nume, tip, varsta, nr, stringuri);


	//TESTE Andrei -> pentru aliment.h

	aliment a1;
	cout << "Test constructor implicit:\n";
	cout << a1 << "\n\n";


	string numeAl = "Heineken 0.33";
	char categ[] = "Bere";
	int lg = 5;
	int cod[] = { 0, 1 , 4 , 7, 7 };

	aliment a2(numeAl, categ, lg, cod, 24.5);
	cout << "Test constructor cu parametri:\n" << a2 << "\n\n";

	aliment a3;
	a3.setnumeAliment(numeAl);
	a3.setCategorie(categ);
	a3.setLungimeCod(lg);
	a3.setPret(24.5);
	a3.setCodBare(cod, lg);

	cout << "Test setteri: \n" << a3 << "\n\n";

	bool tt = true;

	if (a3.getnumeAliment() == numeAl && a3.getCategorie()[0] == categ[0] && a3.getCategorie()[1] == categ[1]
		&& a3.getPret() == 24.5 && a3.getLungimeCod() == lg) {
		for (int i = 0; i < lg; i++)
			if (a3.getCodBare()[i] != cod[i]) { tt = false; break; }
	}
	else tt = false;
	if (tt == true)
		cout << "Getteri corecti" << "\n\n";
	else cout << "Getteri incorecti" << "\n\n";

	aliment a4(a1);
	aliment a5 = a1;
	aliment a6;
	a6 = a1;

	cout << "Test constructor de copiere:\n" << a4 << endl << a5 << "\n\n";

	cout << "Test operator = :\n" << a6 << "\n\n";

	a6 = a6 + 1;
	cout << "Test operator +: " << a6 << "\n\n";

	cout << "Testare cast explicit la int: " << (int)a3 << "\n\n";

	string testMyMeal = a2();
	cout << "Testare cast implicit la string: " << testMyMeal << "\n\n";

	cout << "Testare operator !: ";
	if (!a2) cout << "functioneaza\n\n";
	else cout << "nu functioneaza\n\n";

	cout << "Testare operator <: ";
	if (a1 < a2) cout << "functioneaza\n\n";
	else cout << "nu functioneaza\n\n";

	cout << "Testare operator ==: ";
	if (a2 == a3) cout << "functioneaza\n\n";
	else cout << "nu functioneaza\n\n";


	aliment a7;
	cout << "Test operator --: ";
	if ((a7--).getPret() == 0) cout << "functioneaza\n\n";
	else cout << "nu functioneaza\n\n";

	return 0;
}