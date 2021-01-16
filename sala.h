#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "helpersCRUD.h"

using namespace std;


class sala
{
private:
	const int idSala = 0;
	string numeSala; //A,B,C sau I.C.Carageale, M. Eminescu sau A2D, A3D, B2D, B3D //done
	char* tipSala;// 2D, 3D, 4D, s.a. //done
	int totalSala; // numarul total de locuri pe care le are Sala //done
	int* totalLocuri; //vectorul in care se stocheaza locurile alese din sala (rezervate + cumparate) //done
	int nrLibere; //numarul locurilor ramase 
	int nrRezervate; // numarul locurilor rezervate //done
	int nrCumparate; //numarul biletelor cumparate de la casa //done
	static int numarSali;//pentru a preincrementa in idSala la constructori//done
public:
	sala():idSala(++numarSali) //constructor implicit
	{
		numeSala = "";
		tipSala = nullptr;
		totalSala = 0; //
		totalLocuri = nullptr;
		nrLibere = 0;
		nrRezervate = 0;
		nrCumparate = 0;
	}
	sala(string numeSala, char* tipSala, int totalSala, int* totalLocuri, int nrRezervate, int nrCumparate):idSala(++numarSali) // constructor cu 6 parametri (sunt toti cei necesari)
	{
		if (numeSala != "")		{			this->numeSala = numeSala;			}	else	{			this->numeSala = "Necunoscuta";		}
		if (tipSala != nullptr)		
		{			
			this->tipSala = new char[strlen(tipSala) + 1];
			strcpy_s(this->tipSala, strlen(tipSala) + 1, tipSala);
		}	
		else	
		{		
			this->tipSala = new char[strlen("Necunoscuta") + 1];
			strcpy_s(this->tipSala, strlen("Necunoscuta")+1, "Necunoscuta");		
		}
		if (totalSala > 0)		{			this->totalSala = totalSala;		}	else	{			this->totalSala = 0;				}
		if (nrRezervate > 0)	{			this->nrRezervate = nrRezervate;	}	else	{			this->nrRezervate = 0;				}
		if (nrCumparate > 0)	{			this->nrCumparate = nrCumparate;	}	else	{			this->nrCumparate = 0;				}

		int sumaLocOcupate = nrRezervate + nrCumparate; // fac suma locurilor ocupate prin cumparare si rezervarea lor 
														//ca s-o folosesc pentru a strabate vectorul in care stochez nr scaunelor alese de fiecare client
		if (totalLocuri != nullptr)
		{
			this->totalLocuri = new int[sumaLocOcupate];
			for (int i = 0; i < sumaLocOcupate; i++)
			{
				this->totalLocuri[i] = totalLocuri[i];
			}
		}
		else
		{
			this->totalLocuri = nullptr;
		}

		this->nrLibere = totalSala - (nrCumparate + nrRezervate); // aflu cate locuri libere mai raman
	}
	sala(const sala& s):idSala(s.idSala) //constructor de copiere
	{
		if (s.numeSala != "")	{ this->numeSala = s.numeSala; }		else { this->numeSala = "Necunoscuta"; }
		if (s.tipSala != nullptr)
		{
			this->tipSala = new char[strlen(s.tipSala) + 1];
			strcpy_s(this->tipSala, strlen(s.tipSala) + 1, s.tipSala);
		}
		else
		{
			this->tipSala = new char[strlen("Necunoscuta") + 1];
			strcpy_s(this->tipSala, strlen("Necunoscuta") + 1, "Necunoscuta");
		}
		if (s.totalSala > 0)	{ this->totalSala = s.totalSala; }		else { this->totalSala = 0; }
		if (s.nrRezervate > 0)	{ this->nrRezervate = s.nrRezervate; }	else { this->nrRezervate = 0; }
		if (s.nrCumparate > 0)	{ this->nrCumparate = s.nrCumparate; }	else { this->nrCumparate = 0; }
		int sumaLocOcupate = s.nrRezervate + s.nrCumparate;
		if (s.totalLocuri != nullptr)
		{
			this->totalLocuri = new int[sumaLocOcupate];
			for (int i = 0; i < sumaLocOcupate; i++)
			{
				this->totalLocuri[i] = s.totalLocuri[i];
			}
		}
		else
		{
			this->totalLocuri = nullptr;
		}

		this->nrLibere = s.totalSala - (s.nrCumparate + s.nrRezervate);
	}
	~sala() //destructor
	{
		if (totalLocuri != nullptr) { delete[] totalLocuri; }
		if (tipSala != nullptr)		{ delete[] tipSala; }
	}
	sala operator=(sala s) //operator=
	{
		if (totalLocuri != nullptr) { delete[] totalLocuri; }
		if (s.numeSala != "")	{ this->numeSala = s.numeSala; }		else { this->numeSala = "Necunoscuta"; }
		if (tipSala != nullptr)
		{
			this->tipSala = new char[strlen(s.tipSala) + 1];
			strcpy_s(this->tipSala, strlen(s.tipSala) + 1, s.tipSala);
		}
		else
		{
			this->tipSala = new char[strlen("Necunoscuta") + 1];
			strcpy_s(this->tipSala, strlen("Necunoscuta") + 1, "Necunoscuta");
		}
		if (s.totalSala > 0)	{ this->totalSala = s.totalSala; }		else { this->totalSala = 0; }
		if (s.nrRezervate > 0)	{ this->nrRezervate = s.nrRezervate; }	else { this->nrRezervate = 0; }
		if (s.nrCumparate > 0)	{ this->nrCumparate = s.nrCumparate; }	else { this->nrCumparate = 0; }
		int sumaLocOcupate = s.nrRezervate + s.nrCumparate;
		this->totalLocuri = new int[sumaLocOcupate];
		for (int i = 0; i < sumaLocOcupate; i++)
		{
			this->totalLocuri[i] = s.totalLocuri[i];
		}
		this->nrLibere = s.totalSala - (s.nrCumparate + s.nrRezervate);
		return *this;
	}
	//getter si setter pentru atribute

