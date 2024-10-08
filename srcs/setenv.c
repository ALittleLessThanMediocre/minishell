/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 16:57:42 by dodendaa          #+#    #+#             */
/*   Updated: 2020/06/04 08:53:23 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**		People like to feel involved so set env allows
**		you to say "thats my variable in the environment"
**		setenv will go into the env variable and set a new one
**		or it will update an existing one 
*/

int		set_env(char **cmd)
{
	int		i;
	char	**temp;

	i = 0;
	// too few args 
	if (cmd[1] == NULL || cmd[2] == NULL)
		return (error_params(cmd, -1));
	// too many arguments
	if (cmd[3])
		return (error_params(cmd, 1));

	// if we successfully update the values free and 
	// return to indicate all is good 
	if (update_env(cmd[1], cmd[2]))
	{ 
		array_free(cmd);
		return (1);
	}
	
	//try to think of a way to do all of this on one method
	while (global_env[i])
		i++;

	i++;
	temp = (char **)malloc((sizeof(char *) * (i + 1)));
	temp[i] = 0;
	
	return (ft_insert_var(temp, cmd));
}