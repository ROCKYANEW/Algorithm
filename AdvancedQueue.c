#include <stdio.h>

#define MAX_RC	(1000)
#define MAX_Q	(MAX_RC * MAX_RC)

// Queue ---------------------------------------
typedef struct{
	int r;		// 열
	int c;		// 행
	int time;	// 상태
}QUEUE;

QUEUE queue[MAX_Q];
int wp, rp;

#define Enqueue(X) (queue[wp++] = (X))
#define Dequeue(X) ((X) = queue[rp++])
#define QueueIsNotEmpty (wp > rp)
// ---------------------------------------------
