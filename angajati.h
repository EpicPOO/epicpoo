#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "helpersCRUD.h"
#include "binar.h"
#include <vector>
using namespace std;

class angajati : public binar
{
private:
	const int idAngajat = 0;
	char* nume;
	vector<int> telefon; //int* telefon;
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
		//telefon = nullptr;
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
			//this->telefon = new int[10];
			{
				for (int i = 0; i < 10; i++)
				{
					this->telefon.push_back(telefon[i]); //this->telefon[i] = telefon[i];
				}
			}
		}
		else
		{
			//this->telefon = nullptr;
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
		if (a.telefon.size() != 0) //if (a.telefon != nullptr)
		{
			//this->telefon = new int[10];
			{
				for (int i = 0; i < 10; i++)
				{
					this->telefon.push_back(a.telefon[i]); //this->telefon[i] = a.telefon[i];
				}
			}
		}
		else
		{
			this->telefon.clear(); //this->telefon = nullptr;
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
		//if (telefon != nullptr)
		//{
		//	delete[]  telefon;
		//}
	}
	angajati operator=(angajati a)
	{
		if (nume != nullptr)
		{
			delete[]  nume;
		}
		if (telefon.size() != 0)//if (telefon != nullptr)
		{
			telefon.clear();//delete[]  telefon;
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
		if (a.telefon.size() != 0)//if (a.telefon != nullptr)
		{
			this->telefon.clear();//this->telefon = new int[10];
			{
				for (int i = 0; i < 10; i++)
				{
					this->telefon.push_back(a.telefon[i]);//this->telefon[i] = a.telefon[i];
				}
			}
		}
		else
		{
			this->telefon.clear();//this->telefon = nullptr;
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

	vector<int> getTelefon() { return telefon; }//int* getTelefon() { return telefon; }
	void setTelefon(int* telefon)
	{
		if (telefon != nullptr)
		{
			this->telefon.clear();//this->telefon = new int[10];
			{
				for (int i = 0; i < 10; i++)
				{
					this->telefon.push_back(telefon[i]);//this->telefon[i] = telefon[i];
				}
			}
		}
		else
		{
			this->telefon.clear();//this->telefon = nullptr;
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

	int getIdAngajat()
	{
		return idAngajat;
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
		if (index >= 0 && index < telefon.size() && telefon.size() != 0)//if (index >= 0 && index < sizeof(telefon) && telefon != nullptr)
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

	//FAZA a II-a

	friend angajati gasesteAngajat(int, int&, string);
	friend void writeInBin(angajati, int);

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
	char* nume;
	int* telefon;
	string adresa;
	string email;
	float salariu;
	int varsta;
	*/
	void serializare(string fname)
	{
		serializare(fname, idAngajat);
	}

	void serializare(string fname, int id)
	{
		ofstream f(fname, ios::app | ios::binary);
		f.write((char*)&id, sizeof(id)); //idAngajat
		int lengthNume = strlen(nume) + 1; //dimensiunea lui char* nume
		f.write((char*)&lengthNume, sizeof(lengthNume)); // scrierea dimesiunii lui nume
		f.write(nume, lengthNume); //scriere lui nume
		for (int i = 0; i < 10; i++)
		{
			f.write((char*)&telefon[i], sizeof(telefon[i]));
		}
		int lengthAdresa = adresa.length() + 1;
		f.write((char*)&lengthAdresa, sizeof(lengthAdresa)); //dimensiunea adresa
		f.write(adresa.c_str(), lengthAdresa); // scriere adresa
		int lengthEmail = email.length() + 1;
		f.write((char*)&lengthEmail, sizeof(lengthEmail)); //dimensiunea email
		f.write(email.c_str(), lengthEmail); // scriere email
		f.write((char*)&salariu, sizeof(salariu)); //scriere salariu
		f.write((char*)&varsta, sizeof(varsta));//scriere varsta
		f.close();
	}

	streampos deserializare(streampos start, string fname)
	{
		ifstream f(fname, ios::binary);
		f.seekg(start); // pornim de la pozitia primita ca argument
		f.read((char*)&idAngajat, sizeof(idAngajat));
		int length = 0;
		f.read((char*)&length, sizeof(length));
		char* aux = new char[length];
		f.read(aux, length);
		setNume(aux); //am citit nume
		int* copie = new int[10];
		for (int i = 0; i < 10; i++)
		{
			f.read((char*)&copie[i], sizeof(copie[i]));
		}
		setTelefon(copie); // am citit telefon

		length = 0;
		f.read((char*)&length, sizeof(length));
		delete[] aux;
		aux = new char[length];
		f.read(aux, length);
		setAdresa(aux); //am citit Adresa
		length = 0;
		f.read((char*)&length, sizeof(length));
		delete[] aux;
		aux = new char[length];
		f.read(aux, length);
		setEmail(aux); //am citit Adresa
		f.read((char*)&salariu, sizeof(salariu));//am citit salariu
		f.read((char*)&varsta, sizeof(varsta)); //am citit varsta
		streampos pos = f.tellg();
		f.close();
		return pos;
	}
};
int angajati::nrAngajat = 0;

int getLastIdAngajat(string fname)
{
	int idFilm = 0;
	if (testTipFisier(fname) == 1)
	{
		angajati a;
		streampos pos = 0; // pornim de la pozitia 0
		for (int i = 0; i <= citesteTotalAngajatiInt("Total.txt"); i++)
		{
			pos = a.deserializare(pos, fname); //deserializeaza un obiect si intoarce pozitia la care a ramas
			idFilm = a.getIdAngajat();
		}
		return idFilm;
	}
	else return 0;
}

ostream& operator<<(ostream& out, angajati a)
{
	out << "Id Angajat: " << a.idAngajat << endl;
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
	if (a.telefon.size() != 0)//if (a.telefon != nullptr)
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
	if (a.telefon.size() != 0)//if (a.telefon != nullptr)
	{
		a.telefon.clear();//delete[] a.telefon;
	}
	char bufferTelefon[12];
	in.getline(bufferTelefon, 11);
	//a.telefon = new int[11];
	for (int i = 0; i < 11; i++)
	{
		a.telefon.push_back(bufferTelefon[i]); //a.telefon[i] = bufferTelefon[i];
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



void adaugaAngajat(angajati nou, int& nrTotalAngajati, string fname)
{
	nrTotalAngajati++;
	nou.serializare(fname, getLastIdAngajat(fname)+1);
}

angajati gasesteAngajat(int id, int nrTotalAngajati, string fname) // sau citire
{
	angajati a;
	streampos pos = 0; // pornim de la pozitia 0
	for (int i = 0; i < nrTotalAngajati; i++)
	{
		pos = a.deserializare(pos, fname); //deserializeaza un obiect si intoarce pozitia la care a ramas
		if (id == a.getIdAngajat())
			return a;
	}
	a.setNume((char*)"Negasit");
	return a;
}

void actualizareAngajat(int id, angajati nou, int nrTotalAngajati, string fname)
{
	angajati a;
	streampos pos = 0; //pornim de la pozitia 0
	string copie = "temp.bin";
	for (int i = 0; i < nrTotalAngajati; i++)
	{
		pos = a.deserializare(pos, fname);
		if (id != a.getIdAngajat())// daca nu gasim idul, copiem in noul fisier
			a.serializare(copie);
		else nou.serializare(copie, id);
	}
	remove(fname.c_str());
	rename(copie.c_str(), fname.c_str());
}

void stergeAngajat(int id, int& nrTotalAngajati, string fname)
{
	angajati a;
	int sterse = nrTotalAngajati;
	streampos pos = 0; //pornim de la pozitia 0
	string copie = "temp.bin";
	for (int i = 0; i < nrTotalAngajati; i++)
	{
		pos = a.deserializare(pos, fname);
		if (id != a.getIdAngajat())// daca nu gasim idul, copiem in noul fisier
			a.serializare(copie);
		else
			sterse--; // decrementam copia nr total
	}
	nrTotalAngajati = sterse;
	remove(fname.c_str());
	rename(copie.c_str(), fname.c_str());
}

void afisareAngajati(int nrTotalAngajati, string fname)
{
	angajati a;
	streampos pos = 0;
	for (int i = 0; i < nrTotalAngajati; i++)
	{
		pos = a.deserializare(pos, fname);
		cout << a << "\n";
	}
}


angajati adaugaAngajatConsola() //Stefana: adaugare elemente din consola
{
	string buffer;
	string numeAngajat;
	char* nume;
	int* telefon;
	string adresa;
	string email;
	float salariu;
	int varsta;
	
	cout << "Introdu numele angajatului: ";
	cin >> ws;
	getline(cin, numeAngajat);
	cout << endl;
	cout << "Introdu numarul de telefon: ";
	getline(cin, buffer);
	while (stringToInt(buffer) == 0 || buffer.length()!=10)
	{
		cout << "Numarul de telefon trebuie sa contina 10 cifre. Te rog sa reintroduci numarul de telefon: " << endl;
		getline(cin, buffer);
	}
	telefon = new int[10];
	for (int i = 0; i < 10; i++)
	{
		telefon[i] = stringToInt(buffer.substr(i, 1));
	}
	cout << endl;
	cout << "Introdu adresa angajatului: ";
	cin >> ws;
	getline(cin, buffer);
	adresa = buffer;
	cout << endl;
	cout << "Introdu adresa de email a angajatului: ";
	cin >> ws;
	getline(cin, buffer);
	email = buffer;
	cout << endl;
	cout << "Introdu salariul angajatului: ";
	cin >> ws;
	getline(cin, buffer);
	while (stringToInt(buffer) == 0)
	{
		cout << "Salariul trebuie sa fie un numar pozitiv. Te rog sa reintroduci salariul: " << endl;
		getline(cin, buffer);
	}
	salariu = stringToInt(buffer);
	cout << endl;
	cout << "Introdu varsta angajatului: ";
	cin >> ws;
	getline(cin, buffer);
	while (stringToInt(buffer) == 0 && stringToInt(buffer)<16)
	{
		cout << "Varsta trebuie sa fie un numar pozitiv mai mare de 16. Te rog sa reintroduci varsta: " << endl;
		getline(cin, buffer);
	}
	varsta = stringToInt(buffer);
	cout << endl;
	angajati a;
	a.setNume((char*)numeAngajat.c_str());
	a.setTelefon(telefon);
	a.setAdresa(adresa);
	a.setEmail(email);
	a.setSalariu(salariu);
	a.setVarsta(varsta);
	cout << endl << "Angajatul a fost salvat!" << endl;
	return a;
}