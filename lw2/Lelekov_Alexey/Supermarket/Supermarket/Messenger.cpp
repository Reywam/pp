#include "stdafx.h"
#include "Messenger.h"

Messenger::Messenger()
{
	mutex = CreateMutex(NULL, FALSE, NULL);
}

void Messenger::SendMessageTo(std::ostream &out, const std::string &msg)
{			
	out << msg;	
}


Messenger::~Messenger()
{
}
