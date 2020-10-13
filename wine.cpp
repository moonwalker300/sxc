#include "winec.h"

Wine::Wine(const char *l,int y,const int yr[],const int bot[]):nm(l),year(y)
{
	for (int i = 0;i < y;i++) fk.First()[i] = yr[i],fk.Second()[i] = bot[i];
}

Wine::Wine(const char *l,int y):nm(l),year(y){}

void Wine::GetBottles()
{
	using std::cin;
	using std::cout;
	using std::endl;
	cout<<"Enter "<<nm<<" data for "<<year<<" year(s):"<<endl;
	for (int i = 0;i < year;i++)
	{
		cout<<"Enter year: ";
		int x;
		cin>>x;
		fk.First()[i] = x;
		cout<<"Enter bottles for that year: ";
		cin>>x;
		fk.Second()[i] = x;
	}
}

int Wine::sum() { return (fk.Second()).sum(); }

void Wine::Show()
{
	using std::cout;
	using std::endl;
	cout<<"Wine: "<<nm<<endl;
	cout<<"        Year    Bottles"<<endl;
	for (int i = 0;i < year;i++)
	{
		cout<<"        "<<fk.First()[i]<<"    "<<fk.Second()[i]<<endl;
	}
}