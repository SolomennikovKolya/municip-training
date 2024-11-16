#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<bool>> &a, vector<bool> &visited, int cur_v, int n)
{
	visited[cur_v] = true;
	for (int i = 0; i < n; ++i)
	{
		if (a[cur_v][i] && visited[i] == false)
		{
			dfs(a, visited, i, n);
		}
	}
}

int main()
{
	int n;
	cin >> n;

	vector<vector<bool>> a(n, vector<bool>(n, false));

	int v1, v2;
	while (cin >> v1)
	{
		cin >> v2;
		a[v1 - 1][v2 - 1] = true;
		a[v2 - 1][v1 - 1] = true;
	}

	vector<bool> visited(n, false);

	int components = 0;

	for (int i = 0; i < n; ++i)
	{
		if (visited[i] == false)
		{
			dfs(a, visited, i, n);
			components++;
		}
	}

	cout << components + 1;

	return 0;
}