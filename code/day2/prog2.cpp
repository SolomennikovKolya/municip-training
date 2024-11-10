#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> val(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> val[i];
	}

	const int INF = k + 1;

	int shish_num = 0;
	for (int i : val)
	{
		shish_num += i;
	}

	vector<vector<int>> a(n + 1, vector<int>(shish_num + 1, INF));

	for (int i = 0; i <= n; ++i)
	{
		a[i][0] = 0;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= shish_num; ++j)
		{
			if (j - val[i - 1] < 0)
				a[i][j] = a[i - 1][j];
			else
				a[i][j] = min(a[i - 1][j], a[i - 1][j - val[i - 1]]) + j;
		}
	}

	for (int j = shish_num; j >= 0; j--)
	{
		for (int i = 0; i <= n; ++i)
		{
			if (a[i][j] <= k)
			{
				cout << j << "\n";
				return 0;
			}
		}
	}

	// for (int i = 0; i <= n; ++i)
	// {
	// 	for (int j = 0; j <= shish_num; ++j)
	// 	{
	// 		cout << a[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	// cout << "0\n";

	return 0;
}