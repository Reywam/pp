#pragma once
class Customer
{
public:
	Customer(const size_t &number);
	void Wakeup();
	void WaitOnesTurn();
	size_t GetNumber();
	HANDLE IsWorkFinished();
	~Customer();
private:
	size_t number;
	HANDLE wakeupEvent;
	HANDLE exitEvent;
};