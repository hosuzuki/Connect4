#include "ft_connect4.h"

int ft_validate_vertical(char map[10][9], char *four, int input)
{
	char	str[8];
	int	i;

	for (i = 1; i < 8; i++)
		str[i - 1] = map[i][input];
	str[i -1] = '\0';
	if (ft_strnstr(str, four, 7))
		return (SETTLEMENT);
	return (CONTINUE);
}

int ft_validate_horizontal(char map[10][9], char *four, int input)
{
	char	str[7];
	int	i;
	int j;

	i = 1;
	while (map[i][input] == '|' && i < 8)
		i++;
	for (j = 1; j < 7; j++)
		str[j - 1] = map[i][j];
	str[j - 1] = '\0';
	if (ft_strnstr(str, four, 7))
		return (SETTLEMENT);
	return (CONTINUE);
}

int ft_validate_upperright(char map[10][9], char *four, int input)
{
	char	str[7];
	int	i;
	int j;
	int index;

	i = 1;
	while (map[i][input] == '|' && i < 8)
		i++;
	j = 0;
	while (1 < i - j && input + j < 6)
		j++;
	index = 0;
	while (i - j < 8 && 0 < input + j)
	{
		str[index] = map[i - j][input + j];
		index++;
		j--;
	}
	while (index < 7)
		str[index++] = '\0';
	if (ft_strnstr(str, four, 7))
		return (SETTLEMENT);
	return (CONTINUE);
}

int ft_validate_lowerright(char map[10][9], char *four, int input)
{
	char	str[7];
	int	i;
	int	j;
	int	index;

	i = 1;
	while (map[i][input] == '|' && i < 8)
		i++;
	j = 0;
	while (1 < i + j && 1 < input + j)
		j--;
	index = 0;
	while (i + j < 8 && input + j < 7)
	{
		str[index] = map[i + j][input + j];
		index++;
		j++;
	}
	while (index < 7)
		str[index++] = '\0';
	if (ft_strnstr(str, four, 7))
		return (SETTLEMENT);
	return (CONTINUE);
}

int ft_validation(char map[10][9], int winner, int input)
{
	int	status;
	char	*four;

	if (winner % 2 != 0)
		four = "oooo";
	else
		four = "xxxx";
	status = ft_update_map(map,  winner, input);
	if (status == NOTVALID)
		return (NOTVALID);
	if (ft_validate_vertical(map, four, input) == SETTLEMENT)
		return (SETTLEMENT);
	if (ft_validate_horizontal(map, four, input) == SETTLEMENT)
		return (SETTLEMENT);
	if (ft_validate_upperright(map, four, input) == SETTLEMENT)
		return (SETTLEMENT);
	if (ft_validate_lowerright(map, four, input) == SETTLEMENT)
		return (SETTLEMENT);
	if (ft_isspace(map) == FULL)
		return (TIE);
	return (CONTINUE);
}

