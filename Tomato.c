#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_RC	(1000)
#define MAX_Q	(MAX_RC * MAX_RC)

// Queue ----------------------------------------
typedef struct{
	int r;		// 열
	int c;		// 행
	int time;	// 상태(1:익음, 0:안익음, -1:비었음)
}QUEUE;

QUEUE queue[MAX_Q];
int wp, rp;

#define Enqueue(X) (queue[wp++] = (X))
#define Dequeue(X) ((X) = queue[rp++])
#define QueueIsNotEmpty (wp > rp)
// ---------------------------------------------

int cnt_tomato = 0;	// 익지 않은 토마토의 카운트 
int C,R;
int box[MAX_RC+1][MAX_RC+1];

void Input_Data(void)
{
	int r, c;
	QUEUE data;
		
	scanf("%d %d", &C, &R);
	for (r=1; r <= R; r++) {
		for (c=1; c <= C; c++) {
			scanf("%d ", &box[r][c]);
			switch (box[r][c]) {
				case 0:
					cnt_tomato++;
					break;
				case 1:
					data.r = r;
					data.c = c;
					data.time = 0;
					Enqueue(data);
					break;
				default:
					break;
				
			}
		}
	}
}

int BFS(void)
{
	int i;
	QUEUE data, ndata;		// 현재상태, 다음상태
	// 상,하,좌,우 이동시키기 위한 변이 테이블 생성. dr[], dc[]
	int dr[] = {-1, 1, 0, 0};
	int dc[] = {0, 0, -1, 1};
	
	while (QueueIsNotEmpty) {
		Dequeue(data);
		for (i = 0; i < 4; i++) {
			// 상태 전이
			ndata.r = data.r + dr[i];
			ndata.c = data.c + dc[i];
			ndata.time = data.time + 1;
			
			// 해당 위치가 박스인지 확인, 하지만 그전에 좌표의 유효성 부터 확인해야 한다.(박스를 벗어 나진 않았는가?)
			if (ndata.r < 1 || ndata.r > R) continue;
			if (ndata.c < 1 || ndata.c > C) continue;
			if (box[ndata.r][ndata.c] != 0) continue;	// 익은 토마토이거나, 없는 토마토를 의미 하므로 패스

			Enqueue(ndata);
			box[ndata.r][ndata.c] = 1;
			cnt_tomato--;
		}
	}
	return cnt_tomato ? -1 : data.time;
}

int main(void) 
{
	Input_Data();
	if (cnt_tomato == 0) printf("0\n");
	else printf("%d\n", BFS());
}
