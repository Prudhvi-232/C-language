#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int precedings(char c) {
    if (c=='^')
        return 3;
    else if(c=='*'||c=='/')
        return 2;
    else if(c=='+'||c=='-')
        return 1;
    else
        return -1;
}
char ass(char c) {
    if(c=='^'){
        return 'R';
    }else {
        return 'L';
    }
}
void infixtopostfix(char infix[]){
    char postfix[1000];
    int pindex = 0;
    int infixLength = strlen(infix);
    char stack[1000];
    int sindex=-1;
    for(int i=0;i<infixLength;i++){
        char curchar=infix[i];
        if((curchar>='a'&& curchar<='z')||(curchar>='A'&&curchar<='Z')||(curchar>='0'&&curchar<='9')){
            postfix[pindex++]=curchar;
        }else if(curchar=='('){
            stack[++sindex]=curchar;
        }else if(curchar==')'){
            while(sindex>=0&&stack[sindex]!='('){
                postfix[pindex++]=stack[sindex--];
            }
            sindex--;
        }else{
            while(sindex>=0&&(precedings(curchar)<precedings(stack[sindex])||(precedings(curchar)==precedings(stack[sindex])&&ass(curchar)=='L'))){
                postfix[pindex++]=stack[sindex--];
            }
            stack[++sindex]=curchar;
        }
    }
    while(sindex>=0){
        postfix[pindex++]=stack[sindex--];
    }
    postfix[pindex]='\0';
    printf("postfix exp %s\n", postfix);
}
int main(){
    char infixexp[1000];
    printf("enter infix exp: ");
    scanf("%s",infixexp);
    infixtopostfix(infixexp);
    return 0;
}