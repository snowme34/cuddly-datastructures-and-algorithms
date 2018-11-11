#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <vector>
#include <tuple>
#include <algorithm>

#include <iostream> // should not include this

typedef long long llong;

enum UpdateType { addition, subtraction };
enum QueryType { qmax, qmin, qsum };

class SegmentTree {
  private:
    // size of data
    llong _size;

    // the data given
    std::vector<llong> _data;

    // leftIndex, rightIndex, value
    // 1-index heap
    std::vector<std::tuple<llong, llong, llong> > _storage_min; 
    std::vector<std::tuple<llong, llong, llong> > _storage_max; 
    std::vector<std::tuple<llong, llong, llong> > _storage_sum; 

  public:
    SegmentTree(llong size): _size(size) {
      _data = std::vector<llong>(size);
      _storage_min = std::vector<std::tuple<llong, llong, llong> >(4*_size+1);
      _storage_max = std::vector<std::tuple<llong, llong, llong> >(4*_size+1);
      _storage_sum = std::vector<std::tuple<llong, llong, llong> >(4*_size+1);
      build();
    }

    SegmentTree(std::vector<llong> data): _size(data.size()){
      _data.insert(data.cbegin(),data.cend());
      _storage_min = std::vector<std::tuple<llong, llong, llong> >(4*_size+1);
      _storage_max = std::vector<std::tuple<llong, llong, llong> >(4*_size+1);
      _storage_sum = std::vector<std::tuple<llong, llong, llong> >(4*_size+1);
      build();
    }

    llong size() const {return _size;}

    llong max(llong l, llong r) const;
    llong min(llong l, llong r) const;
    llong sum(llong l, llong r) const;
    llong update(llong l, llong r, llong value, UpdateType utype);
  private:
    void updateNode(llong node, UpdateType utype);
    void build();
    llong lc(llong idx) const {return 2*idx;}
    llong rc(llong idx) const {return 2*idx+1;}
    llong query(llong l, llong r, QueryType qtype, llong n = 1);
};

void SegmentTree::updateNode(llong n, QueryType qtype){
   switch(qtype) {
    case qmax:
      std::get<2>(_storage_max[n]) = std::max(std::get<2>(_storage_max[lc(n)]), 
                                              std::get<2>(_storage_max[rc(n)]));
      break;
    case qmin:
      std::get<2>(_storage_max[n]) = std::min(std::get<2>(_storage_max[lc(n)]), 
                                              std::get<2>(_storage_max[rc(n)]));
      break;
    case qsum:
      std::get<2>(_storage_max[n]) = (std::get<2>(_storage_max[lc(n)]) +
                                      std::get<2>(_storage_max[rc(n)]));
      break;
    default:
      std::cerr << "should not be happenning: " << __func__ << std::endl;
      return;
      break;
  }
}

// only used in building
void SegmentTree::insertNode(llong n, llong l, llong r){
  _storage_min.insert(n,std::make_tuple(l,r,0));
  _storage_max.insert(n,std::make_tuple(l,r,0));
  _storage_sum.insert(n,std::make_tuple(l,r,0));
}

// node: [l,r],value
void SegmentTree::build(){

  // insert all nodes
  // build leaves
  // call updateNode from leaves up to the root

}

/*
 * Query based on query type, assume all parameters are valid
 * n is 1 by default
 */
llong SegmentTree::query(llong l, llong r, QueryType qtype, llong n){

  std::tuple<llong, llong, llong>* node;

  // get node
  // nodes should be identical except for values
  switch(qtype) {
    case qmax:
      node = &_storage_max[n];
      break;
    case qmin:
      node = &_storage_min[n];
      break;
    case qsum:
      node = &_storage_sum[n];
      break;
    default:
      std::cerr << "should not be happenning: " << __func__ << std::endl;
      return -1;
      break;
  }

  llong mid = l + (r-l)/2;
  llong node_left = std::get<0>(*node);
  llong node_right = std::get<1>(*node);

  // overlapping index?

  // potential bug
  // should use < or <=?
  if(l == node_left && r == node_right) {
    return std::get<2>(*node);
  } else if(node_left <= l && r <= mid){
    return query(l,r,qtype,lc(n));
  } else if(mid <= l && r <= node_right) {
    return query(l,r,qtype,rc(n));
  }

  // l and r covers a range that crosses mid

  llong result = 0;

  switch (qtype) {
    case qmax:
      result = std::max(query(l,mid,qtype,lc(n)), query(mid+1,r,qtype,rc(n)));
      break;
    case qmin:
      result = std::min(query(l,mid,qtype,lc(n)), query(mid+1,r,qtype,rc(n)));
      break;
    case qsum:
      result = (query(l,mid,qtype,lc(n)) + query(mid+1,r,qtype,rc(n)));
      break;
    default:
      std::cerr << "should not be happenning: " << __func__ << std::endl;
      break;
  }

  return result;
}

/*
 * Return the max value of query range
 * storage is 1-index heap
 * l: left index of query
 * r: right index of query
 * n: current node, should start with 1
 * range: [l,r), right exclusive
 */
llong SegmentTree::max(llong l, llong r) {
  if(l > r || r >= _size) { // error
    return -1; 
  }

  if(l == r) { // single element query
    return _data[l];
  }

  return query(l,r,qmax);
}

#endif