#include "ft_connect4.h"


int ft_validate_vertical(char map[10][9], char *four, int winner, int c)
{
	char	str[8];
	int	i;

	for (i = 1; i < 8; i++)
		str[i - 1] = map[i][c];
	str[i -1] = '\0';
	if (ft_strnstr(str, four, 7))
		return (SETTLEMENT);
	return (CONTINUE);
}

int ft_validate_horizontal(char map[10][9], char *four, int winner, int c)
{
	char	str[7];
	int	i;
	int j;

	i = 1;
	while (map[i][c] == '|' && i < 8)
		i++;
	for (j = 1; j < 7; j++)
		str[j - 1] = map[i][j];
	str[j - 1] = '\0';
	if (ft_strnstr(str, four, 7))
		return (SETTLEMENT);
	return (CONTINUE);
}

int ft_validate_upperright(char map[10][9], char *four, int winner, int c)
{
	char	str[7];
	int	i;
	int j;
	int n;

	i = 1;
	while (map[i][c] == '|' && i < 8)
		i++;
	j = 0;
	while (1 < i - j && c + j < 6)
		j++;
	n = 0;
	while (i - j < 8 && 0 < c + j)
	{
		str[n] = map[i - j][c + j];
		n++;
		j--;
	}
	while (n < 7)
		str[n++] = '\0';
	if (ft_strnstr(str, four, 7))
		return (SETTLEMENT);
	return (CONTINUE);
}

int ft_validate_lowerright(char map[10][9], char *four, int winner, int c)
{
	char	str[7];
	int	i;
	int	j;
	int	n;

	i = 1;
	while (map[i][c] == '|' && i < 8)
		i++;
	j = 0;
	while (1 < i + j && 1 < c + j)
		j--;
	n = 0;
	while (i + j < 8 && c + j < 7)
	{
		str[n] = map[i + j][c + j];
		n++;
		j++;
	}
	while (n < 7)
		str[n++] = '\0';
	printf("str: %s\n", str);
	if (ft_strnstr(str, four, 7))
		return (SETTLEMENT);
	return (CONTINUE);
}

int ft_validation(char map[10][9], int winner, int c)
{
	int	status;
	char	*four;

	if (winner % 2 != 0)
		four = "oooo";
	else
		four = "xxxx";
	status = ft_update_map(map,  winner, c);
	if (status == NOTVALID)
		return (NOTVALID);
	if (ft_validate_vertical(map, four, winner, c) == SETTLEMENT)
		return (SETTLEMENT);
	if (ft_validate_horizontal(map, four, winner, c) == SETTLEMENT)
		return (SETTLEMENT);
	if (ft_validate_upperright(map, four, winner, c) == SETTLEMENT)
		return (SETTLEMENT);
	if (ft_validate_lowerright(map, four, winner, c) == SETTLEMENT)
		return (SETTLEMENT);
//	if (ft_isspace(map, winner) == FULL)
//		return (TIE);
	return (CONTINUE);
}

