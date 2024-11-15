#include <iostream>

using namespace std;

int variants(int p, int v)
{
	if (p <= 6)
	{
		int res = 1;
		for (int i = p + v - 1; i >= p; --i)
		{
			res *= i;
		}
		for (int i = 2; i <= v; ++i)
		{
			res /= i;
		}
		return res;
	}
	else
	{
		if (v == 5)
		{
			return 252;
		}
		else
		{
			return 2 * 252;
		}
	}
}

int main()
{
	int ans = 1;
	for (int game = 0; game < 3; ++game)
	{
		int p, v;
		cin >> p >> v;

		if (p > v)
			ans *= variants(p, v);
		// cout << variants(p, v) << "\n";
		else
			ans *= variants(v, p);
		// cout << variants(v, p) << "\n";

		// cout << variants(p, v) << "\n";

		// ans *= variants(p, v);
	}
	cout << ans << "\n";
	return 0;
}