#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
 
    while(t--)
    {
        int n,m;
        cin>>n>>m;
 
        char c[n][m];
 
        for(int i=0;i<n;i++)
            cin>>c[i];
 
        int c1=0,c2=0;
 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i+j)%2)
                {
                    (c[i][j]=='R')?c1+=5:c2+=3;
                }
                else
                    (c[i][j]=='R')?c2+=5:c1+=3;
            }
        }
 
        (c1<c2)?cout<<c1<<endl:cout<<c2<<endl;
    }
}
  
