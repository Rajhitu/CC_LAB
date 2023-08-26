#include<bits/stdc++.h>
using namespace std;
int main()
{
      int n;
    cin>>n;
    vector<string> str(n+1);
    vector<string> ans(n+1);

    for (int i = 0; i < n; i++)
    {
        cin>>str[i];
    }
     for (int i = 0; i <= n; i++)
    {
        if(str[i].size()>10)
        { 
            string temp="";
            temp.push_back(str[i].front());
            string x= to_string((str[i].size()-2));
            temp.append(x);
            temp.push_back(str[i].back());
            // cout<<temp<<"\n";
            ans.push_back(temp);

        }
        else
        {     
             ans.push_back(str[i]);
        }
    }

   for (int i = 0; i < ans.size(); i++)
   {
    cout<<ans[i]<<"\n";
   }
   

// string x="adasf";
// cout<<to_string(x.size());
    
    return 0;
}