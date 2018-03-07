#include "stdafx.h"
#include <string>
#include <iostream>
#include "Customer.h"
#include "Cashier.h"
#include "ThreadHandler.h"
#include "Starter.h"

using namespace std;

void kek() {

}

int main(int argc, char* argv[])
{	
	size_t customersCount = stoi(argv[1]);	
	Cashier first(1);
	Cashier second(2);
	
	ThreadHandler handler;	
	handler.Add(Starter::Execute, &first);
	handler.Add(Starter::Execute, &second);	

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

	handler.JoinAll();

    return 0;
}