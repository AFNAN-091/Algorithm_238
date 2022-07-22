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

void permute(string s, int l , int r)
{
	if(l==r)
	{
		cout<<s<<endl;
	}
	

	else{
		unordered_set<char> uset;
		for(int i=l; i<=r; i++)
		{
			

			if (uset.find(s[i]) != uset.end())
            continue;
        
	        else
	            uset.insert(s[i]);
        
			swap(s[l],s[i]);
			permute(s,l+1,r);
			swap(s[l],s[i]);
		}
	}
}

int main()
{   
    FAsT  
    ll a, b, c, d, e, f, g, h, k, len, n, m, p, q, r, t, x, y, z;

    string s;
    cin>>s;
    permute(s,0,s.size()-1);
    exit(0);
}