#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class binar // clasa abstracta care impune crearea metodelor de serializare si deserializare
{
public:
	virtual void serializare(string fname) = 0;
	virtual streampos deserializare(streampos start, string fname) = 0;
};