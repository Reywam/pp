#pragma once
#include <queue>
#include "Customer.h"

class Cashier
{
public:
	Cashier();
	~Cashier();
private:
	std::queue<Customer> queue;
};