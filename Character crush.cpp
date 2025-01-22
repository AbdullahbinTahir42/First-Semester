#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <fstream>

using namespace std;
void mode_selection(char easy[6][6], char med[8][8], char hard[10][10]);
char rand_char();
char med[8][8];
char easy[6][6];
char hard[10][10];
int level = 1;
bool check = false;

void exit();
void developers();
void playing_technique();
void easy_manual();
void med_manual();
void hard_manual();
void game_manual();
void med_level_checker(int &level, int &med_lvl_score, int &med_player_score, int &med_total_moves, int &med_moves_remaining);
void med_update_board(char med[8][8], int &med_lvl_score, int &med_player_score, int &med_total_moves, int &med_moves_remaining);
void med_initial_board(char med[8][8]);
void med_move_valid(char med[8][8], int x1, int x2, int y1, int y2, bool &check, int &med_lvl_score, int &med_player_score, int &med_total_moves, int &med_total_moves1, int &med_moves_remaining);
void med_player_turn(char med[8][8]);
int med_lvl_score = 100;
int med_player_score = 0;
int med_total_moves = 18;
int med_total_moves1 = med_total_moves;
int med_moves_remaining = med_total_moves1;
void med_remove_character(char med[8][8]);

void hard_level_checker(int &level, int &hard_lvl_score, int &hard_player_score, int &hard_total_moves, int &hard_moves_remaining);
void hard_update_board(char hard[10][10], int &hard_lvl_score, int &hard_player_score, int &hard_total_moves, int &hard_moves_remaining);
void hard_initial_board(char hard[10][10]);
void hard_move_valid(char hard[10][10], int x1, int x2, int y1, int y2, bool &check, int &hard_lvl_score, int &hard_player_score, int &hard_total_moves, int &hard_total_moves1, int &hard_moves_remaining);
void hard_player_turn(char hard[10][10]);
int hard_lvl_score = 100;
int hard_player_score = 0;
int hard_total_moves = 15;
int hard_total_moves1 = hard_total_moves;
int hard_moves_remaining = hard_total_moves1;
void hard_remove_character(char hard[10][10]);

void easy_level_checker(int &level, int &easy_lvl_score, int &easy_player_score, int &easy_total_moves, int &easy_moves_remaining);
void easy_remove_character(char easy[6][6]);

void main_menu(char easy[6][6], char[8][8], char hard[10][10]);
void easy_update_board(char easy[6][6], int &easy_lvl_score, int &easy_player_score, int &easy_total_moves, int &easy_moves_remaining);
void easy_initial_board(char easy[6][6]);

void easy_player_turn(char easy[6][6]);
void easy_move_valid(char easy[6][6], int x1, int x2, int y1, int y2, bool &check, int &easy_lvl_score, int &easy_player_score, int &easy_total_moves, int &easy_total_moves1, int &easy_moves_remaining);

int easy_lvl_score = 100;
int easy_player_score = 0;
int easy_total_moves = 20;
int easy_total_moves1 = easy_total_moves;
int easy_moves_remaining = easy_total_moves1;

int main()
{
	system("color F0");
	ofstream file("user.txt", ios::app);
	if (!file)
	{
		cout << "error";
		return 0;
	}
	string name;
	int age;
	string Email;
	// stores data of which user is playing the game

	cout << "\t---------------------------------------------------------" << endl;
	cout << "\t|        C H A R A C T E R        S A G A               |\n";
	cout << "\t---------------------------------------------------------\n";
	cout << "\t|        E N T E R  Y O U R  N A M E:-                  |\n";
	cout << "\t|              ";
	getline(cin, name);
	cout << "\t|        E N T E R  Y O U R  A G E :-                   |\n";
	cout << "\t|              ";
	cin >> age;
	cout << "\t|        E N T E R  Y O U R  E-MAIL:                    |\n";
	cout << "\t|              ";
	cin >> Email;
	cout << "\t---------------------------------------------------------" << endl;

	file << "USER NAME :" << name << endl;
	file << "AGE :" << age << endl;
	file << "E-MAIL :" << Email << endl;
	file << "\t---------------------------------------------------------" << endl;
	file.close();
	char Terms;
	cout << "Do you agree to the terms and conditions :\nenter Y for YES and N for no :";
	cin >> Terms;
	while (1)
	{
		if (Terms == 'y' || Terms == 'Y')
		{
			cout << endl;
			break;
		}
		else if (Terms == 'n' || Terms == 'N')
		{
			cout << "CLOSING THE GAME...." << endl;
			return 0;
		}
		else
		{
			cout << "Invalid input. Please enter 'y' or 'n'." << endl;
			cin >> Terms;
		}
	}
	cout << "press any key to continue";
	getch();
	system("cls");

	// for easy level generating charaters
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{

			easy[i][j] = rand_char();
		}
	}
	// for medium level generating characters
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{

			med[i][j] = rand_char();
		}
	}

	// for hard level generating characters
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			hard[i][j] = rand_char();
		}
	}
	main_menu(easy, med, hard);

	return 0;
}

char rand_char()
{
	char cand;
	int c;
	c = static_cast<char>(32 + (rand() % 5) + 1);
	return c;
}

