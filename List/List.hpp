// still in progress

/**
 * header for List
 * ref: dsa.cs.tsinghua.edu.cn/src_link/list/list.h.htm
 */

#ifndef LIST_HPP
#define LIST_HPP

#include "ListNode.hpp"

template <typename T> class List {

protected:
  // copy one node
  friend void copyNodes ( ListNodePosi(T), int);
  friend void merge ( ListNodePosi(T)&, int, List<T>&, ListNodePosi(T), int );
  friend void sort ( ListNodePosi(T)&, int);

  private:
    int _size;            // num of elements
    ListNodePosi(T) head; // head node
    ListNodePosi(T) tail; // tail node

  protected:
    typedef int Rank; // rank of node
    void init();      // initialization for list

   public:
    List() { init(); }                      // default
    List(List<T> const& l);                 // copy constructor

    ~List(); // destructor

    Rank size() const { return _size; }     // return the size
    bool empty() const {return _size <= 0;} // tell if empty

    T& operator[](Rank r) const;                          // go to nth node
    ListNodePosi(T) first() const { return head->succ; }  // first element
    ListNodePosi(T) last() const { return tail->prev; }   // last element

    bool isValidPosi(ListNodePosi(T) t) const { // tell if the position is valid
      return p && (p != head) && (p != tail);
    }
};

#endif // LIST_HPP