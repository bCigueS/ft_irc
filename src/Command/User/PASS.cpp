/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PASS.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:28:26 by sbeylot           #+#    #+#             */
/*   Updated: 2023/03/23 16:09:05 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

/*
	Command: PASS
	Parameters: <password>
*/

void	PASS(User *user)
{
	
	if (user->getStatus() > STATUS_NEW)
	{
		user->sendMessage(user->formattedReply("462", ERR_ALREADYREGISTRED()));
		return ;
	}

	if (user->getCommand()->getParameters().empty())
	{
		user->sendMessage(user->formattedReply("461", ERR_NEEDMOREPARAMS(user->getCommand()->getName())));
		return ;
	}

	std::string param = user->getCommand()->getParameters()[0];
	if (param == user->getServer()->getPassword())
	{
		if (user->getStatus() == STATUS_NEW)
			user->setStatus(STATUS_PASS);
	}	
}