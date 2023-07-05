void winner(int *num1, int *num2)
{
    int stage5 = 5;
    valuetest(stage5);
    // max_draw - the highest draw value possible
    if (*num1 <= max_draw && *num2 <= max_draw)
    {
        int abole;

        printf("\n(winner) PLAYER capital: %d\n", p_capital);
        printf("(winner) PLAYER Card value: %d\n", p_cardValue);
        printf("(winner) COMPUTER Capital: %d\n", c_capital);
        printf("(winner) COMPUTER Card value: %d\n", c_cardvalue);

        if (p_cardValue == 21)
        {
            player_win();
            return;
        }
        else if (c_cardvalue == 21)
        {
            computer_win();
            return;
        }
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
        int stage6 = 6;
        valuetest(stage6);
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
        p_capital = p_capital + p_stake;
        c_capital = c_capital + c_stake;
    }
    int stage7 = 7;
    valuetest(stage7);
}