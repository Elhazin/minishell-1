/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:46:57 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/02/01 13:44:52 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H


# include "../parser/get_next_line/get_next_line.h"
# include <readline/readline.h>
# include <readline/history.h>
# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"

#define	CURRENT_CONDITION str[i] == '"' || str[i] == '\'' \
			|| str[i] == '<' || str[i] == '>' \
			|| str[i] == ' '

#define NEXT_CONDITIN str[i + 1] == '"' || str[i + 1] == '\'' \
			|| str[i + 1] == '<' || str[i + 1] == '>'\
			|| str[i + 1] == ' '

#define LEFT_REDIRECT ">"
#define RIGHT_REDIRECT "<"
#define DOUBLE_QUOTES "\""
#define SINGLE_QUOTES "'"
#define SPACE " "

typedef struct lexer_s
{
	char	type;
	char	*content;
}	t_lexer;


typedef	struct s_cmd_node
{
	t_lexer				*lexer;
	size_t				lexer_size;
	char				**env;
	struct s_cmd_node	*next;
}	t_cmd_node;



void		*ft_memset(void *b, int c, size_t len);
void		*ft_calloc(size_t count, size_t size);
void		tab_free(char **tab);
char		**ft_split(char const *s, char *sep);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);
void		add_back_lst(t_cmd_node **head, t_cmd_node *node);
void		add_front_lst(t_cmd_node **head, t_cmd_node *node);
void		lst_clear(t_cmd_node **head);
t_cmd_node	*create_node(t_cmd_node **head);
int			ft_strcmp(char *s1, char *s2);
void		init_lexer_node(t_cmd_node **head, char *line, char **env);

#endif