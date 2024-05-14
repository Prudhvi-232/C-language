// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int checkpara(const char*equa){
//     char stackin[100];
//     int tnode=-1;
//     const char*set[]={")(","}{","]["};
//     for(int i=0;equa[i]!='\0';i++){
//         if(equa[i]=='('||equa[i]=='{'||equa[i]=='['){
//             stackin[++tnode]=equa[i];
//         }else if(equa[i]==')'||equa[i]=='}'||equa[i]==']'){
//             if(tnode==-1||set[equa[i]-')'][0]!=stackin[tnode]){
//                 return 0;
//             }else{
//                 tnode--;
//             }
//         }
//     }
//     if(tnode==-1){
//         return 1;
//     }else return 0;
// }
// int main(){
//     char equa[100];
//     printf("enter the equation");
//     fgets(equa, sizeof(equa), stdin);
//     equa[strcspn(equa, "\n")] = '\0';
//     if (checkpara(equa)) {
//         printf("Balanced\n");
//     } else {
//         printf("Not Balanced\n");
//     }
//     return 0;
// }

#include <stdio.h>
int main(){
    printf("enter the equation");
    char equa;
    scanf("%c",&equa);
    printf("Balenced");
}