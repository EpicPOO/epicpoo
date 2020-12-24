#pragma once
#include<iostream>
#include<string>

using namespace std;

//minim un array de caractere si int -> done and 
//camp static done and tested
//getteri setteri -> done and tested
//vallidari la setteri -> done and tested
//regula celor 3 -> done and tested
//>> << -> done and tested
//+,-,* sau / -> done and tested
//++ sau -- cu cele 2 forme -> done and tested
//cast explicit sau implicit -> done and tested
// ! -> done and tested
//< > =< sau >= -> done and tested
//==  -> done and tested

class aliment
{
private:
	const int idAliment = 0;
	string numeAliment; //ca la aliment/sala
	char* categorie;
	int lungimeCod; // avem nevoie de lungime
	int* codBare;
	float pret;
	static int numarAlimente;
public:

	aliment() : idAliment(++numarAlimente) //cstr implicit
	{
		numeAliment = "";
		categorie = nullptr;
		lungimeCod = 0;
		codBare = nullptr;
		pret = 0.0;
	}

	aliment(string numeAliment, const char* categorie, int lungimeCod, int* codBare, float pret) : idAliment(++numarAlimente)//cstr cu 5 par
	{
		if (numeAliment != "") this->numeAliment = numeAliment;
		else this->numeAliment = "";

		if (categorie != nullptr)
		{
			this->categorie = new char[strlen(categorie) + 1];
			strcpy_s(this->categorie, strlen(categorie) + 1, categorie);
		}
		else
		{
			this->categorie = new char[strlen("necunoscutaa") + 1];
			strcpy_s(this->categorie, strlen("necunoscutaa") + 1, "necunoscutaa");
		}

		if (codBare != nullptr && lungimeCod > 0)
		{
			this->lungimeCod = lungimeCod;
			this->codBare = new int[lungimeCod];
			for (int i = 0; i < lungimeCod; i++)
				this->codBare[i] = codBare[i];
		}
		else
		{
			this->lungimeCod = 0;
			this->codBare = nullptr;
		}

		if (pret >= 0) this->pret = pret;
		else this->pret = 0;
	}

	aliment(const aliment& a) :idAliment(a.idAliment) //cstr de copiere
	{
		if (a.numeAliment != "") numeAliment = a.numeAliment;
		else numeAliment = "";

		if (a.categorie != nullptr)
		{
			categorie = new char[strlen(a.categorie) + 1];
			strcpy_s(categorie, strlen(a.categorie) + 1, a.categorie);
		}
		else
		{
			categorie = new char[strlen("necunoscuta") + 1];
			strcpy_s(categorie, strlen("necunoscuta") + 1, "necunoscuta");
		}

		if (a.codBare != nullptr && a.lungimeCod > 0)
		{
			lungimeCod = a.lungimeCod;
			codBare = new int[a.lungimeCod];
			for (int i = 0; i < a.lungimeCod; i++)
				codBare[i] = a.codBare[i];
		}
		else
		{
			lungimeCod = 0;
			codBare = nullptr;
		}

		if (a.pret > 0) pret = a.pret;
		else pret = 0;
	}

	aliment operator=(aliment a)//operator =
	{
		if (a.numeAliment != "") numeAliment = a.numeAliment;
		else numeAliment = "";

		if (categorie != a.categorie)
		{
			if (categorie != nullptr) delete[] categorie; 
			if (a.categorie != nullptr)
			{
				categorie = new char[strlen(a.categorie) + 1];
				strcpy_s(categorie, strlen(a.categorie) + 1, a.categorie);
			}
			else
			{
				categorie = new char[strlen("necunoscuta") + 1];
				strcpy_s(categorie, strlen("necunoscuta") + 1, "necunoscuta");
			}
		}


		if (codBare != a.codBare)
		{
			if (categorie != nullptr) delete[] categorie;
			if (a.codBare != nullptr && a.lungimeCod > 0)
			{
				lungimeCod = a.lungimeCod;
				codBare = new int[a.lungimeCod];
				for (int i = 0; i < a.lungimeCod; i++)
					codBare[i] = a.codBare[i];
			}
			else
			{
				lungimeCod = 0;
				codBare = nullptr;
			}
		}

		if (a.pret > 0) pret = a.pret;
		else pret = 0;

		return *this;
	}

	~aliment() //destructor
	{
		if (categorie != nullptr) delete[] categorie;
		if (codBare != nullptr) delete[] codBare;
	}

	//getter + setteri cu validari

	string getnumeAliment() { return numeAliment; }
	void setnumeAliment(string numeAliment)
	{
		if (numeAliment != "")
			this->numeAliment = numeAliment;
		else this->numeAliment = "";
	}

