#include<math.h>

unsigned int get_money(int amount) {
  int denominations[] = {2000, 500, 100, 50, 20, 10, 5, 1};
  unsigned int dispensed_notes = 0x00;
  if(amount > 31999)
    return dispensed_notes;
  for (int i = 0; i < 8; i++)
  {
    dispensed_notes |= (amount /denominations[i])<<((7-i)*4);
    amount = amount % denominations[i];
  }
  return dispensed_notes;
}