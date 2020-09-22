#include <iostream>


float area();
class a
{
private:
	float length;
	float areas;
public:
	friend float area()
	{
		areas = length*length;
	}
	friend void operator<<(iostream &op, a &area2)
	{

	}
};
