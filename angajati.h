#pragma once
#include<iostream>
#include<string>

using namespace std;

class angajati
{
private:
	const int idAngajat = 0;
	char* nume;
	int* telefon;
	string adresa;
	string email;
	float salariu;
	int varsta;
	static int nrAngajat;

public:
	//constructor implicit
	angajati() :idAngajat(++nrAngajat)
	{
		nume = nullptr;
		telefon = nullptr;
		adresa = "";
		email = "";
		salariu = 0;
		varsta = 0;
	}
	angajati(char* nume, int* telefon, string adresa, string email, float salariu, int varsta) :idAngajat(++nrAngajat)
	{
		if (nume != nullptr)
		{
			this->nume = new char[strlen(nume) + 1];
			for (int i = 0; i < strlen(nume) + 1; i++)
			{
				this->nume[i] = nume[i];
			}
		}
		else
		{
			this->nume = new char[strlen("Necunsocut") + 1];
			strcpy_s(this->nume, strlen("Necunsocut") + 1, "Necunsocut");
		}
		if (telefon != nullptr)
		{
			this->telefon = new int[10];
			{
				for (int i = 0; i < 10; i++)
				{
					this->telefon[i] = telefon[i];
				}
			}
		}
		else
		{
			this->telefon = nullptr;
		}
		if (adresa != "")
		{
			this->adresa = adresa;
		}
		else
		{
			this->adresa = "Necunoscuta";
		}
		if (email != "")
		{
			this->email = email;
		}
		else
		{
			this->email = "Necunoscut";
		}
		if (salariu > 0)
		{
			this->salariu = salariu;
		}
		else
		{
			this->salariu = 0;
		}
		if (varsta > 0)
		{
			this->varsta = varsta;
		}
		else
		{
			this->varsta = 0;
		}
	}
	angajati(const angajati& a) :idAngajat(a.idAngajat)
	{
		if (a.nume != nullptr)
		{
			this->nume = new char[strlen(a.nume) + 1];
			for (int i = 0; i < strlen(a.nume) + 1; i++)
			{
				this->nume[i] = a.nume[i];
			}
		}
		else
		{
			this->nume = nullptr;
		}
		if (a.telefon != nullptr)
		{
			this->telefon = new int[10];
			{
				for (int i = 0; i < 10; i++)
				{
					this->telefon[i] = a.telefon[i];
				}
			}
		}
		else
		{
			this->telefon = nullptr;
		}
		if (a.adresa != "")
		{
			this->adresa = a.adresa;
		}
		else
		{
			this->adresa = "Necunoscuta";
		}
		if (a.email != "")
		{
			this->email = a.email;
		}
		else
		{
			this->email = "Necunoscut";
		}
		if (a.salariu > 0)
		{
			this->salariu = a.salariu;
		}
		else
		{
			this->salariu = 0;
		}
		if (a.varsta > 0)
		{
			this->varsta = a.varsta;
		}
		else
		{
			this->varsta = 0;
		}
	}
	~angajati()
	{
		if (nume != nullptr)
		{
			delete[]  nume;
		}
		if (telefon != nullptr)
		{
			delete[]  telefon;
		}
	}
	angajati operator=(angajati a)
	{
		if (nume != nullptr)
		{
			delete[]  nume;
		}
		if (telefon != nullptr)
		{
			delete[]  telefon;
		}
		if (a.nume != nullptr)
		{
			this->nume = new char[strlen(a.nume) + 1];
			for (int i = 0; i < strlen(a.nume) + 1; i++)
			{
				this->nume[i] = a.nume[i];
			}
		}
		else
		{
			this->nume = nullptr;
		}
		if (a.telefon != nullptr)
		{
			this->telefon = new int[10];
			{
				for (int i = 0; i < 10; i++)
				{
					this->telefon[i] = a.telefon[i];
				}
			}
		}
		else
		{
			this->telefon = nullptr;
		}
		if (a.adresa != "")
		{
			this->adresa = a.adresa;
		}
		else
		{
			this->adresa = "Necunoscuta";
		}
		if (a.email != "")
		{
			this->email = a.email;
		}
		else
		{
			this->email = "Necunoscut";
		}
		if (a.salariu > 0)
		{
			this->salariu = a.salariu;
		}
		else
		{
			this->salariu = 0;
		}
		if (a.varsta > 0)
		{
			this->varsta = a.varsta;
		}
		else
		{
			this->varsta = 0;
		}
		return *this;
	}
	//getter si setter pentru atribute
	char* getNume() { return nume; }
	void setNume(char* nume)
	{
		if (nume != nullptr)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
		else
		{
			this->nume = new char[strlen("Necunsocut") + 1];
			strcpy_s(this->nume, strlen("Necunsocut") + 1, "Necunsocut");
		}
	}

	int* getTelefon() { return telefon; }
	void setTelefon(int* telefon)
	{
		if (telefon != nullptr)
		{
			this->telefon = new int[10];
			{
				for (int i = 0; i < 10; i++)
				{
					this->telefon[i] = telefon[i];
				}
			}
		}
		else
		{
			this->telefon = nullptr;
		}
	}

