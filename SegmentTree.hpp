//Author : Vardhan Shah
//topic : implementation of generic segment tree and its operations
//more about segment tree : "https://en.wikipedia.org/wiki/Segment_tree"
//use it in whatever manner.
//Any suggestion for code improvement will be helpful


#ifndef _SEGMENT_TREE_H
#define _SEGMENT_TREE_H
#include <math.h>
namespace example{
    
    //--------------------CLASS STARTS HERE--------------------
    
    
    template <class T> class SegmentTree
    {
        private:
            T nop;// not possible value for given T
            
            int32_t n;//given input array size

            T *array;// pointer to given array
            
            int32_t sz;//size of segment tree
        
            T *st; //segment tree 
            
            T (*merger)(T,T);
            
            T (*lnode_op)(T);

            void initialize( int , int , int , T * );

            T queryOP( int , int , int , int , int );
       
            void update_val( int , int , int , int );
        public :
            
            SegmentTree( T * , int , T , T (*)(T,T) , T(*)(T) );
            //Arguments : Array, size of array, nop value, function for merging.
            T query( int , int );
            //Arguments : start of range, end of range.
            void update(int idx,T val);
            //Arguments : index, value that has to be updated 
    };
   
    
    //--------------------CLASS ENDS HERE----------------------
    
    template<class T> SegmentTree<T>::SegmentTree(T *array,int n,T nop,T (*merger)(T,T), T(*lnode_op)(T))
    {
        this->n = n;
        this->array = array;
        sz = (1 << (int(ceil(log2(n)))))*2;
        st = new T[sz];
        this->merger=merger;
        this->lnode_op = lnode_op;
        this->nop = nop;
        initialize(0,n-1,1,array);
    }
    
    
    template<class T> void SegmentTree<T>::initialize(int l,int h,int pos,T *a)
    {
        if(l==h)
            st[pos]=lnode_op(a[l]);
        else
        {
            initialize(l,(l+h)/2,2*pos,a);
            initialize((l+h)/2 + 1,h,2*pos+1,a);
            st[pos]=merger(st[2*pos],st[2*pos+1]);
        }
    }
    
    
    template<class T> T SegmentTree<T>::query(int rs,int re)
    {
        return queryOP(0,n-1,1,rs,re);
    }
    
    
    template<class T> T SegmentTree<T>::queryOP(int l,int h,int pos,int rs,int re)
    {
        if(h<rs||l>re)
            return nop; // use of nop value
        if(l>=rs&&h<=re)
            return st[pos];
        
        T p1 = queryOP(l,(l+h)/2,2*pos,rs,re);
        T p2 = queryOP((l+h)/2+1,h,2*pos+1,rs,re);
        if(p1==nop)
            return p2;
        if(p2==nop)
            return p1;
        return merger(p1,p2);
    }
    template<class T> void SegmentTree<T>::update(int idx,T val)
    {
        array[idx]=val;
        update_val(0,n-1,1,idx);    
    }
    template<class T> void SegmentTree<T>::update_val(int l,int h,int pos,int idx)
    {
        if(h<idx||l>idx)
            return;
        if(l!=h)
        {
            update_val(l,(l+h)/2,2*pos,idx);
            update_val((l+h)/2+1,h,2*pos + 1,idx);
            st[pos]=merger(st[2*pos],st[2*pos+1]);
        }
        else
            st[pos]=lnode_op(array[idx]);
    }

}
    
#endif