void easy_initial_board(char easy[6][6]) // function of initial board for easy level
{
	system("cls");
	system("color F2");
	cout << "\t\t---------------------------------------" << endl;
	cout << "\t\t|     C H A R A C T E R   S A G A     |\n";
	cout << "\t\t---------------------------------------\n";
	cout << "M O D E :- EASY\n\n";
	cout << "\t\t--------------\n";
	cout << "\t\t| L E V E L  |\n";
	cout << "\t\t--------------\n";
	cout << "\nL E V E L  S C O R E:...";
	cout << "\nP L A Y E R  S C O R E:... ";
	cout << "\nT O T A L  M O V E S:... ";
	cout << "\nR E M A I N I N G  M O V E S:...";
	cout << "\n\n\t     0     1     2     3     4     5";
	cout << "\n\t  ____________________________________\n";
	for (int i = 0; i < 6; i++)
	{
		cout << "\t" << i << " ";
		for (int j = 0; j < 6; j++)
		{
			cout << "|  " << easy[i][j] << "  ";
		}
		cout << "|\n\t  ____________________________________\n";
	}
	cout << "Press enter to continue..";
	getch();
}
void hard_initial_board(char hard[10][10]) // function of initial board for hard level
{
	system("cls");
	system("color F4");
	cout << "\t\t---------------------------------------" << endl;
	cout << "\t\t|     C H A R A C T E R   S A G A     |\n";
	cout << "\t\t---------------------------------------\n";
	cout << "M O D E :- HARD\n\n";
	cout << "\t\t--------------\n";
	cout << "\t\t| L E V E L  |\n";
	cout << "\t\t--------------\n";
	cout << "\nL E V E L  S C O R E:...";
	cout << "\nP L A Y E R  S C O R E:... ";
	cout << "\nT O T A L  M O V E S:... ";
	cout << "\nR E M A I N I N G  M O V E S:...";
	cout << "\n\n\t     0     1     2     3     4     5     6     7     8     9";
	cout << "\n\t  ___________________________________________________________\n";
	for (int i = 0; i < 10; i++)
	{
		cout << "\t" << i << " ";
		for (int j = 0; j < 10; j++)
		{
			cout << "|  " << hard[i][j] << "  ";
		}
		cout << "|\n\t  _____________________________________________________________\n";
	}
	cout << "Press enter to continue..";
	getch();
}

void easy_player_turn(char easy[6][6]) // function which will take index no from user to swap in easy level
{
	int x1, x2, y1, y2;
	cout << "\nMake your move..\n";
	cout << "Enter index no of character to replace :\n";
	cout << "ENTER ROW :";
	cin >> x1;
	cout << "ENTER COLUMN :";
	cin >> y1;
	cout << "\nEnter index no of character to replace with :\n";
	cout << "ENTER ROW :";
	cin >> x2;
	cout << "ENTER COLUMN :";
	cin >> y2;

	easy_move_valid(easy, x1, x2, y1, y2, check, easy_lvl_score, easy_player_score, easy_total_moves, easy_total_moves1, easy_moves_remaining);

	getch();
}
void hard_player_turn(char hard[10][10]) // function which will take index no from user in hard level
{
	int x1, x2, y1, y2;
	cout << "\nMake your move..\n";
	cout << "Enter index no of character to replace :\n";
	cout << "ENTER ROW :";
	cin >> x1;
	cout << "ENTER COLUMN :";
	cin >> y1;
	cout << "\nEnter index no of character to replace with :\n";
	cout << "ENTER ROW :";
	cin >> x2;
	cout << "ENTER COLUMN :";
	cin >> y2;

	hard_move_valid(hard, x1, x2, y1, y2, check, hard_lvl_score, hard_player_score, hard_total_moves, hard_total_moves1, hard_moves_remaining);

	getch();
}

void easy_update_board(char easy[6][6], int &easy_lvl_score, int &easy_player_score, int &easy_total_moves, int &easy_moves_remaining)
{ // function that will update the score and board and level
	system("cls");
	system("color F2");
	cout << "\t\t---------------------------------------" << endl;
	cout << "\t\t|     C H A R A C T E R   S A G A     |\n";
	cout << "\t\t---------------------------------------\n";
	cout << "M O D E :- EASY\n\n";
	if (easy_lvl_score == 100)
	{
		cout << "\t\t----------------\n";
		cout << "\t\t| L E V E L  1 |\n";
		cout << "\t\t----------------\n";
	}
	if (easy_lvl_score == 150)
	{
		cout << "\t\t----------------\n";
		cout << "\t\t| L E V E L  2 |\n";
		cout << "\t\t----------------\n";
	}
	if (easy_lvl_score == 200)
	{
		cout << "\t\t----------------\n";
		cout << "\t\t| L E V E L  3 |\n";
		cout << "\t\t----------------\n";
	}
	cout << "\nL E V E L  S C O R E:" << easy_lvl_score;
	cout << "\nP L A Y E R  S C O R E: " << easy_player_score;
	cout << "\nT O T A L  M O V E S: " << easy_total_moves;
	cout << "\nR E M A I N I N G  M O V E S:" << easy_moves_remaining;
	easy_remove_character(easy);
	cout << "\n\n\t     0     1     2     3     4     5";
	cout << "\n\t  ____________________________________\n";

	for (int i = 0; i < 6; i++)
	{
		cout << "\t" << i << " ";
		for (int j = 0; j < 6; j++)
		{
			cout << "|  " << easy[i][j] << "  ";
		}
		cout << "|\n\t  ____________________________________\n";
	}
}

void hard_update_board(char hard[10][10], int &hard_lvl_score, int &hard_player_score, int &hard_total_moves, int &hard_moves_remaining)
{ // function which will update the scorecard etc
	system("cls");
	system("color F4");
	cout << "\t\t---------------------------------------" << endl;
	cout << "\t\t|     C H A R A C T E R   S A G A     |\n";
	cout << "\t\t---------------------------------------\n";
	cout << "M O D E :- HARD\n\n";
	if (hard_lvl_score == 100)
	{
		cout << "\t\t----------------\n";
		cout << "\t\t| L E V E L  1 |\n";
		cout << "\t\t----------------\n";
	}
	if (hard_lvl_score == 150)
	{
		cout << "\t\t----------------\n";
		cout << "\t\t| L E V E L  2 |\n";
		cout << "\t\t----------------\n";
	}
	if (hard_lvl_score == 200)
	{
		cout << "\t\t----------------\n";
		cout << "\t\t| L E V E L  3 |\n";
		cout << "\t\t----------------\n";
	}
	cout << "\nL E V E L  S C O R E:" << hard_lvl_score;
	cout << "\nP L A Y E R  S C O R E: " << hard_player_score;
	cout << "\nT O T A L  M O V E S: " << hard_total_moves;
	cout << "\nR E M A I N I N G  M O V E S:" << hard_moves_remaining;
	hard_remove_character(hard);
	cout << "\n\n\t     0     1     2     3     4     5     6     7     8     9";
	cout << "\n\t  _____________________________________________________________\n";

	for (int i = 0; i < 10; i++)
	{
		cout << "\t" << i << " ";
		for (int j = 0; j < 10; j++)
		{
			cout << "|  " << hard[i][j] << "  ";
		}
		cout << "|\n\t  ________________________________________________________________\n";
	}
}

