#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <string>

using namespace std;

//Function Prototypes
string GetPlayerName(string);
int Play (string, int, int &);

//Function main()
int main(){
  srand(time(NULL));

  //Initializing variables
  string player1, player2;
  player1 = GetPlayerName(player1);
  player2 = GetPlayerName(player2);
  int position1 = 0;
  int position2 = 0;
  int card = 1;

  //Checking if the players have reached the winning spot
  while (position1 < 90 || position2 < 90){
    position1 = Play(player1, position1, card);
    if(position1 >= 90){
      cout <<"The game is over!" << player1 << " is the winner! \n";
      break;
    }
    position2 = Play(player2, position2, card);
    if(position2 >= 90){
      cout << "The game is over!" <<player2 << " is the winner! \n";
      break;
    }
  } 
  return 0;
}		

//Function GetPlayerName()
string GetPlayerName(string name){
  cout<<"Enter your name: \n";
  getline(cin, name);
  cout << endl;
  return name;
}

//Function Play()
int Play (string player, int pos, int &card_pos){
  //Starting game if user pressing Enter key
  cout <<"Press enter to roll the dice \n";
  cin.get();

  //Rolling the dice to get a random number
  int dice = rand() % 11 + 2;
  pos += dice;

  //Print the current position after the dice is rolled
  cout << player << " rolls the dice and gets a value of "
       << dice << " landing on space " << pos << "." << endl;

  //Checking to see if the position has any special requirements
  if(pos == 10 || pos == 60 || pos == 70 || pos == 80){
    switch(card_pos){
    case 1 : pos -= 9;
      break;
    case 2 : pos = 0;
      break;
    case 3 : pos -= 3;
      break;
    case 4 : pos -= 8;
      break;
    case 5 : pos += 2;
      break;
    case 6 : pos += 1;
      break;
    case 7 : pos += 3;
      break;
    case 8 : pos = 0;
      break;
    case 9 : pos -= 4;
      break;
    case 10 : pos += 6;
      break;
    }
    //Printing the output if there are any special requirements
    cout << player << " picks the card " << card_pos << " moving to space "
         << pos << "." << endl;
    card_pos ++;
	
  }
  else if(pos == 30){
    pos = 69;
    cout << player << " takes the shortcut to spot 69. \n";
  }

  //Restarting the card deck
  if(card_pos == 11){
    card_pos = 1;
  }

  //returning position of the player
  return pos;
			
}


