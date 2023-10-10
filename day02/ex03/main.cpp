# include "Point.hpp"

using std::cout;
using std::endl;

int main(void)
{
	if (bsp(Point(0, 0), Point(0, 100), Point(100, 0), Point(-1000, 1000)) == true)
        cout << "Point is in the triangle" << endl;
	else
        cout << "Point is not in the triangle" << endl;
	return 0;
}