void main_menu(char easy[6][6], char med[8][8], char hard[10][10])
{ // MAIN MENU OF THE GAME
	system("cls");
	cout << "\t---------------------------------------------------------" << endl;
	cout << "\t|  W E L L C O M E   T O   C H A R A C T E R   S A G A  |\n";
	cout << "\t---------------------------------------------------------\n";
	cout << "\t|              1. G A M E  M O D E S                    |\n";
	cout << "\t|              2. G A M E  M A N U A L                  |\n";
	cout << "\t|              3. D E V E L O P E R S                   |\n";
	cout << "\t|              4. P L A Y I N G  T E C H N I Q U E      |\n";
	cout << "\t|              5. E X I T                               |\n";
	cout << "\t---------------------------------------------------------" << endl;

	cout << "\n---------------------- " << endl;
	cout << "|  Choose an option: |\n";
	cout << "---------------------- " << endl;
	int choice;
	cout << "\nChoice:";
	cin >> choice;

	switch (choice)
	{
	case 1:
		system("cls");

		mode_selection(easy, med, hard);

		break;
	case 2:
		game_manual();

		break;
	case 3:
		developers();
		break;
	case 4:
		playing_technique();

		break;
	case 5:
		exit();

		break;

	default:
		cout << "Invalid choice. Exiting...\n";
		break;
	}
}
void mode_selection(char easy[6][6], char med[8][8], char hard[10][10])
{
	// USER WILL SELECT MODE IN IT and the functions of that mode will be called
	cout << "\n\t------------------------ " << endl;
	cout << "\t|      Game modes      |";
	cout << "\n\t------------------------ " << endl;
	cout << "\n--> \"E\" OR \"e\":-";
	cout << "\n    ---------- ";
	cout << "\n\t\t E A S Y !";
	cout << "\n\t\t ---------";
	cout << "\n--> \"M\" OR \"m\":-";
	cout << "\n    ---------- ";
	cout << "\n\t\t M E D I U M !";
	cout << "\n\t\t -------------";
	cout << "\n--> \"H\" OR \"h\":-";
	cout << "\n    ---------- ";
	cout << "\n\t\t H A R D !";
	cout << "\n\t\t ---------";
	cout << "\n\nEnter character to choose mode:";
	char mode;
	cin >> mode;

	switch (mode)
	{
	case 'E':
	case 'e':
		system("cls");
		easy_manual();
		easy_initial_board(easy);
		easy_remove_character(easy);
		easy_update_board(easy, easy_lvl_score, easy_player_score, easy_total_moves, easy_moves_remaining);

		do
		{

			easy_player_turn(easy);

		} while (check);
		main_menu(easy, med, hard);

		break;
	case 'M':
	case 'm':
		system("cls");
		med_manual();
		med_initial_board(med);
		med_remove_character(med);
		med_update_board(med, med_lvl_score, med_player_score, med_total_moves, med_moves_remaining);

		do
		{

			med_player_turn(med);

		} while (check);
		main_menu(easy, med, hard);

		break;

	case 'H':
	case 'h':
		system("cls");
		hard_manual();
		hard_initial_board(hard);
		hard_remove_character(hard);
		hard_update_board(hard, hard_lvl_score, hard_player_score, hard_total_moves, hard_moves_remaining);

		do
		{

			hard_player_turn(hard);

		} while (check);
		main_menu(easy, med, hard);

		break;

	default:
		system("cls");
		cout << "Enter a valid command:";
		cout << "Press enter to continue";

		getch();
		mode_selection(easy, med, hard);
		break;
	}
}
void easy_remove_character(char easy[6][6]) // It will check if the 3 characters in row and column is same or not
{
	bool check;
	do
	{
		check = false;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				// check column

				if (easy[i][j] == easy[i + 1][j] && easy[i][j] == easy[i + 2][j])
				{
					easy[i][j] = static_cast<char>(32 + (rand() % 5) + 1);
					;
					easy[i + 1][j] = static_cast<char>(32 + (rand() % 5) + 1);
					;
					easy[i + 2][j] = static_cast<char>(32 + (rand() % 5) + 1);
					;
					check = true;
				}
				// check row
				if (easy[i][j] == easy[i][j + 1] && easy[i][j] == easy[i][j + 2])
				{
					easy[i][j] = static_cast<char>(32 + (rand() % 5) + 1);
					easy[i + 1][j] = static_cast<char>(32 + (rand() % 5) + 1);
					easy[i + 2][j] = static_cast<char>(32 + (rand() % 5) + 1);
					check = true;
				}
			}
		}
	} while (check);
}

