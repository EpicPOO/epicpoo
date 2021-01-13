#include<iostream>
#include<string>
#include "sala.h"
#include "film.h"
#include "aliment.h"
#include "angajati.h"
#include "bilet.h"

using namespace std;

int main()
{

	////TESTARE  Buharu CLASA SALA
	////test constructor implicit
	//cout << "						Testare CLASA SALA" << endl;
	//sala A;
	//cout << "		CONSTRUCTOR IMPLICIT" << endl;
	//if (A.getNumeSala() == "") { cout << "Corect Numele Sala" << endl; }			else { cout << "Gresit Numele Sala" << endl; }
	//if (A.getTipSala() == nullptr) { cout << "Corect Tip Sala" << endl; }			else { cout << "Gresit Tip Sala" << endl; }
	//if (A.getTotalSala() == 0) { cout << "Corect Total Sala" << endl; }				else { cout << "Gresit Total Sala" << endl; }
	//if (A.getTotalLocuri() == nullptr) { cout << "Corect Total Locuri" << endl; }	else { cout << "Gresit Total Locuri" << endl; }
	//if (A.getNrLibere() == 0) { cout << "Corect Numar Locuri" << endl; }			else { cout << "Gresit Numar Locuri" << endl; }
	//if (A.getNrRezervate() == 0) { cout << "Corect Nr Rezervate" << endl; }			else { cout << "Gresit Numar Rezervate" << endl; }
	//if (A.getNrCumparate() == 0) { cout << "Corect Nr Cumparate" << endl; }			else { cout << "Gresit Numar Cumparate" << endl; }

	////test counstructor cu parametri
	//cout << "		CONSTRUCTOR CU PARAMETRI" << endl;
	//int totalSalaMain = 0, nrRezervateMain = 0, nrCumparateMain = 0, nrLocuriOcupate;
	//int* locuriAlese = nullptr;

	//cout << "Numarul total sala: ";
	//cin >> totalSalaMain;
	//cout << "Numarul locuri rezervate: ";
	//cin >> nrRezervateMain;
	//cout << "Numar locuri cumparate de la casa: ";
	//cin >> nrCumparateMain;
	//nrLocuriOcupate = nrCumparateMain + nrRezervateMain;
	//locuriAlese = new int[nrLocuriOcupate];
	//cout << "Introduceti scaunele rezervate: " << endl;
	//for (int i = 0; i < nrRezervateMain; i++)
	//{
	//	cin >> locuriAlese[i];
	//	for (int j = 0; j < i; j++)
	//	{
	//		if (locuriAlese[j] == locuriAlese[i])
	//		{
	//			cout << "Loc Ocupat!" << " Alege altul: " << endl;
	//			cin >> locuriAlese[i];
	//		}
	//	}
	//}
	//cout << "Introduceti scaunele cumparate: " << endl;
	//for (int i = nrRezervateMain; i < nrLocuriOcupate; i++)
	//{
	//	cin >> locuriAlese[i];
	//	for (int j = 0; j < i; j++)
	//	{
	//		if (locuriAlese[j] == locuriAlese[i])
	//		{
	//			cout << "Loc Ocupat!" << " Alege altul: " << endl;
	//			cin >> locuriAlese[i];
	//		}
	//	}
	//}
	//char tipSalaMain[] = "2D";
	//sala B("B", tipSalaMain, totalSalaMain, locuriAlese, nrRezervateMain, nrCumparateMain);

	//if (B.getNumeSala() == "B") { cout << "Corect Numele Sala" << endl; }			else { cout << "Gresit Numele Sala" << endl; }
	//if (B.getTipSala() == "2D") { cout << "Corect Tip Sala" << endl; }				else { cout << "Gresit Tip Sala" << endl; }
	//if (B.getTotalSala() == totalSalaMain) { cout << "Corect Total Sala" << endl; }	else { cout << "Gresit Total Sala" << endl; }
	//for (int i = 0; i < nrLocuriOcupate; i++)
	//{
	//	if (B.getTotalLocuri()[i] == locuriAlese[i])
	//	{
	//		cout << "Corect Total Locuri" << endl;
	//	}
	//	else { cout << "Gresit Total Locuri" << endl; }
	//}
	//if (B.getNrLibere() == (totalSalaMain - nrLocuriOcupate)) { cout << "Corect Numar Locuri" << endl; }	else { cout << "Gresit Numar Locuri" << endl; }
	//if (B.getNrRezervate() == nrRezervateMain) { cout << "Corect Nr Rezervate" << endl; }	else { cout << "Gresit Numar Rezervate" << endl; }
	//if (B.getNrCumparate() == nrCumparateMain) { cout << "Corect Nr Cumparate" << endl; }	else { cout << "Gresit Numar Cumparate" << endl; }

	//cout << "		CONSTRUCTOR DE COPIERE SI OPERATORUL =" << endl;
	//sala C("C", tipSalaMain, totalSalaMain, locuriAlese, nrRezervateMain, nrCumparateMain);

	//sala D = C;
	//sala E;
	//sala F = E = D;
	//if (F.getNumeSala() == "C") { cout << "Corect Numele Sala" << endl; }			else { cout << "Gresit Numele Sala" << endl; }
	//if (F.getTipSala() == "3D") { cout << "Corect Tip Sala" << endl; }				else { cout << "Gresit Tip Sala" << endl; }
	//if (F.getTotalSala() == totalSalaMain) { cout << "Corect Total Sala" << endl; }	else { cout << "Gresit Total Sala" << endl; }
	//for (int i = 0; i < nrLocuriOcupate; i++)
	//{
	//	if (F.getTotalLocuri()[i] == locuriAlese[i])
	//	{
	//		cout << "Corect Total Locuri" << endl;
	//	}
	//	else { cout << "Gresit Total Locuri" << endl; }
	//}
	//if (F.getNrLibere() == (totalSalaMain - nrLocuriOcupate)) { cout << "Corect Numar Locuri" << endl; }	else { cout << "Gresit Numar Locuri" << endl; }
	//if (F.getNrRezervate() == nrRezervateMain) { cout << "Corect Nr Rezervate" << endl; }	else { cout << "Gresit Numar Rezervate" << endl; }
	//if (F.getNrCumparate() == nrCumparateMain) { cout << "Corect Nr Cumparate" << endl; }	else { cout << "Gresit Numar Cumparate" << endl; }

	//cout << "		SUPRAINCARCAREA OPERATORULUI<<" << endl;
	//cout << A;

	//cout << "		SUPRAINCARCAREA OPERATORULUI>>" << endl;
	//cin >> A;
	//cout << endl << "		Afisare obiect introdus anterior" << endl << A;
	//cout << "Locul cu indexul 1: " << A[1] << endl;

	//cout << "		SUPRAINCARCAREA OPERATORULUI+" << endl; // nu functioneaza corect functia de anulate a biletelor
	//int locuriSuplimentare = 0;
	//cout << "INAINTE de adaugarea locurilor SUPLIMENTATE: " << A.getTotalSala() << endl;
	//cout << "Locuri Suplimentate: "; cin >> locuriSuplimentare;
	//A = A + locuriSuplimentare;
	//cout << "Dupa adaugarea locurilor SUPLIMENTATE: " << A.getTotalSala() << endl;

	//cout << "		SUPRAINCARCAREA OPERATORULUI!" << endl;
	//if (!A) { cout << "Sunt locuri ocupate!" << endl; }
	//else { cout << "NU sunt locuri ocupate!" << endl; }

	//cout << "		SUPRAINCARCAREA OPERATORULUI!" << endl;
	//if (A < B) { cout << "TRUE " << A.getTotalLocuri() << " < " << B.getTotalLocuri(); }
	//else { cout << "FALSE " << A.getNrLibere() << " > " << B.getNrLibere(); }

	//cout << "		SUPRAINCARCAREA OPERATORULUI==" << endl;
	//if (A == B) { cout << "TRUE! Obiecte identice" << endl; }
	//else { cout << "FALSE! Obiecte DIFERITE" << endl; }
	//sala G = A;
	//if (A == G) { cout << "TRUE! Obiecte identice" << endl; }
	//else { cout << "FALSE! Obiecte DIFERITE" << endl; }

	//cout << "		SUPRAINCARCAREA OPERATORULUI++" << endl;
	//cout << "Total locuri inainte de INCREMENTARE: " << A.getTotalSala() << endl;
	//cout << "Total locuri  PRE-INCREMENTARE : " << A++ << endl;
	//cout << "Total locuri DUPA PRE-INCREMENTARE: " << A.getTotalSala() << endl;
	//cout << "Total locuri POST-INCREMENTARE: " << ++A << endl;
	//cout << "Total locuri DUPA POST-INCREMENTARE: " << A.getTotalSala() << endl;

	//cout << "		Operatorul de CAST IMPLICIT si EXPLICIT" << endl;
	//int locuriLibere = (int)A;
	//cout << "Locuri libere sala " << A() << " " << locuriLibere << endl;







	//

	////TESTE Andrei -> pentru film.h
	//cout << "						Testare CLASA FILM" << endl;
	//film f1;
	//cout << "Test constructor implicit:\n";
	//cout << f1 << "\n\n";

	//string stringuri[2];
	//stringuri[0] = "15.10 15:30 - 17:30";
	//stringuri[1] = "16.10 15:50 - 17:50";
	//string nume = "Avengers";
	//char tip[] = "3D";
	//int varsta = 14, nr = 2;

	//film f2(nume, tip, varsta, nr, stringuri);
	//cout << "Test constructor cu parametri:\n" << f2 << "\n\n";

	//film f3;
	//f3.setNumeFilm(nume);
	//f3.setTipFilm(tip);
	//f3.setNrRulari(nr);
	//f3.setVarstaMin(varsta);
	//f3.setProgram(stringuri, nr);

	//cout << "Test setteri" << f3 << "\n\n";

	//bool t = true;

	//if (f3.getNumeFilm() == nume && f3.getTipFilm()[0] == tip[0] && f3.getTipFilm()[1] == tip[1] && f3.getVarstaMin() == varsta && f3.getNrRulari() == nr) {
	//	for (int i = 0; i < nr; i++)
	//		if (f3.getProgram()[i] != stringuri[i]) { t = false; break; }
	//}
	//else t = false;
	//if (t == true)
	//	cout << "Getteri corecti" << "\n\n";
	//else cout << "Getteri incorecti" << "\n\n";

	//film f4(f1);
	//film f5 = f1;
	//film f6;
	//f6 = f1;

	//cout << "Test constructor de copiere:\n" << f4 << endl << f5 << "\n\n";

	//cout << "Test operator = :\n" << f6 << "\n\n";

	//f6 = f6 + 1;
	//cout << "Test operator +: " << f6 << "\n\n";

	//cout << "Testare cast explicit la int: " << (int)f6 << "\n\n";

	//string testMyName = f2();
	//cout << "Testare cast implicit la string: " << testMyName << "\n\n";

	//cout << "Testare operator !: ";
	//if (!f2) cout << "functioneaza\n\n";
	//else cout << "nu functioneaza\n\n";

	//cout << "Testare operator <: ";
	//if (f1 < f2) cout << "functioneaza\n\n";
	//else cout << "nu functioneaza\n\n";

	//cout << "Testare operator ==: ";
	//if (f2 == f3) cout << "functioneaza\n\n";
	//else cout << "nu functioneaza\n\n";


	//film f7;
	//cout << "Test operator ++: ";
	//if ((f7++).getVarstaMin() == 0) cout << "functioneaza\n\n";
	//else cout << "nu functioneaza\n\n";

	//cout << "Test operator pre ++: ";
	//if ((++f7).getVarstaMin() == 2) cout << "functioneaza\n\n";
	//else cout << "nu functioneaza\n\n";

	//film f9(nume, tip, varsta, nr, stringuri);
	//
	//cout << "Test operator >>: \n";
	//film f10;
	//cin >> f10;
	//cout << f10;




	////TESTE Andrei -> pentru aliment.h
	//cout << "						Testare CLASA ALIMENT" << endl;
	//aliment a1;
	//cout << "Test constructor implicit:\n";
	//cout << a1 << "\n\n";


	//string numeAl = "Heineken 0.33";
	//char categ[] = "Bere";
	//int lg = 5;
	//int cod[] = { 0, 1 , 4 , 7, 7 };

	//aliment a2(numeAl, categ, lg, cod, 24.5);
	//cout << "Test constructor cu parametri:\n" << a2 << "\n\n";

	//aliment a3;
	//a3.setnumeAliment(numeAl);
	//a3.setCategorie(categ);
	//a3.setLungimeCod(lg);
	//a3.setPret(24.5);
	//a3.setCodBare(cod, lg);

	//cout << "Test setteri: \n" << a3 << "\n\n";

	//bool tt = true;

	//if (a3.getnumeAliment() == numeAl && a3.getCategorie()[0] == categ[0] && a3.getCategorie()[1] == categ[1]
	//	&& a3.getPret() == 24.5 && a3.getLungimeCod() == lg) {
	//	for (int i = 0; i < lg; i++)
	//		if (a3.getCodBare()[i] != cod[i]) { tt = false; break; }
	//}
	//else tt = false;
	//if (tt == true)
	//	cout << "Getteri corecti" << "\n\n";
	//else cout << "Getteri incorecti" << "\n\n";

	//aliment a4(a1);
	//aliment a5 = a1;
	//aliment a6;
	//a6 = a1;

	//cout << "Test constructor de copiere:\n" << a4 << endl << a5 << "\n\n";

	//cout << "Test operator = :\n" << a6 << "\n\n";

	//a6 = a6 + 1;
	//cout << "Test operator +: " << a6 << "\n\n";

	//cout << "Testare cast explicit la int: " << (int)a3 << "\n\n";

	//string testMyMeal = a2();
	//cout << "Testare cast implicit la string: " << testMyMeal << "\n\n";

	//cout << "Testare operator !: ";
	//if (!a2) cout << "functioneaza\n\n";
	//else cout << "nu functioneaza\n\n";

	//cout << "Testare operator <: ";
	//if (a1 < a2) cout << "functioneaza\n\n";
	//else cout << "nu functioneaza\n\n";

	//cout << "Testare operator ==: ";
	//if (a2 == a3) cout << "functioneaza\n\n";
	//else cout << "nu functioneaza\n\n";


	//aliment a7;
	//cout << "Test operator --: ";
	//if ((a7--).getPret() == 0) cout << "functioneaza\n\n";
	//else cout << "nu functioneaza\n\n";
	//
	//cout << "Test operator >>: \n";
	//aliment a8;
	//cin >> a8;
	//cout << a8;




	////TESTARE Buharu Vlad clasa angajati
	//cout << "						Testare CLASA Angajati" << endl;
	////constructor implicit
	//angajati angajat1;
	//cout << "		Constructor Implicit" << endl << angajat1;
	//
	////constructor cu parametrii
	//char numeAngajat[] = "Buharu";
	//int telefon[] = { 0,7,6,4,9,8,0,5,1,4 };
	//string adresa = "Bucuresti, sector 3, blv. Unirii, nr 11, sc 1, ap 11";
	//string email = "buharu@yahoo.com";
	//float salariu = 2545.20;
	//int varstaAngajat = 20;
	//angajati angajat2(numeAngajat, telefon, adresa, email, salariu, varstaAngajat);
	//cout << endl << "		Constructor cu parametrii" << endl << angajat2 << endl;

	//angajati angajat4;
	//angajat4 = angajat2;
	//cout << "		Operator =" << endl;
	//if (strcmp(angajat4.getNume(), numeAngajat) == 0) { cout << "Nume Angajat CORECT" << endl; }
	//else { cout << "Nume INCORECT" << endl; }
	//bool testTelefon = true;
	//for (int i = 0; i < 10; i++)
	//{
	//	if (angajat4.getTelefon()[i] != telefon[i]) { testTelefon = false; cout << "Telefon INCORECT" << endl; break; }
	//}
	//if (testTelefon == true) { cout << "Telefon CORECT" << endl; }
	//if (angajat4.getAdresa() == adresa)		{	cout << "Adresa CORECT" << endl;		}	else { cout << "Adresa INCORECT" << endl; }
	//if (angajat4.getEmail() == email)		{	cout << "Email CORECT" << endl;			}	else { cout << "Email INCORECT" << endl; }
	//if (angajat4.getSalariu() == salariu)	{	cout << "Salariu CORECT" << endl;		}	else { cout << "Salariu INCORECT" << endl; }
	//if (angajat4.getVarsta() == varstaAngajat)		{	cout << "Varsta CORECT" << endl;		}	else { cout << "Varsta INCORECT" << endl;	}
	//
	////testare getter si setter
	//cout << "		Testare getter si setter" << endl;
	//angajati angajat3;
	//angajat3.setNume(numeAngajat);
	//angajat3.setTelefon(telefon);
	//angajat3.setAdresa(adresa);
	//angajat3.setEmail(email);
	//angajat3.setSalariu(salariu);
	//angajat3.setVarsta(varstaAngajat);
	//if (strcmp(angajat3.getNume(), numeAngajat) == 0)	{		cout << "Nume Angajat CORECT" << endl;	}	else	{		cout << "Nume Angajat INCORECT" << endl;	}
	//bool testTelefon1 = true;
	//for (int i = 0; i < 10; i++)
	//{
	//	if (angajat3.getTelefon()[i] != telefon[i]) { testTelefon1 = false; cout << "Telefon INCORECT" << endl; break; }
	//}
	//if (testTelefon == true)				{		cout << "Telefon CORECT" << endl;		}
	//if (angajat3.getAdresa() == adresa)		{		cout << "Adresa CORECT" << endl;		}	else	{		cout << "Adresa INCORECT" << endl;	}
	//if (angajat3.getEmail() == email)		{		cout << "Email CORECT" << endl;			}	else	{		cout << "Email INCORECT" << endl;	}
	//if (angajat3.getSalariu() == salariu)	{		cout << "Salariu CORECT" << endl;		}	else	{		cout << "Salariu INCORECT" << endl; }
	//if (angajat3.getVarsta() == varstaAngajat)		{		cout << "Varsta CORECT" << endl;		}	else	{		cout << "Varsta INCORECT" << endl;	}
	//
	////operatorul+
	//cout << "		Operatorul + si -" << endl;
	//int procent = 10;
	//angajat3 = angajat3 + procent;
	//salariu += salariu * 10 / 100;
	//if (angajat3.getSalariu() == salariu)	{		cout << "Operator + CORECT" << endl;	}	else	{		cout << "Operator + INCORECT" << endl;}
	//angajat3 = angajat3 - procent;
	//salariu -= salariu * 10 / 100;
	//if (angajat3.getSalariu() == salariu)	{		cout << "Operator - CORECT" << endl;	}	else	{		cout << "Operator - INCORECT" << endl;}

	////operator[]
	//cout << "		Operatorul []" << endl;
	//if (angajat3[0] == 0)	
	//{		
	//	cout << "Operator [] CORECT" << endl;
	//	if (angajat3[1] == 7)		{		cout << "Operator[] CORECT" << endl;		}	else	{		cout << "Operator[] INCORECT" << endl;}
	//}	
	//else	
	//{	
	//	cout << "Operator [] INCORECT" << endl;		
	//}

	////operator!
	//cout << "		Operatorul !" << endl;
	//if (!angajat3)
	//{
	//	cout << "Operator ! CORECT" << endl;
	//	if (!angajat1)
	//	{
	//		cout << "Operator ! INCORECT" << endl;
	//	}
	//	else
	//	{
	//		cout << "Operator ! CORECT" << endl;
	//	}
	//}
	//else
	//{
	//	cout << "Operator ! INCORECT" << endl;
	//}

	////operator ++
	//cout << "		Operatorul ++" << endl;
	//cout << "angajat4++ " << endl << angajat4++ << endl;
	//cout << "angajat4   " << endl << angajat4 << endl;
	//cout << "++angajat4 " << endl << ++angajat4 << endl;
	//cout << "angajat4   " << endl << angajat4 << endl;

	////operator de cast explicit
	//if ((int)angajat3 == varstaAngajat)
	//{
	//	cout << "Operator de cast explicit CORECT" << endl;
	//}
	//else
	//{
	//	cout << "Operator de cast explicit INCORECT" << endl;
	//}
	//bool testOperatorCast = true;
	//for (int i = 0; i < strlen(numeAngajat) + 1; i++)
	//{
	//	if (angajat3()[i] != numeAngajat[i])
	//	{
	//		testOperatorCast = false; cout << "Operator de cast implicit INCORECT" << endl; break;
	//	}
	//}
	//if (testOperatorCast == true)	{		cout << "Operator de cast implicit CORECT" << endl;}

	//cout << "		Operatorul citire de la tastatura" << endl;
	//cin >> angajat1;
	//angajat4.setVarsta(20);
	//cout << "		Operatorul ==" << endl;
	//if (angajat2 == angajat4)
	//{
	//	cout << "Operator == CORECT" << endl;
	//}
	//else
	//{
	//	cout << "Operator ==  INCORECT" << endl;
	//	cout << "Nume angajat2: " << angajat2.getNume() << endl;
	//	cout << "Nume angajat4: " << angajat4.getNume() << endl;
	//	cout << "Varsta angajat2: " << angajat2.getVarsta() << endl;
	//	cout << "Varsta angajat4: " << angajat4.getVarsta() << endl;
	//}

	//Teste Andrei -> bilet.h

	//cout << "						Testare CLASA bilet" << endl;
	//bilet b1;
	//cout << "Test constructor implicit:\n";
	//cout << b1 << "\n\n";


	//string numeBil = "Avengers";
	//char oraBilet[] = "14.10.2020 15:30";
	//int lgBil = 5;
	//int locuri[] = { 0, 1 , 4 , 7, 7 };

	//bilet b2(numeBil, oraBilet, lgBil, locuri, 24.5);
	//cout << "Test constructor cu parametri:\n" << b2 << "\n\n";

	//bilet b3;
	//b3.setNumeBilet(numeBil);
	//b3.setOraBilet(oraBilet);
	//b3.setNrLocuri(lgBil);
	//b3.setPretTotal(24.5);
	//b3.setLocuriBilet(locuri, lgBil);

	//cout << "Test setteri: \n" << b3 << "\n\n";

	//bool ttt = true;

	//if (b3.getNumeBilet() == numeBil && b3.getOraBilet()[0] == oraBilet[0] && b3.getOraBilet()[1] == oraBilet[1]
	//	&& b3.getPretTotal() == 24.5 && b3.getNrLocuri() == lgBil) {
	//	for (int i = 0; i < lgBil; i++)
	//		if (b3.getLocuriBilet()[i] != locuri[i]) { ttt = false; break; }
	//}
	//else ttt = false;
	//if (ttt == true)
	//	cout << "Getteri corecti" << "\n\n";
	//else cout << "Getteri incorecti" << "\n\n";

	//bilet b4(b1);
	//bilet b5 = b1;
	//bilet b6;
	//b6 = b1;

	//cout << "Test constructor de copiere:\n" << b4 << endl << b5 << "\n\n";

	//cout << "Test operator = :\n" << b6 << "\n\n";

	//b6 = b6 - 1.0;
	//cout << "Test operator -: " << b6 << "\n\n";

	//cout << "Testare cast explicit la int: " << (int)b3 << "\n\n";

	//string testMyBil = b2();
	//cout << "Testare cast implicit la string: " << testMyBil << "\n\n";

	//cout << "Testare operator !: ";
	//if (!b2) cout << "functioneaza\n\n";
	//else cout << "nu functioneaza\n\n";

	//cout << "Testare operator <: ";
	//if (b1 < b2) cout << "functioneaza\n\n";
	//else cout << "nu functioneaza\n\n";

	//cout << "Testare operator ==: ";
	//if (b2 == b3) cout << "functioneaza\n\n";
	//else cout << "nu functioneaza\n\n";


	//bilet b7;
	//cout << "Test operator ++: ";
	//if ((b7++).getNrLocuri() == 0) cout << "functioneaza\n\n";
	//else cout << "nu functioneaza\n\n";
	//cout << "Test preincrementare: ";
	//if ((++b7).getNrLocuri() == 2) cout << "functioneaza\n\n";
	//else cout << "nu functioneaza\n\n";

	//cout << "Teste operator >>, <<: \n";
	///*bilet b8;
	//cin >> b8;
	//cout << b8;*/
	//bilet b10;
	//b3.serializare();
	////cin >> b10;
	////b10.serializare();
	//cout << endl;
	//cout << endl << "primul obiect: " << endl <<  endl;
	//bilet b9;
	//b9.deserializare();
	//cout << b9;
	//cout << endl <<  endl << "al doilea obiect: " << endl << endl;
	//bilet b11;
	//b11.deserializare();
	//cout << b11;
	/*int totalBilete = 4;
	bilet b1, b2, b3, b4;
	cin >> b1 >> b2 >> b3 >> b4;
	adaugaBilet(b1, totalBilete, "bilete.bin");
	adaugaBilet(b2, totalBilete, "bilete.bin");
	adaugaBilet(b3, totalBilete, "bilete.bin");
	adaugaBilet(b4, totalBilete, "bilete.bin");
	bilet cb4 = gasesteBilet(4, totalBilete, "bilete.bin");
	bilet cb1 = gasesteBilet(1, totalBilete, "bilete.bin");
	bilet cb2 = gasesteBilet(2, totalBilete, "bilete.bin");
	bilet cb5 = gasesteBilet(5, totalBilete, "bilete.bin");
	cout << cb1 << endl << cb2 << endl << cb4 << endl << cb5;

	cout << "\n\nActualizare bilet 1 cu bilet 2:\n";
	stergeBilet(2, totalBilete, "bilete.bin");
	bilet actualizat = gasesteBilet(1, totalBilete, "bilete.bin");
	cout << actualizat;
	bilet gasit = gasesteBilet(3, totalBilete, "bilete.bin");
	cout << gasit;*/
	int totalSali = 3;
	//sala(string numeSala, char* tipSala, int totalSala, int* totalLocuri, int nrRezervate, int nrCumparate)
	string numeSala = "Ion Creanga";
	char tipSala[] = "3d";
	int totalSala = 30;
	int totalLocuri[] = { 1,2,3,4 };
	int nrRezervate = 2;
	int nrCumparate = 2;

	sala s1(numeSala, tipSala, totalSala, totalLocuri, nrRezervate, nrCumparate);
	sala s2(numeSala, tipSala, totalSala, totalLocuri, nrRezervate, nrCumparate);
	sala s3(numeSala, tipSala, totalSala, totalLocuri, nrRezervate, nrCumparate);

	adaugaSala(s1, totalSali, "sali.bin");
	adaugaSala(s2, totalSali, "sali.bin");
	adaugaSala(s3, totalSali, "sali.bin");
	sala cs3 = gasesteSala(3, totalSali, "sali.bin");
	sala cs2 = gasesteSala(2, totalSali, "sali.bin");
	sala cs1 = gasesteSala(1, totalSali, "sali.bin");
	cout << endl << "		Sala 1: " << endl << cs1 << endl << "		Sala 2: " << endl << cs2 << endl << "		Sala 3: " << cs3 << endl;



	return 0;
}