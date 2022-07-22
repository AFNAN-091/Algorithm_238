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

void AFnaN()
{
	
}

int main()
{   
    FAsT  
    ll a, b, c, d, e, f, g, h, k, len, n, m, p, q, r, t, x, y, z;

    cin>>n;
    vector<int> arr(n);
    vector<int>lis(n,1);
    for(int i=0; i<n; i++)
    {
    	cin>>arr[i];
    }

    int i;
    i = 0;
    int mx = 1;
  
    while(i<n)
    {
       
        for(int j=0; j<i; j++)
        {
            if(arr[i]>arr[j] and lis[i]<=lis[j])
            {
                lis[i] = lis[j] + 1;
                if(mx<lis[i])
                {
                    mx = lis[i];
                }
            }
        }
        i++;
    }

    cout<<mx<<endl;

    exit(0);
}