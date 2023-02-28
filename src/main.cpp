/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:24:28 by owalsh            #+#    #+#             */
/*   Updated: 2023/02/28 18:18:52 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "irc.h"
# include "Server.hpp"

int main(int argc, char **argv)
{
	Server server;
	
	if (argc != 3)
		return ft_error(ERR_ARGC);
	if (server.createServer(argv[1], argv[2]))
		return 1;
	
	return 0;
}
