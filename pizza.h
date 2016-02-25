#pragma once
#ifndef PIZZA_H
#define PIZZA_H

enum shape_t {SQUARE, CIRCLE, HEXAGON};
enum rank_t {SMALL, MEDIUM, LARGE};

class Pizza
{
private:
rank_t whole, slice;
shape_t shape;
int numSlices;
double dimension;
double wholeArea;
double sliceArea;

public:
  Pizza();
  Pizza(shape_t pizzashape);
//setters
  void setSliceRank(rank_t rank);
  void setWholeRank(rank_t rank);

  //getters
  double getArea_Whole() const;
  double getArea_Slice() const;
  rank_t getSliceRank() const;
  rank_t getWholeRank() const;
  shape_t getShape() const;
};

#endif // PIZZA_H


inline double Pizza::getArea_Slice() const {
  return sliceArea;
}

inline double Pizza::getArea_Whole() const {
  return wholeArea;
}
inline shape_t Pizza::getShape() const{
  return shape;
}

inline rank_t Pizza::getSliceRank() const{
  return slice;
}

inline rank_t Pizza::getWholeRank() const{
  return whole;
}
