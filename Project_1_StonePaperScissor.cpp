/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Project_1_StonePaperScissor.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilelmahi <ilelmahi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:09:54 by ilelmahi          #+#    #+#             */
/*   Updated: 2025/05/21 14:09:54 by ilelmahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using   namespace std;

enum enChoice { Stone = 1, Paper = 2, Scissor = 3 };

#define draw 0
#define playerwin 1
#define computerwin 2

int ReadPositiveNumber(string prompt)
{
    int i;

    do
    {
        cout << prompt ;
        cin >> i;
    } while (i<=0 || i > 10);
    return i;
}

int RandomCharachter(int From, int To)
{
    int RandomN = rand() % (To - From + 1) + From;
    return RandomN;
}

int    CheckResult(int computer_choice, int player_choice)
{
    if ((player_choice == Stone && computer_choice == Stone) || (player_choice == Paper && computer_choice == Paper) || ((player_choice == Scissor && computer_choice == Scissor)))
        return (draw);
    else if ((player_choice == Stone && computer_choice == Scissor) || (player_choice == Paper && computer_choice == Stone) || (player_choice == Scissor && computer_choice == Paper))
        return (playerwin);
    return (computerwin);
}

string  ConvertChoice(int choice)
{
    if (choice == 1)
        return ("Stone");
    else if (choice == 2)
        return ("Paper");
    return ("Scissor");
}
void    PrintResultEachRound(int result, int i, int computer_choice, int player_choice, int *player_count, int *computer_count, int *draw_count)
{
    if (result == draw)
    {
        cout << "____________________Round [" << i << "]____________________" << endl;
        cout << "Computer Choice: " << ConvertChoice(computer_choice) << endl;
        cout << "Player Choice: " << ConvertChoice(player_choice) << endl;
        cout << "Round Winner: " << "[No Winner]" << endl;
        (*draw_count)++;
    }
    else if (result == playerwin)
    {
        cout << "____________________Round [" << i << "]____________________" << endl;
        cout << "Computer Choice: " << ConvertChoice(computer_choice) << endl;
        cout << "Player Choice: " << ConvertChoice(player_choice) << endl;
        cout << "Round Winner: " << "[player win]" << endl;
        (*player_count)++;
    } 
    else if (result == computerwin)
    {
        cout << "____________________Round [" << i << "]____________________" << endl;
        cout << "Computer Choice: " << ConvertChoice(computer_choice) << endl;
        cout << "Player Choice: " << ConvertChoice(player_choice) << endl;
        cout << "Round Winner: " << "[computer win]" << endl;
        (*computer_count)++;
    } 
}

void    check_final_winner(int final_winer)
{
    if (final_winer == 0)
        cout << "Final Winner       :" << "No Winner" << endl;
    else if (final_winer == 1)
        cout << "Final Winner       :" << "Player" << endl;
    else if (final_winer == 2)
        cout << "Final Winner       :" << "Computer" << endl;
}

void    PrintFinalResult(int i,int player_count, int computer_count, int draw_count)
{
    int final_winer = 0;

    if (player_count == computer_count && (player_count+computer_count) == draw_count)
        final_winer = 0;
    else if (player_count > computer_count)
        final_winer = 1;
    else if (player_count < computer_count)
        final_winer = 2;
    i-=1;
    cout << "__________________________________________________________________________" << endl;
    cout << "                +++      G A M E          O V E R     +++                 " << endl;
    cout << "__________________________________________________________________________" << endl;
    cout << "_______________________________[GAME RESULTS ]_______________________________" << endl;
    cout << endl;
    cout << "Game Rounds        :" << i << endl;
    cout << "Player win times   :" << player_count << endl;
    cout << "Computer win times :" << computer_count << endl;
    cout << "Draw Times         :" << draw_count << endl;
    check_final_winner(final_winer);
}

void    read_player_choice(int *player_choice)
{
    do {
        cout << "Your choice: [1]:Stone, [2]:paper, [3]:Scissor ? ";
        cin >> *player_choice;
    }   while(*player_choice<1 || *player_choice > 3);
}

void    StartRounds(int number)
{
    int i = 1;
    int player_choice;
    int computer_choice;
    int result;
    int player_count = 0;
    int computer_count = 0;
    int draw_count = 0;

    computer_choice = RandomCharachter(1,3);
    while(i <= number)
    {
        cout << "Round [" << i << "]" << " begins:" << endl;
        read_player_choice(&player_choice);
        result = CheckResult(computer_choice, player_choice);
        PrintResultEachRound(result, i, computer_choice, player_choice, &player_count, &computer_count, &draw_count);
        i++;
    }
    PrintFinalResult(i,player_count, computer_count, draw_count);
}

int main()
{
    srand((unsigned)time(NULL));
    string    WantToPlayAgain;
    int rounds;

    do
    {
        rounds = ReadPositiveNumber("How many rounds 1 to 10 ?");
        StartRounds(rounds);
        cout << "Do you want to play again: [Y = yes / N or anything else mean No] ? " ;
        cin >> WantToPlayAgain;
    }   while(( WantToPlayAgain != "N"  && WantToPlayAgain != "n") && (WantToPlayAgain == "Y" || WantToPlayAgain == "y"));
}