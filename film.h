#pragma once
#include<iostream>
#include<string>
#include "helpersCRUD.h"
#include "binar.h"

using namespace std;

class film : public binar
{
private:
	const int idFilm = 0;
	string numeFilm; //ca la sala
	char* tipFilm;  //ca la sala
	int varstaMin; //pentru a intra la film
	int nrRulari;//pt array ul program, avem nevoie de lungime
	string* program; //poate rula de mai multe ori, deci e nevoie de un array de stinguri
	static int numarFilme; //folosit in constructori pentru a pune un id filmului (preincrementare)
public:
	film() : idFilm(++numarFilme) //cstr implicit
	{
		numeFilm = "";
		tipFilm = nullptr;
		varstaMin = 0;
		nrRulari = 0;
		program = nullptr;
	}

	film(std::string numeFilm, const char* tipFilm, int varstaMin, int nrRulari, string* program) : idFilm(++numarFilme)
	{
		if (numeFilm != "") this->numeFilm = numeFilm;//validara numeFilm, string
		else this->numeFilm = "";
		
		if (tipFilm != nullptr)//validare tipFilm, char*
		{
			this->tipFilm = new char[strlen(tipFilm) + 1];
			strcpy_s(this->tipFilm, strlen(tipFilm) + 1, tipFilm);
		}
		else
		{
			this->tipFilm = new char[strlen("Necunoscut") + 1];
			strcpy_s(this->tipFilm, strlen("Necunoscut") + 1, "Necunoscut");
		}

		if (varstaMin > 0) this->varstaMin = varstaMin;//validare varstaMin, int
		else this->varstaMin = 0;

		if (program != nullptr && nrRulari > 0 ) 
		{
			this->nrRulari = nrRulari;
			this->program = new string[nrRulari];
			for (int i = 0; i < nrRulari; i++)
				this->program[i] = program[i];
		}
		else 
		{
			this->nrRulari = 0;
			this->program = nullptr;
		}
	}

	film(const film& f) :idFilm(f.idFilm) //cstr de copiere
	{
		if (f.numeFilm != "") numeFilm = f.numeFilm;//validara numeFilm, string
		else numeFilm = "";

		if (f.tipFilm != nullptr)//validare tipFilm, char*
		{
			tipFilm = new char[strlen(f.tipFilm) + 1];
			strcpy_s(tipFilm, strlen(f.tipFilm) + 1, f.tipFilm);
		}
		else
		{
			tipFilm = new char[strlen("Necunoscut") + 1];
			strcpy_s(tipFilm, strlen("Necunoscut") + 1, "Necunoscut");
		}

		if (f.varstaMin > 0) varstaMin = f.varstaMin;//validare varstaMin, int
		else varstaMin = 0;

		if (f.program != nullptr && f.nrRulari > 0)//validare la array ul de stringuri + marime
		{
			nrRulari = f.nrRulari;
			program = new string[f.nrRulari];
			for (int i = 0; i < f.nrRulari; i++)
				program[i] = f.program[i];
		}
		else
		{
			nrRulari = 0;
			program = nullptr;
		}
	}

	film operator=(film f)//operator =
	{
		if (f.numeFilm != "") numeFilm = f.numeFilm;//validara numeFilm, string
		else numeFilm = "";

		if (tipFilm != f.tipFilm)
		{//evitam autoasignarea, poate cauza probleme cand stergem arrayul daca facem f = f 
			if (tipFilm != nullptr) delete[] tipFilm; //stergere tipFilm daca are ceva in el
			if (f.tipFilm != nullptr)//validare tipFilm, char*
			{
				tipFilm = new char[strlen(f.tipFilm) + 1];
				strcpy_s(tipFilm, strlen(f.tipFilm) + 1, f.tipFilm);
			}
			else
			{
				tipFilm = new char[strlen("Necunoscut") + 1];
				strcpy_s(tipFilm, strlen("Necunoscut") + 1, "Necunoscut");
			}
		}

		if (f.varstaMin > 0) varstaMin = f.varstaMin;//validare varstaMin, int
		else varstaMin = 0;

		if (program != f.program)
		{//la fel ca la tipFilm
			if (program != nullptr) delete[] program; //stergere program daca are ceva in el
			if (f.program != nullptr && f.nrRulari > 0)//validare la array ul de stringuri + marime
			{
				nrRulari = f.nrRulari;
				program = new string[f.nrRulari];
				for (int i = 0; i < f.nrRulari; i++)
					program[i] = f.program[i];
			}
			else
			{
				nrRulari = 0;
				program = nullptr;
			}
		}
		return *this;
	}

