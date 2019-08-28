#include <stdio.h>
 
#define MAX_N (10000)
#define MAX_Q (MAX_N + 1)
int N;
 
int queue[MAX_Q];
int wp = 0, rp = 0;
 
int Enqueue(int data)
{
	/*	wp + 1 은 Next Enqueue의 시점임.
		이것과 rp가 같다는것은 Circular Queue 관점에서 Queue Full을 의미한다. */
    if ((wp + 1) % MAX_Q == rp) return 0;
    queue[wp] = data;
    wp = (wp + 1) % MAX_Q;		// 단순 증가(하지만 Queue가 가득 찼을 경우 0으로 wp를 돌린다. - Circular Queue)
    return 1;
}
 
int Dequeue(int *p)
{
    if(wp == rp) return 0;	// wp == rp 같다는 것은 Queue가 비었다는 것을 의미 한다.
    *p = queue[rp];
    rp = (rp + 1) % MAX_Q;	// 단순 증가(하지만 Queue가 가득 찼을 경우 0으로 rp를 돌린다. - Circular Queue)
    return 1;
}
 
int main(void)
{
    int cmd, data;
    int i;
	
    scanf("%d",&N);
    for(i = 0; i < N; i++) {
        scanf("%d", &cmd);
        switch (cmd) {
		case 1:
			// Push
			scanf("%d", &data);
			Enqueue(data);
			break;
		case 0:
			// Pop
			if (Dequeue(&data)) {
				printf("%d\n",data);
			} else {
				printf("E\n");
			}
			break;
		case 2:
			// Count
			if (rp <= wp) printf("%d\n", wp - rp);
			else  printf("%d\n", MAX_Q - (rp - wp));
			break;
        }
    }
    return 0;
}
