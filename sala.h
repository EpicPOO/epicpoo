#pragma once
#include<iostream>
#include<string>

using namespace std;


class sala
{
private:
	string numeSala; //A,B,C sau I.C.Carageale, M. Eminescu sau A2D, A3D, B2D, B3D //done
	string tipSala;// 2D, 3D, 4D, s.a. //done
	int totalSala; // numarul total de locuri pe care le are Sala //done
	int* totalLocuri; //vectorul in care se stocheaza locurile alese din sala (rezervate si cumparate) //done
	int nrLibere; //numarul locurilor ramase 
	int nrRezervate; // numarul locurilor rezervate //done
	int nrCumparate; //numarul biletelor cumparate de la casa //done
public:
	sala() //constructor implicit
	{
		numeSala = "";
		tipSala = "";
		totalSala = 0; //
		totalLocuri = nullptr;
		nrLibere = 0;
		nrRezervate = 0;
		nrCumparate = 0;
	}
	sala(string numeSala, string tipSala, int totalSala, int* totalLocuri, int nrRezervate, int nrCumparate) // constructor cu 6 parametri (sunt toti cei necesari)
	{
		if (numeSala != "")		{			this->numeSala = numeSala;			}	else	{			this->numeSala = "Necunoscuta";		}
		if (tipSala != "")		{			this->tipSala = tipSala;			}	else	{			this->tipSala = "Necunoscuta";		}
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
	sala(const sala& s) //constructor de copiere
	{
		if (s.numeSala != "")	{ this->numeSala = s.numeSala; }		else { this->numeSala = "Necunoscuta"; }
		if (s.tipSala != "")	{ this->tipSala = s.tipSala; }			else { this->tipSala = "Necunoscuta"; }
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
	}
	sala operator=(sala s) //operator =
	{
		if (totalLocuri != nullptr) { delete[] totalLocuri; }
		if (s.numeSala != "")	{ this->numeSala = s.numeSala; }		else { this->numeSala = "Necunoscuta"; }
		if (s.tipSala != "")	{ this->tipSala = s.tipSala; }			else { this->tipSala = "Necunoscuta"; }
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
	
	string	getNumeSala()		{	return numeSala;	}
	void	setNumeSala(string numeSala)	{	if (numeSala != "")	{	this->numeSala = numeSala;	}	else	{	this->numeSala = "";	}	}

	string	getTipSala()		{	return tipSala;		}
	void	setTipSala(string tipSala) 		{ 	if (tipSala != "")	{	this->tipSala = tipSala;	} 	else	{	this->tipSala = "";		}	}

	int		getTotalSala()		{	return totalSala;	}
	void	setTotaSala(int totalSala)		{	if (totalSala != 0)	{	this->totalSala = totalSala;}	else	{	this->totalSala = 0;	}	}

	int		getNrLibere()		{	return nrLibere;	} // nu avem nevoie de set pentru ca se face calculul in restul functilor
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
			
			for (int i = 0; i < sumaLocuriOcupate; i++)
			{
				this->totalLocuri[i] = totalLocuri[i];
			}
		}
	}
	int metodaVLad()
	{
		return 0;
	}
};