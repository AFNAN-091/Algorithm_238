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
#define sz 50000
typedef long long ll;
int rr[] = { -1, 1, 0, 0, -1, -1, 1, 1};
int cc[] = {0, 0, -1, 1, -1, 1, -1, 1};
/*--------------------------------------------------------------------*/

void bfs(vector<vector<int>>&adj, vector<bool>&visited, vector<int>&dis,int n,vector<int>&v,int cnt)
{
    while(cnt<=n)
    {
        int node;
        if(cnt<=v.size())
        {
             node = v[cnt-1];

             cout<<node<<" ";
        }
        else{
            return;
        }
        

        for(int i=0; i<adj[node].size(); i++)
        {
            int u = adj[node][i];
            if(dis[u]<dis[node]+1 and !visited[u])
            {
                v.push_back(u);
                visited[u] = true;
                dis[u] = dis[node] +1;
            }
        }

        cnt++;
    }
}

void bfstraverse(vector<vector<int>>&adj, int n, int source)
{
    vector<bool>visited(n+1,false);
    vector<int>distance(n+1,0),v;
    v.push_back(source);
    distance[source] = 0;
    visited[source] = true;

    bfs(adj, visited, distance, n, v,1);
}


int main()
{   
    FAsT  
    ll a, b, c, d, e, f, g, h, k, len, n, m, p, q, r, t, x, y, z;

    cin>>n>>m;
    vector<vector<int>>adj(n);

    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
    }

    bfstraverse(adj,n,0);


    exit(0);
}