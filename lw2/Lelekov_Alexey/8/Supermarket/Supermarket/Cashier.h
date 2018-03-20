#pragma once
#include <queue>
#include <memory>
#include <Windows.h>
#include "Customer.h"

class Cashier
{
public:
	Cashier(const size_t &number);
	void ServeCustomer();
	void ServeCustomers();
	void AddCustomerInQueue(Customer* customer);
	void StopWorking();
	size_t GetNumber();
	~Cashier();
private:
	HANDLE semaphore;
	std::queue<Customer*> queue;
	size_t number;
	static const size_t clientsBufferSize = 10;
	bool isWorking = true;
};