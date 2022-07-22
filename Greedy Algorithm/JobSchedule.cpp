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


 struct job{
 	char id;
 	int deadline;
  int profit;

 };

bool cmp(job a, job b)
{
	return (a.profit > b.profit);
}


 void jobSchedule(job arr[], int n)
 {
 	sort(arr, arr+n , cmp);

 	int result[n];
 	bool slot[n];
 	for(int i=0; i< n ; i++)
 	{
 		slot[i] = false;
 	} 	

  

 	for(int i=0; i<n; i++)
 	{
 		for(int j=arr[i].deadline-1; j>=0; j--)
 		{
 			if(slot[j]==false)
 			{
 				result[j] = i;
 				slot[j] = true;
 				break; 
 			}
 		}
 	}

  int ans = 0;
  
 	for(int i=0; i<n; i++)
 	{
 		if(slot[i])
 		{
 			cout<<arr[result[i]].id<<" ";
      ans+=arr[result[i]].profit;

 		}
 	}

  cout<<endl;
  cout<<"Maximum profit is "<<ans<<endl;

 }


int main()
{   
    FAsT  
   

    job arr[] = { { 'a', 2, 100 },
                  { 'b', 1, 19 },
                  { 'c', 2, 27 },
                  { 'd', 1, 25 },
                  { 'e', 3, 15 } };

     int n = sizeof(arr)/sizeof(arr[0]);


     jobSchedule(arr, n );

    exit(0);
}