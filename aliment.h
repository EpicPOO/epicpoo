#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "helpersCRUD.h" //Stefana: adaugat pentru accesare functie stringToInt din header
#include "binar.h"
#include "pr.h"
#include<vector>
using namespace std;

class aliment : public binar, public pr
{
private:
	const int idAliment = 0;
	string numeAliment; //ca la aliment/sala
	char* categorie;
	int lungimeCod; // avem nevoie de lungime
	vector<int>codBare;//int* codBare;
	float pret;
	static int numarAlimente;
public:

	aliment() : idAliment(++numarAlimente) //cstr implicit
	{
		numeAliment = "";
		categorie = nullptr;
		lungimeCod = 0;
		//codBare = nullptr;
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
			//this->codBare = new int[lungimeCod];
			for (int i = 0; i < lungimeCod; i++)
				this->codBare.push_back(codBare[i]);//this->codBare[i] = codBare[i];
		}
		else
		{
			this->lungimeCod = 0;
			this->codBare.clear();//this->codBare = nullptr;
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

		if (a.codBare.size() != 0 && a.lungimeCod > 0)//if (a.codBare != nullptr && a.lungimeCod > 0)
		{
			lungimeCod = a.lungimeCod;
			//codBare = new int[a.lungimeCod];
			for (int i = 0; i < a.lungimeCod; i++)
				codBare.push_back(a.codBare[i]); //codBare[i] = a.codBare[i];
		}
		else
		{
			lungimeCod = 0;
			codBare.clear(); //codBare = nullptr;
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
			if (codBare.size() != 0) codBare.clear();//if (codBare != nullptr) delete[] codBare;
			if (a.codBare.size() != 0 && a.lungimeCod > 0)//if (a.codBare != nullptr && a.lungimeCod > 0)
			{
				lungimeCod = a.lungimeCod;
				//codBare = new int[a.lungimeCod];
				for (int i = 0; i < a.lungimeCod; i++)
					codBare.push_back(a.codBare[i]); //codBare[i] = a.codBare[i];
			}
			else
			{
				lungimeCod = 0;
				//codBare = nullptr;
			}
		}

		if (a.pret > 0) pret = a.pret;
		else pret = 0;

		return *this;
	}

	~aliment() //destructor
	{
		if (categorie != nullptr) delete[] categorie;
		//if (codBare != nullptr) delete[] codBare;
	}

	//getter + setteri cu validari

	int getIdAliment() { return idAliment; } //Stefana: adaugare getter idAliment

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
	void setNumeAliment(string numeAliment) //Stefana: adaugare numeAliment
	{
		this->numeAliment = numeAliment;
	}
	void setLungimeCod(int lungimeCod)
	{
		if (lungimeCod > 0) this->lungimeCod = lungimeCod;
		else lungimeCod = 0;
	}

	vector<int> getCodBare() { return codBare; }//int* getCodBare() { return codBare; }
	void setCodBare(int* codBare, int lungimeCod)
	{
		setLungimeCod(lungimeCod);

		if (this->codBare.size() != 0) this->codBare.clear();//if (this->codBare != nullptr) delete[] this->codBare;
		if (codBare != nullptr)
		{
			this->codBare.clear();//this->codBare = new int[lungimeCod];
			for (int i = 0; i < lungimeCod; i++)
				this->codBare.push_back(codBare[i]);//this->codBare[i] = codBare[i];
		}
		else this->codBare.clear();//else this->codBare = nullptr;
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
		if ((index >= 0 && index < codBare.size() && codBare.size() != 0))//if ((index >= 0 && index < sizeof(codBare) && codBare != nullptr))
			return codBare[index];
		else throw exception("Index invalid");
	}

