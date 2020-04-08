#include<stdio.h>
#include "atm.h"


unsigned int get_money(unsigned short int amount) {
  int_array denominations = denomination_list;
  unsigned int dispensed_notes = 0x00;
  if(amount > 31999)
    return dispensed_notes;
  for (int i = 0; i < 8; i++)
  {
    dispensed_notes <<= 4;
    dispensed_notes |= (amount /denominations[i]);
    amount = amount % denominations[i];
  }
  return dispensed_notes;
}

void display_notes(unsigned int notes) {
  int_array denominations = denomination_list;
  unsigned int notes_count;
  for (int i = 0; i < 8; i++)
  {
    notes_count = (notes & 0xf0000000) >> 28;
    if (notes_count)
      printf("%d note(s) of Rs %d\n", notes_count, denominations[i]);
    notes <<= 4;
  }
}