#include "Header.h";
#include <iostream>;

void setgolf(golf &g, const char *name, int hc)
{
	g = { *name, hc };
}

int setgolf(golf &g)
{

}

void handicap(golf &g, int hc)
{

}

void showgolf(const golf &g)
{
	std::cout << "Name:" << g.fullname << '\n';
	std::cout << "Score" << g.handicap << '\n';
}

int main()
{
	golf anne;
	return 0;
}