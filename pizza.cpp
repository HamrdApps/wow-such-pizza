#include <iostream>
#include "pizza.h"
#include "math.h"

using namespace std;

Pizza::Pizza(shape_t pizzashape){//constructor
//set up strings in an array, arranged in the same order as the elements of shape_t
  const char* shapeStrings[] = {
    "square",
    "circular",
    "hexagonal"
  };
  const char* MeasureStrings[] = {
    "one side",       //SQUARE
    "the diameter",   //CIRCLE
    "the base"        //HEXAGON
  };
  const int SlicesByShape[] = {
    9,  //SQUARE
    8,  //CIRCLE
    6   //HEXAGON
  };

//begin defining private variables
  shape = pizzashape;
  numSlices = SlicesByShape[pizzashape];

//prompt for the dimension, as required
  cout << "Enter the length of "<< MeasureStrings[pizzashape] <<  " of the "<< shapeStrings[pizzashape]<< " pizza (in inches)." << endl;
  cin >> dimension;

  switch(pizzashape) {
    case shape_t::SQUARE:
      wholeArea = pow(dimension,2);
      sliceArea = wholeArea/numSlices;
    break;

    case shape_t::CIRCLE:
      //approximation of area of circle = radius * radius * pi
      //we will use M_Pi from math.h to represent pi
      wholeArea = M_PI*pow(dimension/2,2);
      sliceArea = wholeArea/numSlices;
      break;
    case shape_t::HEXAGON:
      //area of a hexagon = 3 * sqrt(3)/2 * base * base
      wholeArea = (3*sqrt(3)/2) * dimension * dimension;
      sliceArea = wholeArea/numSlices;
      break;
    default:
      cout << "this line should NEVER be called" << endl;
    }
} //end constructor

void Pizza::setSliceRank(rank_t rank){
  slice = rank;
}

void Pizza::setWholeRank(rank_t rank){
  whole = rank;
}
