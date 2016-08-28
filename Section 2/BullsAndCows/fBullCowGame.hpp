//
//  FBullCowGame.hpp
//  BullsAndCows
//
//  Created by David Mckoy on 2016-08-22.
//  Copyright © 2016 David Mckoy. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>
#include <string>

#endif /* FBullCowGame_hpp */

using FString = std::string;
using int32 = int;

struct FBullCowCount {
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EWordStatus {
    Invalid_Status,
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase
};

class FBullCowGame {
public:
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLen() const;
    bool IsGameWon() const;
    EWordStatus IsValidGuess(FString) const;
    
    FBullCowCount SubmitGuess(FString);
    FBullCowGame();
    void Reset();
    
private:
    int32 MyMaxTries;
    int32 MyCurrentTry;
    FString MyHiddenWord;
};