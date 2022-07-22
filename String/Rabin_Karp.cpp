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

#define d 26

void Robin_karp(string text, string pettern, int q)
{
    int m = pettern.size();
    int n = text.size();
    int p = 0;
    int t = 0; 
    int h=1;
    int j;
    for(int i=0; i<m-1; i++)
    {
        h = (h*d)%q;
    }

    for(int i=0; i<m; i++)
    {
        p = (d*p + pettern[i])%q;
        t = (d*t + text[i])%q;
    }

   for(int i=0; i<n-m; i++)
   {
        if(p==t)
        {
            for( j=0; j<m; j++)
            {
                if(text[i+j]!=pettern[j])
                {
                    break;
                }
            }

            if(j==m)
            {
                cout<<"pettern found at position "<<i<<endl;
            }
        }

        if(i<n-m)
        {
            t = (d*(t-text[i]*h)+text[i+m])%q;

            if(t<0)
            {
                t+=q;
            }
        }

   }


}

int main()
{   
    FAsT  
    
    string text, pettern;
    getline(cin,text);
    getline(cin,pettern);
    int q = 101;
    Robin_karp(text,pettern, q);
    exit(0);
}