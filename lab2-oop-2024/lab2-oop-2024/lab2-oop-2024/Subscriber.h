#pragma once

class Publisher;

class Subscriber
{
public:
	virtual void update(const Publisher* publisher) const = 0;
};

