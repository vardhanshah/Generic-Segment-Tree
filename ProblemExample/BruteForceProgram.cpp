/*

Problem Statement : 

We have an array array[1 . . . n], where n is number of elements in array. We should be able to

1 Find the sum s of elements from index l to r where 1 <= l <= r <= n
(if(s>=mod)s=s%mod, where mod is 1000000007)
Print s.

2 Change value of a specified element of the array to a new value x. We need to do arr[i] = x where 1 <= i <= n.

*/
#include<iostream>
#define ford(i,s,e) for(int i=s;i<e;i++)
using namespace std;

const int mod = 1e9 + 7;
int main()
{

    //freopen("Input.txt","r",stdin);
    //freopen("BruteForceProgramOutput.txt","w",stdout);
    int n;
    cin >> n;
    int a[n];
    ford(i,0,n)
        cin >> a[i];
    int q;
    cin >> q;
    int x,y,z;
    while(q--)
    {
        cin >> x >> y >> z;
    //    cout << x << " "  << y  << " " << z << " "<< endl;
        if(x==0)
        {
            int64_t s=0;
            ford(i,y-1,z)
            {
                s+=a[i];
                s%=mod;
            }
            cout << "range ["<< y << "," << z <<"] : "  << s<< endl;
        }
        else
            a[y-1]=z;
    }
    cout << "Time Taken: "  << (float)clock()/CLOCKS_PER_SEC << endl;
    return 0;
}
