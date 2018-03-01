#include<iostream>
#include<string>
#include<vector>
#define SIZE 4
#define swap(typ,A,B) { typ temp;temp=B; B=A;A=temp;}
using namespace std;

vector <int> set;
string flags;
int mint, mpos;

void print( vector <int> v)
{
    for(int i = 0 ; i < v.size(); i++ )
 {
        cout << v[i] << " ";
}
    cout << endl;
}


void updateFlags()
{
    for(int i=0;i<flags.length();i++)
        if(set[i]>mint)
      {
            if(flags[i]=='L')
           flags[i]='R';

            else

               flags[i]='L';

      }
}
void swapSets()
{
    if(flags[mpos] == 'L' )
     {
        swap(int, set[mpos], set[mpos-1]);
        swap(char, flags[mpos], flags[mpos-1]);
    }
    else
    {
        swap(int, set[mpos], set[mpos+1]);
        swap(char, flags[mpos], flags[mpos+1]);
    }
    updateFlags();
}




void findmobileswap()

{
    mint = 0;
    for(int i=0;i<SIZE;i++)
      {
                if( (flags[i]=='L' && i==0) || (flags[i]=='R' && i == SIZE-1))
                    continue;
                if( flags[i] == 'L')
                {
                    if( set[i] > set[i-1] && set[i] > mint )
                    {
                        mint = set[i];
                        mpos = i;
                    }
                }
                else
               {
                    if( set[i] > set[i+1] && set[i] > mint )
                    {
                        mint = set[i];
                        mpos = i;
                    }
                }
    }
    swapSets();
}





int fact(int n)

{
    int x=1;
    for(int i=1; i <= n; i++)
        x *= i;
    return x;
}





int main()
{
            for(int i=1;i<=SIZE;i++)
           {
                        set.push_back(i);
                        flags.push_back('L');
            }

            int t = fact(SIZE);
 cout<<"TOtal = "<< t <<endl;
            for(int i = 0;i< t; i++)
           {
                print(set);
                findmobileswap();
            }
            return 0;
}
