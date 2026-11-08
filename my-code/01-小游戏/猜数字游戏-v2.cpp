// 学习到了 rand srand 两个函数
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int answer = rand() % 100 + 1;
    int input;
    printf("请输入1-100中的一个整数：\n");

    while (1) // 死循环
    {
        scanf("%d", &input);
        if (answer > input)
            printf("大了！\n");
        if (answer < input)
            printf("小了！\n");
        if (input == answer)
        {
            printf("猜对了！\n");
            break;
        }

        else
            printf("没猜对！\n");
    }
}