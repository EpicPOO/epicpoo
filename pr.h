#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "helpersCRUD.h" 
using namespace std;

class pr
{
private:
	float pret;
public:
	virtual float getPret()
	{
		return pret;
	}
	virtual void setPret(float pret)
	{
		if (pret > 0)
			this->pret = pret;
		else this->pret = 0;
	}
};