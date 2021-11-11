/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rft_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 10:23:35 by cchelste          #+#    #+#             */
/*   Updated: 2021/09/04 10:23:37 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_code;

void	rft_pwd(void)
{
	char	pwd[2000];

	getcwd(pwd, 2000);
	ft_putstr_fd(pwd, 1);
	write(1, "\n", 1);
	g_code = 0;
}
