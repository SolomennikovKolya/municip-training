#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int A;
	cin >> A;
	vector<bool> resheto(A + 1, true);
	resheto[1] = false;

	for (int i = 2; i <= A; ++i)
	{
		if (resheto[i])
		{
			for (int j = i * 2; j <= A; j += i)
			{
				resheto[j] = false;
			}
		}
	}

	vector<int> prost;
	for (int i = 2; i <= A; ++i)
	{
		if (resheto[i])
			prost.push_back(i);
	}

	for (int a : prost)
	{
		for (int b : prost)
		{
			int c = A - a - b;
			if (c > 1 && resheto[c])
			{
				cout << a << " " << b << " " << c << "\n";
				return 0;
			}
		}
	}

	cout << "-1\n";
	return 0;
}