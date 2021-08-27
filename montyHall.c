#include <stdio.h>
#include <stdlib.h>

int main() {
    int numTrials;
    printf("Enter the number of trials:");
    scanf("%d", &numTrials );
    int numSuccessNoSwap = 0;
    int numSuccessWithSwap = 0;
    const int guessesNoZero[] = {1,2};
    const int guessesNoOne[] = {0,2};
    const int guessesNoTwo[] = {0,1};
    const int *guessesPossible[] = {guessesNoZero, guessesNoOne, guessesNoTwo};

    for(int i = 0; i < numTrials; i++) {
        const int door = rand() % 3;
        const int guess = rand() % 3;
        const int removed = door ? door - 1 : door + 1;
        const int *possibleGuessWithRemoval = guessesPossible[removed];
        const int guessWithRemoval = possibleGuessWithRemoval[rand() % 2];
        if(guess == door){
            numSuccessNoSwap += 1;
        }
        if (guessWithRemoval == door){
            numSuccessWithSwap += 1;
        } 
    }

    const double percentSuccessWithSwap = ((double)numSuccessWithSwap)/ ((double) numTrials);
    const double percentSuccessNoSwap = ((double)numSuccessNoSwap) / ((double) numTrials);
    printf("%d Trials gave %f without swap\n", numTrials, percentSuccessNoSwap);
    printf("%d Trials gave %f with swap\n", numTrials, percentSuccessWithSwap);
    return 0;
}