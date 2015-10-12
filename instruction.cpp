/* instruction.cpp 
   Authors : Lauren Heinrichs, Brian Caloz, Jacob Allen
   description : 
   implementations of all the functions to grab specific parts
   of a mips instruction statement and has the to_string function
   which tests and converts the input into a understandable english
   form.
*/

#include <iostream>
#include "instruction.hpp"

using namespace std;

//grab opcode 
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

//grab rs
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

//grab rt
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

//grab rd
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

//grab shift amount
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

//grab function
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

//grab immediate value 
bitset<16> Instruction::imm()
{
  //15-0
  bitset<16> temp;
  for ( int i = 15; i >= 0; i--){
    temp[i] = bits[i];
  }
  return temp;
}

//grab jump offset
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

//to_string function that converts given instruction to readable format
//returns INVALID STRING if instruction not recognized
string Instruction:: to_string()
{
  string final; // final opput string 
  //grab each portion of bits for the final instruction
  bitset<6> opcode_ = this->opcode();
  bitset<5> rs_ = this->rs();
  bitset<5> rt_ = this->rt();
  bitset<5> rd_ = this->rd();
  bitset<5> shamt_ = this->shamt();
  bitset<6> func_ = this->funct();
  bitset<26> jump_address = this->jmp_offset();
  bitset<16> imm_ = this->imm();
  //comparison variables
  bitset<6> zero(0);
  bitset<6> J_(2);
  bitset<6> JAL_(3);
  bitset<6> SLL_(0);
  bitset<6> SRL_(2);
  //invalid string 
  string invalid = "INVALID OPCODE";

  //check to see if opcode is zero
  //if zero then it should be R format so use function rather than opcode
  if (opcode_ == zero){
    //check if the function exists 
    bool exit = false;
    int count = 0;
    while ( exit == false){
      if( r_functions[func_.to_ulong()] == r_functions[count] ){
	if ( r_functions[count] == "\0" ){
	  //function does not exist
	  return invalid;}
	//function exists move on to R format
	exit = true;
      }//end if 
      else{
	count++;
	if ( count == 44){
	  //end of list function does not exist
	  return invalid;
	  exit = true;
	}//end if
      }//end if
    }//end while
	  
    //R-Format func $rd,$rs,$rt
    //check for SLL or SRL becuase they use
    // func $rd,$rs,shamt instead
    if ( func_ == SLL_ || func_ == SRL_ ){
      final.append(r_functions[func_.to_ulong()]);
      final.append(" ");
      final.append(reg_names[rd_.to_ulong()]);
      final.append(", ");
      final.append(reg_names[rs_.to_ulong()]);
      final.append(", ");
      string shift = std::to_string(shamt_.to_ulong());
      final.append(shift);
    }//end if
    else{
      //not SLL or SRL 
      final.append(r_functions[func_.to_ulong()]);
      final.append(" ");
      final.append(reg_names[rd_.to_ulong()]);
      final.append(", ");
      final.append(reg_names[rs_.to_ulong()]);
      final.append(", ");
      final.append(reg_names[rt_.to_ulong()]);
    }//end else
  }//end if
  else{
    //check opcode to see if it exists
    bool exit = false;
    int count = 0;
    while ( exit == false){
      if( opcodes[opcode_.to_ulong()] == opcodes[count] ){
	if ( opcodes[count] == "\0" ){
	  return invalid;}
	exit = true;
      }//end if
      else{
	count++;
	if ( count == 44){
	  return invalid;
	  exit = true;
	}//end if
      }//end else
    }//end while
    
    //check for to J-format instructions
    if ( opcode_ == J_ || opcode_ == JAL_ ){
      //J-Format op jmpadd
      final.append(opcodes[opcode_.to_ulong()]);
      final.append(" ");
      long jmp_bin, jmp_decimal = 0;
      jmp_bin = jump_address.to_ulong();
      jmp_decimal = (jmp_bin + 128) % 256 - 128;
      string signedJump = std::to_string(jmp_decimal);
      final.append(signedJump);
    }//end if
    else{
      //I-Format op $rt,$rs,imm
      final.append(opcodes[opcode_.to_ulong()]);
      final.append(" ");
      final.append(reg_names[rt_.to_ulong()]);
      final.append(", ");
      final.append(reg_names[rs_.to_ulong()]);
      final.append(", ");
      long bin, decimal = 0;
      bin = imm_.to_ulong();
      decimal = (bin + 128) % 256 - 128;
      string signedInt = std::to_string(decimal);
      final.append(signedInt);
    }//end else
  }//end else
  //return desired translated instruction
  return final;
}
