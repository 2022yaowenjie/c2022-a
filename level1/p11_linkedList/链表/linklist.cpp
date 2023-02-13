#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct _node {
	int value;
	struct _node* next;
}Node;
Node* creat(Node* head, int len);
int search(Node* head, int number);
int re_search(Node* head, int number);
void oppo(Node** head);
int main()
{
	Node* head = NULL;
	head = creat(head, 5);
	oppo(&head);
}
Node* creat(Node* head, int len)
{
	int number, cnt = 0;
	do {
		scanf("%d", &number);
		cnt++;
		Node* p = (Node*)malloc(sizeof(Node));
		p->value = number;
		p->next = NULL;
		if (head)
		{
			Node* last = head;
			for (; last->next; last = last->next);
			last->next = p;
		}
		else
			head = p;
	} while (cnt < len);
	return head;
}
int search(Node* head, int number)
{
	int k = -1, cnt = 0;
	Node* p = head;
	for (; p; p = p->next)
	{
		cnt++;
		if (p->value == number)
		{
			k = cnt;
			break;
		}

	}
	return k;
}

int re_search(Node* head, int number)
{
	int k = -1, cnt = 0, cnt_times = 0;
	Node* p = head;
	for (; p; p = p->next)
	{
		cnt++;
		if (p->value == number)
		{
			cnt_times++;
			if (cnt_times == 2)
			{
				k = cnt;
				break;
			}
		}

	}
	return k;
}

void oppo(Node** head)
{
	int a[10000];
	int len = 0;
	Node* last = *head;
	for (; last; last = last->next)
	{
		len++;
		a[len] = last->value;
	}
	Node* p = *head;
	for (; p; p = p->next)
	{
		p->value = a[len];
		len--;
	}
}