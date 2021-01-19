#include "meniu.h"

using namespace std;

int main()
{
	string fname = "total.txt";

	if (testTipFisier(fname) == 0)
	{
		adaugaZeroTotal(fname);
	}

	meniu();

	return 0;
}