#include "instruction.hpp"

bitset<6> Instruction::opcode(){
  //opcode is the bits 31-26
  bitset<6> temp;
  int temp_count = 5;
  for (int i = 31; i > 25 ; i--){
    temp[temp_count] = bits[i];
    temp_count--;
  }
  return temp;
}

bitset<5> Instruction::rs(){
  // for I and R format bit locations are 25-21
  // no rs for j format
}

bitset<5> Instruction::rt(){
  // for I and R format bit locations are 20-16
  // no rt for j format
}

bitset<5> Instruction::rd(){
  //for R format the rd is bit locations 15-11
  //no rd for j and I format
}

bitset<5> Instruction::shamt(){
  //only for R format bit locations are 10-6
}

bitset<6> Instruction::funct(){
  //only for R format bit locations are 5-0
}

bitset<16> Instruction::imm(){
  //only for I format bit locations are 15-0
}

bitset<26> Instruction::jmp_offset(){
  //only for j format bit locations are 26-0
}


string Instruction::to_string(){
  //converts the instruction into readable form
}

