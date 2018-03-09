#pragma once
class Customer
{
public:
	Customer(size_t number);
	void Wakeup();
	void WaitOnesTurn();
	size_t GetNumber();
	HANDLE IsWakedUp();
	~Customer();
private:
	size_t number;
	HANDLE wakedUp;
};