	char* getCategorie() { return categorie; }
	void setCategorie(char* categorie)
	{
		if (this->categorie != nullptr) delete[] this->categorie; //stergere categorie daca are ceva in el
		if (categorie != nullptr)//validare categorie, char*
		{
			this->categorie = new char[strlen(categorie) + 1];
			strcpy_s(this->categorie, strlen(categorie) + 1, categorie);
		}
		else
		{
			this->categorie = new char[strlen("necunoscuta") + 1];
			strcpy_s(this->categorie, strlen("necunoscuta") + 1, "necunoscuta");
		}
	}

	int getLungimeCod() { return lungimeCod; }
	void setLungimeCod(int lungimeCod)
	{
		if (lungimeCod > 0) this->lungimeCod = lungimeCod;
		else lungimeCod = 0;
	}

	int* getCodBare() { return codBare; }
	void setCodBare(int* codBare, int lungimeCod)
	{
		setLungimeCod(lungimeCod);

		if (this->codBare != nullptr) delete[] this->codBare;
		if (codBare != nullptr)
		{
			this->codBare = new int[lungimeCod];
			for (int i = 0; i < lungimeCod; i++)
				this->codBare[i] = codBare[i];
		}
		else this->codBare = nullptr;
	}

	float getPret() { return pret; }
	void setPret(float pret)
	{
		if (pret > 0) this->pret = pret;
		else pret = 0;
	}

	aliment operator+(int adaos)//adauga un int la pret
	{
		aliment copie = *this;
		copie.pret += (float)adaos;
		return copie;
	}

	int& operator[](int index) throw (exception) //supraincarcare operator[] pt int
	{
		if ((index >= 0 && index < sizeof(codBare) && codBare != nullptr))
			return codBare[index];
		else throw exception("Index invalid");
	}

	bool operator!() //supraincarcare operator ! -> daca avem codBare
	{
		return codBare != nullptr;
	}

	aliment operator--() // decrementeaza pretul
	{
		this->pret--;
		return *this;
	}

	aliment operator--(int i) // predecrementeaza pretul
	{
		aliment copie = *this;
		this->pret--;
		return copie;
	}

	explicit operator int()//cast explicit la int -> pret
	{
		return (int)pret;
	}

	string operator()()//cast implicit la string, intoarce numele alimentului
	{
		return numeAliment;
	}


	//functii friend
	friend ostream& operator<<(ostream&, aliment);
	friend istream& operator>>(istream&, aliment&);
	friend bool operator<(aliment, aliment);
	friend bool operator==(aliment, aliment);
};

ostream& operator<<(ostream& out, aliment a) // operator afisare
{
	out << "Nume aliment: " << a.numeAliment << endl;
	out << "Categorie: " << a.categorie << endl;
	out << "Pret: " << a.pret << endl;
	out << "Lungimea codului de bare: " << a.lungimeCod << endl;
	out << "Cod de bare: ";
	if (a.codBare != nullptr)
		for (int i = 0; i < a.lungimeCod; i++)
			out << a.codBare[i];
	return out;
}

istream& operator>>(istream& in, aliment& a) // operator citire
{
	cout << "Nume aliment: ";
	in >> ws;
	getline(in, a.numeAliment);

	cout << "Categorie: ";
	char buffer[20];
	if (a.categorie != nullptr) delete[] a.categorie;
	a.categorie = new char[strlen(buffer) + 1];
	strcpy_s(a.categorie, strlen(buffer) + 1, buffer);

	cout << "Pret: ";
	in >> a.pret;
	if (a.pret < 0)
	{
		cout << "Pretul trebuie sa fie cel putin 0! Alege din nou: ";
		in >> a.pret;
	}

	cout << "Ce lungime are codul de bare: ";
	in >> a.lungimeCod;
	if (a.lungimeCod < 1)
	{
		cout << "Codul de bare trebuie sa aiba o lungime cel putin egala cu 1! Alege din nou: ";
		in >> a.lungimeCod;
	}

	cout << "Codul de bare: (enter dupa fiecare cifra)";
	for (int i = 0; i < a.lungimeCod; i++)
		in >> a.codBare[i];

	return in;
}

bool operator<(aliment a1, aliment a2) //operator <, dupa pret
{
	return(a1.pret < a2.pret);
}

bool operator==(aliment a1, aliment a2)
{
	if (a1.numeAliment != a2.numeAliment || a1.pret != a2.pret || a1.lungimeCod != a2.lungimeCod)
		return false;
	for (int i = 0; i < a1.lungimeCod; i++)
		if (a1.codBare[i] != a2.codBare[i])
			return false;
	return true;
} 

int aliment::numarAlimente = 0;