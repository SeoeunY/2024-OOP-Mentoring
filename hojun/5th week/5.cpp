#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#pragma warning (disable: 4267)
using namespace std;

class node
{
private:
	char* name;
	int num;
	node* next;
public:
	node(char* name, int num)
	{
		this->name = NULL;
		this->next = NULL;
		this->num = 0;
		this->setname(name);
		this->setnum(num);
	}
	~node()
	{
		delete name;
		this->next = NULL;
	}

	char* getname() { return this->name; }
	int getnum() { return this->num; }
	node* getnext() { return this->next; }

	void setname(char* name) { int len = strlen(name); this->name = new char[len + 1]; strcpy(this->name, name); }
	void setnum(int num) { this->num = num; }
	void setnext(node* next) { this->next = next; }
};

class list
{
private:
	int size;
	node* head;
	node* tail;
public:
	list()
	{
		this->size = 0;
		this->head = NULL;
		this->tail = NULL;
	}
	~list()
	{
		node* prev;
		this->size = 0;
		while (head->getnext() != NULL)
		{
			prev = head;
			head = head->getnext();
			delete prev;
		}
		delete head;
	}

	int getsize() { return size; }
	node* gethead() { return head; }
	node* gettail() { return tail; }

	void setsize() { this->size++; }
	void setnode(char* name, int num)
	{
		node* new_node = new node(name, num);
		if (head == NULL)
		{
			head = new_node;
			tail = head;
		}
		else
		{
			tail->setnext(new_node);
			tail = tail->getnext();
		}
	}
	void print()
	{
		node* tmp = head;
		while (tmp != NULL)
		{
			cout << tmp->getnum() << " " << tmp->getname() << "\n";
			tmp = tmp->getnext();
		}
	}
	void find(char* name)
	{
		node* tmp = head;
		while (tmp != NULL)
		{
			if (!strcmp(name, tmp->getname()))
			{
				cout << tmp->getnum() << " " << tmp->getname() << "\n";
				break;
			}
			tmp = tmp->getnext();
		}
	}
	void del(char* name)
	{
		node* tmp = NULL;
		if (!strcmp(name, head->getname()))
		{
			tmp = head;
			head = head->getnext();
			delete tmp;
		}
		else
		{
			node* pre = head;
			tmp = pre->getnext();
			while (tmp != NULL)
			{
				if (!strcmp(name, head->getname()))
				{
					if(pre->getnext()!=NULL)
						pre->setnext(tmp->getnext());
					delete tmp;
					break;
				}
				pre = pre->getnext();
				tmp = pre->getnext();
			}
		}
	}
};
int main()
{
	int num = 0;
	char name[20] = {};
	int command = 0;
	list a;

	while (command != 5)
	{
		cout << "Please Enter Command: ";
		cin >> command;
		switch (command)
		{
		case 1:
			cin >> num >> name;
			a.setnode(name, num);
			break;
		case 2:
			a.print();
			break;
		case 3:
			cin >> name;
			a.find(name);
			break;
		case 4:
			cin >> name;
			a.del(name);
			break;
		default:
			break;
		}
	}
	return 0;
}