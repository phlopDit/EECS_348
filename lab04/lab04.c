#include <stdio.h>

int scoringPlays[] = {8, 7, 6, 3, 2};
int plays[5];

/*
Recursively finds all possible combinations of scoring plays based on a given score.
*/
void findScoreCombinations(int score, int index){
    // Base cases
    if(score == 0){
        printf("%d + 2pt, %d + extra point, %d TD, %d FG, %d Safety\n",
        plays[0], plays[1], plays[2], plays[3], plays[4]);
        return;
    }else if (index == 5){
        return;
    }

    int playValue = scoringPlays[index];

    for (int i = 0; i <= score / playValue; i++){
        plays[index] = i;
        findScoreCombinations(score - i * playValue, index + 1);
    }
    plays[index] = 0;
}

/*
Asks the user for a NFL score value and finds all combinations of possible scoring
plays that add up to that value.
*/
int main(){
    int score;

    while (1) {
        printf("Enter the NFL score (0 or 1 to stop): ");
        scanf("%d", &score);

        if(score <= 1) {
            break;
        }

        printf("Possible combinations of scoring plays if a team's score is %d are:\n", score);
        findScoreCombinations(score, 0);
        printf("\n");
    }

    return 0;
}

