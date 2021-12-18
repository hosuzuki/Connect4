#ifndef FT_CONNECT4_H
# define FT_CONNECT4_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define CONTINUE 1
# define SETTLEMENT -1
# define TIE 0
# define FULL 2
# define NOTFULL 3
# define NOTVALID 4

int ft_player_input(int winner);
int ft_validation(char map[10][9], int winner, int c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(char *haystack, const char *needle, size_t len);
int ft_update_map(char map[10][9], int winner, int c);
int ft_isspace(char map[10][9], int winner);

#endif
