/**
 * node class for binary trees
 * ref: dsa.cs.tsinghua.edu.cn/src_link/bintree/binnode.h.htm
 */

#ifndef BINNODE_HPP
#define BINNODE_HPP

// #define BinNodePosi(T) BinNode<T>*
#define stature(p) ((p) ? (p)->height : -1) // if null, has -1 height

#define isRoot(BinNodePosi(T) n) { return !(n->parent); }
 inline bool hasLChild(BinNodePosi(T) n) { return (n->lchild); }
 inline bool hasRChild(BinNodePosi(T) n) { return (n->rchild); }
 inline bool hasParent(BinNodePosi(T) n) { return !(isRoot(n)); }
 inline bool isLChild(BinNodePosi(T) n) { return hasParent(n) && (&x == x->parent->lchild); }
 inline bool isRChild(BinNodePosi(T) n) { return hasParent(n) && (&x == x->parent->rchild); }


template<typename T> struct BinNode {

  typedef enum { RB_RED, RB_BLACK } RBColor; // rb tree

  T const data;

  BinNodePosi(T) lchild;
  BinNodePosi(T) rchild;
  BinNodePosi(T) parent;

  int height = 0;
  RBColor color = RB_RED;

  BinNode() = default;

  BinNode(T const& d, 
          BinNodePosi(T) l = 0, 
          BinNodePosi(T) r = 0,
          BinNodePosi(T) p = 0)
      : lchild(l), rchild(r), parent(p), data(d) {}

  BinNodePosi(T) succ(); // return successor
 }; 

/**
 * return ptr to the direct successor of curent node
 */
template <typename T> BinNodePosi(T) BinNode<T>::succ() {
  BinNodePosi(T) s = this;
  if(rchild) {
    s = rchild;
    while(hasLChild(s)) s = s->lchild;
  } else { 
    while(isRChild(s)) s = s->parent;
    s = s->parent;
  }
  return s;
}

#endif // BINTREENODE_HPP
