#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int max;	
	int ptr;	
	char* stk;	

}CharStack;

int Initialize(CharStack* st, int max)
{
	st->ptr = 0;

	if ((st->stk = calloc(max, sizeof(char))) == NULL)
	{
		st->max = 0;
		return -1;	
	}

	st->max = max;
}

int Push(CharStack* st, char chr)
{
	if (st->ptr >= st->max)
	{
		return -1;
	}

	st->stk[st->ptr] = chr;	
	st->ptr++;

	return 0;
}

int Pop(CharStack* st, char* x)
{
	if (st->ptr <= 0)
	{
		return -1;
	}

	st->ptr--;	
	*x = st->stk[st->ptr];

	return 0;
}

void Terminate(CharStack* st)
{
	if (st->stk != NULL)
	{
		free(st->stk);
	}

	st->ptr = 0;
	st->max = 0;
}


int main()
{
	CharStack st;

	char s[1000];

	printf("거꾸로 할 문자를 입력해주세요 > "); scanf("%s", s);

	if (Initialize(&st, strlen(s)) == -1)	// 스택 동적 생성
	{
		return 1;
	}

	for (int i = 0; i < strlen(s); i++)	 // 문자열의 문자를 스택에 넣음
	{
		if (Push(&st, s[i]) == -1)
		{
			return 1;
		}
	}

	for (int i = 0; i < strlen(s); i++)	 // 스택의 맨위부터 순서대로 문자를 꺼내서 출력
	{
		char ch_print;

		if (Pop(&st, &ch_print) == -1)
		{
			return 1;
		}
		else
		{
			printf("%c", ch_print);
		}

	}

	printf("\n");

	Terminate(&st);

	return 0;
}