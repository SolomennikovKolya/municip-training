
#include <iostream>

using namespace std;

int main()
{
	int d, n;
	cin >> d >> n;

	int a = n / (d * 111);
	int b = (n - a * (d * 111)) / (d * 11);
	int c = (n - a * (d * 111) - b * (d * 11)) / d;

	// cout << a << " " << b << " " << c << "\n";

	cout << a + b + c - 1;

	return 0;
}