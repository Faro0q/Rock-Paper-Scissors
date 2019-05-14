/* ------------------------------------------------
   prog1RockPaperScissors.cpp
 
   Program #1: Play the game of Paper / Rock / Scissors against the computer.
   Class: CS 141, Spring 2019. Tues 9am lab
   Author: *** Farooq Syed ***
	 
 ----------------------------------------------------
*/

#include <iostream> // For cin and cout
#include <cstdlib>  // For rand()
#include <cctype>   // For uppercase
// #include <ctime> Since its predetermined 
using namespace std;
const int ROCK = 0;  // Sets rocks value to 0
const int PAPER = 1; // Sets paper value to 1
const int SCISSORS = 2;  // Sets scissors value to 2
const int USER_POINT = 1; // Gives a point if user wins
const int COMPUTER_POINT = -USER_POINT; // Gives a point to computer and takes away a point from user if computer wins
const int TIE = 0;  // Gives 0 points if no one wins

//-----------------------------------------------------------------------------------------
int main()
{
  // Display Instructions
  cout << "CS 141 Program #1: Rock/Paper/Scissors\n"
       << endl
       << "Welcome to the game of Rock/Paper/Scissors where you play against\n"
       << "the computer.  On each move the computer will choose R, P, or S, then\n"
       << "the user will be prompted for their choice, and then the score will\n"
       << "be updated.  P beats R, R beats S, and S beats P. The score starts\n"
       << "at 0.  Add one if the person wins, subtract one if the computer wins.\n"
       << "The game ends if the score reaches -5 or + 5.\n"
       << "User input of 'x' or 'X' causes the game to exit.\n"
       << endl
       << "Here we go!\n"
       << endl;

  int computerChoiceVersion;
  cout << "Select how the computer chooses its move: \n"
       << "1. Always choose Rock\n"  
       << "2. Random guess\n"
       << "3. Random guess with graphical score\n"
       << "Enter your choice: ";
  cin >> computerChoiceVersion;
  cout << endl;
  if (computerChoiceVersion < 1 && computerChoiceVersion > 3)
  {
    return 0;
  }
  // srand(time(NULL)); no seed required?
  int computerNumber;
  int userNumber;
  int moveNumber = 0;
  int gameScore = 0;
  char userInput;
  // Main loop should go here, with the indented sections below inside the main loop
  // ...
  while (gameScore != -5 && gameScore != 5)
  {
    // Get the computer choice
    // ...
    if (computerChoiceVersion == 1) // Always computer chooses rock 
    {
      computerNumber = ROCK;
    }
    else
    {
      computerNumber = rand() % 3;
    }

    bool isValidInput = false;
    while (!isValidInput)
    {
      // Prompt for and get the user's choice
      // ...
      // Increment move number
      // ...
      cout << ++moveNumber << ". "
           << "Your move: "; // My move
      cin >> userInput;

      if (isalpha(userInput))
      {
        userInput = toupper(userInput);
      }
      if (userInput == 'R')
      {
        userNumber = ROCK;
        isValidInput = true;
      }
      else if (userInput == 'P')
      {
        userNumber = PAPER;
        isValidInput = true;
      }
      else if (userInput == 'S')
      {
        userNumber = SCISSORS;
        isValidInput = true;
      }
      else if (userInput == 'X')
      {
        isValidInput = true;
        cout << "Exiting program..."
             << endl;
        if (gameScore == 0)
        {
          cout << "Tie game!";
        }
        else if (gameScore < 0)
        {
          cout << "Computer wins!";
        }
        else if (gameScore > 0)
        {
          cout << "User wins!";
        }
        cout << endl
             << endl
             << "Ending program..."
             << endl;
        return 0;
      }
      else
      {
        isValidInput = false;
      }
    }

    int winner = TIE;
    if (userNumber == computerNumber)
    {
      winner = TIE;
      gameScore += TIE;
    }
    // Switch statement for rock paper and scissors points
    switch (userNumber)
    {
    case ROCK:
      switch (computerNumber)
      {
      case PAPER:
        winner = COMPUTER_POINT;
        break;
      case SCISSORS:
        winner = USER_POINT;
        break;
      }
      break;
    case PAPER:
      switch (computerNumber)
      {
      case ROCK:
        winner = USER_POINT;
        break;
      case SCISSORS:
        winner = COMPUTER_POINT;
        break;
      }
      break;
    case SCISSORS:
      switch (computerNumber)
      {
      case PAPER:
        winner = USER_POINT;
        break;
      case ROCK:
        winner = COMPUTER_POINT;
        break;
      }
      break;
    }
    cout << "   ";
    // Display computer choice
    // ...
    switch (computerNumber)
    {
    case ROCK:
      cout << "Computer chose R";
      break;
    case PAPER:
      cout << "Computer chose P";
      break;
    case SCISSORS:
      cout << "Computer chose S";
      break;
    }
    cout << endl
         << "   ";
    // Update score, and then display it
    // ...
    if (winner == USER_POINT)
    {
      gameScore += USER_POINT;
      cout << "User's point.";
    }
    else if (winner == COMPUTER_POINT)
    {
      gameScore += COMPUTER_POINT;
      cout << "Computer's point.";
    }
    else
    {
      cout << "Tie.";
    }
    // Shows the graph and the calculations
    if (computerChoiceVersion == 3)
    {
      int dotAmounts = (3 * (gameScore + 5)) + 2;
      cout << endl
           << "    -5 -4 -3 -2 -1  0  1  2  3  4  5" << endl
           << "   ----------------------------------" << endl;
      cout << "   " << string(dotAmounts, '.') << "^";
    }
    else
    {
      cout << " Score: "
           << gameScore;
    }
    cout << endl
         << endl;
  }
    cout //<< "Exiting program..."
       << endl;
  if (gameScore == 0)
  {
    cout << "Tie game!";
  }
  else if (gameScore < 0)
  {
    cout << "Computer wins!";
  }
  else if (gameScore > 0)
  {
    cout << "User wins!";
  }
  cout << endl
       << endl
       << "Ending program..."
       << endl;
  return 0;
  
}  //end main()
// Keep C++ happy
