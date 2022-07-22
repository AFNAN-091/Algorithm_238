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

struct List{
	int value;
	int weight;

	List (int value , int weight)
	{
		this->value = value;
		this->weight = weight;
	}

};


bool cmp(struct List a, struct List b)
{
	double r1 = (double)a.value/(double)a.weight;
	double r2 = (double)b.value/(double)b.weight;

	return r1 > r2;
}


int fractional(struct List arr[], int n, int w)
{
	sort(arr, arr+n, cmp);

	double ans = 0;

	for(int i=0; i<n; i++)
	{
		if(arr[i].weight <= w)
		{
			w-=arr[i].weight;
			ans+=arr[i].value;
		}

		else{
			ans+=arr[i].value*((double)w/(double)arr[i].weight);
			break;
		}
	}
	return ans;
}


int main()
{   
    FAsT  
    int w = 50;
    List arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };

    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<fractional(arr, n, w)<<endl;

    exit(0);
}

// complexity (n log n)
