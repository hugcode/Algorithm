#include <iostream>

using namespace std;

int 	face[100005];
string	role[100005];

int main(void)
{
	int i, n, m, cur;
	int a, s, dir;

	cin >> n >> m;

	for(i=0; i<n; i++)
	{
		cin >> face[i] >> role[i];
		if (face[i]==0)
			face[i] = -1;
	}

	cur = 0;
	for(i=0; i<m; i++)
	{
		cin >> a >> s;

		if (a==0)
			a = -1;

		dir = a*face[cur]*(-1);
		s  %= n;

		cur = (cur + n + dir*s) % n;
	}

	cout << role[cur];

	return 0;
}