	string	getNumeSala()		{	return numeSala;	}
	void	setNumeSala(string numeSala)	{	if (numeSala != "")	{	this->numeSala = numeSala;	}	else	{	this->numeSala = "";	}	}

	char*	getTipSala()		{	return tipSala;		}
	void	setTipSala(char* tipSala) 		
	{ 	
		if (tipSala != nullptr)	
		{	
			this->tipSala = new char[strlen(tipSala) + 1];
			strcpy_s(this->tipSala, strlen(tipSala)+1, tipSala);	
		} 	
		else	
		{	
			this->tipSala = new char[strlen("Necunoscuta") + 1];
			strcpy_s(this->tipSala,strlen("Necunoscuta")+1, "Necunoscuta");		
		}	
	}

	int		getTotalSala()		{	return totalSala;	}
	void	setTotaSala(int totalSala)		{	if (totalSala != 0)	{	this->totalSala = totalSala;}	else	{	this->totalSala = 0;	}	}

	int		getNrLibere()		{	return nrLibere;	} // nu avem nevoie de set pentru ca se face calculul in restul functilor
	void	setNrLibere(int nrLibere) { if (nrLibere > 0)	this->nrLibere = nrLibere;	else this->nrLibere = 0; }	//adaugat setter necesar pentru adaugaFilmConsola()
														// am ales sa fac asta pentru ca atunci cand introduci datele trebuia facut calculul 
														// de care cel care introducea astfel se face automat
	int		getNrRezervate() {		return nrRezervate;	}
	void	setNrRezervate(int nrRezervate) { if (nrRezervate > 0) { this->nrRezervate = nrRezervate; } else	{	this->nrRezervate = 0;	}	}

	int		getNrCumparate() {		return nrCumparate;	}
	void	setNrCumparate(int nrCumparate)	{	if (nrCumparate > 0)	{	this->nrCumparate = nrCumparate;	}	else{	this->nrCumparate = 0;	}	}

	int* getTotalLocuri() 
	{ 
		return (int*)totalLocuri;
	}
	void	setTotalLocuri(int* totalLocuri, int sumaLocuriOcupate)
	{
		if (totalLocuri != nullptr && sumaLocuriOcupate > 0)
		{
			this->totalLocuri = new int[sumaLocuriOcupate];
			for (int i = 0; i < sumaLocuriOcupate; i++)
			{
				this->totalLocuri[i] = totalLocuri[i];
			}
		}
	}

