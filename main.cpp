#include <iostream>
#include "constants.hpp"
#include "instruction.hpp"


using namespace std;


int main() {
  //if you run this you get a seg fault after I
  //although j alone works
  //and if you do just R and I it faults then as well...
  // so yeah
  Instruction R(0x02734820);
  cout << endl << R.dump() << endl << endl;;
  R.to_string();
  Instruction I(0x8d280000);
  cout << endl << I.dump() << endl << endl;
  I.to_string();
  Instruction J(0x08000000);
  cout << endl << J.dump() << endl;
  J.to_string();

}
