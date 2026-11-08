#include <stdio.h>

typedef struct 
{
    int power;   
    int temp;    
} AC;
void switchPower(AC *ps);
void setTemp(AC *ps);
void riseTemp(AC *ps);
void downTemp(AC *ps);
int main()
{
    AC ac = {0, 25}; 
    int choice;

    while (1) {
        printf("\n===== 空调菜单 =====\n");
        printf("1. 开关机\n");
        printf("2. 设置温度\n");
        printf("3. 升温\n");
        printf("4. 降温\n");
        printf("5. 退出\n");
        printf("请选择：");
        scanf("%d", &choice);

        switch (choice) {
            case 1: switchPower(&ac); break;
            case 2: setTemp(&ac); break;
            case 3: riseTemp(&ac); break;
            case 4: downTemp(&ac); break;
            case 5: printf("退出系统\n"); return 0;
            default: printf("无效输入，请重试\n");
        }
    }
}
void switchPower(AC *ps) 
{
    ps->power = !ps->power;
    if (ps->power)
        printf("空调已开机，当前温度：%d\n", ps->temp);
    else
        printf("空调已关机\n");
}
void setTemp(AC *ps)
{
    if (!ps->power) 
    {
        printf("请先开机！\n");
        return;
    }
    int t;
    printf("请输入目标温度（16~30）：");
    scanf("%d", &t);
    if (t < 16) t = 16;
    if (t > 30) t = 30;
    ps->temp = t;
    printf("温度已设置为：%d\n", ps->temp);
}
void riseTemp(AC *ps)
{
    if (!ps->power) {
        printf("请先开机！\n");
        return;
    }
    if (ps->temp < 30) {
        ps->temp++;
        printf("升温至：%d\n", ps->temp);
    } else {
        printf("已达最高温度30度\n");
    }
}
void downTemp(AC *ps) 
{
    if (!ps->power) {
        printf("请先开机！\n");
        return;
    }
    if (ps->temp > 16) {
        ps->temp--;
        printf("降温至：%d\n", ps->temp);
    } 
    else
    {
        printf("已达最低温度16度\n");
    }
}