void hard_move_valid(char hard[10][10], int x1, int x2, int y1, int y2, bool &check, int &hard_lvl_score, int &hard_player_score, int &hard_total_moves, int &hard_total_move1, int &hard_moves_remaining)
{
	int temp;
	// it will check if the move is only up or down and right or left otherwise characters will not swap in hard level
	hard_moves_remaining = --hard_total_moves1;
	bool no_match = true;

	if (hard[x1][y1] == hard[x2 + 1][y2] || hard[x1][y1] == hard[x2][y2 + 1] || hard[x1][y1] == hard[x2 - 1][y2] || hard[x1][y1] == hard[x2][y2 - 1])
	{

		temp = hard[x1][y1];
		hard[x1][y1] = hard[x2][y2];
		hard[x2][y2] = temp;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (hard[i][j] == hard[i][j + 1] && hard[i][j] == hard[i][j + 2])
				{
					hard[i][j] = static_cast<char>(32 + (rand() % 5) + 1);
					hard[i][j + 1] = static_cast<char>(32 + (rand() % 5) + 1);
					hard[i][j + 2] = static_cast<char>(32 + (rand() % 5) + 1);
					no_match = false;
					check = true;
					hard_player_score += 10;
					hard_level_checker(level, hard_lvl_score, hard_player_score, hard_total_moves, hard_moves_remaining);
					hard_update_board(hard, hard_lvl_score, hard_player_score, hard_total_moves, hard_moves_remaining);
					cout << "congrates! You have gain 10 points";
				}

				if (hard[i][j] == hard[i + 1][j] && hard[i][j] == hard[i + 2][j])
				{
					check = true;
					hard[i][j] = static_cast<char>(32 + (rand() % 5) + 1);
					hard[i + 1][j] = static_cast<char>(32 + (rand() % 5) + 1);
					hard[i + 2][j] = static_cast<char>(32 + (rand() % 5) + 1);

					no_match = false;
					hard_player_score += 10;
					hard_level_checker(level, hard_lvl_score, hard_player_score, hard_total_moves, hard_moves_remaining);
					hard_update_board(hard, hard_lvl_score, hard_player_score, hard_total_moves, hard_moves_remaining);
					cout << "\nCongrates! You have gain 10 points";
				}
			}
		}
		if (no_match)
		{
			check = true;
			hard[x2][y2] = hard[x1][x2];
			hard[x1][x2] = temp;
			hard_update_board(hard, hard_lvl_score, hard_player_score, hard_total_moves, hard_moves_remaining);

			cout << "\nINVALID MOVE";
			cout << "\nPLAY WISELY OR READ PLAYING TECHNIQUE";
		}
	}
	else
	{
		check = true;

		hard_update_board(hard, hard_lvl_score, hard_player_score, hard_total_moves, hard_moves_remaining);
		cout << "\nINVALID MOVE";
		cout << "\nPLAY WISELY OR READ PLAYING TECHNIQUE";
	}
}

void hard_remove_character(char hard[10][10]) // It will check if the 3 characters in row and column is same or not in hard level
{
	bool check;
	do
	{
		check = false;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				// check column

				if (hard[i][j] == hard[i + 1][j] && hard[i][j] == hard[i + 2][j])
				{
					hard[i][j] = static_cast<char>(32 + (rand() % 5) + 1);
					;
					hard[i + 1][j] = static_cast<char>(32 + (rand() % 5) + 1);
					;
					hard[i + 2][j] = static_cast<char>(32 + (rand() % 5) + 1);
					;
					check = true;
				}
				// check row
				if (hard[i][j] == hard[i][j + 1] && hard[i][j] == hard[i][j + 2])
				{
					hard[i][j] = static_cast<char>(32 + (rand() % 5) + 1);
					hard[i + 1][j] = static_cast<char>(32 + (rand() % 5) + 1);
					hard[i + 2][j] = static_cast<char>(32 + (rand() % 5) + 1);
					check = true;
				}
			}
		}
	} while (check);
}

void easy_move_valid(char easy[6][6], int x1, int x2, int y1, int y2, bool &check, int &easy_lvl_score, int &easy_player_score, int &easy_total_moves, int &easy_total_move1, int &easy_moves_remaining)
{
	int temp;
	// it will check if the move is only up or down and right or left otherwise characters will not swap in easy level
	easy_moves_remaining = --easy_total_moves1;
	bool no_match = true;

	if (easy[x1][y1] == easy[x2 + 1][y2] || easy[x1][y1] == easy[x2][y2 + 1] || easy[x1][y1] == easy[x2 - 1][y2] || easy[x1][y1] == easy[x2][y2 - 1])
	{

		temp = easy[x1][y1];
		easy[x1][y1] = easy[x2][y2];
		easy[x2][y2] = temp;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (easy[i][j] == easy[i][j + 1] && easy[i][j] == easy[i][j + 2])
				{
					easy[i][j] = static_cast<char>(32 + (rand() % 5) + 1);
					easy[i][j + 1] = static_cast<char>(32 + (rand() % 5) + 1);
					easy[i][j + 2] = static_cast<char>(32 + (rand() % 5) + 1);
					no_match = false;
					check = true;
					easy_player_score += 10;
					easy_level_checker(level, easy_lvl_score, easy_player_score, easy_total_moves, easy_moves_remaining);
					easy_update_board(easy, easy_lvl_score, easy_player_score, easy_total_moves, easy_moves_remaining);
					cout << "congrates! You have gain 10 points";
				}

				if (easy[i][j] == easy[i + 1][j] && easy[i][j] == easy[i + 2][j])
				{
					check = true;
					easy[i][j] = static_cast<char>(32 + (rand() % 5) + 1);
					easy[i + 1][j] = static_cast<char>(32 + (rand() % 5) + 1);
					easy[i + 2][j] = static_cast<char>(32 + (rand() % 5) + 1);

					no_match = false;
					easy_player_score += 10;
					easy_level_checker(level, easy_lvl_score, easy_player_score, easy_total_moves, easy_moves_remaining);
					easy_update_board(easy, easy_lvl_score, easy_player_score, easy_total_moves, easy_moves_remaining);
					cout << "\nCongrates! You have gain 10 points";
				}
			}
		}
		if (no_match)
		{
			check = true;
			easy[x2][y2] = easy[x1][x2];
			easy[x1][x2] = temp;
			easy_update_board(easy, easy_lvl_score, easy_player_score, easy_total_moves, easy_moves_remaining);

			cout << "\nINVALID MOVE";
			cout << "\nPLAY WISELY OR READ PLAYING TECHNIQUE";
		}
	}
	else
	{
		check = true;

		easy_update_board(easy, easy_lvl_score, easy_player_score, easy_total_moves, easy_moves_remaining);
		cout << "\nINVALID MOVE";
		cout << "\nPLAY WISELY OR READ PLAYING TECHNIQUE";
	}
}

