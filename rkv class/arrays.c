#include <stdio.h>  
int *getarray()  
{  
  static int arr[7];  
  printf("Enter the elements in an array : ");  
  for(int i=0;i<7;i++)  
  {  
      scanf("%d",&arr[i]);  
  }  
  return arr;  
      
}  
int main()  
{  
  int *ptr;  
  ptr=getarray();  
  printf("\nElements that you have entered are :");  
  for(int i=0;i<7;i++)  
  {  
      printf("%d \n", ptr[i]);  
  }  
}  



// #include<stdio.h>
// int main(){
//     char name[] = {'T',' ','p','r','u','d','h','v','i'};
//     char name1[] = "T prudhvi";
//     printf("%s\n",name);
//     printf("%s\n",name1);
//     printf("%c\n",2[name]);
//     //printf("%c\n",name1)

//     char fname[10],lname[10],fullname[20];
//     printf("enter your fullname");
//     scanf("%[^\n]s",fullname);
//     printf("enter your fname:");
//     scanf("%s",fname);
//     printf("enter your lname:");
//     scanf("%s",lname);
//     return 0 ;
// }