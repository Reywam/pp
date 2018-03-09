#include "stdafx.h"

using namespace std;

int main(int argc, char* argv[])
{
	size_t customersCount = stoi(argv[1]);
	Cashier first(1);
	Cashier second(2);
	
	ThreadHandler handler;
	handler.Add(Executor::ExecuteCashier, &first);
	handler.Add(Executor::ExecuteCashier, &second);

	for (size_t i = 0; i < customersCount; i++)
	{
		Customer customer(i);

		int rndRes = rand() % 2 + 1;
		handler.Add(Executor::ExecuteCustomer, &customer);
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