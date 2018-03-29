#include <bits/stdc++.h>
#include "SegmentTree.hpp"
using namespace std;
using namespace example;
#define ford(i,s,e) for(int i=s;i<e;i++)
typedef int64_t ll;
const int mod = 1e9 + 7;
int64_t merger(int64_t a,int64_t b) // merger_op function defined as summation of nodes of interval in segment tree.
{
    return (a+b)%mod;
}
int64_t lnode_op(int64_t a) // for leaf node operation
{
    return a;
}
void delay(int nos)
{
    int ms = 1000*nos;
    clock_t s = clock();
    while(clock()<s+ms);
}
  
int main()
{
    //Displaying Problem statement
    {
        string s;
        ifstream fin("ProblemStatement.txt");
        while(getline(fin,s))
            cout << s << endl;
        cout << endl;
        cout << "-------------end------------ " << endl << endl;
        fin.close();

    }
    //Generating random input test cases
    cout << "Generating input file containing test cases for problem : " << endl;
    {
        ofstream fout("input.txt");
        int limidx = 100000;
        int limval = 100000;
        
            int n=(rand()%limidx) + 1;
            fout << n << endl;
            ford(i,0,n)
                fout << (rand()%limval) + 1 << endl;
            int q = 100000;
            fout << q << endl;
            ford(i,0,q)
            {
                int c= rand()%2;
                if(c==0)
                {
                    int l = 1+rand()%n;
                    int r = l+1 + rand()%(n-l);
                    fout << c << " " << l << " " << r << endl;
                }
                else
                {
                    int idx = 1+rand()%n;
                    int val = 1 +rand()%limval;
                    fout << c << " " << idx << " " << val << endl;
                }
            }
        cout << endl << "------------end------------" << endl << endl;
        fout.close();
    }
    //Segment tree solution of problem 
    cout << "Applying Segment Tree approach to input file " << endl << endl << "Storing output to SegmentTreeOuput.txt file: " << endl;
    {
        ifstream fin("input.txt");
        ofstream fout("SegmentTreeOutput.txt");
        clock_t s=clock();
        int n;fin >> n;
        int64_t a[n];
        ford(i,0,n)
            fin >> a[i];
        SegmentTree<int64_t> st(a,n,-1,merger,lnode_op);
        int q;
        fin >> q;
        int x,y,z;
        while(q--)
        {
            fin >> x >> y >> z;
        //    cout << x << " "  << y  << " " << z << " "<< endl;
            if(x==0)
                fout << "range ["<< y << "," << z <<"] : "  << st.query(y-1,z-1) << endl;
            else
                st.update(y-1,z);
        }
        cout << endl << endl  << "Time Taken: "  << (float)(clock()-s)/CLOCKS_PER_SEC << endl;
        cout << endl << "------------end------------" << endl << endl;
        fin.close();
        fout.close();
    }
    //Brute force solution of problem
    cout << "Applying Brute Force approach to input file " << endl << endl  << "Storing  BruteForceOutput.txt file : " << endl;
    {
        ifstream fin("input.txt");
        ofstream fout("BruteForceOutput.txt");
        clock_t s=clock();
        int n;
        fin >> n;
        int a[n];
        ford(i,0,n)
            fin >> a[i];
        int q;
        fin >> q;
        int x,y,z;
        while(q--)
        {
            fin >> x >> y >> z;
        //    cout << x << " "  << y  << " " << z << " "<< endl;
            if(x==0)
            {
                int64_t s=0;
                ford(i,y-1,z)
                {
                    s+=a[i];
                    s%=mod;
                }
                fout << "range ["<< y << "," << z <<"] : "  << s<< endl;
            }
            else
                a[y-1]=z;
        }
        cout <<  endl << endl << "Time Taken: "  << (float)(clock()-s)/CLOCKS_PER_SEC << endl;
        cout << endl << "------------end------------" << endl << endl;
        fin.close();
        fout.close();
    }
    char c;
    cout << "Do you want to generate patch file between two outputs (y/n):  ";
    cin >> c;
    if(c=='y')
        system("diff -u BruteForceOutput.txt SegmentTreeOutput.txt > diff.patch");
    string s;
    ifstream fin("diff.patch");
    if(fin.peek() == ifstream::traits_type::eof() )
        cout << endl  << "Patched file is completely empty" << endl;
    else
    {
        cout << endl << "Presenting patched file: " << endl;
        while(getline(fin,s))
            cout << s << endl;
    }
    cout << endl << "------------end------------" << endl;
    fin.close();
    cout << endl;
    cout << "Do you want to delete all input-output-patch files (y/n) : ";
    cin >> c;
    if(c=='y')
    {
        remove("BruteForceOutput.txt");
        remove("SegmentTreeOutput.txt");
        remove("diff.patch");
        remove("input.txt");
    }

    cout << "Task Completed !" << endl;
    return 0;
}
