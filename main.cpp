#include <iostream>
#include "constants.hpp"
#include "instruction.hpp"


using namespace std;


int main() {
  Instruction i(4042322160); //decimal equal to 1111 0000 1111 0000 1111 0000 1111 0000
  //Instruction i(0xF0F0F0F0) ;
  //Instruction i(string("11110000111100001111000011110000");
  //same input in hex form and string form
  cout << i.dump() << endl; //returns the current 32 bit instruction
  cout << "opcode : " << i.opcode() << endl; //returns the opcode

}
