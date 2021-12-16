#include "ft_connect4.h"

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
}

int ft_validation(void)
{
	return (SETTLEMENT);
}

int	main(void)
{
	int status;
	int winner;
	char	map[10][9];

	status = 0;
	winner = 0;
	ft_generate_map(map);
	while (1)
	{
		status = ft_validation();
		if (status == SETTLEMENT)
			return (1);
		//return (ft_print_winner())
//		else if (status == TIE)
//			return (ft_print_tie());
//		map = ft_generate_map();
	}
	return (0);
}
