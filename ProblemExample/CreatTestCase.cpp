#include <bits/stdc++.h>
using namespace std;
#define ford(i,s,e) for(int i=s;i<e;i++)
#define tr(container,it) for(typeof(container.begin()) it = container.begin();it!=container.end();it++)
#define sz(a) int(a.size())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define rall(c) c.rbegin(),c.rend()
#define vpresent(c,elt) (find(all(c),elt)!=c.end())
#define present(c,elt) (c.find(elt) != c.end())
#define optimize ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(i) cout << "here at position " <<  i;
#define traceone(x) cout << x << endl;
#define tracetwo(x,y) cout << x << " " << y << endl;
#define tracethree(x,y,z) cout << x << " " << y << " " << z << endl;
#define tracefour(x,y,z,w) cout << x << " " << y << " " << z << " " << w << endl;
#define unmaptr(c) for(unordered_map<int,int>::iterator it=c.begin();it!=c.end();it++)
#define limit 100000
typedef int64_t ll;
int main()
{
    int limidx = 100000;
    int limval = 100000;
    freopen("/home/vardhan/Desktop/C++GenericSegmentTreeLibrary/input.txt","w",stdout);
    
        int n=(rand()%limidx) + 1;
        cout << n << endl;
        ford(i,0,n)
            cout << (rand()%limval) + 1 << endl;
        int q = 100000;
        cout << q << endl;
        ford(i,0,q)
        {
            int c= rand()%2;
            if(c==0)
            {
                int l = 1+rand()%n;
                int r = l+1 + rand()%(n-l);
                cout << c << " " << l << " " << r << endl;
            }
            else
            {
                int idx = 1+rand()%n;
                int val = 1 +rand()%limval;
                cout << c << " " << idx << " " << val << endl;
            }
        }
}
