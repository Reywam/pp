#include "stdafx.h"

using namespace std;

struct DataForCustomer
{
	std::vector<Cashier*> cashiers;
	Customer* customer;
};

const size_t ARGUMENTS_COUNT = 2;

int main(int argc, char* argv[])
{
	if (argc != ARGUMENTS_COUNT)
	{
		cout << "Invalid argumets count. Use Supermarket.exe <count of customers>" << endl;
		return 1;
	}

	size_t customersCount = stoi(argv[1]);
	ThreadHandler handler;

	srand(time(NULL));
	vector<Cashier*> cashiers = { new Cashier(1), new Cashier(2) };
	for (auto cashier : cashiers)
	{
		handler.Add(Executor::ExecuteCashier, cashier);
	}

	vector<Customer*> customers;
	vector<DataForCustomer*> customersData;
	for (size_t i = 0; i < customersCount; i++)
	{
		customers.push_back(new Customer(i));
		customersData.push_back(new DataForCustomer{ cashiers, customers.back() });
		handler.Add(Executor::ExecuteCustomer, customersData.back());
	}
	handler.WaitAll();
	return 0;
}