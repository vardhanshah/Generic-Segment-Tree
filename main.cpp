#include<iostream>
#include "SegmentTree.hpp"

using namespace example;
using namespace std;

int merger(int a,int b) // merger_op function defined as summation of nodes of interval in segment tree.
{
    return a+b;
}
int lnode_op(int a) // for leaf node operation
{
    return a;
}


int main()
{
    int32_t t;
    int input_array[]={5,3,2,1,6};
    
    cout << "Input array is: ";
    for(int i=0;i<5;i++)
        cout << input_array[i] << " ";
    cout << endl;

    SegmentTree<int> s(input_array,5,-1,merger,lnode_op);
    //Segment Tree of int type is defined
    //Arguments : array = input_array , n = 5 , nop = -1 , merger = merger , lnode_op = lnode_op
    //array is main input array on which segment tree has been defined
    //here n stands for size of array
    //nop stands for not possible value, this value is different for
        //different type of chosen SegmentTree type
    //merger stands for "segment tree node merging function"
    //lnode_op stands for "leaf node value operation"
    
    // "SegmentTree" consturctor will initialize and build segment tree and store necessary information.
    cout << "-----------------------------------------" << endl;  
    cout << "Find the summation for range (0,4) in input array : ";
    cout << s.query(0,4) << endl;
    //query function
    //Arguments : rs = 0 , re = 4 .
    //rs stands for start of range
    //re stands for end of range
    
    // "query" function will give the answer as per merger(in our case: comp) is defined
    
    cout << "-----------------------------------------" << endl;  
    cout << "Update the value 1000 for index no. - 3" << endl;
    s.update(3,1000) ;
    //update function
    //Arguments : idx = 3 , val = 10000
    //idx stands for index of main array, and it will be updated
    //update value of index
    
    // "update" function :  update the value of given index in main input array(in our case input_array)
        //and in segment tree also.
    cout << "-----------------------------------------" << endl;  
    cout << "Find the summation for range (0,4) for input array : ";
    cout << s.query(0,4) << endl;
    
    return 0;
}

