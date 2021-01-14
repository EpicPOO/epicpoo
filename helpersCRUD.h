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

int citesteTotalInt(string linie,string fname)
{
	int totalInt = 0;
	for (int i = 0; i < linie.length(); i++)
		if (linie[i] - '0' >= 0 && linie[i] - '0' <= 9)
			totalInt = totalInt * 10 + (linie[i] - '0');
	return totalInt;
}

void modifica(string obiect, int noulTotal, string fname) // functie modificare, facuta foarte raw, direct -> FUNCTIONEAZA DOAR PENTRU UN TOTAL < 10
{
	string copie = "copie.txt", buffer;
	if (obiect == "alimente")
	{
		adaugaTotalAlimente(noulTotal, copie); // adaugam noul total
		adaugaTotalAngajati(citesteTotalInt(citesteTotalAngajati(fname), fname), copie); //adaugam totalul de int citit de pe linia respectiva
		adaugaTotalBilete(citesteTotalInt(citesteTotalBilete(fname), fname), copie);
		adaugaTotalFilme(citesteTotalInt(citesteTotalFilme(fname), fname), copie);
		adaugaTotalSali(citesteTotalInt(citesteTotalSali(fname), fname), copie);
	}
	else if (obiect == "angajati")
	{
		adaugaTotalAlimente(citesteTotalInt(citesteTotalAlimente(fname), fname), copie);
		adaugaTotalAngajati(noulTotal, copie);
		adaugaTotalBilete(citesteTotalInt(citesteTotalBilete(fname), fname), copie);
		adaugaTotalFilme(citesteTotalInt(citesteTotalFilme(fname), fname), copie);
		adaugaTotalSali(citesteTotalInt(citesteTotalSali(fname), fname), copie);
	}
	else if (obiect == "bilete")
	{
		adaugaTotalAlimente(citesteTotalInt(citesteTotalAlimente(fname), fname), copie);
		adaugaTotalAngajati(citesteTotalInt(citesteTotalAngajati(fname), fname), copie);
		adaugaTotalBilete(noulTotal, copie);
		adaugaTotalFilme(citesteTotalInt(citesteTotalFilme(fname), fname), copie);
		adaugaTotalSali(citesteTotalInt(citesteTotalSali(fname), fname), copie);
	}
	else if (obiect == "filme")
	{
		adaugaTotalAlimente(citesteTotalInt(citesteTotalAlimente(fname), fname), copie);
		adaugaTotalAngajati(citesteTotalInt(citesteTotalAngajati(fname), fname), copie);
		adaugaTotalBilete(citesteTotalInt(citesteTotalBilete(fname), fname), copie);
		adaugaTotalFilme(noulTotal, copie);
		adaugaTotalSali(citesteTotalInt(citesteTotalSali(fname), fname), copie);
	}
	else
	{
		adaugaTotalAlimente(citesteTotalInt(citesteTotalAlimente(fname), fname), copie);
		adaugaTotalAngajati(citesteTotalInt(citesteTotalAngajati(fname), fname), copie);
		adaugaTotalBilete(citesteTotalInt(citesteTotalBilete(fname), fname), copie);
		adaugaTotalFilme(citesteTotalInt(citesteTotalFilme(fname), fname), copie);
		adaugaTotalSali(noulTotal, copie);
	}
	remove(fname.c_str());
	rename(copie.c_str(), fname.c_str());
}

void modifica2(string obiect, int noulTotal, string fname) // functie modificare, facuta foarte raw, direct -> FUNCTIONEAZA DOAR PENTRU UN TOTAL < 10
{
	string copie = "copie.txt", buffer;
	if (obiect == "alimente")
	{
		adaugaTotalAlimente(noulTotal, copie);
		adaugaTotalAngajati(citesteTotalAngajati(fname).back() - '0', copie); //citesteetc(fname).back() -> intoarce ultimul caracter - '0' -> transforma in int
		adaugaTotalBilete(citesteTotalBilete(fname).back() - '0', copie);
		adaugaTotalFilme(citesteTotalFilme(fname).back() - '0', copie);
		adaugaTotalSali(citesteTotalSali(fname).back() - '0', copie);
	}
	else if (obiect == "angajati")
	{
		adaugaTotalAlimente(citesteTotalAlimente(fname).back() - '0', copie);
		adaugaTotalAngajati(noulTotal, copie);
		adaugaTotalBilete(citesteTotalBilete(fname).back() - '0', copie);
		adaugaTotalFilme(citesteTotalFilme(fname).back() - '0', copie);
		adaugaTotalSali(citesteTotalSali(fname).back() - '0', copie);
	}
	else if (obiect == "bilete")
	{
		adaugaTotalAlimente(citesteTotalAlimente(fname).back() - '0', copie);
		adaugaTotalAngajati(citesteTotalAngajati(fname).back() - '0', copie);
		adaugaTotalBilete(noulTotal, copie);
		adaugaTotalFilme(citesteTotalFilme(fname).back() - '0', copie);
		adaugaTotalSali(citesteTotalSali(fname).back() - '0', copie);
	}
	else if (obiect == "filme")
	{
		adaugaTotalAlimente(citesteTotalAlimente(fname).back() - '0', copie);
		adaugaTotalAngajati(citesteTotalAngajati(fname).back() - '0', copie);
		adaugaTotalBilete(citesteTotalBilete(fname).back() - '0', copie);
		adaugaTotalFilme(noulTotal, copie);
		adaugaTotalSali(citesteTotalSali(fname).back() - '0', copie);
	}
	else
	{
		adaugaTotalAlimente(citesteTotalAlimente(fname).back() - '0', copie);
		adaugaTotalAngajati(citesteTotalAngajati(fname).back() - '0', copie);
		adaugaTotalBilete(citesteTotalBilete(fname).back() - '0', copie);
		adaugaTotalFilme(citesteTotalFilme(fname).back() - '0', copie);
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