void easy_level_checker(int &level, int &easy_lvl_score, int &easy_player_score, int &easy_total_moves, int &easy_moves_remaining)
{ // it will check the level
	if (level == 1)
	{
		if (easy_moves_remaining == 0 && easy_lvl_score > easy_player_score)
		{
			system("cls");
			cout << "\t\t|  GAME OVER   |\n";
			cout << "Do you want to play it again y/n:";
			char choice;
			cin >> choice;
			switch (choice)
			{
			case 'y':
			case 'Y':
				easy_player_score = 0;
				easy_moves_remaining = easy_total_moves1;
				break;
			case 'n':
			case 'N':
				main_menu(easy, med, hard);
				break;
			}
		}

		if (easy_player_score > easy_lvl_score)
		{
			system("cls");
			char next;
			cout << "Congrates! You have promoted to next level:)\n";
			cout << "Do you want to move to next level(y/n):";
			cin >> next;
			switch (next)
			{

			case 'y':
			case 'Y':
				level = 2;
				easy_lvl_score = 150;
				easy_total_moves = 25;
				easy_player_score = 0;
				easy_total_moves1 = easy_total_moves;

				easy_update_board(easy, easy_lvl_score, easy_player_score, easy_total_moves, easy_moves_remaining);

				easy_player_turn(easy);
				break;
			case 'n':
			case 'N':
				main_menu(easy, med, hard);
				break;
			}
		}
	}

	if (level == 2)
	{
		if (easy_moves_remaining == 0 && easy_lvl_score > easy_player_score)
		{
			system("cls");
			cout << "\t\t|  GAME OVER   |\n";
			cout << "Do you want to play it again y/n:";
			char choice;
			cin >> choice;
			switch (choice)
			{
			case 'y':
			case 'Y':
				easy_player_score = 0;
				easy_moves_remaining = easy_total_moves1;
				break;
			case 'n':
			case 'N':
				main_menu(easy, med, hard);
				break;
			}
		}

		if (easy_player_score > easy_lvl_score)
		{
			system("cls");
			char next;
			cout << "Congrates! You have promoted to next level:)\n";
			cout << "Do you want to move to next level(y/n):";
			cin >> next;
			switch (next)
			{

			case 'y':
			case 'Y':
				level = 3;

				easy_player_score = 0;
				easy_lvl_score = 200;
				easy_total_moves = 30;
				easy_total_moves1 = easy_total_moves;
				easy_update_board(easy, easy_lvl_score, easy_player_score, easy_total_moves, easy_moves_remaining);

				easy_player_turn(easy);
				break;
			case 'n':
			case 'N':
				main_menu(easy, med, hard);
				break;
			}
		}
	}
	if (level == 3)
	{

		if (easy_moves_remaining == 0 && easy_lvl_score > easy_player_score)
		{
			system("cls");
			cout << "\t\t|  GAME OVER   |\n";
			cout << "Do you want to play it again y/n:";
			char choice;
			cin >> choice;
			switch (choice)
			{
			case 'y':
			case 'Y':
				easy_player_score = 0;
				easy_moves_remaining = easy_total_moves1;
				break;
			case 'n':
			case 'N':
				main_menu(easy, med, hard);
				break;
			}
		}
		if (easy_player_score > easy_lvl_score)
		{
			system("cls");
			cout << "You have completed all the levels:)";
			getch();
			mode_selection(easy, med, hard);
		}
	}
}
void hard_level_checker(int &level, int &hard_lvl_score, int &hard_player_score, int &hard_total_moves, int &hard_moves_remaining)
{ // level checker for hard
	if (level == 1)
	{
		if (hard_moves_remaining == 0 && hard_lvl_score > hard_player_score)
		{
			system("cls");
			cout << "\t\t|  GAME OVER   |\n";
			cout << "Do you want to play it again y/n:";
			char choice;
			cin >> choice;
			switch (choice)
			{
			case 'y':
			case 'Y':
				hard_player_score = 0;
				hard_moves_remaining = hard_total_moves1;
				break;
			case 'n':
			case 'N':
				main_menu(easy, med, hard);
				break;
			}
		}

		if (hard_player_score > hard_lvl_score)
		{
			system("cls");
			char next;
			cout << "CongratesYou have promoted to next level:)\n";
			cout << "Do you want to move to next level(y/n):";
			cin >> next;
			switch (next)
			{

			case 'y':
			case 'Y':
				level = 2;
				hard_lvl_score = 150;
				hard_total_moves = 20;
				hard_player_score = 0;
				hard_total_moves1 = hard_total_moves;

				hard_update_board(hard, hard_lvl_score, hard_player_score, hard_total_moves, hard_moves_remaining);

				hard_player_turn(hard);
				break;
			case 'n':
			case 'N':
				main_menu(easy, med, hard);
				break;
			}
		}
	}

	if (level == 2)
	{
		if (hard_moves_remaining == 0 && hard_lvl_score > hard_player_score)
		{
			system("cls");
			cout << "\t\t|  GAME OVER   |\n";
			cout << "Do you want to play it again y/n:";
			char choice;
			cin >> choice;
			switch (choice)
			{
			case 'y':
			case 'Y':
				hard_player_score = 0;
				hard_moves_remaining = hard_total_moves1;
				break;
			case 'n':
			case 'N':
				main_menu(easy, med, hard);
				break;
			}
		}

		if (hard_player_score > hard_lvl_score)
		{
			system("cls");
			char next;
			cout << "Congrates! You have promoted to next level:)\n";
			cout << "Do you want to move to next level(y/n):";
			cin >> next;
			switch (next)
			{

			case 'y':
			case 'Y':
				level = 3;

				hard_player_score = 0;
				hard_lvl_score = 200;
				hard_total_moves = 25;
				hard_total_moves1 = hard_total_moves;
				hard_update_board(hard, hard_lvl_score, hard_player_score, hard_total_moves, hard_moves_remaining);

				hard_player_turn(hard);
				break;
			case 'n':
			case 'N':
				main_menu(easy, med, hard);
				break;
			}
		}
	}
	if (level == 3)
	{

		if (hard_moves_remaining == 0 && hard_lvl_score > hard_player_score)
		{
			system("cls");
			cout << "\t\t|  GAME OVER   |\n";
			cout << "Do you want to play it again y/n:";
			char choice;
			cin >> choice;
			switch (choice)
			{
			case 'y':
			case 'Y':
				hard_player_score = 0;
				hard_moves_remaining = hard_total_moves1;
				break;
			case 'n':
			case 'N':
				main_menu(easy, med, hard);
				break;
			}
		}
		if (hard_player_score > hard_lvl_score)
		{
			system("cls");
			cout << "You have completed all the levels:)";
			getch();
			mode_selection(easy, med, hard);
		}
	}
}

