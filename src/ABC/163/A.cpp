#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	double R;
	cin >> R;

	cout << fixed << setprecision(numeric_limits<double>::max_digits10) << (R * M_PI * 2) << endl;
	return 0;
}
