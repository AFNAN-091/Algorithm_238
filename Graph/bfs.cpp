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

std::vector<int> adj[100];

int cost[100];
int visit[100];
void bfs(int u)
{
	queue<int>q;
	q.push(u);
	cost[u] = 0;
	visit[u] = 1;
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		for(int i=0; i<adj[cur].size(); i++)
		{
			int node = adj[cur][i];
			if(!visit[node])
			{
				visit[node] = 1;
				//cout<<cost[u]<<endl;
				cost[node] = cost[cur] + 1;
				q.push(node);
			}
		}
	}

}

int main()
{   
    FAsT  
    ll a, b, c, d, e, f, g, h, k, len, n, m, p, q, r, t, x, y, z;

   cin>>n>>m;
    for(int i=0; i<m; i++)
    {
    	cin>>x>>y;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }

    bfs(1);
  
    for(int i=0; i<n; i++)
    {
    	cout<< i <<" : "<<cost[i]<<endl;
    }

    exit(0);

}

/*

5 5
0 2
0 1
0 3
1 3
3 4
*/