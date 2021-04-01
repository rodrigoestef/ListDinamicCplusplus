
#ifndef LIST_H_
#define LIST_H_
#include <cstdint>
struct element
{
	void *thisElement;
	element *nextElement;
};
struct listStruct
{
	uint8_t i;
	element *list;
};
class List
{
private:
	listStruct *listBase;
	element *getPrivateElementByIndex(uint8_t index);

public:
	List();
	void set(void *);
	void *getByIndex(uint8_t index);
	void removeByIndex(uint8_t index);
	uint8_t getSize();
};

#endif /* LIST_H_ */