	bool operator!() //supraincarcare operator ! -> daca avem codBare
	{
		return codBare.size() != 0; //return codBare != nullptr;
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

	void inchidereFisier(ifstream f) //Stefana: adaugare functie inchidere fisier
	{
		f.close();
	}

	ifstream deschidereFisier(string numeFisier) //Stefana: adaugare functie deschidere fisier
	{
		ifstream f(numeFisier, ios::binary);
		return f;
	}

	void serializare(string fname) //Stefana: adaugare serializare
	{
		serializare(fname, idAliment);
	}

	void serializare(string fname, int id) //Stefana: adaugare serializare
	{
		ofstream f(fname, ios::app | ios::binary);
		f.write((char*)&id, sizeof(id));
		int lengthNume = numeAliment.length() + 1;
		f.write((char*)&lengthNume, sizeof(lengthNume)); //dimensiune nume aliment
		f.write(numeAliment.c_str(), lengthNume); // scriere numeAliment
		int lengthCategorie = strlen(getCategorie()) + 1; //modificati sa fie doar o variabila pentru o mai buna gestionare a memoriei
		f.write((char*)&lengthCategorie, sizeof(lengthCategorie)); // dimensiunea categoriei
		f.write(categorie, lengthCategorie); //scriere categorie
		f.write((char*)&lungimeCod, sizeof(lungimeCod)); //scriere lungimeCod
		for (int i = 0; i < lungimeCod; i++)
		{
			f.write((char*)&codBare[i], sizeof(codBare[i])); //scriere codBare
		}
		f.write((char*)&pret, sizeof(pret));
		f.close();
	}

	streampos deserializare(streampos start, string fname) //Stefana: adaugare deserializare
	{
		ifstream f(fname, ios::binary);
		f.seekg(start); // pornim de la pozitia primita ca argument
		f.read((char*)&idAliment, sizeof(idAliment));
		int length = 0;
		f.read((char*)&length, sizeof(length));
		char* aux = new char[length];
		f.read(aux, length);
		setNumeAliment(aux); //am citit numeAliment
		length = 0;
		f.read((char*)&length, sizeof(length));
		delete[] aux;
		aux = new char[length];
		f.read(aux, length);
		setCategorie(aux);
		f.read((char*)&lungimeCod, sizeof(lungimeCod)); //lungime cod bare
		int* copie = new int[lungimeCod];
		for (int i = 0; i < lungimeCod; i++)
		{
			f.read((char*)&copie[i], sizeof(copie[i]));
		}
		setCodBare(copie, lungimeCod); //lungime cod
		f.read((char*)&pret, sizeof(pret));
		streampos pos = f.tellg();
		f.close();
		return pos;
	}
};

ostream& operator<<(ostream& out, aliment a) // operator afisare
{
	out << "ID aliment: " << a.idAliment << endl; //Stefana: adaugare idAliment in operator<<
	out << "Nume aliment: " << a.numeAliment << endl;
	out << "Categorie: " << a.categorie << endl;
	out << "Pret: " << a.pret << endl;
	out << "Lungimea codului de bare: " << a.lungimeCod << endl;
	out << "Cod de bare: ";
	if (a.codBare.size() != 0)//if (a.codBare != nullptr)
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
	in.getline(buffer, 19);
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
	int* codBare = new int[a.lungimeCod]; //modif refact stl
	for (int i = 0; i < a.lungimeCod; i++)
		in >> codBare[i];
	for (int i = 0; i < a.lungimeCod; i++)
	{
		a.codBare.clear();
		a.codBare.push_back(codBare[i]);
	}
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

int getLastIdAliment(string fname)
{
	int idAlim = 0;
	if (testTipFisier(fname) == 1)
	{
		aliment a;
		streampos pos = 0; // pornim de la pozitia 0
		for (int i = 0; i <= citesteTotalAlimenteInt("Total.txt"); i++)
		{
			pos = a.deserializare(pos, fname); //deserializeaza un obiect si intoarce pozitia la care a ramas
			idAlim = a.getIdAliment();
		}
		return idAlim;
	}
	else return 0;
}

void adaugaAliment(aliment noul, int& nrTotalAlimente, string fname) //Stefana: adaugare functie adauga aliment
{
	nrTotalAlimente++;
	noul.serializare(fname, getLastIdAliment(fname) + 1);

}

aliment gasesteAliment(int id, int nrTotalAlimente, string fname) // sau citire //Stefana: adaugare functie gaseste aliment
{
	aliment a;
	streampos pos = 0; // pornim de la pozitia 0
	for (int i = 0; i < nrTotalAlimente; i++)
	{
		pos = a.deserializare(pos, fname); //deserializeaza un obiect si intoarce pozitia la care a ramas
		if (id == a.getIdAliment())
			return a;
	}
	a.setNumeAliment("Negasit");
	return a;
}

void actualizareAliment(int id, aliment nou, int nrTotalAlimente, string fname) //Stefana: adaugare functie actualizare aliment
{
	aliment a;
	streampos pos = 0; //pornim de la pozitia 0
	string copie = "temp.bin";
	for (int i = 0; i < nrTotalAlimente; i++)
	{
		pos = a.deserializare(pos, fname);
		if (id != a.getIdAliment())// daca nu gasim idul, copiem in noul fisier
			a.serializare(copie);
		else nou.serializare(copie, id);
	}
	remove(fname.c_str());
	rename(copie.c_str(), fname.c_str());
}

void stergeAliment(int id, int& nrTotalAlimente, string fname) //Stefana: adaugare functie stergere aliment
{
	aliment a;
	int sterse = nrTotalAlimente;
	streampos pos = 0; //pornim de la pozitia 0
	string copie = "temp.bin";
	for (int i = 0; i < nrTotalAlimente; i++)
	{
		pos = a.deserializare(pos, fname);
		if (id != a.getIdAliment())// daca nu gasim idul, copiem in noul fisier
			a.serializare(copie);
		else
			sterse--;//decrementam copia nr total
	}
	nrTotalAlimente = sterse;
	remove(fname.c_str());
	rename(copie.c_str(), fname.c_str());
}

void afisareAlimente(int nrTotalAlimente, string fname)
{
	aliment a;
	streampos pos = 0;
	for (int i = 0; i < nrTotalAlimente; i++)
	{
		pos = a.deserializare(pos, fname);
		cout << a << "\n";
	}
}


aliment adaugaAlimentConsola() //Stefana: adaugare elemente din consola
{
	string buffer;
	string numeAliment; //ca la aliment/sala
	string categorieConsola;
	char* categorie;
	int lungimeCod; // avem nevoie de lungime
	string codB;
	int* codBare;
	float pret;
	static int numarAlimente;
	cout << "Introdu numele alimentului: ";
	cin >> ws;
	getline(cin, numeAliment);
	cout << endl;
	cout << "Introdu categoria alimentului: ";
	getline(cin, categorieConsola);
	cout << endl;
	cout << "Introdu lungimea codului de bare: ";
	cin >> ws;
	getline(cin,buffer);
	while (stringToInt(buffer) == 0)
	{
		cout << "Lungimea codului de bare trebuie sa fie mai mare decat 0. Te rog sa reintroduci lungimea: " << endl;
		getline(cin, buffer);
	}
	lungimeCod = stringToInt(buffer);
	cout << endl;
	int* cod = new int[lungimeCod];
	for (int i = 0; i < lungimeCod; i++)
	{
		cout << "Introdu cifra " << i+1 << " a codului de bare: ";
		cin >> cod[i];
	}
	cout << endl;
	cout << "Introdu pretul alimentului: ";
	cin >> ws;
	getline(cin, buffer);
	while (stringToInt(buffer) == 0)
	{

		cout << "Pretul trebuie sa fie un numar pozitiv. Te rog sa reintroduci pretul: " << endl;
		getline(cin, buffer);
	}
	pret = stringToInt(buffer);
	cout << endl;
	aliment a;
	a.setnumeAliment(numeAliment);
	a.setCategorie((char*)categorieConsola.c_str());
	a.setCodBare(cod, lungimeCod);
	a.setPret(pret);
	cout << endl << "Alimentul a fost salvat!" << endl;
	return a;
}