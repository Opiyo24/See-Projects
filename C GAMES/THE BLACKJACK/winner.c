void winner(int *num1, int *num2)
{
    if (p_value > 21 || c_value > 21)
    {
        if (p_value > 21 && c_value !> 21)
        {
            player_win()
            return;
        }
        else if (p_value !> 21 && c_value > 21)
        {
            computer_win();
            return;
        }
        else
        {
            printf("\n\nB U S T\n");
            p_capital = p_capital + p_stake;
            c_capital = c_capital + c_stake;
            return;
        }
    }
    else if (p_value <= 21 && c_value <= 21)
    {
        if (p_value > c_value)
        {
            player_win();
            return;
        }
        else if (c_value > p_value)
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
            return;
        }
    }
}