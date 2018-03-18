#include "stdafx.h"

using namespace std;

const size_t ARGUMENTS_COUNT = 2;

int main(int argc, char* argv[])
{
	if (argc != ARGUMENTS_COUNT)
	{
		cout << "Invalid argumets count. Use Supermarket.exe <count of customers>" << endl;
		return 1;
	}

	size_t customersCount = stoi(argv[1]);
	Cashier first(1);
	Cashier second(2);
	
	ThreadHandler handler;
	handler.Add(Executor::ExecuteCashier, &first);
	handler.Add(Executor::ExecuteCashier, &second);

	srand(time(NULL));
	vector<shared_ptr<Customer>> customers;
	for (size_t i = 0; i < customersCount; i++)
	{
		int rndRes = rand() % 2 + 1;
		auto customer = make_shared<Customer>(i);
		customers.push_back(customer);
		if (rndRes == 1)
		{
			handler.Add(Executor::ExecuteCustomer, customers.back().get());
			first.AddCustomerInQueue(customers.back());
		}
		else
		{
			handler.Add(Executor::ExecuteCustomer, customers.back().get());
			second.AddCustomerInQueue(customers.back());
		}
	}
	first.StopWorking();
	second.StopWorking();
	handler.WaitAll();
	return 0;
}