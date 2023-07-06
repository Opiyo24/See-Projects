#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char p_name[] = "PLAYER"; // Name of the player
char c_name[] = "COMPUTER"; // Nmae of the computer player
int p_capital = 1000; // Amount of money in the players account
int c_capital = 1000; // Amount of money in computer's account
int p_stake, c_stake, common_pool; //Player's stake, computer's stake and common pool (A sum of the two)
int stack[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; //The tsack of cards
int p_cardValue = 0;// The value of cards dealt to the player
int c_cardvalue = 0; //Value of cards dealt to the computer
int deal1, deal2, deal3; //Player's cards deal first, second and third time
int counter1, counter2; //Index number for player's deal
int cdeal1, cdeal2, cdeal3, cdeal4; //Number of computer deals
int ccounter1, ccounter2, ccounter3, ccounter4; //Computer deals index
int draw_hold; //0Decision by the player whether to draw or hold
int response1, response2; //Players response on whether to draw or hold
const int max_draw = 21; //Maximum value of careds a player can draw
int p_scoreDiff, c_scoreDiff; //Player's card value and computer's card value subtracted from 21 - max card value
char round_winner[20]; //The winner of a round

void playerstake();
void computerstake(int *capital);
void Deal();
void playerDrawHold(int *response);
void winner(int *num1, int *num2);
int max(int *num1, int *num2);
void computer_win();
void player_win();
void subsequent_deal();
void valuetest(int stage);
void bust_player_win();
void bust_computer_win();

int main()
{
    int stage1 = 1;
    valuetest(stage1);
    // The main code goes here
    computerstake(&c_capital);
    playerstake();
    // printf("PLAYER STAKE: %d", p_stake);
    // printf("PLAYER CAPITAL: %d", p_capital);


    printf("COMPUTER: %d\n", c_stake);
    printf("\nTOTAL STAKE: %d\n", common_pool);

    int stage2 = 2;
    valuetest(stage2);

    Deal();
    printf("Computer: %d\n", c_cardvalue);
    printf("Player: %d", p_cardValue);

    int stage3 = 3;
    valuetest(stage3);

    // Display the card value for the player
    printf("\nReply with a  number: \n1 - DRAW\t2 - HOLD\t3 - CASH OUT/ OPT OUT: ");
    scanf("%d", &response1);

    playerDrawHold(&response1);

    printf("Player: %d", p_cardValue);

    winner(&p_cardValue, &c_cardvalue);

    printf("\nPlayer account: %d", p_capital);
    printf("\nComputer account: %d", c_capital);

    int stage9 = 9;
    valuetest(stage9);

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
            int stage10 = 10;
            valuetest(stage10);
            break;
        }
        case 2:
        {
            EXIT_SUCCESS;// Exit the loop
            int stage11 = 11;
            valuetest(stage11);
            break;
        }
        default:
            printf("\nUNKNOWN SELECTION: Please Make A Valid Choice!.");
            break;
        }
        return(0);
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

    common_pool = p_stake + c_stake;
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
    int stage101 = 101;
    valuetest(stage101);
    printf("\nTOTAL STAKE: %d\n", common_pool);
    Deal();
    printf("Computer: %d", c_cardvalue);
    printf("\nPlayer: %d", p_cardValue);

    int stage102 = 102;
    valuetest(stage102);

    // Display the card value for the player
    printf("\nReply with a  number: \n1 - DRAW\t2 - HOLD: ");
    scanf("%d", &response1);

    playerDrawHold(&response1);
    printf("Player: %d", p_cardValue);

    winner(&p_cardValue, &c_cardvalue);

    //p_capital = p_capital - p_stake;
    //c_capital = c_capital - c_stake;

   // printf("\nPlayer account: %d", p_capital);
    //printf("\nComputer account: %d", c_capital);
    int stage103 = 103;
    valuetest(stage103);

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
        int stage4 = 4;
        valuetest(stage4);
    }
    else if (*response == 2)
    {
        // When player decideds to hold.
        winner(&p_cardValue, &c_cardvalue);
    }
    
    deal3 = stack[counter3];
    p_cardValue = deal1 + deal2 + deal3;

    int stage8 = 8;
    valuetest(stage8);

}

void winner(int *num1, int *num2)
{
    int stage5 = 5;
    valuetest(stage5);

    if (*num1 > 21 || *num2 > 21)
    {
        if (*num1 > 21 && *num2 <= 21)
        {
            bust_computer_win();
            return;
        }
        else if (*num1 <= 21 && *num2 > 21)
        {
            bust_player_win();
            return;
        }
       
    }
    else if (*num1 <= 21 && *num2 <= 21)
    {
        if (*num1 > *num2)
        {
            player_win();
            return;
        }
        else if (*num1 > *num2)
        {
            computer_win();
            return;
        }
        else
        {
            printf("\nIt's a   T I E !!\n\n");
            printf("The Game Automatically Resets.\nAll Bets Are Refunded.");

            p_capital = p_capital + p_stake;
            c_capital = c_capital + c_stake;
            p_stake = 0;
            c_stake = 0;
            common_pool = 0;
            p_cardValue = 0;
            c_cardvalue = 0;

            int stage7 = 7;
            valuetest(stage7);

            return;
        }
    }
    else if (*num1 > 21 && *num2 > 21)
    {
            printf("\n\nB U S T\n");
            p_capital = p_capital + p_stake;
            c_capital = c_capital + c_stake;
            common_pool = 0;
            p_stake = 0;
            c_stake = 0;

            int stage6 = 6;
            valuetest(stage6);

            return;
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

void bust_computer_win()
{
    printf("\nPLAYER BUSTS!!\n\nCOMPUTER WINS!!\n");
    c_capital = c_capital + common_pool;
    p_stake = 0;
    c_stake = 0;
    common_pool = 0;
}

void computer_win()
{
    printf("\nYOU LOSE!!\n\nCOMPUTER WINS!!\n");
    c_capital = c_capital + common_pool;
    p_stake = 0;
    c_stake = 0;
    common_pool = 0;
}

void bust_player_win()
{
    printf("\nCOMPUTER BUSTS!!\n\nYOU ARE THE WINNER!!\n\n");
    p_capital = p_capital + common_pool;
    p_stake = 0;
    c_stake = 0;
    common_pool = 0;
}

void player_win()
{
    printf("\nWINNER\nWINNER!!\n\nYOU ARE THE WINNER!!\n\n");
    p_capital = p_capital + common_pool;
    p_stake = 0;
    c_stake = 0;
    common_pool = 0;
}

void valuetest(int stage)
{
    printf("\n(STAGE %d) PLAYER capital: %d\n", stage, p_capital);
    printf("(STAGE %d) PLAYER Card value: %d\n", stage, p_cardValue);
    printf("(STAGE %d) COMPUTER Capital: %d\n", stage, c_capital);
    printf("(STAGE %d) COMPUTER Card value: %d\n", stage, c_cardvalue);
    printf("(STAGE %d) TOTAL STAKE: %d\n", stage, common_pool);
    printf("(STAGE %d) Common Pool: %d\n", stage, common_pool);
    printf("(STAGE %d) Computer stake: %d\n", stage, c_stake);
    printf("(STAGE %d) Player Stake: %d\n", stage, p_stake);
}



