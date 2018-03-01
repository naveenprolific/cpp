#include<iostream>

using namespace std;
void permi(int n, int p[], int pi[], int dir[]) ;
void perm(int n) 
{
        int p[n];    
        int pi[n];    
        int dir[n];    
        for (int i = 0; i < n; i++) 
		{
            dir[i] = -1;
            p[i]  = i;
            pi[i] = i;
        }
        permi(0, p, pi, dir);
        cout<<"   (0 1)\n"<<endl;
}
void permi(int n, int p[], int pi[], int dir[]) 
{ 

       int x = p[n]/p[0];
        if (n >= x) 
		{
            for (int i = 0; i < x; i++)
                cout<<p[i]<<endl;
            return;
        }

        permi(n+1, p, pi, dir);
        for (int i = 0; i <= n-1; i++)
		 {

           
            cout<< pi[n]<< pi[n] + dir[n]<<endl;
            int z = p[pi[n] + dir[n]];
            p[pi[n]] = z;
            p[pi[n] + dir[n]] = n;
            pi[z] = pi[n];
            pi[n] = pi[n] + dir[n];  

            permi(n+1, p, pi, dir); 
        }
        dir[n] = -dir[n];
}

int  main() 
{
        int n ;
        perm(n);
        return 0;
 }


