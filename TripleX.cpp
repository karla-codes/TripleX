#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty, int Levels) {
  // prints game instructions to the terminal
  std::cout << "\n\n-----------------------------------------------------------------\n";
  std::cout << "You're trying to break into your mom's secret weed stash\n";
  std::cout << "but it's secured behind " << Levels << " levels of security codes.\n";
  std::cout << "You're on code " << Difficulty << ".\nEnter the correct code to continue...\n";
  std::cout << "-----------------------------------------------------------------\n\n";
}

bool PlayGame(int Difficulty, int Levels) {
  PrintIntroduction(Difficulty, Levels);

  // Declare 3 number code
  const int CodeA = rand() % Difficulty + Difficulty;
  const int CodeB = rand() % Difficulty + Difficulty;
  const int CodeC = rand() % Difficulty + Difficulty;
  const int CodeSum = CodeA + CodeB + CodeC;
  const int CodeProduct = CodeA * CodeB * CodeC;

  // Print sum and product to the terminal
  std::cout << "+ There are 3 numbers in the code\n";
  std::cout << "+ The code adds up to: " << CodeSum;
  std::cout << "\n+ The code multiplies to: " << CodeProduct << std::endl;

  // Store player guess
  int GuessA, GuessB, GuessC;
  std::cin >> GuessA >> GuessB >> GuessC;

  int GuessSum = GuessA + GuessB + GuessC;
  int GuessProduct = GuessA * GuessB * GuessC;

  // Check if the player's guess is correct
  if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
    std::cout << "\n*** You guessed the code correctly! One step closer to the good stuff. ***\n";
    return true;
  } else {
    std::cout << "\n*** WRONG CODE ***\n*** Watch your back and try again. ***\n";
    return false;
  }

}

int main() {
  srand(time(NULL)); // create new random sequence based on time of day

  int LevelDifficulty = 1;

  const int MaxLevel = 5;

  while (LevelDifficulty <= MaxLevel) // Loop game until all levels are completed
  {
    bool bLevelComplete = PlayGame(LevelDifficulty, MaxLevel);
    std::cin.clear();
    std::cin.ignore();

    if (bLevelComplete)
    {
      ++LevelDifficulty;
    }
    
  }

  std::cout << "*** You've aquired the stash! Happy toking! ***";

  return 0;
}