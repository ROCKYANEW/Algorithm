// [1일차] [TST]주사위 던지기1

/*
[Explain]

주사위를 던진 횟수 N과 출력형식 M을 입력 받아서 M의 값에 따라 각각 아래와 같이 출력하는 프로그램을 작성하시오.
M = 1 : 주사위를 N번 던져서 나올 수 있는 모든 경우
M = 2 : 주사위를 N번 던져서 중복이 되는 경우를 제외하고 나올 수 있는 모든 경우
M = 3 : 주사위를 N번 던져서 모두 다른 수가 나올 수 있는 모든 경우
* 중복의 예
1 1 2 와 중복 : 1 2 1, 2 1 1
1 2 3 과 중복 : 1 3 2, 2 1 3, 2 3 1, 3 1 2

---------------------------------------------------------------------------------------------------
[Input]

첫 줄에 주사위를 던진 횟수 N(2≤N≤5)과 출력모양 M(1≤M≤3)이 들어온다.

[Output]

주사위를 던진 횟수 N에 대한 출력모양을 출력한다.
작은 숫자부터 출력한다.

---------------------------------------------------------------------------------------------------

[Input Example]

3 1

[Output Example]

1 1 1
1 1 2
1 1 3
1 1 4
1 1 5
1 1 6
1 2 1
…
6 6 6


[Extram Explain]

*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_N (5)

int N, M;				// 주사위의 횟수, 경우의 수 모델
int select[MAX_N + 1]; 	// 기록
int chk[MAX_N + 2];		// For Dice3() : flag Array

void Dice1(int n)
{
	// n번째 던져서 나오는 숫자의 수를 만든다는 역할
	int i;

	// 경우의 수 완성 상황
	if (n > N) {
		for (i = 1; i <= N; i++) {
			printf("%d", select[i]);
		}
		printf("\n");
		return ;
	}
	
	for (i = 1; i <= 6; i++) {
		// N번째 주사위로 i라는 숫자를 기록한다
		select[n] = i;
		Dice1(n + 1);
	}
}

void Dice2(int n, int s)
{
	int i;

	if (n > N) {
		for (i = 1; i <= N; i++) {
			printf("%d", select[i]);
		}
		printf("\n");
		return ;
	}
	
	for (i = s; i <= 6; i++) {
		select[n] = i;
		Dice2(n + 1, i)
	}
}

void Dice3(int n)
{
	// n번째 던져서 나오는 숫자의 수를 만든다는 역할
	int i;

	// 경우의 수 완성 상황
	if (n > N) {
		for (i=1; i<=N; i++) {
			printf("%d", select[i]);
		}
		printf("\n");
		return ;
	}
	
	for (i = 1; i <= 6; i++) {
		// i라는 숫자를 무조건 선택할 수 없다.(중복 제거)
		if (chk[i] == 1) continue;
		
		select[n] = i;
		chk[i] = 1;
		Dice3(n + 1);
		chk[i] = 0;		// 재선택 하기 위해
	}
}

int main(void)
{
	scanf("%d %d",&N, &M);
	switch(M) {
		case 1:
			// void Dice1(int n)
			Dice1(1);
			break;
		case 2:
			// void Dice1(int n, int s) : s는 어디서 부터 시작할지 기준 숫자
			Dice2(1, 1);
			break;
		case 3:
			Dice3(1);
			break;
	}
}