void med_update_board(char med[8][8], int &med_lvl_score, int &med_player_score, int &med_total_moves, int &med_moves_remaining)
{ // updates the scorecard etc for medium
	system("cls");
	system("color F6");
	cout << "\t\t---------------------------------------" << endl;
	cout << "\t\t|     C H A R A C T E R   S A G A     |\n";
	cout << "\t\t---------------------------------------\n";
	cout << "M O D E :- MEDIUM\n\n";
	if (med_lvl_score == 100)
	{
		cout << "\t\t----------------\n";
		cout << "\t\t| L E V E L  1 |\n";
		cout << "\t\t----------------\n";
	}
	if (med_lvl_score == 150)
	{
		cout << "\t\t----------------\n";
		cout << "\t\t| L E V E L  2 |\n";
		cout << "\t\t----------------\n";
	}
	if (med_lvl_score == 200)
	{
		cout << "\t\t----------------\n";
		cout << "\t\t| L E V E L  3 |\n";
		cout << "\t\t----------------\n";
	}
	cout << "\nL E V E L  S C O R E:" << med_lvl_score;
	cout << "\nP L A Y E R  S C O R E: " << med_player_score;
	cout << "\nT O T A L  M O V E S: " << med_total_moves;
	cout << "\nR E M A I N I N G  M O V E S:" << med_moves_remaining;
	med_remove_character(med);
	cout << "\n\n\t     0     1     2     3     4     5     6     7";
	cout << "\n\t  _________________________________________________\n";

	for (int i = 0; i < 8; i++)
	{
		cout << "\t" << i << " ";
		for (int j = 0; j < 8; j++)
		{
			cout << "|  " << med[i][j] << "  ";
		}
		cout << "|\n\t  ___________________________________________________\n";
	}
}

void med_player_turn(char med[8][8])
{ // gets the index no from user to swap in medium level
	int x1, x2, y1, y2;
	cout << "\nMake your move..\n";
	cout << "Enter index no of character to replace :\n";
	cout << "ENTER ROW :";
	cin >> x1;
	cout << "ENTER COLUMN :";
	cin >> y1;
	cout << "\nEnter index no of character to replace with :\n";
	cout << "ENTER ROW :";
	cin >> x2;
	cout << "ENTER COLUMN :";
	cin >> y2;

	med_move_valid(med, x1, x2, y1, y2, check, med_lvl_score, med_player_score, med_total_moves, med_total_moves1, med_moves_remaining);

	getch();
}

void med_remove_character(char med[8][8])
{ // checks the rows and colums if any 3 characters are consequently same
	bool check;
	do
	{
		check = false;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				// check column

				if (med[i][j] == med[i + 1][j] && med[i][j] == med[i + 2][j])
				{
					med[i][j] = static_cast<char>(32 + (rand() % 5) + 1);
					;
					med[i + 1][j] = static_cast<char>(32 + (rand() % 5) + 1);
					;
					med[i + 2][j] = static_cast<char>(32 + (rand() % 5) + 1);
					;
					check = true;
				}
				// check row
				if (med[i][j] == med[i][j + 1] && med[i][j] == med[i][j + 2])
				{
					med[i][j] = static_cast<char>(32 + (rand() % 5) + 1);
					med[i + 1][j] = static_cast<char>(32 + (rand() % 5) + 1);
					med[i + 2][j] = static_cast<char>(32 + (rand() % 5) + 1);
					check = true;
				}
			}
		}
	} while (check);
}

void med_initial_board(char med[8][8]) // initial board for medium level
{
	system("cls");
	system("color F6");
	cout << "\t\t---------------------------------------" << endl;
	cout << "\t\t|     C H A R A C T E R   S A G A     |\n";
	cout << "\t\t---------------------------------------\n";
	cout << "M O D E :- med\n\n";
	cout << "\t\t--------------\n";
	cout << "\t\t| L E V E L  |\n";
	cout << "\t\t--------------\n";
	cout << "\nL E V E L  S C O R E:...";
	cout << "\nP L A Y E R  S C O R E:... ";
	cout << "\nT O T A L  M O V E S:... ";
	cout << "\nR E M A I N I N G  M O V E S:...";
	cout << "\n\n\t     0     1     2     3     4     5     6     7";
	cout << "\n\t  _______________________________________________\n";
	for (int i = 0; i < 8; i++)
	{
		cout << "\t" << i << " ";
		for (int j = 0; j < 8; j++)
		{
			cout << "|  " << med[i][j] << "  ";
		}
		cout << "|\n\t  __________________________________________________\n";
	}
	cout << "Press enter to continue..";
	getch();
}

