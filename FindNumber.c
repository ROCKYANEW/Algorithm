// [2일차] codexpert - 숫자찾기(Binary Search )

/*
[Explain]

오름차순의 순서대로 정렬되어 있는 N개의 데이터에서 특정한 숫자가 몇 번째 위치에 있는지를 알아내는 프로그램을 작성하시오.

---------------------------------------------------------------------------------------------------
[Input]

첫 번째 줄에 N(1≤N≤50,000)이 주어진다. N은 정렬되어 주어지는 데이터의 수이다.
두 번째 줄에는 N개의 서로 다른 수가 정렬되어 주어진다. 각 수는 공백 하나로 분리되어 주어진다.
세 번째 줄에는 데이터에서 찾아야 할 특정한 수의 개수 T(1≤T≤10,000)가 주어진다. 
즉, T가 3이면 3개의 수를 정렬된 데이터에서 찾아야 한다.
네 번째 줄에는 T개의 수가 공백 하나로 분리되어 주어진다.

[Output]
찾아야 할 수가 정렬되어 주어진 데이터의 수 중에서 앞에서부터 몇 번째에 있는지 그 위치를 출력한다. 
첫 번째 위치는 1이다. 만약, 찾으려는 수가 주어지는 데이터에 존재하지 않는다면, 0을 출력한다.

---------------------------------------------------------------------------------------------------

[Input Example]

7
2 4 9 10 14 23 32
3
6 23 9

[Output Example]

0
6
3

[Extram Explain]

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
  
#define MAX_N (50000)
  
int N;
int num[MAX_N + 1];
  
void Input_Data(void)
{
    int i;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d", &num[i]);
    }
}

int Binary_Search(int s,int e,int d)
{
    int m;
 
    while(s < =e) {
        m = (s + e) / 2;
        if(num[m] == d) return m;
        else if(num[m] > d) e = m - 1;
        else s = m + 1;
    }
    return -1;
}
 
int main(void)
{
    int i, T, d, ret ;
    Input_Data();
  
    scanf("%d", &T);
    for (i = 0; i < T; i++) {
        scanf("%d", &d);
     
        //Binary_Search(int s,int e,int d)
        ret = Binary_Search(1,N,d);
        if (ret == -1) printf("0\n");
        else printf("%d\n",ret);
    }
    return 0;
}
