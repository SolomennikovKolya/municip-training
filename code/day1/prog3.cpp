// 2019 - N4

#include <iostream>
#include <vector>

using namespace std;

const int MAX_NUM = 100;

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	int dels[MAX_NUM + 1];
	for (int i = 0; i < MAX_NUM; ++i)
	{
		dels[i] = 0;
	}
	for (int d = 1; d <= MAX_NUM; ++d)
	{
		for (int i = d; i <= MAX_NUM; i += d)
		{
			dels[i] += 1;
		}
	}

	int coord1 = 0;
	int coord2 = 0;
	int coord3 = 0;
	for (int i = 0; i < n; ++i)
	{
		const int num = abs(a[i]);
		if (dels[num] == 2)
			coord1 += a[i];
		else if (dels[num] == 3)
			coord2 += a[i];
		else if (dels[num] == 4)
			coord3 += a[i];
	}

	cout << coord1 << " " << coord2 << " " << coord3 << "\n";

	return 0;
}