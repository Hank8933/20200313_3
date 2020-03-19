#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 12

int total = 0;
int win = 0;

int playerRound(int *stack)
{
    int c,n;
    printf("請輸入移動哪[堆] [數量]: ");
    scanf("%d%d",&c,&n);
    if (n > 2 || n < 1 || stack[c-1] < n || c > 3 || c < 1)
    {
        printf("請重新輸入!\n");
        return 0;
    }
    else
    {
        stack[c-1] -= n;
        return 1;
    }
}

void check(int a,int b,int c,int player)
{
    int i;

    if(a == 0 && b == 0 && c == 0)
    {
        total++;

        if(player % 2 == 1)
            win++;
    }

    for(i = 1; i <= 2 && a - i >= 0; i++) check(a - i, b, c, player + 1);
    for(i = 1; i <= 2 && b - i >= 0; i++) check(a, b - i, c, player + 1);
    for(i = 1; i <= 2 && c - i >= 0; i++) check(a, b, c - i, player + 1);
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
    int stack[3];
    int player = 0; // 0 user 1 NPC
    int choose, num, i;
    double accuracy, max = -1;
    for (int i = 0; i < 3; i++) stack[i] = rand()%(MAX-2)+3;
    printf("請選擇先後手 當先手輸入[0] 後手[1]: ");
    scanf("%d",&player);
    printf("你選擇了 %s手\n",(player) ? "後" : "先");

    for (;;)
    {
        showStone(stack);

        if(stack[0] == 0 && stack[1] == 0 && stack[2] == 0)
        {
            printf("Game Over %s贏了\n",(player & 1) ? "玩家" : "電腦");
            break;
        }
        if(player % 2 == 0) while(!playerRound(stack));
        else  //computer
        {
            printf("電腦思考中...\n");
            max = -1;
            for(i = 1; i <= 2 && stack[0] - i >= 0; i++)
            {
                win = total = 0;
                check(stack[0] - i, stack[1], stack[2], 1);
                accuracy = (double)win / total;
                //printf("勝率: %f\n",accuracy);
                if(max < accuracy)
                {
                    choose = 1;
                    num = i;
                    max = accuracy;
                }
            }

            for(i = 1; i <= 2 && stack[1] - i >= 0; i++)
            {
                win = total = 0;
                check(stack[0], stack[1] - i, stack[2], 1);
                accuracy = (double)win / total;
                //printf("勝率: %f\n",accuracy);
                if(max < accuracy)
                {
                    choose = 2;
                    num = i;
                    max = accuracy;
                }
            }

            for(i = 1; i <= 2 && stack[2] - i >= 0; i++)
            {
                win = total = 0;
                check(stack[0], stack[1], stack[2] - i, 1);
                accuracy = (double)win / total;
                //printf("勝率: %f\n",accuracy);
                if(max < accuracy)
                {
                    choose = 3;
                    num = i;
                    max = accuracy;
                }
            }

            if(choose == 1) stack[0] -= num;
            if(choose == 2) stack[1] -= num;
            if(choose == 3) stack[2] -= num;
        }
        player++;
    }
    system("pause");
    return 0;
}
