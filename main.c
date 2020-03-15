#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAX 3

_Bool tryEveryResult(int *wA ,int a ,int b ,int c)
{
    int flag = 1;
    //printf("%d %d %d\n",a,b,c);
    if (a == 0 && b == 0 && c == 0)
    {
        //printf("輸了\n");
        return false;  //輸
    }
    if (a > 1)
        if (tryEveryResult(wA ,a-2 ,b ,c))
        {
            flag = 0;
        }
    if (b > 1)
        if (tryEveryResult(wA ,a ,b-2 ,c))
        {
            flag = 0;
        }
    if (c > 1)
        if (tryEveryResult(wA ,a ,b ,c-2))
        {
            flag = 0;
        }
    if (a > 0)
        if (tryEveryResult(wA ,a-1 ,b ,c))
        {
            flag = 0;
        }
    if (b > 0)
        if (tryEveryResult(wA ,a ,b-1 ,c))
        {
            flag = 0;
        }
    if (c > 0)
        if (tryEveryResult(wA ,a ,b ,c-1))
        {
            flag = 0;
        }
    if (flag) {return true;}
}

void computerDo (int *stack)
{
    int wA[2];
    printf("電腦思考中...\n");

    if (stack[0] > 1)
        if (!(tryEveryResult(wA ,stack[0]-2 ,stack[1] ,stack[2])))
        {
            stack[0] -= 2;
            return;
        }
    if (stack[1] > 1)
        if (!(tryEveryResult(wA ,stack[0] ,stack[1]-2 ,stack[2])))
        {
            stack[1] -= 2;
            return;
        }
    if (stack[2] > 1)
        if (!(tryEveryResult(wA ,stack[0] ,stack[1] ,stack[2]-2)))
        {
            stack[2] -= 2;
            return;
        }
    if (stack[0] > 0)
        if (!(tryEveryResult(wA ,stack[0]-1 ,stack[1] ,stack[2])))
        {
            stack[0] -= 1;
            return;
        }
    if (stack[1] > 0)
        if (!(tryEveryResult(wA ,stack[0] ,stack[1]-1 ,stack[2])))
        {
            stack[1] -= 1;
            return;
        }
    if (stack[2] > 0)
        if (!(tryEveryResult(wA ,stack[0] ,stack[1] ,stack[2]-1)))
        {
            stack[2] -= 1;
            return;
        }
    if (stack[0] != 0) stack[0] -= 1;
    else if (stack[1] != 0) stack[1] -= 1;
    else stack[2] -= 1;
}

void playerDo(int *stack)
{
    int which,amount;
    printf("請選擇移除哪堆: ");
    scanf("%d",&which);
    printf("請選擇移除個數: ");
    scanf("%d",&amount);
    stack[which-1] -= amount;
}

void showStone(int *stack)
{
    printf("\nStone Stack:");
    for (int i = 0; i <3 ;i++){
        printf("\n\nStack %d: ",i+1);
        for (int j = 0; j < stack[i]; j++) printf("* ");
    }
    printf("\n\n");
}

int main()
{
    srand(time(NULL));
    int player;
    int stack[3] = {};
    for (int i = 0; i < 3; i++) stack[i] = rand()%(MAX-2)+3;
    printf("請選擇先後手 當先手輸入[1] 後手[0]: ");
    scanf("%d",&player);
    printf("你選擇了 %s手\n",(player) ? "先" : "後");
    showStone(stack);
    for (;;)
    {
        if (player) playerDo(stack);
        else computerDo(stack);
        printf("%d %d %d\n",stack[0] ,stack[1] ,stack[2]);
        showStone(stack);
        if (stack[0] == 0 && stack[1] == 0 && stack[2] == 0) break;
        player++;
        player %= 2;
    }
    printf("Game Over %s贏了\n",(player) ? "玩家" : "電腦");
    system("pause");
    return 0;
}