void med_level_checker(int &level, int &med_lvl_score, int &med_player_score, int &med_total_moves, int &med_moves_remaining)
{ // checks the level in medium
	if (level == 1)
	{
		if (med_moves_remaining == 0 && med_lvl_score > med_player_score)
		{
			system("cls");
			cout << "\t\t|  GAME OVER   |\n";
			cout << "Do you want to play it again y/n:";
			char choice;
			cin >> choice;
			switch (choice)
			{
			case 'y':
			case 'Y':
				med_player_score = 0;
				med_moves_remaining = med_total_moves1;
				break;
			case 'n':
			case 'N':
				main_menu(easy, med, hard);
				break;
			}
		}

		if (med_player_score > med_lvl_score)
		{
			system("cls");
			char next;
			cout << "CongratesYou have promoted to next level:)\n";
			cout << "Do you want to move to next level(y/n):";
			cin >> next;
			switch (next)
			{

			case 'y':
			case 'Y':
				level = 2;
				med_lvl_score = 150;
				med_total_moves = 23;
				med_player_score = 0;
				med_total_moves1 = med_total_moves;

				med_update_board(med, med_lvl_score, med_player_score, med_total_moves, med_moves_remaining);

				med_player_turn(med);
				break;
			case 'n':
			case 'N':
				main_menu(easy, med, hard);
				break;
			}
		}
	}

	if (level == 2)
	{
		if (med_moves_remaining == 0 && med_lvl_score > med_player_score)
		{
			system("cls");
			cout << "\t\t|  GAME OVER   |\n";
			cout << "Do you want to play it again y/n:";
			char choice;
			cin >> choice;
			switch (choice)
			{
			case 'y':
			case 'Y':
				med_player_score = 0;
				med_moves_remaining = med_total_moves1;
				break;
			case 'n':
			case 'N':
				main_menu(easy, med, hard);
				break;
			}
		}

		if (med_player_score > med_lvl_score)
		{
			system("cls");
			char next;
			cout << "Congrates! You have promoted to next level:)\n";
			cout << "Do you want to move to next level(y/n):";
			cin >> next;
			switch (next)
			{

			case 'y':
			case 'Y':
				level = 3;

				med_player_score = 0;
				med_lvl_score = 200;
				med_total_moves = 28;
				med_total_moves1 = med_total_moves;
				med_update_board(med, med_lvl_score, med_player_score, med_total_moves, med_moves_remaining);

				med_player_turn(med);
				break;
			case 'n':
			case 'N':
				main_menu(easy, med, hard);
				break;
			}
		}
	}
	if (level == 3)
	{

		if (med_moves_remaining == 0 && med_lvl_score > med_player_score)
		{
			system("cls");
			cout << "\t\t|  GAME OVER   |\n";
			cout << "Do you want to play it again y/n:";
			char choice;
			cin >> choice;
			switch (choice)
			{
			case 'y':
			case 'Y':
				med_player_score = 0;
				med_moves_remaining = med_total_moves1;
				break;
			case 'n':
			case 'N':
				main_menu(easy, med, hard);
				break;
			}
		}
		if (med_player_score > med_lvl_score)
		{
			system("cls");
			cout << "You have completed all the levels:)";
			getch();
			mode_selection(easy, med, hard);
		}
	}
}
void med_move_valid(char med[8][8], int x1, int x2, int y1, int y2, bool &check, int &med_lvl_score, int &med_player_score, int &med_total_moves, int &med_total_move1, int &med_moves_remaining)
{
	int temp; // checks if the move is up or down and right or left only otherwise dont swipe

	med_moves_remaining = --med_total_moves1;
	bool no_match = true;

	if (med[x1][y1] == med[x2 + 1][y2] || med[x1][y1] == med[x2][y2 + 1] || med[x1][y1] == med[x2 - 1][y2] || med[x1][y1] == med[x2][y2 - 1])
	{

		temp = med[x1][y1];
		med[x1][y1] = med[x2][y2];
		med[x2][y2] = temp;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (med[i][j] == med[i][j + 1] && med[i][j] == med[i][j + 2])
				{
					med[i][j] = static_cast<char>(32 + (rand() % 5) + 1);
					med[i][j + 1] = static_cast<char>(32 + (rand() % 5) + 1);
					med[i][j + 2] = static_cast<char>(32 + (rand() % 5) + 1);
					no_match = false;
					check = true;
					med_player_score += 10;
					med_level_checker(level, med_lvl_score, med_player_score, med_total_moves, med_moves_remaining);
					med_update_board(med, med_lvl_score, med_player_score, med_total_moves, med_moves_remaining);
					cout << "congrates! You have gain 10 points";
				}

				if (med[i][j] == med[i + 1][j] && med[i][j] == med[i + 2][j])
				{
					check = true;
					med[i][j] = static_cast<char>(32 + (rand() % 5) + 1);
					med[i + 1][j] = static_cast<char>(32 + (rand() % 5) + 1);
					med[i + 2][j] = static_cast<char>(32 + (rand() % 5) + 1);

					no_match = false;
					med_player_score += 10;
					med_level_checker(level, med_lvl_score, med_player_score, med_total_moves, med_moves_remaining);
					med_update_board(med, med_lvl_score, med_player_score, med_total_moves, med_moves_remaining);
					cout << "\nCongrates! You have gain 10 points";
				}
			}
		}
		if (no_match)
		{
			check = true;
			med[x2][y2] = med[x1][x2];
			med[x1][x2] = temp;
			med_update_board(med, med_lvl_score, med_player_score, med_total_moves, med_moves_remaining);

			cout << "\nINVALID MOVE";
			cout << "\nPLAY WISELY OR READ PLAYING TECHNIQUE";
		}
	}
	else
	{
		check = true;

		med_update_board(med, med_lvl_score, med_player_score, med_total_moves, med_moves_remaining);
		cout << "\nINVALID MOVE";
		cout << "\nPLAY WISELY OR READ PLAYING TECHNIQUE";
	}
}
void game_manual() // MANUAL OF GAME
{
	system("cls");
	cout << "                     | GAME MANUAL  | \n\n";

	cout << "                  | IT HAS THREE MODES |  \n";
	cout << "         1.EASY \n";
	cout << "         2.MEDIUM \n";
	cout << "         3.HARD   \n\n";
	cout << " | EASY:-                                                 |\n";
	cout << " | EASY MODE HAS A 6 BY 6 Array                           |\n";
	cout << " | EASY MODE HAS 3 DIFFERENT LEVELS                       |\n";
	cout << " | EASY LEVEL CONSISTS OF A TARGET SCORES OF              |\n";
	cout << " |  1: 100                                                |\n";
	cout << " |  2: 150                                                |\n";
	cout << " |  3: 200                                                |\n";
	cout << " | IN EASY LEVEL YOU GET 20 MODES OF CHARACTER SWAPPING   | \n";
	cout << " | IN EACH LEVEL YOU GET 3 MOVES LESS                     |\n";
	cout << "\n | MEDIUM:-                                               |\n";
	cout << " | MEDIUM MODE IS QUITE DIFFERENT                         |\n";
	cout << " | MEDIUM MODE HAS An 8 BY 8 Array                        |\n";
	cout << " | MEDIUM MODE HAS 3 DIFFERENT LEVELS                     |\n";
	cout << " | MEDIUM LEVEL CONSISTS OF A TARGET SCORES OF            |\n";
	cout << " |  1: 100                                                |\n";
	cout << " |  2: 150                                                |\n";
	cout << " |  3: 200                                                |\n";
	cout << " | IN MEDIUM LEVEL YOU GET 17 MOVES OF CHARACTER SWAPPING | \n";
	cout << " | IN EACH LEVEL YOU GET 3 MOVES LESS                     |\n";
	cout << "\n | HARD:-                                                 |\n";
	cout << " | HARD MODE IS QUITE DIFFERENT FROM EASY AND MEDIUM      |\n";
	cout << " | HARD MODE HAS An 10 BY 10 Array                        |\n";
	cout << " | HARD MODE HAS 3 DIFFERENT LEVELS                       |\n";
	cout << " | HARD LEVEL CONSISTS OF A TARGET SCORES OF              |\n";
	cout << " |  1: 100                                                |\n";
	cout << " |  2: 150                                                |\n";
	cout << " |  3: 200                                                |\n";
	cout << " | IN MEDIUM LEVEL YOU GET 14 MOVES OF CHARACTER SWAPPING | \n";
	cout << " | IN EACH LEVEL YOU GET 3 MOVES LESS                     |\n";
	cout << "\n\nIf you have read Game manual  press enterto return to main menu:";

	getch();
	main_menu(easy, med, hard);
}
void easy_manual() // manual for easy level
{
	system("cls");
	cout << " EASY:-\n\n";
	cout << " | EASY MODE HAS A 6 BY 6 Array                         |\n";
	cout << " | EASY MODE HAS 3 DIFFERENT LEVELS                     |\n";
	cout << " | EASY LEVEL CONSISTS OF A TARGET SCORES OF            |\n";
	cout << " |  1: 100                                              |\n";
	cout << " |  2: 150                                              |\n";
	cout << " |  3: 200                                              |\n";
	cout << " | IN EASY LEVEL YOU GET 20 MOVES OF CHARACTER SWAPPING | \n";
	cout << " | IN EACH LEVEL YOU GET 3 MOVES LESS                   |\n";
	cout << "Press enter to continue:";
	getch();
}
void med_manual() // medium manual
{
	system("cls");
	cout << " MEDIUM:-\n\n";
	cout << " | MEDIUM MODE IS QUITE DIFFERENT                         |\n";
	cout << " | MEDIUM MODE HAS An 8 BY 8 Array                        |\n";
	cout << " | MEDIUM MODE HAS 3 DIFFERENT LEVELS                     |\n";
	cout << " | MEDIUM LEVEL CONSISTS OF A TARGET SCORES OF            |\n";
	cout << " |  1: 100                                                |\n";
	cout << " |  2: 150                                                |\n";
	cout << " |  3: 200                                                |\n";
	cout << " | IN MEDIUM LEVEL YOU GET 17 MOVES OF CHARACTER SWAPPING | \n";
	cout << " | IN EACH LEVEL YOU GET 3 MOVES LESS                     |\n";
	cout << "Press erter to continue:";
	getch();
}
void hard_manual() // manualfor hard
{
	system("cls");

	cout << " HARD:-\n\n";
	cout << " | HARD MODE IS QUITE DIFFERENT FROM EASY AND MEDIUM      |\n";
	cout << " | HARD MODE HAS An 10 BY 10 Array                        |\n";
	cout << " | HARD MODE HAS 3 DIFFERENT LEVELS                       |\n";
	cout << " | HARD LEVEL CONSISTS OF A TARGET SCORES OF              |\n";
	cout << " |  1: 100                                                |\n";
	cout << " |  2: 150                                                |\n";
	cout << " |  3: 200                                                |\n";
	cout << " | IN MEDIUM LEVEL YOU GET 14 MOVES OF CHARACTER SWAPPING | \n";
	cout << " | IN EACH LEVEL YOU GET 3 MOVES LESS                     |\n";

	cout << "Press erter to continue:";
	getch();
}

