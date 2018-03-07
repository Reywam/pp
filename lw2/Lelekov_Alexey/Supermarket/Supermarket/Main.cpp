#include "stdafx.h"

using namespace std;

int main(int argc, char* argv[])
{	
	size_t customersCount = stoi(argv[1]);	
	Cashier first(1);
	Cashier second(2);
	
	ThreadHandler handler;	
	handler.Add(Starter::Execute, &first);
	handler.Add(Starter::Execute, &second);	

	Messenger &messenger = Messenger::GetInstanse();

	for (size_t i = 0; i < customersCount; i++)
	{
		Customer customer;
		int rndRes = rand() % 2 + 1;
		if (rndRes == 1) 
		{			
			first.AddCustomerInQueue(customer);
		} 
		else
		{
			second.AddCustomerInQueue(customer);
		}		
	}	
	
	first.StopWorking();
	second.StopWorking();
	handler.WaitAll();

    return 0;
}