	int getIdSala()
	{
		return idSala;
	}
	//SUPRAINCARCAREA OPERATORILOR SI METODELE FRIEND
	sala operator+(int locSuplimentar) //supraincarcarea operator+
	{
		sala copie = *this;
		copie.totalSala += locSuplimentar;	
		return copie;
	}
	int& operator[](int index) throw (exception) //supraincarcarea operator[]
	{
		if (index >= 0 && index < (this->nrCumparate + this->nrRezervate) && this->totalLocuri != nullptr)
		{
			return totalLocuri[index];
		}
		else
		{
			throw exception("index invalid");
		}
	}
	
	bool operator!() //supraincarcarea operator!
	{
		int locOcupate = nrRezervate + nrCumparate;
		return locOcupate > 0;
	}

	sala operator++() // mareste numarul total de locuri pe care-l are sala
	{
		this->totalSala++;
		return *this;
	}

	sala operator++(int i) // mareste numarul total de locuri pe care-l are sala
	{
		sala copie = *this;
		this->totalSala++;
		return copie;
	}
	// Operatorul de CAST EXPLICIT
	explicit operator int()
	{
		nrLibere = totalSala - (nrCumparate + nrRezervate);
		return this->nrLibere;
	}
	// Operatorul de CAST IMPLICIT
	string operator()()
	{
		return this->numeSala;
	}

	friend ostream& operator<<(ostream&, sala);		// operatorul<<
	friend istream& operator>>(istream&, sala&);	// operatorul>>
	friend bool operator<(sala, sala);				// operatorul<
	friend bool operator==(sala, sala);				// operatorul==

	//FAZA a II-a

	friend sala gasesteSala(int, int&, string);
	friend void writeInBin(sala, int);

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
	const int idSala = 0;
	string numeSala; //A,B,C sau I.C.Carageale, M. Eminescu sau A2D, A3D, B2D, B3D //done
	char* tipSala;// 2D, 3D, 4D, s.a. //done
	int totalSala; // numarul total de locuri pe care le are Sala //done
	int* totalLocuri; //vectorul in care se stocheaza locurile alese din sala (rezervate + cumparate) //done
	int nrLibere; //numarul locurilor ramase 
	int nrRezervate; // numarul locurilor rezervate //done
	int nrCumparate; //numarul biletelor cumparate de la casa //done
	static int numarSali;//pentru a preincrementa in idSala la constructori//done
	*/
	void serializare(string fname)
	{
		serializare(fname, idSala);
	}

	void serializare(string fname, int id)
	{
		ofstream f(fname, ios::app);
		f.write((char*)&id, sizeof(id));
		int lengthNume = numeSala.length() + 1;
		f.write((char*)&lengthNume, sizeof(lengthNume)); //dimensiunea numeSala
		f.write(numeSala.c_str(), lengthNume); // scriere numeSala
		int lengthTipSala = strlen(tipSala) + 1; //dimensiunea lui char* tipSala
		f.write((char*)&lengthTipSala, sizeof(lengthTipSala)); // scrierea dimesiunii
		f.write(tipSala, lengthTipSala); //scriere lui tipSala
		f.write((char*)&totalSala, sizeof(totalSala)); //scriere total Locuri
		f.write((char*)&nrRezervate, sizeof(nrRezervate));//scriere Locuri rezervate, nrRezervate
		f.write((char*)&nrCumparate, sizeof(nrCumparate));//scriere Locuri cumparate, nrCumparate
		int nrSala = nrCumparate + nrRezervate;
		for (int i = 0; i < nrSala; i++)
		{
			f.write((char*)&totalLocuri[i], sizeof(totalLocuri[i]));
		}
		f.write((char*)&nrLibere, sizeof(nrLibere));//scriere Locuri libere, nrLibere
		f.close();
	}



