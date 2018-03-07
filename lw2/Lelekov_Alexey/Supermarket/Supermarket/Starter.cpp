#include "stdafx.h"
#include "Starter.h"
#include "Cashier.h"

Starter::Starter()
{
}

DWORD Starter::Execute(LPVOID parameter)
{
	Cashier *cashier = (Cashier *) parameter;
	cashier->ServeCustomers();
	return 0;
}

Starter::~Starter()
{
}
