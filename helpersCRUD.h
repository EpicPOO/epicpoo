#pragma once
#include<iostream>
#include<string>
#include<fstream>

//all done

using namespace std;

void adauga(string obiect, int total, string fname) // functie "template care va fi apelata de catre celalalte functii specifice
{
	ofstream co;
	co.open(fname, std::ios_base::app);
	co << "Total " << obiect << ": " << total << "\n"; // adaugam "Total <obiect>: <total>\n"  
}

void adaugaTotalAlimente(int totalAlimente, string fname)
{
	adauga("alimente", totalAlimente, fname);
}

void adaugaTotalAngajati(int totalAngajati, string fname)
{
	adauga("angajati", totalAngajati, fname);
}

void adaugaTotalBilete(int totalBilete, string fname)
{
	adauga("bilete", totalBilete, fname);
}

void adaugaTotalFilme(int totalFilme, string fname)
{
	adauga("filme", totalFilme, fname);
}

void adaugaTotalSali(int totalSali, string fname)
{
	adauga("sali", totalSali, fname);
}

void adaugaZeroTotal(string fname) // o sa apelam pentru a putea avea o ordine in fisierul text
{
	adaugaTotalAlimente(0, fname);
	adaugaTotalAngajati(0, fname);
	adaugaTotalBilete(0, fname);
	adaugaTotalFilme(0, fname);
	adaugaTotalSali(0, fname);
}

string citeste(int index, string fname) // functie template, ca la adaugare index = 1 -> alimente, 2 -> angajati, 3 -> bilete, 4 -> filme , 5 -> sali
{
	ifstream ci;
	string total;
	ci.open(fname);
	for (int i = 0; i < index; i++)
	{
		total = "";
		getline(ci, total); // citeste in "total" linie cu linie. cand e o linie noua il suprascrie
	}
	return total;
}

string citesteTotalAlimente(string fname)
{
	return citeste(1, fname); 
}

string citesteTotalAngajati(string fname)
{
	return citeste(2, fname);
}

string citesteTotalBilete(string fname)
{
	return citeste(3, fname);
}

string citesteTotalFilme(string fname)
{
	return citeste(4, fname);
}

string citesteTotalSali(string fname)
{
	return citeste(5, fname);
}

int citesteTotalAlimenteInt(string fname)
{
	string numar = citesteTotalAlimente(fname).substr(citesteTotalAlimente(fname).find(": ") + 2, citesteTotalAlimente(fname).length() - citesteTotalAlimente(fname).find(": ") - 2);
	return stoi(numar, nullptr, 10);
}

int citesteTotalAngajatiInt(string fname)
{
	string numar = citesteTotalAngajati(fname).substr(citesteTotalAngajati(fname).find(": ") + 2, citesteTotalAngajati(fname).length() - citesteTotalAngajati(fname).find(": ") - 2);
	return stoi(numar, nullptr, 10);
}

int citesteTotalBileteInt(string fname)
{
	string numar = citesteTotalBilete(fname).substr(citesteTotalBilete(fname).find(": ") + 2, citesteTotalBilete(fname).length() - citesteTotalBilete(fname).find(": ") - 2);
	return stoi(numar, nullptr, 10);
}


int citesteTotalFilmeInt(string fname)
{
	string numar = citesteTotalFilme(fname).substr(citesteTotalFilme(fname).find(": ") + 2, citesteTotalFilme(fname).length() - citesteTotalFilme(fname).find(": ") - 2);
	return stoi(numar, nullptr, 10);
}

int citesteTotalSaliInt(string fname)
{
	string numar = citesteTotalSali(fname).substr(citesteTotalSali(fname).find(": ") + 2, citesteTotalSali(fname).length() - citesteTotalSali(fname).find(": ") - 2);
	return stoi(numar, nullptr, 10);
}

void modifica(string obiect, int noulTotal, string fname) // functie modificare, facuta foarte raw, direct -> FUNCTIONEAZA DOAR PENTRU UN TOTAL < 10
{
	string copie = "copie.txt", buffer;
	if (obiect == "alimente")
	{
		adaugaTotalAlimente(noulTotal, copie); // adaugam noul total
		adaugaTotalAngajati(citesteTotalAngajatiInt(fname), copie);
		adaugaTotalBilete(citesteTotalBileteInt(fname), copie);
		adaugaTotalFilme(citesteTotalFilmeInt(fname), copie);
		adaugaTotalSali(citesteTotalSaliInt(fname), copie);
	}
	else if (obiect == "angajati")
	{
		adaugaTotalAlimente(citesteTotalAlimenteInt(fname), copie); // adaugam noul total
		adaugaTotalAngajati(noulTotal, copie);
		adaugaTotalBilete(citesteTotalBileteInt(fname), copie);
		adaugaTotalFilme(citesteTotalFilmeInt(fname), copie);
		adaugaTotalSali(citesteTotalSaliInt(fname), copie);
	}
	else if (obiect == "bilete")
	{
		adaugaTotalAlimente(citesteTotalAlimenteInt(fname), copie); // adaugam noul total
		adaugaTotalAngajati(citesteTotalAngajatiInt(fname), copie);
		adaugaTotalBilete(noulTotal, copie);
		adaugaTotalFilme(citesteTotalFilmeInt(fname), copie);
		adaugaTotalSali(citesteTotalSaliInt(fname), copie);
	}
	else if (obiect == "filme")
	{
		adaugaTotalAlimente(citesteTotalAlimenteInt(fname), copie); // adaugam noul total
		adaugaTotalAngajati(citesteTotalAngajatiInt(fname), copie);
		adaugaTotalBilete(citesteTotalBileteInt(fname), copie);
		adaugaTotalFilme(noulTotal, copie);
		adaugaTotalSali(citesteTotalSaliInt(fname), copie);
	}
	else
	{
		adaugaTotalAlimente(citesteTotalAlimenteInt(fname), copie); // adaugam noul total
		adaugaTotalAngajati(citesteTotalAngajatiInt(fname), copie);
		adaugaTotalBilete(citesteTotalBileteInt(fname), copie);
		adaugaTotalFilme(citesteTotalFilmeInt(fname), copie);
		adaugaTotalSali(noulTotal, copie);
	}
	remove(fname.c_str());
	rename(copie.c_str(), fname.c_str());
}

void modificaAlimente(int totalAlimente, string fname)
{
	modifica("alimente", totalAlimente, fname);
}

void modificaAngajati(int totalAngajati, string fname)
{
	modifica("angajati", totalAngajati, fname);
}

void modificaBilete(int totalBilete, string fname)
{
	modifica("bilete", totalBilete, fname);
}

void modificaFilme(int totalFilme, string fname)
{
	modifica("filme", totalFilme, fname);
}

void modificaSali(int totalSali, string fname)
{
	modifica("sali", totalSali, fname);
}

int stringToInt(string buffer) //Stefana: functie - testeaza daca bufferul e numar. returneaza 0 daca nu e numar sau numarul
{
	int nr;
	try {
		nr = stoi(buffer, nullptr, 10);
	}
	catch (...) {
		nr = 0;
	}
	return nr;
}