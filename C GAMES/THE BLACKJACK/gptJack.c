#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYER_NAME "PLAYER"
#define COMPUTER_NAME "COMPUTER"
#define INITIAL_CAPITAL 1000

int stake = 0;
int player_capital = INITIAL_CAPITAL;
int computer_capital = INITIAL_CAPITAL;
int player_card_value = 0;
int computer_card_value = 0;
int common_pool = 0;
int draw_hold = 0;

void player_stake();
void computer_stake();
void deal();
void player_draw_hold();
void winner();
void subsequent_deal();
void valuetest(int stage);

int main()
{
    int response2;

    srand(time(NULL));

    while (player_capital > 10)
    {
        player_stake();
        computer_stake();
        common_pool = stake + stake;

        valuetest(2);
        deal();
        valuetest(3);

        printf("\nReply with a number: \n1 - DRAW\t2 - HOLD\t3 - CASH OUT/ OPT OUT: ");
        scanf("%d", &draw_hold);

        player_draw_hold();
        valuetest(4);

        winner();

        valuetest(6);

        printf("\nPlayer account: %d\n", player_capital);
        printf("Computer account: %d\n", computer_capital);

        printf("\nWould you like to play another round?");
        printf("\nReply with 1 - YES\t2 - NO\nRESPONSE: ");
        scanf("%d", &response2);

        if (response2 == 2) {
            break;
        }
    }

    return 0;
}

void player_stake()
{
    printf("Stake limit = %d\n", player_capital);
    printf("How much would you like to stake?\n(No Decimals)\n");
    printf("STAKE: ");
    scanf("%d", &stake);

    player_capital -= stake;
    common_pool = stake + stake;
}

void computer_stake()
{
    float counter_1;
    int countera;

    countera = rand() % 100 + 1;
    counter_1 = countera / 10.0;

    stake = counter_1 * 100;

    if (stake > computer_capital)
    {
        computer_stake();
    }
    else
    {
        computer_capital -= stake;
    }
}

void deal()
{
    int stack[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int counter1, counter2;

    counter1 = rand() % 12;
    player_card_value = stack[counter1];

    counter2 = rand() % 12;
    while (counter2 == counter1) {
        counter2 = rand() % 12;
    }
    player_card_value += stack[counter2];

    counter1 = rand() % 12;
    computer_card_value = stack[counter1];

    counter2 = rand() % 12;
    while (counter2 == counter1) {
        counter2 = rand() % 12;
    }
    computer_card_value += stack[counter2];

    draw_hold = rand() % 2;
    if (draw_hold == 1)
    {
        int counter3 = rand() % 12;
        while (counter3 == counter1 || counter3 == counter2)
        {
            counter3 = rand() % 12;
        }
        player_card_value += stack[counter3];
    }
}

void player_draw_hold()
{
    int counter3;

    if (draw_hold == 1)
    {
        counter3 = rand() % 12;
        while (counter3 == player_card_value)
        {
            counter3 = rand() % 12;
        }
        player_card_value += counter3;
    }
}

void winner()
{
    if (player_card_value > 21 || computer_card_value > 21)
    {
        if (player_card_value > 21 && computer_card_value <= 21)
        {
            printf("\nPLAYER BUSTS!!\n\nCOMPUTER WINS!!\n");
            computer_capital += common_pool;
        }
        else if (player_card_value <= 21 && computer_card_value > 21)
        {
            printf("\nYOU LOSE!!\n\nCOMPUTER WINS!!\n");
            computer_capital += common_pool;
        }
        else
        {
            printf("\nIt's a T I E !!\n\n");
            printf("The Game Automatically Resets.\nAll Bets Are Refunded.");
            player_capital += stake;
            computer_capital += stake;
            common_pool = 0;
            player_card_value = 0;
            computer_card_value = 0;
            return;
        }
    }
    else if (player_card_value <= 21 && computer_card_value <= 21)
    {
        if (player_card_value > computer_card_value)
        {
            printf("\nWINNER\nWINNER!!\n\nYOU ARE THE WINNER!!\n\n");
            player_capital += common_pool;
        }
        else if (player_card_value < computer_card_value)
        {
            printf("\nYOU LOSE!!\n\nCOMPUTER WINS!!\n");
            computer_capital += common_pool;
        }
        else
        {
            printf("\nIt's a T I E !!\n\n");
            printf("The Game Automatically Resets.\nAll Bets Are Refunded.");
            player_capital += stake;
            computer_capital += stake;
            common_pool = 0;
            player_card_value = 0;
            computer_card_value = 0;
            return;
        }
    }
}

void valuetest(int stage)
{
    printf("\n(STAGE %d) PLAYER capital: %d\n", stage, player_capital);
    printf("(STAGE %d) PLAYER Card value: %d\n", stage, player_card_value);
    printf("(STAGE %d) COMPUTER Capital: %d\n", stage, computer_capital);
    printf("(STAGE %d) COMPUTER Card value: %d\n", stage, computer_card_value);
    printf("(STAGE %d) TOTAL STAKE: %d\n", stage, common_pool);
    printf("(STAGE %d) Common Pool: %d\n", stage, common_pool);
    printf("(STAGE %d) Computer stake: %d\n", stage, stake);
    printf("(STAGE %d) Player Stake: %d\n", stage, stake);
}
