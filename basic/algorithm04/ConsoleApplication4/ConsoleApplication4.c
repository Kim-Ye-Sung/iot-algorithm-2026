#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char name[100];
	int score;

} Student;


int main()
{
	int N;

	printf("몇명의 학생을 입력하시겠습니까 > "); scanf("%d", &N);

	Student* Students = calloc(N, sizeof(Student));

	for (int i = 0; i < N; i++)
	{
		printf("학생의 이름을 입력해주세요 > "); scanf("%s", Students[i].name);
		printf("그 학생의 점수를 입력해주세요 > "); scanf("%d", &Students[i].score);
	}


	for (int i = 0; i < N-1; i++)		// 버블정렬을 하되 딱 한번만 한다. 왜냐하면 제일 최고로 높은 점수의 학생은 맨 뒤까지 무조건 이동할테니까
	{
		if (Students[i].score >= Students[i + 1].score)		// >= 조건으로 인해 동점일 경우 먼저 입력받은 사람이 제일 뒤로 이동한다.
		{

			int temp = Students[i].score;
			Students[i].score = Students[i+1].score;
			Students[i + 1].score = temp;

			char name_ptr[100] = "";
			strcpy(name_ptr, Students[i].name);
			strcpy(Students[i].name, Students[i + 1].name);
			strcpy(Students[i + 1].name, name_ptr);
		}

	}

	printf("%s %d\n", Students[N-1].name, Students[N-1].score);	// 현재 정렬되었기에 제일 첫번째 학생이 제일 큰 점수를 가지고 있고, 제일 먼저 입력받은 순서대로 있다.

	return 0;
}