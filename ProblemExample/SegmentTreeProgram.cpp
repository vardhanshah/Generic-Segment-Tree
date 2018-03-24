/*

Problem Statement : 

We have an array array[1 . . . n], where n is number of elements in array. We should be able to

1 Find the sum s of elements from index l to r where 1 <= l <= r <= n
(if(s>=mod)s=s%mod, where mod is 1000000007)
Print s.

2 Change value of a specified element of the array to a new value x. We need to do arr[i] = x where 1 <= i <= n.


*/

#include<iostream>
#include "/path/to/SegmentTree.hpp"
#define ford(i,s,e) for(int i=s;i<e;i++)
using namespace example;
using namespace std;
const int mod = 1e9 + 7;
int64_t merger(int64_t a,int64_t b) // merger_op function defined as summation of nodes of interval in segment tree.
{
    return (a+b)%mod;
}
int64_t lnode_op(int64_t a) // for leaf node operation
{
    return a;
}


int main()
{
    //freopen("Input.txt","r",stdin);
    //freopen("SegmentTreeProgramOutput.txt","w",stdout);
    int n;cin >> n;
    int64_t a[n];
    ford(i,0,n)
        cin >> a[i];
    SegmentTree<int64_t> st(a,n,-1,merger,lnode_op);
    int q;
    cin >> q;
    int x,y,z;
    while(q--)
    {
        cin >> x >> y >> z;
    //    cout << x << " "  << y  << " " << z << " "<< endl;
        if(x==0)
            cout << "range ["<< y << "," << z <<"] : "  << st.query(y-1,z-1) << endl;
        else
            st.update(y-1,z);
    }
    cout << "Time Taken: "  << (float)clock()/CLOCKS_PER_SEC << endl;
    return 0;
}


