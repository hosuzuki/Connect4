#include "ft_connect4.h"

int ft_update_map(char map[10][9], int winner, int c)
{
	int i;
	
	for (i = 7; i > 0; i--)
	{
		if (map[i][c] == ' ')
		{
			if (winner % 2 != 0)
			{
				map[i][c] = 'o';
				return (CONTINUE);
			}
			else
			{
				map[i][c] = 'x';
				return (CONTINUE);
			}
		}
	}
	return (NOTVALID);
}

void ft_print_map(char map[10][9])
{
	for (int i = 0; i < 10; i++)
	{
	//	for(int j = 0; i < 9; j++)
		printf("%s\n", map[i]);
	//	printf("%c", '\n');
	}
}

void ft_generate_map(char map[10][9])
{
	int i;
	int j;

	map[0][0] = '+';
	map[0][7] = '+';
	map[8][0] = '+';
	map[8][7] = '+';
	for (i = 1; i < 8; i++)
	{
		map[i][0] = '|';
		map[i][7] = '|';	
	}
	for (j = 1; j < 7; j++)
	{
		map[0][j] = '-';
		map[8][j] = '-';	
	}
	for (i = 1; i < 8; i++)
	{
		for (j = 1; j < 7; j++)
			map[i][j] = ' ';
	}
	for (j = 1; j < 7; j++)
		map[9][j] = j + '0';
	map[9][0] = ' ';
	map[9][7] = ' ';
	for (i = 0; i < 10; i++)
		map[i][8] = '\0';
	ft_print_map(map);
	printf("Enter a number. (1 ~ 6)\n");
}

/*int ft_validation(void)
{
	return (SETTLEMENT);
}
*/
int	main(void)
{
	int	status;
	int	winner;
	int	c;
	char	map[10][9];

	status = 0;
	winner = 0;
	ft_generate_map(map);
	while (1)
	{
		winner++;
		c = ft_player_input(map, winner);
//		status = ft_validation();
		status = ft_validation(map, winner, c);
		if (status == TIE)
		{
			printf("The game was a tie.\n");
			return (0);
		}
		if (status == NOTVALID)
		{
			printf("Not valid. Please enter a valid number.\n");
			winner--;
		}
		if (status == SETTLEMENT)
		{
			ft_print_map(map);
			if (winner % 2 == 0)
				printf("PLAYER 2 won!!\n");
			else
				printf("PLAYER 1 won!!\n");
			return (1);
		}
		if (status == CONTINUE)
			ft_print_map(map);
		//return (ft_print_winner())
//		else if (status == TIE)
//			return (ft_print_tie());
//		map = ft_generate_map();
	}
	return (0);
}
