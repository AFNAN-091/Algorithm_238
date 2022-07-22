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

int n,m;
vector<int>adj[100];
int w[100][100];

int minvertex(vector<bool>&visit,vector<int>&dis)
{
	int mn = INT_MAX;
	int node;
	for(int i=0; i<n; i++)
	{
		if(dis[i]<mn and visit[i]==false)
		{
			node = i;
			mn = dis[i];
		}
	}

	return node;
}

void prims()
{
	
	 vector<int>dis(n,100);
	 vector<bool>visit(n,false);
	 vector<int>par(n,-1);
	 dis[0] = 0;
 	 par[0] = -1;
	
	for(int i=0; i<n; i++)
	{
		int mn = minvertex(visit,dis);
		visit[mn] = true;
		
		//cout<<mn<<" ";
		for(int j=0; j<adj[mn].size(); j++)
		{
				int node = adj[mn][j];
			if(!visit[node] and dis[node]>w[mn][node])
				{
				//	cout<<node<<endl;
					dis[node] = w[mn][node];
					//cout<<w[mn][node]<<endl;
				//	cout<<mn<<" "<<node<<" "<<dis[node]<<endl;
					par[node] = mn;
				}
		}
		// cout<<endl<<endl;
	}

	
	for(int i=1; i<n; i++)
	{
		cout<<i<<" "<<par[i]<<" "<<w[i][par[i]]<<endl;
	}
}

int main()
{   
    FAsT  
    ll a, b, c, d, e, f, g, h, k, len, p, q, r, t, x, y, z;

    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
    	cin>>x>>y>>z;
    	
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    	w[x][y] = z;
    	w[y][x] = z;
    }

    // for(int i=0; i<n; i++)
    // {
    // 	cout<<i<<" :";
    // 	for(auto it: w[i])
    // 	{
    // 		cout<<it<<' ';
    // 	}
    // 	cout<<endl;
    // }

    prims();
   

    exit(0);
}