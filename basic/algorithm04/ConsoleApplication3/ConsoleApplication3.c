#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

static int Memo_Result[150] = { 0 };  // 몇개까지 할진 모르겠으니 150개만 일단 준비하고 전부 0으로 초기화

int Add(int n)
{
	if (n <= 0)  // 0보다 작거나 같으면 더할수 없으니 0으로 종료
	{
		Memo_Result[0] = 0;
		return 0;
	}

	if (Memo_Result[n] > 0) // 배열의 값이 0보다 크면(값이 담겨져 있으면)
	{
		return Memo_Result[n];  // 바로 그 값을 즉시 출력
	}
	else  // 배열에 값이 담겨져 있지 않고
	{
		if ((n-1) == 0) // 하위 배열이 0번째인덱스면(즉, 현재 인덱스가 1이면)
		{
			Memo_Result[n] = n + Memo_Result[0];
			
			return Memo_Result[n];
		}
		else if (Memo_Result[n - 1] > 0)	// 하위 배열에 값이 담겨져 있으면
		{
			Memo_Result[n] = n + Memo_Result[n - 1];

			return Memo_Result[n];
		}
		else // 하위 배열에도 값이 담겨져 있지 않으면
		{
			Memo_Result[n] = n + Add(n - 1);

			return Memo_Result[n];
		}
	}
}

int main()
{
	int N;

	while (1)
	{
		
		printf("N을 입력해주세요(종료를 하려면 -1을 입력해주세요) > "); scanf("%d", &N);

		if (N == -1)
		{
			break;
		}

		printf("%d\n\n", Add(N));
	}
	return 0;
}