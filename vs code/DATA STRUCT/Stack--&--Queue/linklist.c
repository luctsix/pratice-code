/*   缺陷：不适用于计算过程中会出现 负数 的算数表达式
   
    *改进建议：
        1.将NODE结构体数据域类型改为int 或者 void*
        2.使用企业链表
            struct node{
                void* ptr;
                int   data;
            };
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void* LinkStack;

#if 1           //链栈操作接口
    typedef struct node{
        char ch;
        struct node *next;
    }NODE;
    typedef struct LinkStack{
        NODE head;
        int  size;
    }LINKLIST;

    //初始化链栈
    LinkStack Init_LinkStack(){
        LINKLIST *stack = (LINKLIST*)malloc(sizeof(LINKLIST));
        stack->head.next = NULL;
        stack->size = 0;
        //printf("init success....\n");
        return (LinkStack)stack; 
    }
    //压栈 入栈
    int Push_LinkStack(LinkStack stack, char data){
        //printf("test1...\n");
        if(stack == NULL || data == ' ')
        {
            return -1;
        }
        //printf("test2...\n");
        LINKLIST* mystack = (LINKLIST*)stack;
        //printf("test3...\n");
        NODE* pnew = malloc(sizeof(NODE));
        pnew->ch = data;
        //printf("test4...\n");
        pnew->next = mystack->head.next;
        //printf("test5...\n");
        mystack->head.next = pnew;
        //printf("test6...\n");
        mystack->size++;
        //printf("push success....\n");
        return 0;
    }
    //出栈 弹栈
    int Pop_LinkStack(LinkStack stack){
        LINKLIST* mystack = (LINKLIST*)stack;
        if(mystack->size <= 0)
            return -1;
        mystack->head.next = mystack->head.next->next;
        mystack->size--;
        //printf("pop success....\n");
        return 0;
    }
    //获取栈顶数据
    char GetTop_LinkStack(LinkStack stack){
        if(stack == NULL)
        {
            return 0;
        }
        LINKLIST* mystack = (LINKLIST*)stack;
        if(mystack->size <= 0){
            return 0;
        }
        //printf("get top success....\n");
        return mystack->head.next->ch;
    }
    //获取栈的size
    int GetSize_LinkStack(LinkStack stack){
        LINKLIST* mystack = (LINKLIST*)stack;
        if(mystack->size <0)
            return -1;
        //printf("get size success....\n");    
        return mystack->size;
    }
    //判空
    int IsEmptyLinkStack(LinkStack stack){
        LINKLIST* mylist = (LINKLIST*)stack;
        if(mylist->size <= 0)   return 1;
        return 0;
    }
    //销毁栈
    void Destroy_LinkStack(LinkStack stack){
        free(stack);
    }
#endif

int myCompare(char ch1, char ch2){      //比较两个运算符的优先级、、同级或优先级低则出栈
    // * / % > + -
    switch (ch1)
    {
        case '+':
        case '-':
        {
            if(ch2=='(')    {return 1;}
            else    {return 0;}
        }  
        case '*':
        case '/': 
        case '%':
        {
            if(ch2=='+'||ch2=='-'||ch2=='(')    {return 1;}
            else    {return 0;}
        }    
    }
}
int myCalculate(int i, int j, char ch);     //前向声明


int main()
{
    //test01(); //链表接口测试函数(接口已改，不再适用)
#if 1       //中缀转后缀
    //char *str = "1*2+9%6*2-4/(5-3)";    //中缀表达式
    char str[128] = "";
    printf("please input the impression:"); //输入表达式
    gets(str);
    char str2[128] = {0};       //用于保存后缀表达式
    char *p = str;
    LinkStack stack;        //创建链栈
    stack = Init_LinkStack();       //初始化链表
    int i = 0;              //用作str2[]下标
    while(*p != '\0')       //遍历str字符串
    {
        if(*p=='+'||*p=='-'||*p=='*'||*p=='/'||*p=='%') //同级或优先级低则出栈
        {
            if(IsEmptyLinkStack(stack))        //栈空则直接入栈
            {
                Push_LinkStack(stack, *p);
                p++;
                continue;            //结束本次循环
            }
            char ch = GetTop_LinkStack(stack);  //获取栈顶元素用于和当前元素进行比较优先级
            if(myCompare(*p, ch))
            {
                Push_LinkStack(stack, *p);      //优先级高--入栈
            }
            else        //优先级低--栈顶元素出栈--打印--当前符号入栈
            {
                printf("%c ", ch);
                str2[i++] = ch;
                Pop_LinkStack(stack);
                Push_LinkStack(stack, *p);
            }
            
        }
        else if(*p=='(')    //左括号直接入栈，优先级最低
        {
            Push_LinkStack(stack, *p);
        }
        else if(*p == ')')  //右括号--栈顶元素连续-获取打印并且出栈--直到遇到左括号--丢弃左右括号
        {
            while(1)
            {
                char ch = GetTop_LinkStack(stack);
                if(ch == '(')   
                {
                    Pop_LinkStack(stack);
                    break;
                }
                printf("%c ", ch);
                str2[i++] = ch;
                Pop_LinkStack(stack);
            }
        }
        else if(*p>'0' && *p<='9')  //遇到0-9的数字字符直接打印出来 
        {
            printf("%c ", *p);
            str2[i++] = *p;            
        }
        p++;        //指针移到下一字符位置
    }
    while(!IsEmptyLinkStack(stack))     //将栈中剩余符号取出打印--同时出栈丢弃
    {
        char ch = GetTop_LinkStack(stack);
        printf("%c ", ch);
        str2[i++] = ch;
        Pop_LinkStack(stack);
    }
    printf("\nstr2 = %s\n", str2);      //此时str2存着str的后缀表达式
#endif
 
#if 1  //后缀计算
    
    // char str2[] = "12*96%2*323-/-+";
    // int i = strlen(str2)+1;
    // LinkStack stack = NULL;
    // stack = Init_LinkStack();

    for(int j=0; j<i; j++)      
    {
        if(str2[j]>='0' && str2[j]<='9')            //如果是数字字符，直接入栈
        {
            Push_LinkStack(stack, str2[j]);
        }
        else{                                       //str2[j]是运算符字符
            char ch1 = GetTop_LinkStack(stack);     //取出第一个栈顶元素作为右操作数
            Pop_LinkStack(stack);                   //丢弃以取出的元素
            char ch2 = GetTop_LinkStack(stack);     //取出第二个栈顶元素作为左操作数
            Pop_LinkStack(stack);                   //丢弃
            printf("ch1 = %c  ch2 = %c", ch1, ch2); //查看所取出的字符是否正确
            int right = ch1 - '0';                   //字符转数字
            int left = ch2 - '0';                  //字符转数字
            int sum = myCalculate(left, right, str2[j]);    //计算  left str2[j]  right
            printf("  sum = %d\n", sum);        
            char s = sum + '0';         //数字转字符
            Push_LinkStack(stack, s);   //计算结果入栈
        }
    }
    char ch1 = GetTop_LinkStack(stack); //取出最终计算结果
    Pop_LinkStack(stack);               //清空栈
    printf("final result:%c\n", ch1);

    Destroy_LinkStack(stack);           //销毁链栈
#endif
    return 0;
}
int myCalculate(int i, int j, char ch){      //根据运算符计算
    switch(ch){
        case '+': return i+j;
        case '-': return i-j;
        case '*': return i*j;
        case '/': return i/j;
        case '%': return i%j;
    }
}

#if 0
    typedef struct person{          //用户数据
        LinkStack ptr;
        char name[16];
        int age;
    }PERSON;    
    //void test01();
    void test01(){
        printf("test...\n");
        PERSON p = {NULL, "hello", 20};
        LinkStack stack = Init_LinkStack();
        Push_LinkStack(stack, &p);
        LinkStack data= GetTop_LinkStack(stack);
        PERSON *p2 = (PERSON*)data;
        printf("p2:%s %d\n", p2->name, p2->age);
        Pop_LinkStack(stack);
        printf("current size:%d\n", GetSize_LinkStack(stack));
        Destroy_LinkStack(stack);
    }
#endif