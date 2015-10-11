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
  for ( int i = 15; i >= 0; i--){
    temp[i] = bits[i];
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
  string final;
  bitset<6> opcode_ = this->opcode();
  bitset<5> rs_ = this->rs();
  bitset<5> rt_ = this->rt();
  bitset<5> rd_ = this->rd();
  bitset<5> shamt_ = this->shamt();
  bitset<6> func_ = this->funct();
  bitset<26> jump_address = this->jmp_offset();
  bitset<16> imm_ = this->imm();
  //comparisons                                                                                                                                                                                       
  bitset<6> zero(0);
  bitset<6> J_(2);
  bitset<6> JAL_(3);
  if (opcode_ == zero){
    //R-Format func $rd,$rs,$rt                                                                                                                                                                       
    final.append(r_functions[func_.to_ulong()]);
    final.append(" ");
    final.append(reg_names[rd_.to_ulong()]);
    final.append(", ");
    final.append(reg_names[rs_.to_ulong()]);
    final.append(", ");
    final.append(reg_names[rt_.to_ulong()]);
  }//end if                                                                                                                                                                                           
  else{
    if ( opcode_ == J_ || opcode_ == JAL_ ){
      //J-Format op jmpadd                                                                                                                                                                            
      final.append(opcodes[opcode_.to_ulong()]);
      final.append(" ");
      final.append(jump_address.to_string());
    }//end if                                                                                                                                                                                         
    else{
      //I-Format op $rt,$rs,imm                                                                                                                                                                       
      final.append(opcodes[opcode_.to_ulong()]);
      final.append(" ");
      final.append(reg_names[rt_.to_ulong()]);
      final.append(", ");
      final.append(reg_names[rs_.to_ulong()]);
      final.append(", ");
      final.append(imm_.to_string());
    }//end else                                                                                                                                                                                       
  }//end else                                                                                                                                                                                         
  return final;
}

