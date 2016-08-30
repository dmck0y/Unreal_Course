//
//  FBullCowGame.cpp
//  BullsAndCows
//
//  Created by David Mckoy on 2016-08-22.
//  Copyright © 2016 David Mckoy. All rights reserved.
//
#include "FBullCowGame.hpp"
#include <map>
#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame() {
    Reset();
}

void FBullCowGame::Reset() {
    const FString HiddenWord = "planet";
    
    MyHiddenWord = HiddenWord;
    MyCurrentTry = 1;
    bGameWon = false;
    
    return;
}

int32 FBullCowGame::GetMaxTries() const {
    TMap<int32, int32> WordLentoTries {{3,4}, {4,6}, {5,6}, {6,6}};
    return WordLentoTries[MyHiddenWord.length()];
}

int32 FBullCowGame::GetCurrentTry() const {
    return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const {
    return bGameWon;
}

bool FBullCowGame::IsIsogram(FString Word) const {
    if (Word.length() <= 1) return true;
    
    TMap<char, bool> LetterSeen;
    for(auto Letter : Word) {
        Letter = tolower(Letter);
        if (LetterSeen[Letter]) {
            return false;
        } else {
            LetterSeen[Letter] = true;
        }
    }
    
    return true;
}

bool FBullCowGame::IsLowercase(FString Word) const {
    for(auto Letter : Word) {
        if (!islower(Letter)) return false;
    }
    return true;
}

EWordStatus FBullCowGame::IsValidGuess(FString Guess) const {
    if (!IsIsogram(Guess)) {
        return EWordStatus::Not_Isogram;
    } else if  (Guess.length() != GetHiddenWordLen()) {
        return EWordStatus::Wrong_Length;
    } else if (!IsLowercase(Guess)) {
        return EWordStatus::Not_Lowercase;
    } else {
        return EWordStatus::OK;
    }
}

int32 FBullCowGame::GetHiddenWordLen() const {
    return MyHiddenWord.length();
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {
    MyCurrentTry++;
    
    FBullCowCount BullCowCount;
    
    int32 HiddenWordLen = GetHiddenWordLen();
    
    for(int32 i = 0; i < HiddenWordLen; i++) {
        for(int32 j = 0; j < HiddenWordLen; j++) {
            if(Guess[j] == MyHiddenWord[i]) {
                if (i == j) {
                    BullCowCount.Bulls++;
                } else {
                    BullCowCount.Cows++;
                }
            }
        }
    }
    if (BullCowCount.Bulls == HiddenWordLen) bGameWon = true; else bGameWon = false;
    
    return BullCowCount;
}
