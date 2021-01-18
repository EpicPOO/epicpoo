#include<iostream>
#include<string>
#include "sala.h"
#include "film.h"
#include "aliment.h"
#include "angajati.h"
#include "bilet.h"
#include "helpersCRUD.h"
#include "meniuAliment.h"//de sters dupa ce terminam proiectul ca sunt incluse in meniu.h si merg de acolo
#include "meniu.h"
#include "meniuSala.h" //de sters dupa ce terminam proiectul ca sunt incluse in meniu.h si merg de acolo
#include "meniuFilm.h"//de sters dupa ce terminam proiectul ca sunt incluse in meniu.h si merg de acolo
#include "meniuBilet.h"//de sters dupa ce terminam proiectul ca sunt incluse in meniu.h si merg de acolo
#include "meniuAngajat.h"//de sters dupa ce terminam proiectul ca sunt incluse in meniu.h si merg de acolo
#include "emitereBilet.h"
using namespace std;

int main()
{

	string fname = "total.txt";
	if (testTipFisier(fname) == 0)
	{
		adaugaZeroTotal(fname);
	}
	//cout << stringToInt("Gresit", ">=0") << endl;
	////sala(string numeSala, char* tipSala, int totalSala, int* totalLocuri, int nrRezervate, int nrCumparate) :idSala(++numarSali)
	//int nrTotalSali = citesteTotalSaliInt(fname);
	//int nr = 10;
	//int* locuri = new int[nr];
	//for (int i = 0; i < 10; i++) locuri[i] = 0;
	//sala s1((string)"Ion Creanga",(char*)"3d", nr,locuri,0,0);
	//adaugaSala(s1, nrTotalSali, "Sali.bin");
	//modificaSali(nrTotalSali, fname);
	//afisareSali(nrTotalSali, "Sali.bin");
	//int id = selectieSala();
	//cout<<endl<<gasesteSala(id, nrTotalSali, "Sali.bin");
	//int nrLocuriBilet = selectieNrLocuri(gasesteSala(id, nrTotalSali, "Sali.bin"));
	//int* locuriSelectate = new int[nrLocuriBilet];
	//locuriSelectate = selectieLocuri(gasesteSala(id, nrTotalSali, "Sali.bin"), nrLocuriBilet);
	//cout << "Locurile selectate sunt: ";
	//for (int i = 0; i < nrLocuriBilet; i++)
	//{
	//	cout << locuriSelectate[i] << ", ";
	//}
	//cout << "." << endl;
	//afisareSali(nrTotalSali, "Sali.bin");

	//string numeBil = "Avengers";
	//char oraBilet[] = "14.10.2020 15:30";
	//int lgBil = 5;
	//int locuri2[] = { 0, 1 , 4 , 7, 7 };
	//int nrBilete = citesteTotalBileteInt(fname);
	//bilet b1(numeBil, oraBilet, lgBil, locuri2, 24.5);
	//bilet b2(numeBil, oraBilet, lgBil, locuri2, 24.5);
	//adaugaBilet(b1, nrBilete, "Bilete.bin");
	//adaugaBilet(b2, nrBilete, "Bilete.bin");
	//modificaBilete(nrBilete,fname);
	//afisareBilete(nrBilete, "Bilete.bin");
	//adaugaBiletTxt(2, nrBilete, "Bilete.bin");
	//bilet b3 = gasesteBilet(6, nrBilete, "Bilete.bin");
	//cout << endl << b3;
		string stringuri[2];
	stringuri[0] = "15.10 15:30 - 17:30";
	stringuri[1] = "16.10 15:50 - 17:50";
	string nume = "Avengers";
	char tip[] = "3D";
	int varsta = 14, nr2 = 2;

	film f2(nume, tip, varsta, nr2, stringuri);
	//cout << "Test constructor cu parametri:\n" << f2 << "\n\n";
	int nrFilme = citesteTotalFilmeInt("Total.txt");

	film f3 = f2;
	adaugaFilm(f2, nrFilme, "Filme.bin");
	adaugaFilm(f3, nrFilme, "Filme.bin");
	adaugaFilm(f3, nrFilme, "Filme.bin");
	modificaFilme(nrFilme, fname);
	afisareFilme(nrFilme, "Filme.bin");
	cout << endl << endl;
	int nrTotalSali = citesteTotalSaliInt(fname);
	int nr1 = 10;
	int* locuri = new int[nr1];
	for (int i = 0; i < 10; i++) locuri[i] = 0;
	sala s1((string)"Ion Creanga",(char*)"3d", nr1,locuri,0,0);
	adaugaSala(s1, nrTotalSali, "Sali.bin");
	adaugaSala(s1, nrTotalSali, "Sali.bin");
	adaugaSala(s1, nrTotalSali, "Sali.bin");
	modificaSali(nrTotalSali, fname);
	afisareSali(nrTotalSali, "Sali.bin");
	film f4;
	f4 = gasesteFilm(2, nrFilme, "Filme.bin");
	//cout << f4 << endl;

	//int idSala = selectieSala();
	//cout << endl << gasesteSala(idSala, nrTotalSali, "Sali.bin") << endl;
	//int nrLocuri = selectieNrLocuri(gasesteSala(idSala, nrTotalSali, "Sali.bin"));
	//int* locuriAlese = new int[nrLocuri];
	//locuriAlese =selectieLocuri(gasesteSala(idSala, nrTotalSali, "Sali.bin"), nrLocuri);
	//for (int i = 0; i < nrLocuri; i++)
	//{
	//	cout << locuriAlese[i] << ", ";
	//}
	int idFilm = selectiefilm(); 
	film filmTest = gasesteFilm(idFilm, nrFilme, "Filme.bin");
	
	//cout << endl << gasesteFilm(idFilm, nrFilme, "Filme.bin") << endl;
	/*int selectieProgr = selectieProgramFilm(filmTest);
	cout << selectieProgr << endl;
	int nrRulari = filmTest.getNrRulari();
	string* program = new string[nrRulari];
	program = filmTest.getProgram();
	string programAles = program[selectieProgr];
	char* prog = new char[programAles.length()+1];
	prog = (char*)programAles.c_str();*/

	/*cout<<gasesteFilm(115, nrFilme, "Filme.bin");*/
	emitereBilet();
	int nrBilete = citesteTotalBileteInt("Total.txt");
	
	afisareBilete(nrBilete, "Bilete.bin");
	string test = "16.10 15:50 - 17:50";



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
	//if (strcmp(B.getTipSala(), "2D") == 0) { cout << "Corect Tip Sala" << endl; }				else { cout << "Gresit Tip Sala" << endl; }
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
	//if (strcmp(F.getTipSala(), "2D") == 0) { cout << "Corect Tip Sala" << endl; }				else { cout << "Gresit Tip Sala" << endl; }
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

	//cout << "		SUPRAINCARCAREA OPERATORULUI<" << endl;
	//if (A < B) { cout << "TRUE " << A.getTotalLocuri() << " < " << B.getTotalLocuri(); }
	//else { cout << "FALSE " << A.getNrLibere() << " > " << B.getNrLibere(); }

	//cout << "		SUPRAINCARCAREA OPERATORULUI==" << endl;
	//if (A == B) { cout << "TRUE! Obiecte identice" << endl; }
	//else { cout << "FALSE! Obiecte DIFERITE" << endl; }
	//sala G = A;
	//if (A == G) { cout << "TRUE! Obiecte identice" << endl; }
	//else { cout << "FALSE! Obiecte DIFERITE" << endl; }

	//cout << "		SUPRAINCARCAREA OPERATORULUI++" << endl;
	//cout << "Total locuri inainte de INCREMENTARE: "<< A.getTotalSala() << endl;
	//cout << "Total locuri  PRE-INCREMENTARE : " << endl << A++ << endl;
	//cout << "Total locuri DUPA PRE-INCREMENTARE: " << A.getTotalSala() << endl;
	//cout << "Total locuri POST-INCREMENTARE: " << ++A << endl;
	//cout << "Total locuri DUPA POST-INCREMENTARE: " << A.getTotalSala() << endl;

	//cout << "		Operatorul de CAST IMPLICIT si EXPLICIT" << endl;
	//int locuriLibere = (int)A;
	//cout << "Locuri libere sala " << A() << " " << locuriLibere << endl;

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
	//angajati angajat5(numeAngajat, telefon, adresa, email, salariu, varstaAngajat);
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
	///*int totalBilete = 4;
	//bilet b1, b2, b3, b4;
	//cin >> b1 >> b2 >> b3 >> b4;
	//adaugaBilet(b1, totalBilete, "bilete.bin");
	//adaugaBilet(b2, totalBilete, "bilete.bin");
	//adaugaBilet(b3, totalBilete, "bilete.bin");
	//adaugaBilet(b4, totalBilete, "bilete.bin");
	//bilet cb4 = gasesteBilet(4, totalBilete, "bilete.bin");
	//bilet cb1 = gasesteBilet(1, totalBilete, "bilete.bin");
	//bilet cb2 = gasesteBilet(2, totalBilete, "bilete.bin");
	//bilet cb5 = gasesteBilet(5, totalBilete, "bilete.bin");
	//cout << cb1 << endl << cb2 << endl << cb4 << endl << cb5;

	//cout << "\n\nActualizare bilet 1 cu bilet 2:\n";
	//stergeBilet(2, totalBilete, "bilete.bin");
	//bilet actualizat = gasesteBilet(1, totalBilete, "bilete.bin");
	//cout << actualizat;
	//bilet gasit = gasesteBilet(3, totalBilete, "bilete.bin");
	//cout << gasit;*/

	// Testare FAza II Buharu
	//	int totalSali = 3;
	//	//sala(string numeSala, char* tipSala, int totalSala, int* totalLocuri, int nrRezervate, int nrCumparate)
	//	string numeSala = "Ion Creanga";
	//	char tipSala[] = "3d";
	//	int totalSala = 30;
	//	int totalLocuri[] = { 1,2,3,4 };
	//	int nrRezervate = 2;
	//	int nrCumparate = 2;

	//	sala s1(numeSala, tipSala, totalSala, totalLocuri, nrRezervate, nrCumparate);
	//	sala s2(numeSala, tipSala, totalSala, totalLocuri, nrRezervate, nrCumparate);
	//	sala s3(numeSala, tipSala, totalSala, totalLocuri, nrRezervate, nrCumparate);

	//	adaugaSala(s1, totalSali, "sali.bin");
	//	adaugaSala(s2, totalSali, "sali.bin");
	//	adaugaSala(s3, totalSali, "sali.bin");
	//	stergeSala(2, totalSali, "sali.bin");
	//	sala cs3 = gasesteSala(3, totalSali, "sali.bin");
	//	actualizareSala(1, s2, totalSali, "sali.bin");
	//	sala cs2 = gasesteSala(2, totalSali, "sali.bin");
	//	sala cs1 = gasesteSala(1, totalSali, "sali.bin");
	//	cout << endl << "		Sala 1: " << endl << cs1 << endl << "		Sala 2: " << endl << cs2 << endl << "		Sala 3: " << cs3 << endl;
	//	

	//int nrAngajati = 3;
	//angajat2.setNume((char*)"Vlad Buharu");
	//adaugaAngajat(angajat2, nrAngajati, "angajati.bin");
	//adaugaAngajat(angajat4, nrAngajati, "angajati.bin");
	//adaugaAngajat(angajat5, nrAngajati, "angajati.bin");

	//angajat2.setNume((char*)"Vlad");
	//angajati a3 = gasesteAngajat(3, nrAngajati, "angajati.bin");


	//stergeAngajat(2, nrAngajati, "angajati.bin");

	//actualizareAngajat(1, angajat2, nrAngajati, "angajati.bin");
	//angajati a1 = gasesteAngajat(1, nrAngajati, "angajati.bin");
	//angajati a2 = gasesteAngajat(2, nrAngajati, "angajati.bin");
	//cout << "		Angajat 1: " << endl << a1 << endl << "		Angajat 2: " << endl << a2 << endl << "		Angajat 3: " << endl << a3 << endl;

	////Teste functii globale - Andrei

	//adaugaZeroTotal(fname);

	//modificaAlimente(2147483647, fname);
	//modificaAngajati(2147483647, fname);
	//modificaBilete(2147483647, fname);
	//modificaFilme(2147483647, fname);
	//modificaSali(2147483647, fname);

	////integrare cu bilet
	//bilet b1, b2, b3, b4;
	//int nrTotalBilete = 0;
	////cin >> b1 >> b2 >> b3 >> b4;
	//string finame = "bilete.bin";
	//nrTotalBilete = citesteTotalBilete(fname).back() - '0';
	//adaugaBilet(b1, nrTotalBilete, finame);
	//adaugaBilet(b2, nrTotalBilete, finame);
	//adaugaBilet(b3, nrTotalBilete, finame);
	//adaugaBilet(b4, nrTotalBilete, finame);

	//cout << "Inainte de stergere: " << nrTotalBilete << "\n";
	//stergeBilet(3, nrTotalBilete, finame);
	//b3 = gasesteBilet(3, nrTotalBilete, finame);

	//cout << b1 << "\n" << b2 << "\n" << b3 << "\n" << b4 << "\n" << "Dupa stergere: " << nrTotalBilete << "\n";
	//modificaBilete(nrTotalBilete, fname);

	//// integrare cu sala
	//adaugaZeroTotal(fname);
	//string salibin = "sali.bin", numeSala1 = "Ion", numeSala2 = "Mirel", numeSala3 = "Gigel";

	//int nrTotalSali = citesteTotalSaliInt(fname);
	//char tipSala[] = "3d";
	//int totalSala = 30;
	//int totalLocuri[] = { 1,2,3,4 };
	//int nrRezervate = 2;
	//int nrCumparate = 2;

	//sala s1(numeSala1, tipSala, totalSala, totalLocuri, nrRezervate, nrCumparate);
	//sala s2(numeSala2, tipSala, totalSala, totalLocuri, nrRezervate, nrCumparate);
	//sala s3(numeSala3, tipSala, totalSala, totalLocuri, nrRezervate, nrCumparate);
	//sala s4(numeSala3, tipSala, totalSala, totalLocuri, nrRezervate, nrCumparate);

	//adaugaSala(s1, nrTotalSali, salibin);
	//adaugaSala(s2, nrTotalSali, salibin);
	//adaugaSala(s3, nrTotalSali, salibin);

	//afisareSali(nrTotalSali, salibin);
	//modificaSali(nrTotalSali, fname);

//
////	teste clasa film Faza II Buharu

	//string stringuri[2];
	//string fisierFilme = "filme.bin";
	//stringuri[0] = "15.10 15:30  17:30";
	//stringuri[1] = "16.10 15:50  17:50";
	//string nume = "Avengers";
	//char tip[] = "3D";
	//int varsta = 14, nr = 2;
	//string numeNou = "The Priest";

	//int nrTotalFilme = citesteTotalFilme(fname).back() - '0';

	//film f2(nume, tip, varsta, nr, stringuri);
	//film f3(nume, tip, varsta, nr, stringuri);
	//film f4(nume, tip, varsta, nr, stringuri);

	//adaugaFilm(f2, nrTotalFilme, fisierFilme);
	//adaugaFilm(f3, nrTotalFilme, fisierFilme);
	//adaugaFilm(f4, nrTotalFilme, fisierFilme);

	//modificaFilme(nrTotalFilme, "Total.txt");
	//afisareFilme(nrTotalFilme, fisierFilme);

	//film cf2 = gasesteFilm(1, nrTotalFilme, fisierFilme);
	//film cf3 = gasesteFilm(2, nrTotalFilme, fisierFilme);
	//film cf4 = gasesteFilm(3, nrTotalFilme, fisierFilme);
	//stergeFilm(1, nrTotalFilme, fisierFilme);
	//f3.setNumeFilm(numeNou);
	//actualizareFilm(2, f3, nrTotalFilme, fisierFilme);

	//film cf5 = gasesteFilm(2, nrTotalFilme, fisierFilme);

	//cout << "\n\ns1:\n" << cf2 << "\n\ns2:\n" << cf3 << "\n\ns3:\n" << cf4 << "\n\ns4:\n" <<  cf5 << endl;
	//modificaFilme(nrTotalFilme, fname);


	////Stefana: teste pentru alimente

	///*aliment(string numeAliment, const char* categorie, int lungimeCod, int* codBare, float pret) : idAliment(++numarAlimente);
	//aliment a1;
	//cin >> a1;
	//cout << a1 << endl;
	//aliment a2;
	//cin >> a2;
	//cout << a2 << endl;*/

	////Stefana: Teste meniu alimente
	//string numeA1 = "Bere", numeA2 = "Popcorn", numeA3 = "CocaCola", numeA4 = "Alune";
	//char categA1[] = "Bauturi", categA2[] = "Snack", categA3[] = "Bauturi", categA4[] = "Snack";
	//int lgCodAll = 8;
	//int codB1[] = { 1,1,1,1,1,1,1,1 }, codB2[] = { 2,2,2,2,2,2,2,2 }, codB3[] = { 3,3,3,3,3,3,3,3 }, codB4[] = { 4,4,4,4,4,4,4,4,4 };
	//string fileAliment = "alimente.bin";
	//float pA1 = 10.0f, pA2 = 15.5f, pA3 = 12.0f, pA4 = 21.2f;

	////aliment(string numeAliment, const char* categorie, int lungimeCod, int* codBare, float pret) : idAliment(++numarAlimente)
	//aliment a1(numeA1, categA1, lgCodAll, codB1, pA1);
	//aliment a2(numeA2, categA2, lgCodAll, codB2, pA2);
	//aliment a3(numeA3, categA3, lgCodAll, codB3, pA3);
	//aliment a4(numeA4, categA4, lgCodAll, codB4, pA4);
	////adaugaZeroTotal(fname);
	//int nrTotalAlimente = 0;
	//adaugaAliment(a1, nrTotalAlimente, fileAliment);
	//adaugaAliment(a2, nrTotalAlimente, fileAliment);
	//adaugaAliment(a3, nrTotalAlimente, fileAliment);
	//adaugaAliment(a4, nrTotalAlimente, fileAliment);
	////modificaAlimente(nrTotalAlimente, fname);
	//afisareAlimente(nrTotalAlimente, fileAliment);
	////aliment gasesteAliment(int id, int nrTotalAlimente, string fname)
	////meniuAliment();
	//cout << gasesteAliment(2, nrTotalAlimente, fileAliment) << endl;

	////aliment a5=adaugaAlimentConsola();
	////cout << a5 << endl;

	////meniuAliment();

	//////Buharu test pentru functia testTipFisier
	////if (testTipFisier(fileAliment) == 0)
	////{
	////	cout << "Nu exista fisierul" << endl;
	////}
	////else
	////{
	////	cout << "Exista fisierul" << endl;
	////}
	////if (testTipFisier("Total.txt") == 0)
	////{
	////	cout << "Nu exista fisierul" << endl;
	////}
	////else
	////{
	////	cout << "Exista fisierul" << endl;
	////}
	//////Buharu test pentru meniu.h
	//meniu();
	////Buharu testare meniuSala.h
	////meniuSala();
	////Buharu testare meniuFilm.h
	////meniuFilm();
	////Buharu testare meniuBilet.h
	////meniuBilet();
	////Buharu testare meniuAngajat.h
	////meniuAngajat();


	return 0;


}

