#include "search.h"

typedef struct{}BiTree;

/*---------二叉查找树-------------------*/
BiTree SearchBST(BiTree T, cKeyType key){
    if((!T) || EQ(key,T->data.key)) return(T);
    else if LT(key, T->data.key)    return(SearchBST(T->lchild), key);
    else return(SearchBST(T->rchild), key);       
} 

Status SearchBST(BiTree T, cKeyType key, BiTree f, BiTree &p){
    if(!T) {p = f; return FALSE;}
    else if EQ(key, T->data.key){p = T; return TRUE;}
    else if LT(key, T->data.key) return SearchBST(T->lchild, key, T, p);
    else return SearchBST(T->rchild,key, T, p);
}

Status InsertBST(BiTree &T, ElemType e){
    if(!SearchBST(T, e.key, NULL, p)){
        s = (BiTree)malloc(sizeof(BiNode));
        s->data = e; s->lchild = s->rchild = NULL;
        if(!p) T = s;
        else if LT(e.key, p->data.key)  p->lchild = s;
        else p->rchild = s;
        return TRUE;
    }
    else return FALSE;
}