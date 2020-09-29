#include <iostream>
#include "SimLink.h"
using namespace std;
int main() {
	SimLink<int > s;
	s.Insert(1, 100);
	int a;
	s.GetElem(1, a);
	s.Delete(1, a);
	s.GetElem(1, a);
	cout << s.Length() << endl << a;
	return 0;
}