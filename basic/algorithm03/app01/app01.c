// app01 - 큐 구현

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "IntQueue.h"


int main()
{
	IntQueue que;

	if (Initialize(&que, 8) == -1)
	{
		puts("큐 생성 실패!");

		return 1;  // 또는 exit(1);
	}

	int menu, x, ch;

	while (1)
	{
		menu = -1;

		printf("현재 데이터 수 : %d / %d\n", Size(&que), Capacity(&que));
		printf("(1)인큐  (2)디큐  (3)피크  (4)출력  (5)검색  (6)클리어  (0)종료  > "); scanf("%d", &menu);

		// 잘못된 키보드 입력 버퍼를 제거
		// 기초 프로그래밍 주소록 토이프로젝트 소스 참조
		while ((ch = getchar()) != '\n' && ch != EOF)
		{
		}

		if (menu == 0)
		{
			break;
		}

		switch (menu)
		{
		case 1 : // 인큐
			if (IsFull(&que) == 1)
			{
				puts("큐가 꽉 찼습니다. 데이터를 넣을 수 없습니다.");
			}
			else
			{
				printf("데이터 입력 > "); scanf("%d", &x);
				if (Enque(&que, x) == -1)
				{
					puts("\a오류 : 인큐 실패!");
				}
			}
			break;

		case 2 : // 디큐
			if (IsEmpty(&que) == 1)
			{
				puts("디큐할 자료가 없습니다.");
			}
			else 
			{
				if (Deque(&que, &x) == -1)
				{
					puts("\a오류 : 디큐 실패!");
				}
				else
				{
					printf("디큐 데이터 : %d\n", x);
				}
			}
			break;

		case 3 : // 피크
			if (Peek(&que, &x) == -1)
			{
				puts("\a오류 : 피크 실패!!");
			}
			else
			{
				printf("피크 데이터 : %d\n", x);
			}
			break;

		case 4 : // 출력
			Print(&que);
			break;

		case 5:	// 검색
			if (IsEmpty(&que) == 1)
			{
				puts("큐가 비어 있습니다. 따라서 자료를 찾을 수 없습니다.");
			}
			else
			{
				printf("찾을 자료를 입력해주세요 > "); scanf("%d", &x);
				int res = Search(&que, x);
				if (res == -1)
				{
					puts("찾고자 하는 자료가 큐에 들어있지 않습니다.");
				}
				else
				{
					printf("찾고자 하는 자료 %d 는 que[%d] 에 있습니다.\n", x, res);
				}
			}
			break;
			
		case 6:
			Clear(&que);
			puts("큐를 비웠습니다!");
			break;

		default :	// 오류 잡기
			puts("입력 오류!");
			break;
		}

		printf("\n");
	}

	Terminate(&que);	// 종료


	return 0;
}