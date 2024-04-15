#include <algorithm>

#include "Publisher.h"

void Publisher::subscribe(Subscriber* s)
{
	subscribers.push_back(s);
}

void Publisher::unsubscribe(Subscriber* s)
{
	subscribers.erase(
		std::remove_if(
			subscribers.begin(),
			subscribers.end(),
			[s](const Subscriber* item) { return item == s; }),
		subscribers.end());
}

void Publisher::notify() const
{
	for (auto item : subscribers)
	{
		item->update(this);
	}
}
