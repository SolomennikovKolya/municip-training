#include <iostream>

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int a, b, c, d;

	cin >> a >> b >> c >> d;

	int ans = 1000000000;
	int ansMajki = 0, ansNoski = 0;

	if (ans > b + 1 + d + 1)
	{
		ans = b + 1 + d + 1;
		ansMajki = b + 1;
		ansNoski = d + 1;
	}
	if (ans > a + 1 + c + 1)
	{
		ans = a + 1 + c + 1;
		ansMajki = a + 1;
		ansNoski = c + 1;
	}
	if (ans > max(a, b) + 1 + 1)
	{
		ans = max(a, b) + 1 + 1;
		ansMajki = max(a, b) + 1;
		ansNoski = 1;
	}
	if (ans > 1 + max(c, d) + 1)
	{
		ans = 1 + max(a, b) + 1;
		ansMajki = 1;
		ansNoski = max(c, d);
	}

	cout << ansMajki << " " << ansNoski << "\n";
	// cout << ans;

	return 0;
}