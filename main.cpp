#include <iostream>
#include "constants.hpp"
#include "instruction.hpp"


using namespace std;

bool go = true;

int main() {

  Instruction i(0);//R                                                                                                                                
  Instruction i2(0x08 << 26 | 17 << 21 | 16 << 16 | 0xffff);//I                                                                                       
  Instruction i3(0xffffffff);
  Instruction i4(0);
  Instruction i5(0x02734820);//R                                                                                                                      
  Instruction i6(0x8d280000);//I                                                                                                                      
  Instruction i7(0x08000000);//J                                                                                                                      
  cout << i5.to_string() << endl;
  cout << i6.to_string() << endl;
  cout << i7.to_string() << endl;
}