	~film() //destructor
	{
		if (tipFilm != nullptr) delete[] tipFilm;
		if (program != nullptr) delete[] program;
	}

	//getter + setteri cu validari

	string getNumeFilm() { return numeFilm; }
	void setNumeFilm(string numeFilm) 
	{ 
		if (numeFilm != "")
			this->numeFilm = numeFilm;
		else this->numeFilm = "";
	} 

	char* getTipFilm() { return tipFilm; }
	void setTipFilm(char* tipFilm)
	{
		if (this->tipFilm != nullptr) delete[] this->tipFilm; //stergere tipFilm daca are ceva in el
		if (tipFilm != nullptr)//validare tipFilm, char*
		{
			this->tipFilm = new char[strlen(tipFilm) + 1];
			strcpy_s(this->tipFilm, strlen(tipFilm) + 1, tipFilm);
		}
		else
		{
			this->tipFilm = new char[strlen("Necunoscut") + 1];
			strcpy_s(this->tipFilm, strlen("Necunoscut") + 1, "Necunoscut");
		}
	}

	int getVarstaMin() { return varstaMin; }
	void setVarstaMin(int varstaMin)
	{
		if (varstaMin > 0) this->varstaMin = varstaMin;
		else varstaMin = 0;
	}

	int getNrRulari() { return nrRulari; }
	void setNrRulari(int nrRulari)
	{
		if (nrRulari > 0) this->nrRulari = nrRulari;
		else nrRulari = 0;
	}

	string* getProgram() { return program; }
	void setProgram(string* program, int nrRulari)
	{
		setNrRulari(nrRulari);

		if (this->program != nullptr) delete[] this->program;
		if (program != nullptr)
		{
			this->program = new string[nrRulari];
			for (int i = 0; i < nrRulari; i++)
			this->program[i] = program[i];
		}
		else this->program = nullptr;
	}

	int getIdFilm()
	{
		return idFilm;
	}

	film operator+(int age)//adauga un int la varsta minima
	{
		film copie = *this;
		copie.varstaMin += age;
		return copie;
	}

	char& operator[](int index) throw (exception) //supraincarcare operator[] pt char 
	{
		if ((index >= 0 && index < strlen(tipFilm) + 1) && tipFilm != nullptr)
			return tipFilm[index];
		else throw exception("Index invalid");
	}

	bool operator!() //supraincarcare operator ! -> daca avem program
	{
		return program != nullptr;
	}

	film operator++() // incrementeaza varsta minima
	{
		this->varstaMin++;
		return *this;
	}

	film operator++(int i) // preincrementeaza varsta minima
	{
		film copie = *this;
		this->varstaMin++;
		return copie;
	}

	explicit operator int()//cast explicit la int, intoarce varsta minima
	{
		return varstaMin;
	}

	string operator()()//cast implicit la string, intoarce numele
	{
		return numeFilm;
	}


	
//functii friend
	friend ostream& operator<<(ostream&, film);
	friend istream& operator>>(istream&, film&);
	friend bool operator<(film, film); 
	friend bool operator==(film, film);

	// FAZA II

	friend film gasesteFilm(int, int, string);
	friend void writeInBin(film, int);

	void inchidereFisier(ifstream f)
	{
		f.close();
	}

	ifstream deschidereFisier(string numeFisier)
	{
		ifstream f(numeFisier, ios::binary);
		return f;
	}

	/*
	string numeFilm; //ca la sala
	char* tipFilm;  //ca la sala
	int varstaMin; //pentru a intra la film
	int nrRulari;//pt array ul program, avem nevoie de lungime
	string* program; //poate rula de mai multe ori, deci e nevoie de un array de stinguri
	*/
	void serializare(string fname)
	{
		serializare(fname, idFilm);
	}

