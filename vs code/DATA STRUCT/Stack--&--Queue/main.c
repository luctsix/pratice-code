#include "seqstack.c"

typedef struct person{
    char name[64];
    int age;
}PERSON;

void myPrint(SeqStack data)
{
    PERSON* p = (PERSON*)data;
    printf("%s  %d\n", p->name, p->age);
}

int main()
{
#if 0
    PERSON p1 = {"老师", 18};
    PERSON p2 = {"学生", 20};
    PERSON p3 = {"教授", 21};
    PERSON p4 = {"校长", 22};
    PERSON p5 = {"院长", 23};
    
    SeqStack stack = NULL;
    stack = Init_seqstack();
    Push_SeqStack(stack, &p1);
    Push_SeqStack(stack, &p2);
    Push_SeqStack(stack, &p3);
    Push_SeqStack(stack, &p4);
    Push_SeqStack(stack, &p5);

    // SeqStack top_data = GetTop_SeqStack(stack);
    // myPrint(top_data);
    // int n = GetSize_SeqStack(stack);
    // printf("stack->size = %d\n", n);
    // printf("----------------\n");

    SeqStack top_data;
    while(!IsEmpty_SeqStack(stack))
    {
        top_data = GetTop_SeqStack(stack);
        myPrint(top_data);
        printf("stack->size = %d\n", GetSize_SeqStack(stack));
        Pop_SeqStack(stack);
    }
    Destroy_SeqStack(stack);
#endif
    

    return 0;
}