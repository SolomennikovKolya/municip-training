#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
		}
	}

	vector<vector<int>> b(n, vector<int>(m, 0));
	b[n - 1][m - 1] = 2;

	for (int j = m - 2; j >= 0; --j)
	{
		if (a[n - 1][j] > m - j - 1)
			b[n - 1][j] = 2;
		else
		{
			int delta = a[n - 1][j];
			if (a[n - 1][j + delta] == 1)
				b[n - 1][j] = 2;
			else
				b[n - 1][j] = 1;
		}
	}

	for (int i = n - 2; i >= 0; --i)
	{
		if (a[i][m - 1] > n - i - 1)
			b[i][m - 1] = 2;
		else
		{
			int delta = a[i][m - 1];
			if (a[i + delta][m - 1] == 1)
				b[i][m - 1] = 2;
			else
				b[i][m - 1] = 1;
		}
	}

	for (int i = n - 2; i >= 0; --i)
	{
		for (int j = m - 2; j >= 0; --j)
		{
			int delta = a[i][j];
			if (delta > m - j - 1)
			{
				if (delta > n - i - 1)
				{
					b[i][j] = 2;
				}
				else
				{
					if (a[i + delta][j] == 1)
					{
						b[i][j] = 2;
					}
					else
					{
						b[i][j] = 1;
					}
				}
			}
			else
			{
				if (delta > n - i - 1)
				{
					if (a[i][j + delta] == 1)
						b[i][j] = 2;
					else
						b[i][j] = 1;
				}
				else
				{
					if (a[i + delta][j] == 2 || a[i][j + delta] == 2)
						b[i][j] = 1;
					else
						b[i][j] = 2;
				}
			}
		}
	}

	cout << b[0][0] << "\n";
	int cur_x = 0;
	int cur_y = 0;

	while (true)
	{
		if (a[cur_y][cur_x] == 0)
			break;

		int delta = a[cur_y][cur_x];

		if (delta > m - cur_x - 1)
		{
			if (delta > n - cur_y - 1)
			{
				break;
			}
			else
			{
				cur_y += delta;
			}
		}
		else
		{
			if (delta > n - cur_y - 1)
			{
				cur_x += delta;
			}
			else
			{
				if (a[cur_x][cur_y] == 1)
				{
					if (a[cur_y + delta][cur_x] == 2)
					{
						cur_y += delta;
					}
					else
					{
						cur_x += delta;
					}
				}
				else
				{
					if (a[cur_y + delta][cur_x] == 1)
					{
						cur_y += delta;
					}
					else
					{
						cur_x += delta;
					}
				}
			}
		}
	}

	cout << cur_y << " " << cur_x << "\n";

	return 0;
}