#pragma once
class Counter
{
public:
	Counter();
	static void IncPoint();
	static void IncCount();
	static size_t GetCount();
	static size_t GetPoints();
	void Reset();
	~Counter();
private:
	static size_t count;
	static size_t points;
};

