#pragma once
#include <vector>
#include "Subscriber.h"
class Publisher
{
protected:
	std::vector<Subscriber* > subscribers;
public:
	virtual void subscribe(Subscriber*);
	virtual void unsubscribe(Subscriber*);
	virtual void notify() const;
};

