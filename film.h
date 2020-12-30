#pragma once
#include<iostream>
#include<string>

using namespace std;

//minim un array de caractere -> done and tested
//camp static? -> done
//getteri setteri -> done and tested
//vallidari la setteri -> done and tested
//regula celor 3 -> done and tesded
//>> << -> done and tested
//+,-,* sau / done pt plus -> done si testat
//++ sau -- cu cele 2 forme -> done and tested
//cast explicit sau implicit -> done and tested
// ! -> done and tested
//< > =< sau >= -> done and tested
//==  -> done and tested

class film
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
			if (tipFilm != nullptr) delete[] tipFilm; //stergere tipFilm daca are ceva in el
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
};

int film::numarFilme = 0;

ostream& operator<<(ostream& out, film f) // operator afisare
{
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
