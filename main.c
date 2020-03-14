#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 12
void tryEveryResult(int *wA)
{

}

void computerDo (int *stack)
{
    int wA[2];
    printf("電腦思考中...\n");

    stack[wA[0]] -= wA[1];
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

        showStone(stack);
        if (stack[0] == 0 && stack[1] == 0 && stack[2] == 0) break;
        player++;
        player %= 2;
    }
    printf("Game Over %s贏了\n",(player) ? "玩家" : "電腦");
    system("pause");
    return 0;
}
