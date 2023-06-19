#pragma once
#include<string>

class Worker
{
private:
	std::string fullname;
	long id;
protected:
	virtual void Data()const;
	virtual void Get();
public:
	Worker() : fullname("no name"), id(0L) {}
	Worker(const std::string& s, long n)
		: fullname(s), id(n) {}
	virtual ~Worker() = 0;
	virtual void Set() = 0;
	virtual void Show() const = 0;
};

