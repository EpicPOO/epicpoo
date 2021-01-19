#pragma once
#include<iostream>
#include<string>
#include<fstream>

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
	try
	{
		string numar = citesteTotalAlimente(fname).substr(citesteTotalAlimente(fname).find(": ") + 2, citesteTotalAlimente(fname).length() - citesteTotalAlimente(fname).find(": ") - 2);
		return stoi(numar, nullptr, 10);
	}
	catch (const std::exception&)
	{
		return 0;
	}
}

int citesteTotalAngajatiInt(string fname)
{
	try
	{
		string numar = citesteTotalAngajati(fname).substr(citesteTotalAngajati(fname).find(": ") + 2, citesteTotalAngajati(fname).length() - citesteTotalAngajati(fname).find(": ") - 2);
		return stoi(numar, nullptr, 10);
	}
	catch (const std::exception&)
	{
		return 0;
	}
}

int citesteTotalBileteInt(string fname)
{
	try
	{
		string numar = citesteTotalBilete(fname).substr(citesteTotalBilete(fname).find(": ") + 2, citesteTotalBilete(fname).length() - citesteTotalBilete(fname).find(": ") - 2);
		return stoi(numar, nullptr, 10);
	}
	catch (const std::exception&)
	{
		return 0;
	}
}


int citesteTotalFilmeInt(string fname)
{
	try
	{
		string numar = citesteTotalFilme(fname).substr(citesteTotalFilme(fname).find(": ") + 2, citesteTotalFilme(fname).length() - citesteTotalFilme(fname).find(": ") - 2);
		return stoi(numar, nullptr, 10);
	}
	catch (const std::exception&)
	{
		return 0;
	}
}

int citesteTotalSaliInt(string fname)
{
	try
	{
		string numar = citesteTotalSali(fname).substr(citesteTotalSali(fname).find(": ") + 2, citesteTotalSali(fname).length() - citesteTotalSali(fname).find(": ") - 2);
		return stoi(numar, nullptr, 10);
	}
	catch (const std::exception&)
	{
		return 0;
	}
}

void modifica(string obiect, int noulTotal, string fname) // functie modificare, facuta foarte raw
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

int stringToInt(string buffer) //functie - testeaza daca bufferul e numar. returneaza 0 daca nu e numar sau numarul
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
int stringToInt(string buffer,string tip) //functie - testeaza daca bufferul e numar. returneaza 0 daca nu e numar sau numarul
{
	int nr;
	if (tip == ">0")
	{

		try {
			nr = stoi(buffer, nullptr, 10);
		}
		catch (...) {
			nr = 0;
		}
		return nr;
	}
	if (tip == ">=0")
	{
		try {
			nr = stoi(buffer, nullptr, 10);
		}
		catch (...) {
			nr = -1;
		}
		return nr;
	}
}
 
bool testTipFisier(string buffer) // testare tip fisier: bin sau text
{
	string extensie = buffer.substr(buffer.find(".") + 1, buffer.length() - (buffer.find(".") + 1));
	if (extensie == "bin")
	{
		ifstream f(buffer, ios::binary); //deschidere fisierb daca exista
		if (!f) //testez daca se poate deschide fisierul
		{
			return 0;
		}
		else
		{
			//cout << " extensia este: " << extensie << endl; // de sters la forma finala
			return 1;
		}

	}
	if (extensie == "txt")
	{
		ifstream f(buffer, ios::binary);
		if (!f)  //testez daca se poate deschide fisierul
		{
			return 0;
		}
		else
		{
			//cout << " extensia este: " << extensie << endl; // de sters la forma finala
			return 1;
		}
	}
}

bool testareExistentaFisiere() //pentru a testa existenta fisierelor, fizic 
{
	bool film = 0, sala = 0, bilet = 0, aliment = 0, angajat = 0, total = 0;
	if (testTipFisier("filme.bin") == 1)
	{
		film = 1;
	}
	if (testTipFisier("sali.bin") == 1)
	{
		sala = 1;
	}
	if (testTipFisier("bilete.bin") == 1)
	{
		bilet = 1;
	}
	if (testTipFisier("alimente.bin") == 1)
	{
		aliment  =1;
	}
	if (testTipFisier("angajati.bin") == 1)
	{
		angajat = 1;
	}
	if (testTipFisier("total.txt") == 1)
	{
		total = 1;
	}
	if (film == 1 && sala == 1 && bilet == 1 && aliment == 1 && angajat == 1 && total == 1)
	{
		return 1;
	}
	else
	{
		if (film == 0)
		{
			cout << "Baza de date nu contine filme.bin" << endl;
		}
		if (sala == 0)
		{
			cout << "Baza de date nu contine sali.bin" << endl;
		}
		if (bilet== 0)
		{
			cout << "Baza de date nu contine bilete.bin" << endl;
		}
		if (aliment == 0)
		{
			cout << "Baza de date nu contine alimente.bin" << endl;
		}
		if (angajat == 0)
		{
			cout << "Baza de date nu contine angajati.bin" << endl;
		}
		if (total == 0)
		{
			cout << "Baza de date nu contine total.bin" << endl;
		}
		return 0;

	}
}



