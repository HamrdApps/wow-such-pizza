#include <vector>
#include "pizza.h"
using namespace std;

//Returns the name of the shape from shape_t
const char* shape2char(shape_t s){
  switch(s){
    case SQUARE:
      return "square";
      break;
    case CIRCLE:
      return "circle";
      break;
    case HEXAGON:
      return "hexagon";
      break;
    default:
      return "shapeless, nonexistent"; //this should never be returned
    }
}
const char* rank2char(rank_t r){
  switch(r){
    case SMALL:
      return "SMALL";
      break;
    case MEDIUM:
      return "MEDIUM";
      break;
    case LARGE:
      return "LARGE";
      break;
    default:
      return "\nnope, you shouldn't be reading this! something's wrong!\n";
    }
}

//Pizza Comparison Functions
bool cmpSlice(Pizza &p1, Pizza &p2){
  return p1.getArea_Slice() < p2.getArea_Slice();
}
bool cmpWhole(Pizza &p1, Pizza &p2){
  return p1.getArea_Whole()<p2.getArea_Whole();
}


void sortPies(vector<Pizza> &pizzaVec){
  //sort pizzas by SLICE area
  sort(pizzaVec.begin(),pizzaVec.end(),cmpSlice);

  //assign the pizzas slice rank based on sorted vector position
  pizzaVec[0].setSliceRank(SMALL);
  pizzaVec[1].setSliceRank(MEDIUM);
  pizzaVec[2].setSliceRank(LARGE);

  //sort pizzas by WHOLE area
  sort(pizzaVec.begin(),pizzaVec.end(),cmpWhole);

  //assign the pizzas whole rank based on sorted vector position
  pizzaVec[0].setWholeRank(SMALL);
  pizzaVec[1].setWholeRank(MEDIUM);
  pizzaVec[2].setWholeRank(LARGE);
}