	void serializare(string fname, int id)
	{
		ofstream f(fname, ios::app | ios::binary);
		f.write((char*)&id, sizeof(id)); //idFilm

		int lengthNume = numeFilm.length() + 1;
		f.write((char*)&lengthNume, sizeof(lengthNume)); //dimensiunea numeFIlm
		f.write(numeFilm.c_str(), lengthNume); // scriere numeFIlm

		int lengthTipFilm = strlen(tipFilm) + 1; //dimensiunea lui char* tipFilm
		f.write((char*)&lengthTipFilm, sizeof(lengthTipFilm)); // scrierea dimesiunii lui tipFilm
		f.write(tipFilm, lengthTipFilm); //scriere lui tipFilm

		f.write((char*)&varstaMin, sizeof(varstaMin)); // varstaMinima
		f.write((char*)&nrRulari, sizeof(nrRulari)); // nrRulari


		for (int i = 0; i < nrRulari; i++)
		{
			int lengthProgram = program[i].length() + 1;
			f.write((char*)&lengthProgram, sizeof(lengthProgram));
			f.write(program[i].c_str(), lengthProgram);
		}

		f.close();
	}
	streampos deserializare(streampos start, string fname)
	{
		ifstream f(fname, ios::binary);
		f.seekg(start); // pornim de la pozitia primita ca argument

		f.read((char*)&idFilm, sizeof(idFilm));

		int length = 0;
		f.read((char*)&length, sizeof(length));
		char* aux = new char[length];
		f.read(aux, length);
		setNumeFilm(aux); //am citit nume

		length = 0;
		f.read((char*)&length, sizeof(length));
		delete[] aux;
		aux = new char[length];
		f.read(aux, length);
		setTipFilm(aux); //am citit tipFilm


		f.read((char*)&varstaMin, sizeof(varstaMin));//am citit varstaMin
		f.read((char*)&nrRulari, sizeof(nrRulari)); //am citit nrRulari


		string* copie = new string[nrRulari];
		for (int i = 0; i < nrRulari; i++)
		{
			length = 0;
			f.read((char*)&length, sizeof(length));
			char* aux = new char[length];
			f.read(aux, length);
			copie[i] = aux;
			delete[] aux;
		}
		setProgram(copie, nrRulari); // am citit program
		streampos pos = f.tellg();
		f.close();
		return pos;
	}
};

int film::numarFilme = 0;

ostream& operator<<(ostream& out, film f) // operator afisare
{
	out << "Id Film: " << f.idFilm << endl;
	out << "Nume film: " << f.numeFilm << endl;
	out << "Tip film: " << f.tipFilm << endl;
	out << "Varsta minima pentru acces: " << f.varstaMin << endl;
	out << "Cate rulari va avea filmul: " << f.nrRulari << endl;
	out << "Program: ";
	if (f.program != nullptr)
		for (int i = 0; i < f.nrRulari; i++)
			out << f.program[i] << " | ";
	return out;
}

istream& operator>>(istream& in, film& f) // operator citire
{
	cout << "Nume film: ";
	in >> ws;
	getline(in, f.numeFilm);

	cout << "Tip film: ";
	char buffer[20];
	in.getline(buffer, 19);
	if (f.tipFilm != nullptr) delete[] f.tipFilm;
	f.tipFilm = new char[strlen(buffer) + 1];
	strcpy_s(f.tipFilm, strlen(buffer) + 1, buffer);

	cout << "Varsta minima pentru acces: ";
	in >> f.varstaMin;
	if (f.varstaMin < 0)
	{
		cout << "Varsta minima trebuie sa fie cel putin 0! Alege din nou: ";
		in >> f.varstaMin;
	}

	cout << "Cate rulari va avea filmul: ";
	in >> f.nrRulari;
	if (f.nrRulari < 1)
	{
		cout << "Filmul adaugat trebuie sa fie rulat cel putin o data! Alege din nou: ";
		in >> f.nrRulari;
	}

	cout << "Program: ";
	f.program = new string[f.nrRulari];
	for (int i = 0; i < f.nrRulari; i++)
	{
		in >> ws;
		getline(in, f.program[i]);
	}

	return in;
}

bool operator<(film f1, film f2) //operator <, dupa varsta minima
{
	return(f1.varstaMin < f2.varstaMin);
}

