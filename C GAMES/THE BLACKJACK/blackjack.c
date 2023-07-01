#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char p_name[] = "PLAYER";
char c_name[] = "COMPUTER";
int p_capital = 1000;
int c_capital = 1000;
int p_stake, c_stake, common_pool;;
int stack[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int p_cardValue = 0;
int c_cardvalue = 0;
int deal1, deal2, deal3;
int counter1, counter2;
int cdeal1, cdeal2, cdeal3, cdeal4;
int ccounter1, ccounter2, ccounter3, ccounter4;
int draw_hold;
int response1, response2;
const int max_draw = 21;
int p_scoreDiff, c_scoreDiff;
char round_winner[20];

void playerstake();
void computerstake(int *capital);
void Deal();
void playerDrawHold(int *response);
void winner(int *num1, int *num2);
int max(int *num1, int *num2);
void computer_win();
void player_win();
void subsequent_deal();

int main()
{
    // The main code goes here
    playerstake();
    computerstake(&p_capital);

    common_pool = p_stake + c_stake;
    printf("\nTOTAL STAKE: %d\n", common_pool);

    Deal();
    printf("Computer: %d\n", c_cardvalue);
    printf("Player: %d", p_cardValue);

    // Display the card value for the player
    printf("\nReply with a  number: \n1 - DRAW\t2 - HOLD: ");
    scanf("%d", &response1);

    playerDrawHold(&response1);

    printf("Player: %d", p_cardValue);

    winner(&p_cardValue, &c_cardvalue);

    printf("\nPlayer account: %d", p_capital);
    printf("\nComputer account: %d", c_capital);

    while (p_capital > 10)
    {
        printf("\nWould you like to play another round?");
        printf("\nReply with 1 - YES\t2 - NO\nRESPONSE: ");
        scanf("%d", &response2);

        switch (response2)
        {
        case 1:
        {
            subsequent_deal();
            break;
        }
        case 2:
        {
            // Exit the loop
            break;
        }
        default:
            printf("\nUNKNOWN SELECTION: Please Make A Valid Choice!.");
            break;
        }
    }


    return(0);
}

void playerstake()
{
    printf("Stake limit = %d\n", p_capital);
    printf("How much would you like to stake?\n(No Decimals)\n");
    printf("STAKE: ");
    scanf("%d", &p_stake);

    p_capital = p_capital - p_stake;
}

void computerstake(int *capital)
{
    float counter_1;
    int countera;

    srand(time(NULL));
    countera = rand() % 100 + 1;
    counter_1 = countera / 10;

    c_stake = counter_1 * 100;

    if (c_stake > *capital)
    {
        computerstake(&c_capital);
    }
    else
    {
        c_capital = c_capital - c_stake;
    }
}

void Deal()
{
    srand(time(NULL));
    // Player deal
    counter1 =  rand() % 12;
    deal1 = stack[counter1];

    counter2 = rand() % 12;

    while (counter2 == counter1)
        counter2 = rand() % 12;
 
    deal2 = stack[counter2];
    p_cardValue = deal1 + deal2;

    // Computer deal
    srand(time(NULL));
    ccounter1 =  rand() % 12;
    cdeal1 = stack[ccounter1];

    ccounter2 = rand() % 12;

    while (ccounter2 == ccounter1)
        ccounter2 = rand() % 12;
 
    cdeal2 = stack[ccounter2];
    c_cardvalue = cdeal1 + cdeal2;

    srand(time(NULL));
    draw_hold = rand() % 2;

    if (draw_hold == 1)
    {
        ccounter3 = rand() % 12;
        while (ccounter3 == ccounter1 || ccounter3 == ccounter2)
        {
            ccounter3 = rand() % 12;
            cdeal3 = stack[ccounter3];
            c_cardvalue = cdeal1 + cdeal2 + cdeal3;  
        }
    }
}

void subsequent_deal()
{
    playerstake();
    computerstake(&p_capital);

    common_pool = p_stake + c_stake;
    printf("\nTOTAL STAKE: %d\n", common_pool);
    Deal();
    printf("Computer: %d", c_cardvalue);
    printf("Player: %d", p_cardValue);

    // Display the card value for the player
    printf("\nReply with a  number: \n1 - DRAW\t2 - HOLD: ");
    scanf("%d", &response1);

    playerDrawHold(&response1);
    printf("Player: %d", p_cardValue);

    winner(&p_cardValue, &c_cardvalue);

}

void playerDrawHold(int *response)
{
    int counter3;

    if (*response == 1)
    {
        srand(time(NULL));
        counter3 = rand() % 12;

        while (counter3 == counter1 || counter3 == counter2)
        {
            counter3 = rand() % 12;
        }
    }
    else
    {
        // When player decideds to hold.
        winner(&p_cardValue, &c_cardvalue);
    }
    
    deal3 = stack[counter3];
    p_cardValue = deal1 + deal2 + deal3;
}

void winner(int *num1, int *num2)
{

    // max_draw - the highest draw value possible
    if (*num1 <= max_draw && *num2 <= max_draw)
    {
        int abole;

        if (p_cardValue = 21)
            player_win();
        else if (c_cardvalue = 21)
            computer_win();
        // Evalueate winner, both card values are within 21 points.
        p_scoreDiff = max_draw - *num1;
        c_scoreDiff = max_draw - *num2;

        abole = max(&p_scoreDiff, &c_scoreDiff);

        if (abole == p_scoreDiff && abole != c_scoreDiff)
        {
            strcpy(round_winner, "PLAYER");
            //printf("\n\nTHE WINNER IS: %s", round_winner);
            player_win();
        }
        else if (abole != p_scoreDiff && abole == c_scoreDiff)
        {
            strcpy(round_winner, "COMPUTER");
            //printf("\n\nTHE WINNER IS: %s", round_winner);
            computer_win();
        }
        else
        {
            printf("\nIt's a   T I E !!\n\n");
            printf("The Game Automatically Resets.\nAll Bets Are Refunded.");

            p_capital = p_capital + p_stake;
            c_capital = c_capital + c_stake;
        }


        // Evaluate whoever is closer to 21
        // Create a situation handling for when there is a tie.
    }
    else if (*num1 > max_draw && *num2 <= max_draw)
    {
        computer_win();
    }
    else if (*num1 <= max_draw && *num2 > max_draw)
    {
        player_win();
    }
    else
    {
        printf("\n\nB U S T\n");
    }
}


int max(int *num1, int *num2)
{
    if (*num1 > *num2)
    {
        return(*num1);
    }
    else if (*num2 > *num1)
    {
        return(*num2);
    }
}

void computer_win()
{
        printf("\nPLAYER BUSTS!!\n\nCOMPUTER WINS!!\n");
        c_capital = c_capital + common_pool;
}

void player_win()
{
    ("\nCOMPUTER BUSTS!!\n\nYOU ARE THE WINNER!!\n\n");
    p_capital = p_capital + common_pool;
}



