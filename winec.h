#include <iostream>
#include <string>
#include <valarray>


template <typename T1,typename T2>
class Pair
{
	private:
	T1 first;
	T2 second;
	public:
	Pair():first(10),second(10) {}
	~Pair() {}
	T1& First() { return first; }
	T2& Second() { return second; }
};

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt,ArrayInt> PairArray;


class Wine
{
	private:
	int year;
	std::string nm;
	Pair<ArrayInt,ArrayInt> fk;
	public:
	Wine(const char *l,int y,const int yr[],const int bot[]);
	Wine(const char *l,int y);
	void GetBottles();
	std::string& Label() { return nm; }
	int sum();
	void Show();
};