//           * * ببسم الله الرحمن الرحيم    * *
// ********************@Author**************************************
//     ____     _____   __  _     ____     __  _
//    / __ \   | ____| |  \| |   / __ \   |  \| |
//   / /__\ \  | |__   | |\  |  / /__\ \  | |\  |
//  /_/    \_\ |_|     |_| \_| /_/    \_\ |_| \_|
 
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define lcm(a,b)    a*b/__gcd(a,b)
#define endl '\n'
#define FAsT ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long ll;

int rr[] = { -1, 1, 0, 0, -1, -1, 1, 1};
int cc[] = {0, 0, -1, 1, -1, 1, -1, 1};

const int N = 1e6+7;

/*--------------------------------------------------------------------*/

int Lcs(string a, string b)
{
	int temp[a.size()+1][b.size()+1];
	int mx = 0;
	for(int i=0; i<a.size()+1; i++)
	{
		temp[i][0] = 0;
	}
	for(int i=0; i<b.size()+1; i++)
	{
		temp[0][i] = 0;
	}
	for(int i=1; i<a.size()+1; i++)
	{
		for(int j=1; j<b.size()+1; j++)
		{
			if(a[i-1]==b[j-1])
			{
				temp[i][j] = temp[i-1][j-1] + 1;
			}
			else{
				temp[i][j] = max(temp[i-1][j],temp[i][j-1]);
			}
		}
	}

	
	return temp[a.size()][b.size()];

}

int main()
{   
    FAsT  
    ll a, b, c, d, e, f, g, h, k, len, n, m, p, q, r, t, x, y, z;

    string  s1,s2;
    s1 = "abcdaf";
    s2 = "acbcf";
    cout<<Lcs(s1,s2)<<endl;

    exit(0);
}