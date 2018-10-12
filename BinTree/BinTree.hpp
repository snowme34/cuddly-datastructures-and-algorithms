#ifndef BINTREE_HPP
#define BINTREE_HPP

#include "BinNode.hpp"

#include <iostream>
#include <algorithm>

template<typename T> class BinTree {
protected:
  int _size;
  BinNodePosi(T) _root;

public:

  BinTree() : root(0), isize(0) {} // default


  ~BinTree();

  bool insert(const T& item);


  bool find(const T& item) const;

  
  unsigned int size() const;

  int height() const;

  bool empty() const;

  BinTreeIterator<T> begin() const;

  BinTreeIterator<T> end() const;


private:

  BSTNode<T>* firstNode();

  static void deleteHelper(BSTNode<T>* n);

  int maxHeightOf(BSTNode<T>* n) const;

 };


template <typename T> BST<T>::~BST() {
  deleteHelper(root);
}


template <typename T> bool BST<T>::insert(const T& item) {

}


template <typename T> ? BST<T>::find(const T& item) const {
}

  
/** Return the number of items currently in the BST.
 */ 
template <typename T> unsigned int BST<T>::size() const {
  return _size;
}

template <typename T> int BST<T>::height() const {
  return (!root) ? -1 : (-1 + maxHeightOf(root));
}


template <typename T> bool BST<T>::empty() const {
  return (root) ? false : true;
}

template <typename T> BSTIterator<T> BST<T>::begin() const
{
  return BSTIterator<T>(first(root));
}

template <typename T> BSTIterator<T> BST<T>::end() const
{
  return BSTIterator<T>(nullptr);
}

template <typename T> BSTNode<T>* BST<T>::firstNode(BSTNode<T>* root)
{
  return (!root) ? nullptr : ((root->left) ? first(root->left) : root);
}

template <typename T> void BST<T>::deleteHelper(BSTNode<T>* n)
{
  if(!n) return;
  if(n->left) deleteAll(n->left);
  if(n->right) deleteAll(n->right);
  delete n;
}

template <typename T> int BST<T>::maxHeightOf(BSTNode<T>* n) const {
  return (std::max(
      (n->left) ? maxHeightOf(n->left) : 0,
      (n->right) ? maxHeightOf(n->right) : 0)
    + 1);
}


#endif // BINTREE_HPP
