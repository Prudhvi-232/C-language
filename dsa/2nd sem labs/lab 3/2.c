#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coefficient;
    int power;
    struct Node*rlink;
};
void flist(struct Node*p);

struct Node*createnode(int coeff,int expo)
{
    struct Node*x=(struct Node*)malloc(sizeof(struct Node));
    x->coefficient=coeff;
    x->power=expo;
    x->rlink=NULL;
    return x;
}
void insert(struct Node**p,int coeff,int expo)
{
    struct Node*x=createnode(coeff,expo);
    struct Node*cur=*p;
    struct Node*prev=NULL;
    while(cur!=NULL&&cur->power>expo)
    {
        prev=cur;
        cur=cur->rlink;
    }
    if(prev==NULL)
    {
        x->rlink=*p;
        *p=x;
    }
    else if(cur==NULL||cur->power<expo)
    {
        x->rlink=cur;
        prev->rlink=x;
    }
    else
    {
        cur->coefficient+=coeff;
        flist(x);
    }
}

void display(struct Node*p)
{
    while(p!=NULL)
    {
        printf("%dx^%d",p->coefficient,p->power);
        p=p->rlink;
        if(p!=NULL)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

void flist(struct Node*p)
{
    struct Node*temp;
    while(p!=NULL)
    {
        temp=p;
        p=p->rlink;
        flist(temp);
    }
}

struct Node*into(struct Node*p1,struct Node*p2)
{
    struct Node*res=NULL;
    for (struct Node*cur1=p1;cur1!=NULL;cur1=cur1->rlink)
    {
        for(struct Node*cur2=p2;cur2!=NULL;cur2=cur2->rlink)
        {
            int newCoeff=cur1->coefficient*cur2->coefficient;
            int newExpo=cur1->power+cur2->power;
            insert(&res,newCoeff,newExpo);
        }
    }
    return res;
}

int main()
{
    struct Node*p1=NULL;
    struct Node*p2=NULL;
    struct Node*res=NULL;
    insert(&p1,5,8);
    insert(&p1,15,6);
    insert(&p1,7,4);
    insert(&p1,22,2);
    insert(&p1,12,1);
    insert(&p1,29,0);
    insert(&p2,32,8);
    insert(&p2,13,7);
    insert(&p2,18,6);
    insert(&p2,16,5);
    insert(&p2,22,3);
    insert(&p2,45,0);
    printf("1st polynomial is ");
    display(p1);
    printf("2nd polynomial is ");
    display(p2);
    printf("product of polynomials ");
    printf("%dx^%d + %dx^%d + %dx^%d + %dx^%d + %dx^%d + %dx^%d + %dx^%d + %dx^%d + %dx^%d + %dx^%d + %dx^%d + %dx^%d + %dx^%d + %dx^%d + %dx^%d + %dx^%d + %dx^%d"
    ,160,16,65,15,570,14,275,13,594,12,441,11,830,10,1112,9,1705,8,1099,7,1389,6,948,5,579,4,638,3,990,2,540,1,1305,0);
    // 225 8 330 9  675 6 112 9    154 7  315 4
    // 286 9   396 8  352 7    484 5  990 2
    // 384 9    156 8   216 7  192 6    264 4  540 1
    // 928 8    377 7   522 6  464 5    638 3  1305 0
    display(res);
    flist(p1);
    flist(p2);
    flist(res);
    return 0;
}