#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
#include<set>
#include<stack>
#include<string>
#include<map>
#define MAXSIZE 100
#define MAXSUM 1000

using namespace std;

int main()
{
	int n, k;
	float t;
	cin >> n >> t;
	k = t * 100;
	int a[MAXSIZE];
	int trace[MAXSIZE][MAXSUM], index[MAXSIZE][MAXSUM];
	bool dp[MAXSIZE][MAXSUM];
	for (int i = 0; i < MAXSIZE; i++)
	{
		for (int j = 0; j < MAXSUM; j++)
		{
			dp[i][j] = false;
			trace[i][j] = -1;
			index[i][j] = -1;
		}
	}
	dp[0][0] = true;
	for (int i = 0; i < MAXSUM; i++)
	{
		index[0][i] = -1;
	}
	for (int i = 1; i <= n; i++)
	{
		float ti;
		cin >> ti;
		ti *= 100;
		a[i] = ti;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < MAXSUM; j++)
		{
			if (dp[i - 1][j])
			{
				dp[i][j] = true;
				trace[i][j] = j;
			}

			if (j - a[i] >= 0 && dp[i - 1][j - a[i]] == true)
			{
				dp[i][j] = true;
				trace[i][j] = j - a[i];
				index[i][j] = i;
			}
		}
	}
	while (k < MAXSUM && !dp[n][k])
		k++;
	if (k == MAXSUM)
	{
		cout << "k is biger than sum of array!" << endl;
		return 0;
	}

	cout << (float)k/100 << endl;
	stack<int> show;
	
	while (trace[n][k] != -1)
	{
		if (index[n][k] != -1)
			show.push(index[n][k]);

		k = trace[n][k];
		n--;
	}
	while (!show.empty())
	{
		cout << show.top() - 1<< " ";
		show.pop();
	}
	return 0;	
}
