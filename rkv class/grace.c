#include<stdio.h>
int main(){
    int class,failed;
    printf("enter your class(1 or 2 or 3)");
    scanf("%d",&class);
    printf("how many sub you failed in");
    scanf("%d",&failed);
    switch (class)
    {
    case 1:
        if (failed>3){
            printf("you got 0 marks");
        else 
        {
           printf("you scored 25 marks");
        }
        
        }
        }
        break;
    case 2:

        break;
    case 3:

        break;
    
    default:
        break;
    }



    return 0;
}