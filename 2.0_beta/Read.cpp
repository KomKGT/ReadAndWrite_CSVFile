#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double D_convertstringTodoubleOfx();
double D_convertstringTodoubleOfy();
void V_readCSVfile();

int I_count = 0;
string str_x[100];
string str_y[100];

double D_x[100];
double D_y[100];

double x;
double y;

int i = 0;

double D_convertstringTodoubleOfx()
{
	if(I_count>=1)
	{
		stringstream convertx(str_x[I_count]);
		convertx >> D_x[I_count];
        return D_x[I_count];
	}
	
}
double D_convertstringTodoubleOfy()
{
	if(I_count>=1)
	{
		stringstream converty(str_y[I_count]);
		converty >> D_y[I_count];
        return D_y[I_count];
	}

}
void V_readCSVfile()
{
	ifstream MyReadFile("xy.csv"); //Re file position
	
	if(!MyReadFile.is_open())
		cout<<"File Can't Open"<<endl;
		
	string line;
	
	while(getline(MyReadFile,line))
	{
		stringstream ss(line);
		
		getline(ss,str_x[I_count],',');
		getline(ss,str_y[I_count],'\n');
		
		if(I_count >= 1)
		{
			D_x[I_count] = D_convertstringTodoubleOfx();
			D_y[I_count] = D_convertstringTodoubleOfy();	
		}
		
		I_count++;
		
		if(I_count ==100 )
			I_count == 0;
			
		
	}
}

int main(int argc, char** argv) {
	 
	V_readCSVfile();
	
	
	
	for(int i =1;i<=100;i++)
	{
		cout<<"x = "<<D_x[i]<<" "<<"y = "<<D_y[i]<<"\n";
	}
	//cout<<"x = "<<x<<" "<<"y = "<<y<<"\n";
	//V_readCSVfile();
	//cout<<"x = "<<D_x[2]<<" "<<"y = "<<D_y[2]<<"\n";
	
	return 0;
}

