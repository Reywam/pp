#pragma once
class Customer
{
public:
	Customer(size_t number);
	void Wakeup();
	void WaitOnesTurn();
	void Suicide();
	size_t GetNumber();
	HANDLE ExitEvent();
	~Customer();
private:
	size_t number;
	HANDLE wakeupEvent;
	HANDLE exitEvent;
	HANDLE suicideEvent;
};