	streampos deserializare(streampos start, string fname)
	{
		ifstream f(fname, ios::binary);
		f.seekg(start); // pornim de la pozitia primita ca argument
		f.read((char*)&idSala, sizeof(idSala));
		int length = 0;
		f.read((char*)&length, sizeof(length));
		char* aux = new char[length];
		f.read(aux, length);
		setNumeSala(aux); //am citit numeSala
		length = 0;
		f.read((char*)&length, sizeof(length));
		delete[] aux;
		aux = new char[length];
		f.read(aux, length);
		setTipSala(aux); //am citit tipSala
		f.read((char*)&totalSala, sizeof(totalSala));//totalSala
		f.read((char*)&nrRezervate, sizeof(nrRezervate)); //nrRezervate
		f.read((char*)&nrCumparate, sizeof(nrCumparate)); //nrCumparate
		int nrSala = nrCumparate + nrRezervate;
		int* copie = new int[nrSala];
		for (int i = 0; i < nrSala; i++)
		{
			f.read((char*)&copie[i], sizeof(copie[i]));
		}
		setTotalLocuri(copie, nrSala); //totalLocuri
		f.read((char*)&nrLibere, sizeof(nrLibere)); //nrLibere
		streampos pos = f.tellg();
		f.close();
		return pos;
	}
};
// initializare atribut static
int sala::numarSali = 0;
// operatorul<<
ostream& operator<<(ostream& out, sala s)
{
	out << "ID Sala: " << s.idSala << endl;
	out << "Nume sala: " << s.numeSala << endl;
	out << "Tip sala: " << s.tipSala << endl;
	out << "Total locuri: " << s.totalSala << endl;
	out << "Locuri ocupate: ";
	int locOcupate = s.nrRezervate + s.nrCumparate;
	if (s.totalLocuri != nullptr)
	{
		for (int i = 0; i < locOcupate; i++)
		{
			out << s.totalLocuri[i] << " ";
		}
	}
	out << endl << "Locuri libere: " << s.nrLibere << endl;
	out << "Locuri rezervare: " << s.nrRezervate << endl;
	out << "Locuri cumparate: " << s.nrCumparate << endl;

	return out;
} 
// operatorul>>
istream& operator>>(istream& in, sala& s)
{
	cout << "Nume sala: ";		in >> ws;	getline(in, s.numeSala);
	
	cout << "Tip sala: ";
	char buffer[20];
	in >> ws;
	in.getline(buffer, 19);
	
	if (s.tipSala != nullptr) delete[] s.tipSala;
	s.tipSala = new char[strlen(buffer) + 1];
	strcpy_s(s.tipSala, strlen(buffer) + 1, buffer);
	
	cout << "Total locuri: ";		in >> s.totalSala;

	if (s.totalSala < 1)
	{
		cout << "Sala trebuie sa aiba minim 1 loc! Alege din nou: "; in >> s.totalSala;
	}
	
	cout << "Locuri rezervare: ";	in >> s.nrRezervate;
	
	cout << "Locuri cumparate: ";	in >> s.nrCumparate;

	s.nrLibere = s.totalSala - (s.nrCumparate + s.nrRezervate);

	cout << "		Locuri ocupate " << endl;	int locOcupate = s.nrRezervate + s.nrCumparate;
	if (s.totalLocuri != nullptr)	delete[] s.totalLocuri;
	s.totalLocuri = new int[locOcupate];
	cout << "Locuri Rezervate: " << endl;
	for (int i = 0; i < s.nrRezervate; i++)
	{
		in >> s.totalLocuri[i];
		for (int j = 0; j < i; j++)
		{
			if (s.totalLocuri[j] == s.totalLocuri[i])
			{
				cout << "Loc Ocupat!" << "Alege din nou: " << endl;
				in >> s.totalLocuri[i];
			}
		}
	}
	cout << "Locuri Cumparate: " << endl;		
	for (int i = s.nrRezervate; i < locOcupate; i++)
	{
		in >> s.totalLocuri[i];
		for (int j = 0; j < i; j++)
		{
			if (s.totalLocuri[j] == s.totalLocuri[i])
			{
				cout << "Loc Ocupat!" << "Alege din nou: " << endl;
				in >> s.totalLocuri[i];				
			}
		}
	}


	cout << "Locuri libere: " << s.nrLibere;

	return in;
}
// operatorul<
bool operator<(sala s1, sala s2)
{
	return(s1.nrLibere < s2.nrLibere);
}
// operatorul==
bool operator==(sala s1, sala s2)
{
	bool numeSala = true;
	bool tipSala =  true;
	bool totalSala = true;
	bool nrRezervate = true; 
	bool nrCumparate =  true;

	if (s1.numeSala == s2.numeSala)			{		numeSala = true;	}	else	{		numeSala = false;	}
	if (s1.tipSala == s2.tipSala)			{		tipSala = true;		}	else	{		tipSala = true;	}
	if (s1.totalSala == s2.totalSala)		{		totalSala = true;	}	else	{		totalSala = false;	}
	if (s1.nrRezervate == s2.nrRezervate)	{		nrRezervate = true;	}	else	{		nrRezervate = false;	}
	if (s1.nrCumparate == s2.nrCumparate)	{		nrCumparate = true;	}	else	{		nrCumparate = false;	}
	
	if (numeSala == tipSala == totalSala == nrRezervate == nrCumparate)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void adaugaSala(sala noua, int& nrTotalSali, string fname)
{
	noua.serializare(fname, ++nrTotalSali);
}

sala gasesteSala(int id, int nrTotalSali, string fname) // sau citire
{
	sala s;
	streampos pos = 0; // pornim de la pozitia 0
	for (int i = 0; i < nrTotalSali; i++)
	{
		pos = s.deserializare(pos, fname); //deserializeaza un obiect si intoarce pozitia la care a ramas
		if (id == s.getIdSala())
			return s;
	}
	s.setNumeSala("Negasit");
	return s;
}

void actualizareSala(int id, sala noua, int nrTotalSali, string fname)
{
	sala s;
	streampos pos = 0; //pornim de la pozitia 0
	string copie = "temp.bin";
	for (int i = 0; i < nrTotalSali; i++)
	{
		pos = s.deserializare(pos, fname);
		if (id != s.getIdSala())// daca nu gasim idul, copiem in noul fisier
			s.serializare(copie);
		else noua.serializare(copie, id);
	}
	remove(fname.c_str());
	rename(copie.c_str(), fname.c_str());
}

void stergeSala(int id, int& nrTotalSali, string fname)
{
	sala s;
	int sterse = nrTotalSali;
	streampos pos = 0; //pornim de la pozitia 0
	string copie = "temp.bin";
	for (int i = 0; i < nrTotalSali; i++)
	{
		pos = s.deserializare(pos, fname);
		if (id != s.getIdSala())// daca nu gasim idul, copiem in noul fisier
			s.serializare(copie);
		else
			sterse--;
	}
	nrTotalSali = sterse;
	remove(fname.c_str());
	rename(copie.c_str(), fname.c_str());
}

void afisareSali(int nrTotalSali, string fname)
{
	sala s;
	streampos pos = 0;
	for (int i = 0; i < nrTotalSali; i++)
	{
		pos = s.deserializare(pos, fname);
		cout << s << "\n";
	}
}

sala adaugaSalaConsola() //Stefana: adaugare elemente din consola
{
	string buffer;
	string numeSala; //A,B,C sau I.C.Carageale, M. Eminescu sau A2D, A3D, B2D, B3D //done
	char* tipSala;// 2D, 3D, 4D, s.a. //done
	string tipSalaStr;
	int totalSala; // numarul total de locuri pe care le are Sala //done
	int* totalLocuri; //vectorul in care se stocheaza locurile alese din sala (rezervate + cumparate) //done
	int nrLibere; //numarul locurilor ramase 
	int nrRezervate; // numarul locurilor rezervate //done
	int nrCumparate; //numarul biletelor cumparate de la casa //done

	cout << "Introdu numele salii: ";
	cin >> ws;
	getline(cin, numeSala);
	cout << endl;
	cout << "Introdu tipul salii: ";
	cin >> ws;
	getline(cin, tipSalaStr);
	cout << endl;
	cout << "Introdu numarul de locuri din sala: ";
	getline(cin, buffer);
	while (stringToInt(buffer) == 0)
	{
		cout << "Numarul de locuri din sala trebuie sa fie un numar intreg pozitiv. Te rog sa reintroduci numarul de locuri pentru aceasta sala: " << endl;
		getline(cin, buffer);
	}
	totalSala = stringToInt(buffer);
	cout << endl;
	totalLocuri = new int[totalSala]; //presupun 0 pentru locurile neocupate; de modificat daca e altfel
	for (int i = 0; i < totalSala; i++)
	{
		totalLocuri[i] = 0;
	}
	cout << endl;
	sala s;
	s.setNumeSala(numeSala);
	s.setTipSala((char*)tipSalaStr.c_str());
	s.setTotaSala(totalSala);
	s.setTotalLocuri(totalLocuri,0);
	s.setNrCumparate(0);
	s.setNrRezervate(0);
	s.setNrLibere(totalSala);
	cout << endl << "Biletul a fost salvat!" << endl;
	return s;
}