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
bool bfs(int rgraph[100][100],int s, int t, int par[])
{
	queue<int>q;
	q.push(s);
	int visit[100];
	memset(visit,0,sizeof(visit));
	visit[s] = true;
	par[s] = -1;

	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		for(int i=0; i<n; i++)
		{
			if(visit[i]==false and rgraph[u][i]>0)
			{
				visit[i] = true;
				par[i] = u;
				if(i==t)
				{
					return true;
				}
				q.push(i);

			}
		}
	}

	return false;

}


void fulkerson(int graph[100][100], int s, int t)
{
	
	int rgraph[100][100];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			rgraph[i][j] = graph[i][j];
		}
	}

	int par[n+1];
	int max_flow= 0;
	vector<vector<int>> path;
	
	while(bfs(rgraph,s,t,par))
	{
		vector<int>subPath;
		int path_flow = INT_MAX;
		for(int v = t; v!=s; v = par[v])
		{

			int u = par[v];
			subPath.push_back(v);
			path_flow = min(path_flow, rgraph[u][v]);
		}

		for(int v = t; v!=s; v = par[v])
		{
			int u = par[v];
			rgraph[u][v]-=path_flow;
			rgraph[v][u]+=path_flow;
		}

		max_flow+=path_flow;
		path.push_back(subPath);
		subPath.clear();

	}

	for(auto it: path)
	{
		
		vector<int>res;
		res = it;

		reverse(res.begin(),res.end());

		for(auto ans: res)
		{
			cout<<ans<<",";
		}
		cout<<endl;
		
	}
	cout<<"Maximum flow is "<<max_flow<<endl;
}


int main()
{   
    FAsT  
   
    
    cin>>n>>m;
    
    int graph[100][100];
    for(int i=0; i<m; i++)
    {
    	int x,y,z;
		cin>>x>>y>>z;
    	x--;
    	y--;
    	// cout<<x<<" "<<y<<" "<<z<<endl;
     graph[x][y] = z;
    }
    
    int s, t;
    cin>>s>>t;
    s--;
    t--;
    
    fulkerson(graph, s,t);    

    exit(0);
}