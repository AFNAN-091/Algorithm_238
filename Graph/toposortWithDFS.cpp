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

vector<int>adj[sz];

void dfs(vector<int>&res, vector<bool>&visited, int n)
{
    visited[n] = true;

    for(int i=0; i< adj[n].size(); i++)
    {
        if(!visited[adj[n][i]]) dfs(res,visited,adj[n][i]);
    }

    res.push_back(n);
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
       
    }

    vector<bool>visited(n,false);
    vector<int>res;
    for(int i=0; i<n; i++)
    {
        if(!visited[i]) dfs(res,visited,i);
    }

    reverse(res.begin(),res.end());
    for(auto it: res)
    {
        cout<<it<<" ";
    }
    cout<<endl;

    exit(0);
}