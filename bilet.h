#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//minim un array de caractere -> done and tested
//minim un array de int -> done and tested
//camp static? -> done and tested
//getteri setteri -> done and tested
//vallidari la setteri -> done and tested
//regula celor 3 -> done and tested
//>> << -> done and tested
//+,-,* sau /  -> done for - and tested
//++ sau -- cu cele 2 forme ->  done and tested
//cast explicit sau implicit -> done and tested
// ! -> done and tested
//< > =< sau >= -> done for < and tested
//==  -> done and tested

class bilet
{
private:
	const int idBilet = 0;
	string numeBilet; //ca la sala
	char* oraBilet;
	int nrLocuri;
	int* locuriBilet;
	float pretTotal;
	static int numarBilete; //folosit in constructori pentru a pune un id biletului (preincrementare)
public:
	bilet() : idBilet(++numarBilete) //cstr implicit
	{
		numeBilet = "";
		oraBilet = nullptr;
		nrLocuri = 0;
		locuriBilet = nullptr;
		pretTotal = 0.0;
	}

	bilet(std::string numeBilet, const char* oraBilet, int nrLocuri, int* locuriBilet, float pretTotal) : idBilet(++numarBilete)
	{
		if (numeBilet != "") this->numeBilet = numeBilet;//validara numeBilet, string
		else this->numeBilet = "";

		if (oraBilet != nullptr)//validare oraBilet, char*
		{
			this->oraBilet = new char[strlen(oraBilet) + 1];
			strcpy_s(this->oraBilet, strlen(oraBilet) + 1, oraBilet);
		}
		else
		{
			this->oraBilet = new char[strlen("Necunoscuta") + 1];
			strcpy_s(this->oraBilet, strlen("Necunoscuta") + 1, "Necunoscuta");
		}


		if (locuriBilet != nullptr && nrLocuri > 0)
		{
			this->nrLocuri = nrLocuri;
			this->locuriBilet = new int[nrLocuri];
			for (int i = 0; i < nrLocuri; i++)
				this->locuriBilet[i] = locuriBilet[i];
		}
		else
		{
			this->nrLocuri = 0;
			this->locuriBilet = nullptr;
		}

		if (pretTotal > 0) this->pretTotal = pretTotal;
		else pretTotal = 0.0;
	}

	bilet(const bilet& b) :idBilet(b.idBilet) //cstr de copiere
	{
		if (b.numeBilet != "") numeBilet = b.numeBilet;//validara numeBilet, string
		else numeBilet = "";

		if (b.oraBilet != nullptr)//validare oraBilet, char*
		{
			oraBilet = new char[strlen(b.oraBilet) + 1];
			strcpy_s(oraBilet, strlen(b.oraBilet) + 1, b.oraBilet);
		}
		else
		{
			oraBilet = new char[strlen("Necunoscuta") + 1];
			strcpy_s(oraBilet, strlen("Necunoscuta") + 1, "Necunoscuta");
		}

		if (b.locuriBilet != nullptr && b.nrLocuri > 0)//validare la array ul de stringuri + marime
		{
			nrLocuri = b.nrLocuri;
			locuriBilet = new int[b.nrLocuri];
			for (int i = 0; i < b.nrLocuri; i++)
				locuriBilet[i] = b.locuriBilet[i];
		}
		else
		{
			nrLocuri = 0;
			locuriBilet = nullptr;
		}

		if (b.pretTotal > 0) pretTotal = b.pretTotal;//validare pretTotal, int
		else pretTotal = 0;
	}

	bilet operator=(bilet b)//operator =
	{
		if (b.numeBilet != "") numeBilet = b.numeBilet;//validara numeBilet, string
		else numeBilet = "";

		if (oraBilet != b.oraBilet)
		{//evitam autoasignarea, poate cauza probleme cand stergem arrayul daca facem f = f 
			if (oraBilet != nullptr) delete[] oraBilet; //stergere oraBilet daca are ceva in el
			if (b.oraBilet != nullptr)//validare oraBilet, char*
			{
				oraBilet = new char[strlen(b.oraBilet) + 1];
				strcpy_s(oraBilet, strlen(b.oraBilet) + 1, b.oraBilet);
			}
			else
			{
				oraBilet = new char[strlen("Necunoscuta") + 1];
				strcpy_s(oraBilet, strlen("Necunoscuta") + 1, "Necunoscuta");
			}
		}

		if (locuriBilet != b.locuriBilet)
		{//la fel ca la oraBilet
			if (locuriBilet != nullptr) delete[] locuriBilet; //stergere locuriBilet daca are ceva in el
			if (b.locuriBilet != nullptr && b.nrLocuri > 0)//validare la array ul de stringuri + marime
			{
				nrLocuri = b.nrLocuri;
				locuriBilet = new int[b.nrLocuri];
				for (int i = 0; i < b.nrLocuri; i++)
					locuriBilet[i] = b.locuriBilet[i];
			}
			else
			{
				nrLocuri = 0;
				locuriBilet = nullptr;
			}
		}

		if (b.pretTotal > 0) pretTotal = b.pretTotal;//validare pretTotal, int
		else pretTotal = 0;

		return *this;
	}

