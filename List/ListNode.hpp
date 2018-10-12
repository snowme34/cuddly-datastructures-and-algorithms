/**
 * header for ListNode
 * ref: dsa.cs.tsinghua.edu.cn/src_link/list/listnode.h.htm
 */

#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP

// #define ListNodePosi(T) ListNode<T>*

// double linked
template <typename T> struct ListNode {

  const T data;             // data
  ListNodePosi(T) prev = 0; // previous node
  ListNodePosi(T) succ = 0; // successor node

  ListNode() = default;     // default constructor

  ListNode(T e, ListNodePosi(T) p = 0, ListNodePosi(T) s = 0)
      : data(e), prev(p), succ(s) {}  // constructor

  ListNodePosi(T) insertBefore(T const& e);    // insert a node before cur node
  ListNodePosi(T) insertAfter(T const& e);     // insert a node after cur node
};

/**
 * insert a node with given data before the current node
 * assume prev node exists
 */
template <typename T>
ListNodePosi(T) ListNode<T>::insertBefore(T const& e) {
  ListNodePost(T) n = new ListNode(e, prev, this);  // create a new node
  prev->succ = n; prev = n;  // set relationship
  return n;                  // return ptr to new node
}

/**
 * insert a node with given data after the current node
 * assume succ node exists
 */
template <typename T>
ListNodePosi(T) ListNode<T>::insertAfter(T const& e) {
  ListNodePost(T) n = new ListNode(e, this, succ);  // create a new node
  succ->prev = n; succ = n;  // set relationship
  return n;                  // return ptr to new node
}

#endif // LIST_NODE_HPP