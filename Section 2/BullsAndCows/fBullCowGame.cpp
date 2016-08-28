//
//  FBullCowGame.cpp
//  BullsAndCows
//
//  Created by David Mckoy on 2016-08-22.
//  Copyright © 2016 David Mckoy. All rights reserved.
//
#include "FBullCowGame.hpp"

using int32 = int;

FBullCowGame::FBullCowGame() {
    Reset();
}

void FBullCowGame::Reset() {
    constexpr int32 MAX_TRIES = 8;
    const FString HiddenWord = "planet";
    
    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HiddenWord;
    MyCurrentTry = 1;
    
    return;
}

int32 FBullCowGame::GetMaxTries() const {
    return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const {
    return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const {
    return false;
}

EWordStatus FBullCowGame::IsValidGuess(FString Guess) const {
    if (false) {
        return EWordStatus::Not_Isogram;
    } else if  (Guess.length() != GetHiddenWordLen()) {
        return EWordStatus::Wrong_Length;
    } else if (false) {
        return EWordStatus::Not_Lowercase;
    } else {
        return EWordStatus::OK;
    }
}

int32 FBullCowGame::GetHiddenWordLen() const {
    return MyHiddenWord.length();
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
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
    
    return BullCowCount;
}
