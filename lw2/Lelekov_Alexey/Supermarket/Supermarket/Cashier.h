#pragma once
#include <queue>
#include <memory>
#include "Customer.h"
#include <Windows.h>

class Cashier
{
public:
	Cashier(const size_t &number);
	void ServeCustomer();
	void ServeCustomers();
	void AddCustomerInQueue(std::shared_ptr<Customer> customer);
	void StopWorking();
	size_t GetNumber();
	~Cashier();
private:
	HANDLE semaphore;
	std::queue<std::shared_ptr<Customer>> queue;
	size_t number;
	bool isWorking = true;
};