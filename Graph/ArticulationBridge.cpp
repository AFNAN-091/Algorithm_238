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
std::vector<int> adj[100];

void dfs(int u, vector<int>&dis, vector<int>&low, vector<int>&par, vector<pair<int,int>>&bridge )
{
	static int time = 0;
	dis[u] = low[u] = time;
	time++;
	for(auto v : adj[u])
	{
		if(dis[v]==-1)
		{
			par[v] = u;
			dfs(v,dis,low,par,bridge);
			low[u] = min(low[u], low[v]);

			if(low[v]> dis[u])
			{
				//low[v]>= dis[u] for AP
				bridge.push_back({u,v});
			}
		}
		else if(v!=par[u]){
			low[u] = min(low[u], dis[v]);
		}
	}
}


void findBridge()
{
	vector<int>dis(7,-1),low(7,-1),par(7,-1);
	vector<pair<int,int>>bridge;

	for(int i=0; i<n; i++)
	{
		if(dis[i]==-1)
		{
			dfs(i,dis,low,par,bridge);
		}
	}

	cout<<bridge.size()<<endl;
	for(auto it: bridge)
	{
		cout<<it.first<<" "<<it.second<<endl;
	}
}

int main()
{   
    FAsT  
    ll a, b, c, d, e, f, g, h, k, len,  p, q, r, t, x, y, z;

    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
    	cin>>x>>y;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }

    findBridge();

    exit(0);
}