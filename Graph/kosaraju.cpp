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

std::vector<int> adj[100],rev[100];

int n,m;

void dfs1(int u,vector<bool>&visit, stack<int>&st)
{
	visit[u] = true;
	for(auto v: adj[u])
	{
		if(!visit[v])
			dfs1(v,visit,st);
	}
	st.push(u); // backtracking 
}

void reverse() // transpose graph
{
	for(int i=0; i<n; i++)
	{
		for(auto v: adj[i])
		{
			rev[v].push_back(i);
		}
	}
}


void dfs2(int u, vector<bool>&visit)
{
	cout<<u<<" ";
	visit[u] = true;
	for(auto it: rev[u])
	{
		if(!visit[it])
		{
			dfs2(it,visit);
		}
	}
}

void kosaraju()
{
	stack<int>st;
	vector<bool>visit1(7,false);

	for(int i=0; i<7; i++)
	{
		//cout<<i<<endl;
		if(visit1[i]==false)
		{
			
			dfs1(i,visit1,st);
		}
	}

	reverse();
	for(int i=0; i<n; i++)
	{
		visit1[i] =false;
	}

	while(!st.empty())
	{
		int cur = st.top();
		st.pop();
		//cout<<"cur "<<cur<<endl;
		if(visit1[cur]==false)
		{
			cout<<"component :";
			dfs2(cur,visit1); // new component
			cout<<endl;
		}
	}


}


int main()
{   
    FAsT  
    ll a, b, c, d, e, f, g, h, k, len, p, q, r, t, x, y, z;

    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
    	cin>>x>>y;
    	//cout<<x<<" "<<y<<endl;
    	adj[x].push_back(y);
    }

    kosaraju();

    exit(0);
}