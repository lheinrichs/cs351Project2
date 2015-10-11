#include <iostream>
#include "instruction.hpp"

using namespace std;

bitset<6> Instruction:: opcode()
{
  bitset<6> temp;
  int temp_count = 5;
  for(int i = 31; i > 25; i--){
    temp[temp_count] = bits[i];
    temp_count--;
  }
  return temp;
}

bitset<5> Instruction:: rs()
{
  bitset<5> temp;
  int temp_count = 4;
  for(int i = 25; i > 20; i--)
    {
      temp[temp_count] = bits[i];
      temp_count--;
    }
  return temp;
}

bitset<5> Instruction:: rt()
{
  bitset<5> temp;
  int temp_count = 4;
  for(int i = 20; i > 15; i--)
    {
      temp[temp_count] = bits[i];
      temp_count--;
    }
  return temp;
}

bitset<5> Instruction:: rd()
{
  bitset<5> temp;
  int temp_count = 4;
  for(int i = 15; i > 10; i--)
    {
      temp[temp_count] = bits[i];
      temp_count--;
    }
  return temp;
}

bitset<5> Instruction:: shamt()
{
  bitset<5> temp;
  int temp_count = 4;
  for(int i = 10; i > 5; i--)
    {
      temp[temp_count] = bits[i];
      temp_count--;
    }
  return temp;
}

bitset<6> Instruction:: funct()
{
  bitset<6> temp;
  int temp_count = 5;
  for(int i = 5; i >= 0; i--)
    {
      temp[temp_count] = bits[i];
      temp_count--;
    }
  return temp;
}

bitset<16> Instruction::imm()
{
  //15-0
  bitset<16> temp;
  int temp_count = 16;
  for ( int i = 16; i >= 0; i--){
    temp[temp_count] = bits[i];
    temp_count--;
  }
  return temp;
}

bitset<26> Instruction::jmp_offset()
{
  //26-0
  bitset<26> temp;
  int temp_count = 25;
  for( int i = 25; i >= 0; i--){
    temp[temp_count] = bits[i];
    temp_count--;
  }
  return temp;
}


string Instruction:: to_string()
{
  bitset<6> op = this->opcode();
  bitset<6> zero;
  bitset<6> j_(2);
  bitset<6> jal_(3);
  if ( op == zero ) {
    //R format
    bitset<5> rs_ = this->rs();
    bitset<5> rt_ = this->rt();
    bitset<5> rd_ = this->rd();
    bitset<5> shamt_ = this->shamt();
    bitset<6> func = this->funct();
    cout << "  R - Format " << endl;
    cout << "rs : " << reg_names[rs_.to_ulong()] << endl;
    cout << "rt : " << reg_names[rt_.to_ulong()] << endl;
    cout << "rd : " << reg_names[rd_.to_ulong()] << endl;
    cout << "shamt : " << shamt_ << endl;
    cout << "func : " << r_functions[func.to_ulong()] << endl;
  }
  else{
    if ( op == j_ || op == jal_ ){
      //j format
      bitset<26> jump_address = this->jmp_offset();
      cout << "  J - Format " << endl;
      cout << "opcode : " << opcodes[op.to_ulong()] << endl;
      cout << "jump adress : " << jump_address << endl;
      
    }
    else{
      //I format
      bitset<5> rs_ = this->rs();
      bitset<5> rt_ = this->rt();
      bitset<16> imm_ = this->imm();
      cout << "  I - Format " << endl;
      cout << "opcode : " << opcodes[op.to_ulong()] << endl;
      cout << "rs : " << reg_names[rs_.to_ulong()] << endl;
      cout << "rt : " << reg_names[rt_.to_ulong()] << endl;
      cout << "immediate : " << imm_ << endl;
    }
  }
}
