#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
typedef char ElemType;

typedef struct
{
    ElemType *top;
    ElemType *base;
    int stackSize;
}sqStack;

void InitStack(sqStack *s)
{
    s->base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if(!s->base)
    {
        exit(0);
    }
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

void Push(sqStack *s,ElemType e)
{
    if(s->top - s->base >= s->stackSize)
    {
        s->base = (ElemType*)realloc(s->base,(s->stackSize + STACKINCREMENT * sizeof(ElemType)));
        if(!s->base)
        {
            exit(0);
        }
    }
    *(s->top) = e;
    s->top++;
}

void Pop(sqStack *s,ElemType *e)
{
    if(s->top == s->base)
    {
        return;
    }
    *e = *--(s->top);
}

int StackLen(sqStack s)
{
    return (s.top - s.base);
}

int main()
{
    sqStack s;
    int len,i,sum = 0;
    ElemType c;

    InitStack(&s);
    printf("请输入二进制数，输入#表示结束！\n");
    scanf("%c",&c);

    while(c != '#')
    {
        Push(&s,c);
        scanf("%c",&c);
    }
    getchar();

    len = StackLen(s);
    printf("当前栈的容量为：%d\n",len);
    for(i = 0;i < len;++i)
    {
        Pop(&s,&c);
        sum += (c - 48) * pow(2,i);
    }
    printf("转换为十进制数为：%d\n",sum);
}
