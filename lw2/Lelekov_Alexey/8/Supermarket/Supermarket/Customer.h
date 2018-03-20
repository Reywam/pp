#pragma once
#include <vector>
class Cashier;

class Customer
{
public:
	Customer(const size_t &number);
	void Wakeup();
	void WaitOnesTurn();
	size_t GetNumber();
	HANDLE GetExitEvent();
	void Action(std::vector<Cashier*> cashiers);
	void GetInLine(std::vector<Cashier*> cashiers);
	~Customer();
private:
	size_t number;
	HANDLE wakeupEvent;
	HANDLE exitEvent;
};