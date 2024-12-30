#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int userChoice, computerChoice, rounds;
    int userScore = 0, computerScore = 0;
    srand(time(NULL));

    // Ask for number of rounds
    printf("Let's play Rock Paper Scissors!\n");
    printf("Do you want to play best of 3 or 5 rounds? Enter 3 or 5: ");
    scanf("%d", &rounds);

    if (rounds != 3 && rounds != 5)
    {
        printf("Invalid choice! Please choose 3 or 5 rounds.\n");
        return 1;
    }

    // Main game loop
    for (int round = 1; round <= rounds; round++)
    {
        char userInput;
        printf("\n=== Round %d ===\n", round);
        printf("Enter your choice:\n");
        printf("'r' for Rock\n'p' for Paper\n'z' for Scissors\n");
        scanf(" %c", &userInput);

        // Convert input to choice number
        if (userInput == 'r' || userInput == 'R')
            userChoice = 1;
        else if (userInput == 'p' || userInput == 'P')
            userChoice = 2;
        else if (userInput == 'z' || userInput == 'Z')
            userChoice = 3;
        else
        {
            printf("Invalid choice! Round forfeited.\n");
            computerScore++;
            continue;
        }

        // Generate computer's choice (1-3)
        computerChoice = (rand() % 3) + 1;

        // Display choices
        printf("\nYou chose: ");
        switch (userChoice)
        {
        case 1:
            printf("Rock\n");
            break;
        case 2:
            printf("Paper\n");
            break;
        case 3:
            printf("Scissors\n");
            break;
        }

        printf("Computer chose: ");
        switch (computerChoice)
        {
        case 1:
            printf("Rock\n");
            break;
        case 2:
            printf("Paper\n");
            break;
        case 3:
            printf("Scissors\n");
            break;
        }

        // Determine round winner
        if (userChoice == computerChoice)
        {
            printf("This round is a tie!\n");
            // In case of a tie, play the round again
            round--;
        }
        else if ((userChoice == 1 && computerChoice == 3) ||
                 (userChoice == 2 && computerChoice == 1) ||
                 (userChoice == 3 && computerChoice == 2))
        {
            printf("You win this round!\n");
            userScore++;
        }
        else
        {
            printf("Computer wins this round!\n");
            computerScore++;
        }

        // Display current score
        printf("\nScore - You: %d, Computer: %d\n", userScore, computerScore);
    }

    // Announce final winner
    printf("\n=== Game Over ===\n");
    printf("Final Score - You: %d, Computer: %d\n", userScore, computerScore);
    if (userScore > computerScore)
    {
        printf("Congratulations! You won the game!\n");
    }
    else
    {
        printf("Computer wins the game! Better luck next time!\n");
    }

    return 0;
}
