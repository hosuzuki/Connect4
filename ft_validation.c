#include "ft_connect4.h"

int ft_player_input(char map[10][9], int winner)
{
	int c;

	if (winner % 2 != 0)
	{
		while (1)
		{
			printf("PLAYER 1 >> ");
			scanf("%d", &c);
			if (1 <= c  && c <= 6)	
				break;
			else
				printf("Wrong input. Please enter a number. (1 ~ 6)\n");
		}
	}
	else
	{
		while (1)
		{
			printf("PLAYER 2 >> ");
			scanf("%d", &c);
			if (1 <= c  && c <= 6)	
				break;
			else
				printf("Wrong input. Please enter a number. (1 ~ 6)\n");
		}
	}
	return (c);
}

int ft_validate_vertical(char map[10][9], int winner, int c)
{
	char	*four;
	char	*str;
	int	i;

	for (i = 1; i < 8; i++)
		str[i - 1] = map[i][c];
	str[i - 1] = '\0';
	if (winner % 2 != 0)
	{
		four = "oooo";
		if (ft_strnstr(str, four, 7))
			return (SETTLEMENT);
	}
	else
	{
		four = "xxxx";
		if (ft_strnstr(str, four, 7))
			return (SETTLEMENT);
	}
	return (CONTINUE);
}

int ft_validate_horizontal(void)
{
	return (CONTINUE);
}

int ft_validate_upperright(void)
{
	return (CONTINUE);
}

int ft_validate_lowerright(void)
{
	return (CONTINUE);
}

int ft_validation(char map[10][9], int winner, int c)
{
	int status;
	
	status = ft_update_map(map, winner, c);
	if (status == NOTVALID)
		return (NOTVALID);
	if (ft_validate_vertical(map, winner, c) == SETTLEMENT)
		return (SETTLEMENT);
	if (ft_validate_horizontal() == SETTLEMENT)
		return (SETTLEMENT);
	if (ft_validate_upperright() == SETTLEMENT)
		return (SETTLEMENT);
	if (ft_validate_lowerright() == SETTLEMENT)
		return (SETTLEMENT);
//	if (ft_isspace(map, winner) == FULL)
//		return (TIE);
	return (CONTINUE);
}

