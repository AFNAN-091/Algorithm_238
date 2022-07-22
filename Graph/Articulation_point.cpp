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

std::vector<int> adj[5000];
int m,n;

void dfs(int u, vector<int>&dis,vector<int>&low, vector<int>&par,vector<bool>&AP)
{
    static int time = 0;
    dis[u] = low[u] = time;
    time++;
    int child = 0;
    
    for(auto v: adj[u])
    {
        
        if(dis[v]==-1)
        {
            child++;
            par[v] = u;
            dfs(v,dis,low,par,AP);
            low[u] = min(low[v],low[u]); // backtracking 
            
            if(par[u] == -1 and child>1)
            {
                       
                AP[u] = true;   //  CAse 1 - U root node 
            }

            if(par[u] != -1 and low[v]>= dis[u])          
            {      
                AP[u] = true; // case 2 atleast 1 component

                /*  কোনো একটা এজ u -v এর জন্য d[u]>low[v] 
               হবার অর্থ কি? d[u] এর থেকে ডিসকভারি টাইম ছোটো একমাত্র ancestor(u)
               সেটের নোডগুলোর। subtree(v) এর কোনো নোড ব্যাকএজ দিয়ে ancestor(u) এর সাথে যুক্ত, 
                 সেজন্য low[v] এর মান d[u] এর থেকে কমে গিয়েছে। যদি d[u]<=low[v]
              হয়, তাহলেই শুধুমাত্র u একটা আর্টিকুলেশন পয়েন্ট হবে। */

            }

        }

        else if(v != par[u]){ 
            low[u] = min(low[u],dis[v]); // back- edge u to v
        }
    }
}


void findAp()
{
	vector<int> dis(n,-1),low(n,-1),par(n,-1);
    vector<bool>AP(n,false);

    
    for(int i=0; i<n; i++)
    {
        if(dis[i]==-1)
        {
            dfs(i,dis,low,par,AP);
        }
    }

    //cout<<"Articulation point : "; 
    
    for (int i=0 ; i<n; i++)
    {
        if(AP[i] == 1)
        {
            cout<<i<<endl;
        }
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

    findAp();

    exit(0);
}

/*

6 6 
0 1
0 2
0 3
3 4
3 5
1 2

*/