void playing_technique() // how to play the game
{

	system("cls");

	cout << "                  | PLAYING TECHNIQUES |\n";
	cout << " | THIS GAME IS PLAYED WITH THE HELP OF CHANGING INDEXES                  |\n";
	cout << " | YOU HAVE TO DO THE FOLLOWING STEPS                                     |\n";
	cout << " | ENTER THE SECOND INDEX TO COMBINE WITH THE FIRST                       |\n ";
	cout << " | REPLACE THE CHARACTER AT THE FIRST INDEX WITH A NEW COMBINED CHARACTER |";
	cout << "\n\nSAMPLE:\n";
	cout << "   0   1  \n";
	cout << "  ---------\n";
	cout << "0 | & |   |\n";
	cout << "1 | % | & |\n";
	cout << "2 | & |   |\n";
	cout << "  ---------\n";
	cout << "  THE FIRST INDEX WILL HOLD THE CHARACTER \n";
	cout << "As &'s index is 1,1 so type 1 ,1\n";
	cout << " | ENTER THE SECOND INDEX TO COMBINE WITH THE FIRST \n ";
	cout << "And %'s index is 1,0 so type this\n";
	cout << "   0   1  \n";
	cout << "  ---------\n";
	cout << "0 | & |   |\n";
	cout << "1 | & | % | \n";
	cout << "2 | & |   | \n";
	cout << "  ---------\n";
	cout << "You will gain 10 points\n";
	cout << "If you get it press enter:";
	getch();
	main_menu(easy, med, hard);
}
void developers()
{

	system("cls");
	cout << "\t\t  ------------------------\n";
	cout << "\t\t  |  D E V E L O P E R  | \n";
	cout << "\t\t  ------------------------\n";

	cout << "\t\t-------------------------------\n";
	cout << "\t\t|      ABDULLAH TAHIR         |\n";
	cout << "\t\t-------------------------------\n";
	getch();
	main_menu(easy, med, hard);
}
void exit() // exit function to exit the game
{
	system("cls");
	cout << "\t\t----------------------\n";
	cout << "\t\t|    Are You sure    |\n";
	cout << "\t\t----------------------\n";
	cout << "\t\t|         ||         |\n";
	cout << "\t\t|  yes(y) ||  no(n)  |\n";
	cout << "\t\t|         ||         |\n";
	cout << "\t\t----------------------\n";
	cout << "Choice is yours:";
	char choose;
	cin >> choose;
	switch (choose)
	{
	case 'y':
	case 'Y':
		cout << "Very disappointing:";

		break;
	case 'n':
	case 'N':
		main_menu(easy, med, hard);
		break;
	}
}
