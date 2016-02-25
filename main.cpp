#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "pizza.h"
#include "auxfuncs.hpp"
using namespace std;

int main(int argc, char *argv[])
{
  //initialize each pizza
  Pizza squarePie(shape_t::SQUARE);
  Pizza circlePie(shape_t::CIRCLE);
  Pizza hexagonPie(shape_t::HEXAGON);

  //add each pizza to a vector container to facilitate sorting
  vector<Pizza> pizzaVec;
  pizzaVec.push_back(hexagonPie);
  pizzaVec.push_back(squarePie);
  pizzaVec.push_back(circlePie);

  sortPies(pizzaVec);

  //display each pizza's size ranks
  for(int i=0;i<pizzaVec.size();i++){
      cout << "The " << shape2char(pizzaVec[i].getShape()) << "-shaped pizza:" << endl;
      cout << "   Whole: "<<endl;
      cout << "      --Area: " << pizzaVec[i].getArea_Whole() << endl;
      cout << "      --Rank: " << rank2char(pizzaVec[i].getWholeRank()) << endl;
      cout << "   Slice: " << endl;
      cout << "      --Area: " << pizzaVec[i].getArea_Slice() << endl;
      cout << "      --Rank: " << rank2char(pizzaVec[i].getSliceRank()) << endl;
    }


//output each pizza's size ranks to comparisons.prn
  ofstream fout;
  fout.open("./comparisons.prn");
  while(fout.is_open()){
      for(int i=0;i<pizzaVec.size();i++){
        fout << "The " << shape2char(pizzaVec[i].getShape()) << "-shaped pizza:" << endl;
        fout << "   Whole: "<< endl;
        fout << "      --Area: " << pizzaVec[i].getArea_Whole() << endl;
        fout << "      --Rank: " << rank2char(pizzaVec[i].getWholeRank()) << endl;
        fout << "   Slice: " << endl;
        fout << "      --Area: " << pizzaVec[i].getArea_Slice() << endl;
        fout << "      --Rank: " << rank2char(pizzaVec[i].getSliceRank()) << endl;
        fout << endl;
      }
    cout << "file written!" << endl;
    fout.close(); //close the output file stream
    }

}