	~bilet() //destructor
	{
		if (oraBilet != nullptr) delete[] oraBilet;
		if (locuriBilet != nullptr) delete[] locuriBilet;
	}

	//getter + setteri cu validari

	string getNumeBilet() { return numeBilet; }
	void setNumeBilet(string numeBilet)
	{
		if (numeBilet != "")
			this->numeBilet = numeBilet;
		else this->numeBilet = "";
	}

	char* getOraBilet() { return oraBilet; }
	void setOraBilet(char* oraBilet)
	{
		if (this->oraBilet != nullptr) delete[] this->oraBilet; //stergere oraBilet daca are ceva in el
		if (oraBilet != nullptr)//validare oraBilet, char*
		{
			this->oraBilet = new char[strlen(oraBilet) + 1];
			strcpy_s(this->oraBilet, strlen(oraBilet) + 1, oraBilet);
		}
		else
		{
			this->oraBilet = new char[strlen("Necunoscuta") + 1];
			strcpy_s(this->oraBilet, strlen("Necunoscuta") + 1, "Necunoscuta");
		}
	}

	float getPretTotal() { return pretTotal; }
	void setPretTotal(float pretTotal)
	{
		if (pretTotal > 0) this->pretTotal = pretTotal;
		else pretTotal = 0;
	}

	int getNrLocuri() { return nrLocuri; }
	void setNrLocuri(int nrLocuri)
	{
		if (nrLocuri > 0) this->nrLocuri = nrLocuri;
		else nrLocuri = 0;
	}

	int* getLocuriBilet() { return locuriBilet; }
	void setLocuriBilet(int* locuriBilet, int nrLocuri)
	{
		setNrLocuri(nrLocuri);

		if (this->locuriBilet != nullptr) delete[] this->locuriBilet;
		if (locuriBilet != nullptr)
		{
			this->locuriBilet = new int[nrLocuri];
			for (int i = 0; i < nrLocuri; i++)
				this->locuriBilet[i] = locuriBilet[i];
		}
		else this->locuriBilet = nullptr;
	}

	bilet operator-(float price)//scade un float din pret
	{
		bilet copie = *this;
		copie.pretTotal -= price;
		return copie;
	}

	char& operator[](int index) throw (exception) //supraincarcare operator[] pt char 
	{
		if ((index >= 0 && index < strlen(oraBilet) + 1) && oraBilet != nullptr)
			return oraBilet[index];
		else throw exception("Index invalid");
	}

	bool operator!() //supraincarcare operator ! -> daca avem locuriBilet
	{
		return locuriBilet != nullptr;
	}

	bilet operator++() // incrementeaza nrLocuri
	{
		this->nrLocuri++;
		return *this;
	}

	bilet operator++(int i) // preincrementeaza nrLocuri
	{
		bilet copie = *this;
		this->nrLocuri++;
		return copie;
	}

	explicit operator int()//cast explicit la int, intoarce pretul
	{
		return (int)pretTotal;
	}

	string operator()()//cast implicit la string, intoarce numele
	{
		return numeBilet;
	}



	//functii friend
	friend ostream& operator<<(ostream&, bilet);
	friend istream& operator>>(istream&, bilet&);
	friend bool operator<(bilet, bilet);
	friend bool operator==(bilet, bilet);

	/*
const int idBilet = 0;
string numeBilet; //ca la sala
char* oraBilet;
int nrLocuri;
int* locuriBilet;
float pretTotal;
static int numarBilete; //folosit in constructori pentru a pune un id biletului (preincrementare)
*/
	void inchidereFisier(ifstream f)
	{
		f.close();
	}

