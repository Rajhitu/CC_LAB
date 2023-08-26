#include<bits/stdc++.h>
using namespace std;
bool is_prime(int n)
{

   for (int i = 2; i < n; i++)
   {
            if(n%i==0)
            {
                return false;
            } 

   } 

  return true; 
   


}
int main()
{

    int n;
    cin>>n;

    int j=2;
    int ans;
    for (int i = 1; i <= n; )
    {
        if(is_prime(j))

        { 
             cout<<j<<" ";
            ans=j;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    cout<<"\n"<<ans<<"is ur ans";
    return 0;
}