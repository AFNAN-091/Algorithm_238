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

void dfs(int u, vector<int>&dis,vector<int>&low,stack<int>&st,vector<bool>&presentInStack)
{
    static int time =0; 
    dis[u] = low[u] = time;
    time++; 
    st.push(u);
    presentInStack[u] = true;
    for(auto v: adj[u])
    {
        if(dis[v]==-1)
        {
            dfs(v,dis,low,st,presentInStack);
            low[u] = min(low[u],low[v]);
            
        }
        else if(presentInStack[v])
        {
            low[u] = min(low[u],dis[v]);
        }

    }


    if(dis[u]==low[u])
    {
        cout<<"component : ";
        while(st.top()!=u)
        {
            cout<<st.top()<<" ";
            
            presentInStack[st.top()] = false;
            st.pop();
        }
        cout<<st.top()<<endl;
        presentInStack[st.top()] = false;
        st.pop();
    }

}

void tarjan()
{
    vector<int>dis(n,-1),low(n,-1);
    stack<int>st;
    vector<bool>presentInStack(n,false);
   // cout<<dis[5]<<endl;
    for(int i=0; i<n; i++)
    {
        //cout<<i<<endl;
        if(dis[i]== -1)
        {
            
            dfs(i,dis,low,st,presentInStack);
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
    	adj[x].push_back(y);
    }


    tarjan();

    exit(0);
}

/*

6 10
0 1
1 2
1 3
3 4
4 0
4 5
5 6
6 5
4 6
5 2


*/