	ifstream deschidereFisier(string numeFisier)
	{
		ifstream f(numeFisier, ios::binary);
		return f;
	}
	void serializare()
	{
		ofstream f("bilete.bin", ios::app);
		f.write((char*)&idBilet, sizeof(idBilet));
		int lengthNume = numeBilet.length() + 1;
		f.write((char*)&lengthNume, sizeof(lengthNume)); //dimensiunea biletului
		f.write(numeBilet.c_str(), lengthNume); // scriere numeBilet
		int lengthOra = strlen(oraBilet) + 1; //modificati sa fie doar o variabila pentru o mai buna gestionare a memoriei
		f.write((char*)&lengthOra, sizeof(lengthOra)); // dimensiunea orei
		f.write(oraBilet, lengthOra); //scriere ora
		f.write((char*)&nrLocuri, sizeof(nrLocuri)); //scriere nrLocuri
		for (int i = 0; i < nrLocuri; i++)
		{
			f.write((char*)&locuriBilet[i], sizeof(locuriBilet[i]));
		}
		f.write((char*)&pretTotal, sizeof(pretTotal));
		f.close();
	}

	void deserializare()
	{
		ifstream f("bilete.bin", ios::binary);
		f.read((char*)&idBilet, sizeof(idBilet));
		int length = 0;
		f.read((char*)&length, sizeof(length));
		char* aux = new char[length];
		f.read(aux, length);
		setNumeBilet(aux); //am citit numeBilet
		length = 0;
		f.read((char*)&length, sizeof(length));
		delete[] aux;
		aux = new char[length];
		f.read(aux, length);
		setOraBilet(aux);
		f.read((char*)&nrLocuri, sizeof(nrLocuri)); //nrLocuri
		int* copie = new int[nrLocuri];
		for (int i = 0; i < nrLocuri; i++)
		{
			f.read((char*)&copie[i], sizeof(copie[i]));
		}
		setLocuriBilet(copie, nrLocuri); //LocuriBilet
		f.read((char*)&pretTotal, sizeof(pretTotal));
		f.close();
	}
};

int bilet::numarBilete = 0;

ostream& operator<<(ostream& out, bilet b) // operator afisare
{
	out << "ID bilet: " << b.idBilet << endl;
	out << "Nume bilet/film: " << b.numeBilet << endl;
	out << "Tip bilet: " << b.oraBilet << endl;
	out << "Pretul total: " << b.pretTotal << endl;
	out << "Cate locuri sunt pe bilet: " << b.nrLocuri << endl;
	out << "Locurile de pe bilet: ";
	if (b.locuriBilet != nullptr)
		for (int i = 0; i < b.nrLocuri; i++)
			out << b.locuriBilet[i] << " | ";
	return out;
}

istream& operator>>(istream& in, bilet& b) // operator citire
{
	cout << "Nume bilet/film: ";
	in >> ws;
	getline(in, b.numeBilet);

	cout << "Tip bilet: ";
	char buffer[20];
	in.getline(buffer, 19);
	if (b.oraBilet != nullptr) delete[] b.oraBilet;
	b.oraBilet = new char[strlen(buffer) + 1];
	strcpy_s(b.oraBilet, strlen(buffer) + 1, buffer);

	cout << "Pretul total: ";
	in >> b.pretTotal;
	if (b.pretTotal < 0)
	{
		cout << "Pretul trebuie sa fie cel putin 0! Alege din nou: ";
		in >> b.pretTotal;
	}

	cout << "Cate locuri sunt pe bilet: ";
	in >> b.nrLocuri;
	if (b.nrLocuri < 1)
	{
		cout << "Biletul adaugat trebuie sa contina cel putin un loc! Alege din nou: ";
		in >> b.nrLocuri;
	}

	cout << "Locurile de pe bilet: ";
	b.locuriBilet = new int[b.nrLocuri];
	for (int i = 0; i < b.nrLocuri; i++)
		in >> b.locuriBilet[i];

	return in;
}

bool operator<(bilet f1, bilet f2) //operator <, dupa pret
{
	return(f1.pretTotal < f2.pretTotal);
}

bool operator==(bilet f1, bilet f2)
{
	if (f1.numeBilet != f2.numeBilet || f1.pretTotal != f2.pretTotal || f1.nrLocuri != f2.nrLocuri)
		return false;
	for (int i = 0; i < f1.nrLocuri; i++)
		if (f1.locuriBilet[i] != f2.locuriBilet[i])
			return false;
	return true;
}


void adaugaBilet(bilet nou)
{
	nou.serializare();
}

//void gasesteBilet(int id)
//{
//	bilet b;
//	bool cd = false;
//	b.deschidereFisier("bilete.bin");
//	ifstream f("bilete.bin", ios::binary);
//
//	while (cd == false)
//	{
//		b.deserializare();
//	}
//
//}
//
//void citireBilet(bilet b)
//{
//		
//}


