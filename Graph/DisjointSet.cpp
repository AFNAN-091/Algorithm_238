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

vector<int>par(100,-1);

int find(int u)
{
	if(par[u]==-1)
	{
		return u;
	}
	return find(par[u]);
}

void union_(int u,int v)
{
	int x = find(u);
	int y = find(v);
	par[x] = y;
}


int disjointSet(vector<pair<int,int>> &edge)
{
	for(auto it: edge)
	{
		int x = find(it.first);
		int y = find(it.second);
		if(x==y)
		{
			return true;
		}

		union_(it.first,it.second);
	}

	return false;
}


int main()
{   
    FAsT  
    
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> edge;
    for(int i=0; i<m; i++)
    {
    	int x,y;
    	cin>>x>>y;
    	edge.push_back({x,y});
    }

    if(disjointSet(edge))
    {
    	cout<<"cycle detected ";
    }
    else{
    	cout<<"cycle not found ";
    }

    exit(0);
}