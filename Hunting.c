/* Personal Opinion -
총을 쏠 수 있는 모든 거리에서 동물이 잡힐 것인가?
동물의 수가 많아질 수록, 총의 위치가 많을 수록 연산량이 많아진다.
사실 모든 총의 위치에서 전부 확인해야 할까?(Binary Search)

결국 해당 동물이 잡힌다면 x축 기준에서 가장 가까운 사대의 위치를 찾아라!!
각 동물의 위치에서 왼쪽으로 가까운 사대와 오른쪽으로 가까운 사대를 찾자.
lower & Upper bound binary search를 사용하면 연산량을 단축할 수 있을것이다.*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N	(100000)
#define MAX_POS (100000)

int N;	// 동물수
int M;	// 사대수
int L;	// 총의 사거리

typedef struct {
    int x;
    int y;
}Point2D;

Point2D animal_pos[MAX_N];
int guns_pos[MAX_N];

int comp(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

void Input_Data(void)
{
    int i = 0;
	
	scanf("%d %d %d", &M, &N, &L);

	for (i=0; i<M; i++) {
		// 사대 위치 입력
        scanf("%d ", &guns_pos[i]);
    }
	
    for (i=0; i<N; i++) {
		// 동물 위치 입력
        scanf("%d %d", &animal_pos[i].x, &animal_pos[i].y);
    }
}

/*
int Hunting_Start(void)
{
	int i, j, k = 0;
	int hunted_Cnt = 0;
	Point2D animal;
	
	for (i=0; i<N; i++) {
		animal = animal_pos[i];
		// 사거리 안에 존재하는 동물들 탐색
		if (animal.y >= L) {
			// 사거리 안에 들어왔으며, 동물을 기준으로 사거리 안에 총이 있는지 확인.
			for (j=0; j<M; j++) {
				if (((animal.x - (L+N)) > 0 && (animal.x - (L+N) < guns_pos[j]) ||
					((animal.x + (L-N) < MAX_POS  && (animal.x + (L-N) < guns_pos[j])) {
					hunted_Cnt++;
					break;
				}
			}
		}
	}
	return hunted_Cnt;
}*/



int Binary_Search_Lower(int s, int e, int d)
{
    int m, sol = -1;
 
    while (s <= e) {
        m = (s + e) / 2;
        if (guns_pos[m] >= d) {
            sol = m;
            e = m - 1;
        } else {
			s = m + 1;
        }	
    }
    return sol;
}

int Binary_Search_Upper(int s, int e, int d)
{
    int m, sol = -1;
 
    while (s <= e) {
        m = (s + e) / 2;
        if (guns_pos[m] <= d) {
            sol = m;
            s = m + 1;
        } else {
			e = m - 1;
        }
    }
    return sol;
}

int Get_Distance(int idx_animal, int idx_gus)
{
	return animal_pos[idx_animal].y + abs(animal_pos[idx_animal].x - guns_pos[idx_gus]);
}

int Hunting_Start(void)
{
	int i = 0;
	int hunted_Cnt, ret = 0;

	// 사대의 거리를 기준으로 정렬 작업 실시
	qsort(guns_pos, M, sizeof(guns_pos[0]), comp);
	
	for (i=0; i<N; i++) {
		ret = Binary_Search_Upper(0, M-1, animal_pos[i].x);
		if (ret != -1 && Get_Distance(i, ret) <= L) {
			hunted_Cnt++;
			continue;
		}

		ret = Binary_Search_Lower(0, M-1, animal_pos[i].x);
		if (ret != -1 && Get_Distance(i, ret) <= L) {
			hunted_Cnt++;
			continue;
		}
	}
	return hunted_Cnt;
}

int main(void)
{
	// 여기서부터 작성
	Input_Data();
	printf("%d\n", Hunting_Start());
	return 0;
}
