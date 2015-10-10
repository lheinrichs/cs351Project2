include <iostream>
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

string Instruction:: to_string()
{
}
}