bool operator==(film f1, film f2)
{
	if (f1.numeFilm != f2.numeFilm || f1.varstaMin != f2.varstaMin || f1.nrRulari != f2.nrRulari)
		return false;
	for (int i = 0; i < f1.nrRulari; i++)
		if (f1.program[i] != f2.program[i])
			return false;
	return true;
}

//FAZA II

void adaugaFilm(film nou, int& nrTotalFilme, string fname)
{
	nou.serializare(fname, ++nrTotalFilme);
}

film gasesteFilm(int id, int nrTotalFilme, string fname) // sau citire
{
	film f;
	streampos pos = 0; // pornim de la pozitia 0
	for (int i = 0; i < nrTotalFilme; i++)
	{
		pos = f.deserializare(pos, fname); //deserializeaza un obiect si intoarce pozitia la care a ramas
		if (id == f.getIdFilm())
			return f;
	}
	f.setNumeFilm("Negasit");
	return f;
}

void actualizareFilm(int id, film nou, int nrTotalFilme, string fname)
{
	film f;
	streampos pos = 0; //pornim de la pozitia 0
	string copie = "temp.bin";
	for (int i = 0; i < nrTotalFilme; i++)
	{
		pos = f.deserializare(pos, fname);
		if (id != f.getIdFilm())// daca nu gasim idul, copiem in noul fisier
			f.serializare(copie);
		else nou.serializare(copie, id);
	}
	remove(fname.c_str());
	rename(copie.c_str(), fname.c_str());
}

void stergeFilm(int id, int& nrTotalFilme, string fname)
{
	film f;
	int sterse = nrTotalFilme;
	streampos pos = 0; //pornim de la pozitia 0
	string copie = "temp.bin";
	for (int i = 0; i < nrTotalFilme; i++)
	{
		pos = f.deserializare(pos, fname);
		if (id != f.getIdFilm())// daca nu gasim idul, copiem in noul fisier
			f.serializare(copie);
		else
			sterse--;//decrementam copia nr total
	}
	nrTotalFilme = sterse;
	remove(fname.c_str());
	rename(copie.c_str(), fname.c_str());
}

void afisareFilme(int nrTotalFilme, string fname)
{
	film f;
	streampos pos = 0;
	for (int i = 0; i < nrTotalFilme; i++)
	{
		pos = f.deserializare(pos, fname);
		cout << f << "\n";
	}
}

film adaugaFilmConsola() //Stefana: adaugare elemente din consola
{
	string buffer;
	string numeFilm; //ca la sala
	char* tipFilm;  //ca la sala
	string tipFilmStr;
	int varstaMin; //pentru a intra la film
	int nrRulari;//pt array ul program, avem nevoie de lungime
	string* program; //poate rula de mai multe ori, deci e nevoie de un array de stinguri

	cout << "Introdu numele filmului: ";
	cin >> ws;
	getline(cin, numeFilm);
	cout << endl;
	cout << "Introdu tipul filmului: ";
	cin >> ws;
	getline(cin, tipFilmStr);
	cout << endl;
	cout << "Introdu varsta minima pentru a viziona acest film: ";
	getline(cin, buffer);
	while (stringToInt(buffer) == 0)
	{
		cout << "Varsta trebuie sa fie un numar intreg pozitiv. Te rog sa reintroduci varsta minima pentru a viziona acest film: " << endl;
		getline(cin, buffer);
	}
	varstaMin = stringToInt(buffer);
	cout << endl;
	cout << "Numarul de rulari pentru acest film: ";
	getline(cin, buffer);
	while (stringToInt(buffer) == 0)
	{
		cout << "Numarul de rulari trebuie sa fie un numar intreg pozitiv. Te rog sa reintroduci numarul rulari: " << endl;
		getline(cin, buffer);
	}
	nrRulari = stringToInt(buffer);
	cout << endl;
	program = new string[nrRulari];
	for (int i = 0; i < nrRulari; i++)
	{
		cout << "Program film - introdu rularea (" << i + 1 << "): ";
		cin >> ws;
		getline(cin, program[i]);
	}
	cout << endl;
	film f;
	f.setNrRulari(nrRulari);
	f.setProgram(program,nrRulari);
	f.setNumeFilm(numeFilm);
	f.setTipFilm((char*)tipFilmStr.c_str());
	f.setVarstaMin(varstaMin);
	cout << endl << "Filmul a fost salvat!" << endl;
	return f;
}