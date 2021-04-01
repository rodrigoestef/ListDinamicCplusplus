
#include "List.h"
#include <stdlib.h>

List::List()
{
	this->listBase = (listStruct *)malloc(sizeof(listStruct));
	this->listBase->i = 0;
	this->listBase->list = 0;
}

void List::set(void *item)
{
	element *nextElement = (element *)malloc(sizeof(element));
	nextElement->thisElement = item;
	nextElement->nextElement = 0;
	element *lastElement = this->getPrivateElementByIndex(this->listBase->i);
	if (lastElement == 0)
	{
		this->listBase->list = nextElement;
	}
	else
	{
		lastElement->nextElement = nextElement;
	}
	this->listBase->i = 1 + this->listBase->i;
}

void *List::getByIndex(uint8_t index)
{
	if (index >= this->listBase->i)
		return 0;
	element *e = this->getPrivateElementByIndex(index);
	if (index == 0)
		return e->thisElement;
	return e->nextElement->thisElement;
}

void List::removeByIndex(uint8_t index)
{
	if (index >= this->listBase->i)
		return;
	element *e = this->getPrivateElementByIndex(index);
	if (index == 0)
	{
		this->listBase->list = e->nextElement;
	}
	else if (index + 1 == this->listBase->i)
	{
		e->nextElement = 0;
	}
	else
	{
		e->nextElement = e->nextElement->nextElement;
	}
	this->listBase->i = this->listBase->i - 1;
}

uint8_t List::getSize()
{
	return this->listBase->i;
}

element *List::getPrivateElementByIndex(uint8_t index)
{

	if (index > this->listBase->i || this->listBase->i == 0)
		return 0;
	if (index == 0)
		return this->listBase->list;
	uint8_t i;
	element *e = this->listBase->list;
	for (i = 1; i < index; ++i)
	{
		e = e->nextElement;
	}
	return e;
}
