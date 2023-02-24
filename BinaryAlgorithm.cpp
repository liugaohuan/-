#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//链表存储结构
typedef struct BSTNode {
    char data;
    struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

// 链栈存储结构
typedef struct StackNode
{
    BSTree data;        // 栈中结点的数据域
    struct StackNode *next; // 结点的指针域   
} StackNode, *LinkStack;

// 初始化栈函数
void InitStack(LinkStack &s)
{
    s = NULL;
    return;
}

// 创建二叉树函数
void CreateBiTree(BSTree &T)
{
    char e;
    e = getchar();
    if (e == '#')
    {
        T = NULL;
    }
    else
    {
        T = (BSTNode *)malloc(sizeof(BSTNode));
        T->data = e;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

//不带头结点的入栈函数
void Push(LinkStack &s, BSTree T)
{
  //生成存储新元素的结点
    LinkStack sNode =(LinkStack)malloc(sizeof(StackNode));
    //将新结点sNode的数据域置为e
    sNode->data=T;
    //将新结点插入栈顶
    sNode->next = s;//头插法
    //修改栈顶指针,指向新结点
    s=sNode;
}

// 判断栈是否为空
bool EmptyStack(LinkStack s)
{
    if (s->next != NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//获取栈顶元素
BSTree GetTop(LinkStack s)
{
    BSTree t;
    t = s->next->data;
    return t;
}

//带头结点的出栈函数
void pop(LinkStack &s)
{
    LinkStack p = (LinkStack)malloc(sizeof(StackNode));
    p = s->next;
    s->next = p->next;
    free(p);
}

//先序非递归遍历
void PreOrderTraverse(BSTree T)
{
    LinkStack s;
    BSTree p;
    p = T;
    InitStack(s);
    while(p || !EmptyStack(s))
    {
        if(p)
        {
            printf("%c\n", p->data);
            Push(s, p);
            p = p->lchild;
        }
        else
        {
            p = GetTop(s);
            pop(s);
            p = p->rchild;
        }
    }
    printf("\n");
}

//折半查找
BSTree SearchBST(BSTree T, char c){
    //在根指针T所指二叉排序树中递归地查找某关键字等于key的数据元素，若查找成功 ， 则返回指向该数据元素结点的指针， 否则返回空指针
    int element;
    element=int(c);
    if ((!T) || element==T->data) return T;
    else if (c<T->data) return SearchBST (T->lchild,c);
    else return SearchBST(T->rchild, c);
}

int main()
{
    BSTree bitree;
    printf("Creating binary tree, e.g. DBC##AE###FG###, empty node use # .\n");
    CreateBiTree(bitree);
    printf("PreOrder traverse tree:\n");
    PreOrderTraverse(bitree);
    BSTree result = SearchBST(bitree, 'A');
    printf("result:%p\n",result);
    printf("result:%c",result->data);
    return 0;
}