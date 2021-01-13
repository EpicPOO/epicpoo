#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void adauga(string obiect, int total, string fname)
{
	ofstream co;
	co.open(fname, std::ios_base::app);
	co << "Total " << obiect << ": " << total << "\n";
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

string citeste(int index, string fname)
{
	ifstream ci;
	string total;
	ci.open(fname);
	for (int i = 0; i < index; i++)
	{
		total = "";
		getline(ci, total);
	}
	return total;
}

void adaugaZeroTotal(string fname) // o sa apelam pentru a putea avea o ordine in fisierul text
{
	adaugaTotalAlimente(0, fname);
	adaugaTotalAngajati(0, fname);
	adaugaTotalBilete(0, fname);
	adaugaTotalFilme(0, fname);
	adaugaTotalSali(0, fname);
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

void modifica(string obiect, int noulTotal, string fname)
{
	string copie = "copie.txt", buffer;
	if (obiect == "alimente")
	{
		adaugaTotalAlimente(noulTotal, copie);
		adaugaTotalAngajati(citesteTotalAngajati(fname).back() - '0', copie);
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
