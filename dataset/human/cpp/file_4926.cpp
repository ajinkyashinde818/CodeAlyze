#include <iostream>

int main() {
  int  number_of__contests, displayed_rating;
  int inner_rating = 0;
  std::cin >> number_of__contests >> displayed_rating;

  if(number_of__contests >= 10){
    inner_rating = displayed_rating;
  }
  else {
    inner_rating = displayed_rating + (100*(10-number_of__contests));
  }

  std::cout << inner_rating ;
}
