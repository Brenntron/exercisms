#include "dnd_character.h"
#include <stdlib.h>
#include <time.h>

int ability()
{ 
  int rolls[4];
  int min_idx = 0;
  int sum = 0;
  srand(time(NULL));

  for (int i = 0; i < 4; i++) {
    rolls[i] = (rand() % 6) + 1;
    if (rolls[i] < rolls[min_idx]) min_idx = i;
  }

  for (int i = 0; i < 4; i++) {
    if (i != min_idx) sum += rolls[i];
  }

  return sum;
}

int modifier(int score)
{
  if (score == 0) {
    return 0;
  }
  score -= 10;
  score = (score >= 0) ? (score / 2) : ((score - 2 + 1) / 2);
  return score;
}

dnd_character_t make_dnd_character(void)
{
  dnd_character_t character;

  character.strength = ability();
  character.dexterity = ability();
  character.constitution = ability();
  character.intelligence = ability();
  character.wisdom = ability();
  character.charisma = ability();
  character.hitpoints = (10 + modifier(character.constitution));

  return character;
}
