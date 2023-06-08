#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#pragma once

typedef struct
{
	int max;
	int num;
	int front;
	int rear;
	int* que;
}IntQueue;

int Initialiize(IntQueue* q, int max)
{
	q->num = q->front = q->rear = 0;
	if ((q->que = calloc(max, sizeof(int))) == NULL)
	{
		q->max = 0;
		return -1;
	}
}

int Engue(IntQueue* q, int x)
{
	if (q->num >= q->max)
		return -1;
	else
	{
		q->num++;
		q->que[q->rear++] = x;
		if (q->rear == q->max)
			q->rear = 0;
		return 0;
	}
}

int Deque(IntQueue* q, int* x)
{
	if (q->num <= 0)
		return -1;
	else
	{
		q->num--;
		*x = q->que[q->front++];
		if (q->front == q->max)
			q->front = 0;
		return 0;
	}
}

int Peek(const IntQueue* q, int* x)
{
	if (q->num <= 0)
		return -1;
	*x = q->que[q->front];
	return 0;
}

void clear(IntQueue* q)
{
	q->num = q->front = q->rear = 0;
}

int Capacity(const IntQueue* q)
{
	return q->max;
}

int Size(const IntQueue* q)
{
	return q->num;
}

int IsEmpty(const IntQueue* q)
{
	return q->num >= q->max;
}

int search(const IntQueue* q, int x)
{
	for (int i = 0;i < q->num;i++)
	{
		int idx;
		if (q->que[idx = (i + q->front) % q->max] == x)
			return idx;
	}
	return -1;
}

void Print(const IntQueue* q)
{
	for (int i = 0;i < q->num;i++)
		printf("%d", q->que[(i + q->front) % q->max]);
	putchar('\n');
}

void Terminate(IntQueue* q)
{
	if (q->que != NULL)
		free(q->que);
	q->max = q->num = q->front = q->rear = 0;
}
