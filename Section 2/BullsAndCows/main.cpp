//
//  main.cpp
//  BullsAndCows
//
//  Created by David Mckoy on 2016-08-21.
//  Copyright © 2016 David Mckoy. All rights reserved.
//

#include <iostream>
#include "FBullCowGame.hpp"

using FText = std::string;
using int32 = int;

void printIntro();
void playGame();
bool askToPlayAgain();
FText getValidGuess();

FBullCowGame BCGame;

int main() {
    do {
        printIntro();
        playGame();
    } while (askToPlayAgain());
    
    return 0;
}

void printIntro() {
    std::cout << "Welcome to Bulls and Cows\n";
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLen() << " letter isogram I'm thinking of?\n";
    std::cout << std::endl;
    
    return;
}

void playGame() {
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    
    for (int32 count = 0; count < MaxTries; count++) {
        FText Guess = getValidGuess();
        
        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
    }
}

FText getValidGuess() {
    FText Guess = "";
    EWordStatus Status = EWordStatus::Invalid_Status;
    
    do {
        int32 currentTry = BCGame.GetCurrentTry();
        std::cout << "Try " << currentTry << ". Enter your guess: ";
        std::getline(std::cin, Guess);
        
        Status = BCGame.IsValidGuess(Guess);
        switch (Status) {
            case EWordStatus::Wrong_Length:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLen() << " lettered word.\n";
                break;
                
            case EWordStatus::Not_Lowercase:
                std::cout << "Please use all lowercse characters.\n";
                break;
            
            case EWordStatus::Not_Isogram:
                std::cout << "Please enter a word without repeating letters.\n";
                break;
            
            default:
                return Guess;
        }
        std::cout << std::endl;
    } while(Status != EWordStatus::OK);
    
    return Guess;
}

bool askToPlayAgain() {
    std::cout << "Do you want to play again? (y/n) ";
    FText res = "";
    
    std::getline(std::cin, res);
    
    return (res[0] == 'y') || (res[0] == 'Y');
}