	string getAdresa() { return adresa; }
	void setAdresa(string adresa)
	{
		if (adresa != "")
		{
			this->adresa = adresa;
		}
		else
		{
			this->adresa = "Necunoscuta";
		}
	}

	string getEmail() { return email; }
	void setEmail(string email)
	{
		if (email != "")
		{
			this->email = email;
		}
		else
		{
			this->email = "Necunoscut";
		}
	}

	float getSalariu()	{		return salariu;	}
	void setSalariu(float salariu)
	{
		if (salariu > 0)
		{
			this->salariu = salariu;
		}
		else
		{
			this->salariu = 0;
		}
	}
	
	int getVarsta()	{		return varsta;	}
	void setVarsta(int varsta)
	{
		if (varsta > 0)
		{
			this->varsta = varsta;
		}
		else
		{
			this->varsta = 0;
		}
	}

	//SUPRAINCARCAREA OPERATORILOR SI METODELE FRIEND
	//operator+
	angajati operator+(int procent) // ne ofera posibilitatea sa majoram salariu cu un anumit procent
	{
		angajati copie = *this;
		copie.salariu += copie.salariu * procent / 100;
		return copie;
	}
	//operator-
	angajati operator-(int procent) // ne ofera posibilitatea sa micsoram salariu cu un anumit procent
	{
		angajati copie = *this;
		copie.salariu -= copie.salariu * procent / 100;
		return copie;
	}
	//operator[]
	int& operator[](int index) throw (exception) // aflam o cifra anume din nr. de telefon. (de ex. daca avem un numar de telefon si nu stim al cui este il cautam cu index)
	{
		if (index >= 0 && index < sizeof(telefon) && telefon != nullptr)
		{
			return telefon[index];
		}
		else
		{
			throw exception("index invalid");
		}
	}
	//operator!
	bool operator!() //inseamna ca angajatul exista in baza de date
	{
		return nume != nullptr;
	}
	//operator++
	angajati operator++()
	{
		varsta++;
		return *this;
	}
	//operator++
	angajati operator++(int i)
	{
		angajati copie = *this;
		this->varsta++;
		return copie;
	}
	// Operatorul de CAST EXPLICIT
	explicit operator int()
	{
		return this->varsta;
	}
	// Operatorul de CAST IMPLICIT
	char* operator()()
	{
		return this->nume;
	}

	friend ostream& operator<<(ostream&, angajati);
	friend istream& operator>>(istream&, angajati&);
	friend bool operator<(angajati, angajati);
	friend bool operator==(angajati, angajati);	
};
int angajati::nrAngajat = 0;

ostream& operator<<(ostream& out, angajati a)
{
	if (a.nume != nullptr)
	{
		out << "Nume Angajat: ";
		for (int i = 0; i < strlen(a.nume) + 1; i++)
		{
			out << a.nume[i];
		}
	}
	else
	{
		out << "Nume Angajat: " << "";
	}
	out << endl;
	if (a.telefon != nullptr)
	{
		out << "Telefon: ";
		for (int i = 0; i < 10; i++)
		{
			out << a.telefon[i];
		}
	}
	else
	{
		out << "Telefon: " << "";
	}
	out << endl;
	if (a.adresa != "")	{		out << "Adresa: " << a.adresa <<endl;		}	else	{		out << "Adresa: " << "" << endl;	}
	if (a.email != "")	{		out << "Email: " << a.email << endl;		}	else	{		out << "Email: " << "" << endl;		}
	if (a.salariu > 0)	{		out << "Salariu: " << a.salariu << endl;	}	else	{		out << "Salariu: " << 0 << endl;	}
	if (a.varsta > 0)	{		out << "Varsta: " << a.varsta << endl;		}	else	{		out << "Varsta: " << 0 << endl;		}

	return out;
}

istream& operator>>(istream& in, angajati& a)
{
	cout << "Nume Angajat: "; 
	char bufferNume[100];
	in >> ws;
	in.getline(bufferNume, 99);
	if (a.nume != nullptr)
	{
		delete[] a.nume;
	}
	a.nume = new char[strlen(bufferNume) + 1];
	strcpy_s(a.nume, strlen(bufferNume) + 1, bufferNume);
	cout << "Telefon: ";
	if (a.telefon != nullptr)
	{
		delete[] a.telefon;
	}
	char bufferTelefon[12];
	in.getline(bufferTelefon, 11);
	a.telefon = new int[11];
	for (int i = 0; i < 11; i++)
	{
		a.telefon[i] = bufferTelefon[i];
	}
	cout << "Adresa: ";	in >> ws;	getline(in, a.adresa);
	cout << "Email: ";	in >> ws;	getline(in, a.email);
	cout << "Salariu: ";
	in >> a.salariu;
	cout << "Varsta: ";
	in >> a.varsta;

	return in;
}

bool operator<(angajati a, angajati b)
{
	return (a.varsta < b.varsta);
}

bool operator==(angajati a, angajati b)
{
	bool nume = true;
	bool varsta = true;
	if (strcmp(a.nume, b.nume) == 0)	{		nume = true;	}	else	{		nume = false;	}
	if (a.varsta == b.varsta)			{		varsta = true;	}	else	{		varsta = false;	}
	if (nume == varsta == true)			{		return true;	}	else	{		return false;	}
}