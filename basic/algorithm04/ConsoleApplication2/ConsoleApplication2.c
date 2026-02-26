#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int max;	// 큐 최대크기
	int num;	// 큐 현재 요소 개수
	int front;	// 큐 프런트
	int rear;	// 큐 리어
	int* que;	// 실제 큐데이터의 맨 앞요소의 포인터
} IntQueue;

int Initialize(IntQueue* qu, int max)
{
	qu->num = qu->front = qu->rear = 0;

	if ((qu->que = calloc(max, sizeof(int))) == NULL)	
	{
		qu->max = 0;
		return -1;
	}

	qu->max = max;
	return 0;
}

int Enque(IntQueue* qu, int x)
{
	if (qu->num >= qu->max)		
	{
		return -1;
	}
	else
	{
		qu->num++;	
		qu->que[qu->rear] = x;	
		qu->rear++;	

		if (qu->rear == qu->max)
		{
			qu->rear = 0;	
		}

		return 0;
	}
}

int Deque(IntQueue* qu, int* x)
{
	if (qu->num <= 0)
	{
		return -1;
	}
	else
	{
		qu->num--;	
		*x = qu->que[qu->front];
		qu->front++;

		if (qu->front == qu->max)	
		{
			qu->front = 0;
		}

		return 0;
	}
}

int Size(const IntQueue* qu)
{
	return qu->num;
}

void Print(const IntQueue* qu)
{
	printf("%d", qu->que[qu->front]);	// 어차피 마지막 결과는 항상 한장밖에 안남으니 이 코드로 충분.
}

void Terminate(IntQueue* qu)
{
	if (qu->que != NULL)
	{
		free(qu->que);
	}

	qu->max = qu->num = qu->front = qu->rear = 0;
}



int main()
{
	IntQueue qu;

	int N;	// 다른 것도 확인하려면 여기를 바꾸면 됨.

	printf("N을 입력해주세요 > "); scanf("%d", &N);

	if (Initialize(&qu, N) == -1)
	{
		return 1;
	}

	for (int i = 1; i <= N; i++)	// 입력한 숫자를 전부 큐(카드뭉치)에 넣음
	{
		if (Enque(&qu, i) == -1)
		{
			return 1;
		}
	}

	while (1)	// 카드를 버리고, 맨 아래로 넣고를 반복
	{
		int x;

		if (Deque(&qu, &x) == -1)		// 맨 위의 카드를 버림 
		{
			return 1;
		}
	
		if (Size(&qu) == 1)	 // 맨 위의 카드를 버렸을때, 1장만 남은 상황이라면 그 카드를 출력하고 종료
		{
			Print(&qu);

			break;
		}

		// 카드를 버렸는데도 카드가 2장 이상 남아있다면	
		Deque(&qu, &x);	// 맨 위의 카드를 
		Enque(&qu, x);  // 맨 아래로 옮긴다.
	}

	printf("\n");

	Terminate(&qu);

	return 0;
}