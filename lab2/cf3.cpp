#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
      int sum_x=0;
      int sum_y=0;
      int sum_z=0;

    for(int i=0;i<n;i++)
    {
          sum_x+=arr[i][0];
          sum_y+=arr[i][1];
          sum_z+=arr[i][2];
          
    }
    
   if(sum_x==0 && sum_y==0 && sum_z==0)
   {
    cout<<"YES";
   }
   else
   {
    cout<<"NO";
   }
    return 0;
}