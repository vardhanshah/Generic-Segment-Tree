# Generic-Segment-Tree
Generic Segment Tree frame work: <br>

SegmentTree class constructor definition:

SegmentTree<T> (T *array, int size_of_array , T nop , T(*merger)(T,T) , T(*lnode_op)(T) )
  
- array is main input array on which segment tree has been defined          
- here n stands for size of array                                           
- nop stands for not possible value, this value is different for different T.                             
- merger stands for "segment tree node merging function"                    
- lnode_op stands for "leaf node value operation"

Query operation:

T SegmentTree<T>::query(int start_of_range, int end_of_range)
  
As the argument's name suggest, we give a starting and ending range to query function, It will conclude the appropriate 
output value T for that range.

Update operation:

void SegmentTree<T>::update(int index,int update_value)

We want to update value for particular index in input array, so we take index as input and new value. This function will update the value at index in input array and also in segment tree.


Example is given in main.cpp file.

  
