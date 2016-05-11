#include "list.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

struct ListElement
{
	int value;
	ListElement *next;
};

struct List
{
	ListElement *head;
};

List *createList()
{
	List *result = new List;
	result->head = nullptr;
	return result;
};

void insertToHead(List *list, int value)
{
	ListElement *element = new ListElement;
	element->next = list->head;
	list->head = element;
	list->head->value = value;
}

void printList(List *list)
{
	ListElement *tmp = list->head;
	while (tmp != nullptr)
	{
		cout << tmp->value << " ";
		tmp = tmp->next;
	}
	printf("\n");
}

void deleteList(List *list)
{
	ListElement *tmp = list->head;
	ListElement *delValue = tmp;
	while (tmp)
	{
		delValue = tmp;
		tmp = tmp->next;
		delete(delValue);
	}
	delete list;
}

void insert(List *list, int value, int n)
{
	if (n == 0)
	{
		insertToHead(list, value);
		return;
	}
	if (n <= numberOfElements(list))
	{
		ListElement *newElement = new ListElement;
		newElement->value = value;
		ListElement *pos = position(list, n);
		newElement->next = pos->next;
		pos->next = newElement;
	}
}

ListElement *position(List *list, int n)
{
	ListElement *p = list->head;
	while (n != 1)
	{
		p = p->next;
		n--;
	}
	return p;
}

int numberOfElements(List *list)
{
	ListElement *i = list->head;
	int count = 0;
	while (i != nullptr)
	{
		++count;
		i = i->next;
	}
	return count;
}

ListElement* last(List *list)
{
	ListElement *i = list->head;
	while (i->next != nullptr)
	{
		i = i->next;
	}
	return i;
}


List *reverse(List *list)
{
	List *newlist = createList();
	ListElement *i = list->head;
	while (i != nullptr)
	{
		insertToHead(newlist, i->value);
		i = i->next;
	}
	return newlist;
}
