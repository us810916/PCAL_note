/***************************************************************************************************
	This macro will help to rewrite the attenuation coefficients compatible to copy
	in the PCAL note

	TAYA, May 24, 2016
****************************************************************************************************/
#include<stdio.h>
#include<fstream>

void tableForNote()
{	
	int counter;
	double UcoeffA[100], UcoeffB[100], UcoeffC[100], UstripNum[100], junk[100];
	//read U coeff
	ifstream ifileU("/home/chetry/EC_PCAL/PCALnote/tableFormat/WattenCoeff.dat");
	ofstream ofileU("/home/chetry/EC_PCAL/PCALnote/tableFormat/WcoeffTEX.dat");
	counter = 0;
    if(ifileU.is_open())
    {
        while(!ifileU.eof())
        {
        	ifileU >> UstripNum[counter] >> junk[counter] >> UcoeffA[counter] >> UcoeffB[counter] >> UcoeffC[counter];
            ++counter;//remember that the counter will be 1 more than it should be
        }
        ifileU.close();
    }
    for(int i = 0; i < counter-1; ++i)
    {
		ofileU << UstripNum[i] << " & " << UcoeffA[i] << " & " << UcoeffB[i] << " & " << UcoeffC[i] << " \\\\ \\ hline " << endl;
		cout << UstripNum[i]  << " & " << UcoeffA[i] << " & " << UcoeffB[i] << " & " << UcoeffC[i] << " \\\\ \\ hline " << endl;
	}
    ofileU.close();
}

