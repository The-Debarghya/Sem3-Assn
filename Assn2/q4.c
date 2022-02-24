#define MAX 30
#include"set.h"

int main(){
  int set1[MAX],set2[MAX],set3[MAX];
  int op;
  set1[0]=set2[0]=set3[0]=0;
  do{
     printf("\n1)Create\n2)Print\n3)Union\n4)Intersection\n5)Difference");
     printf("\n6)Symmetrec Difference \n7)Quit");
     printf("\nEnter Your Choice:");
     scanf("%d",&op);
     switch(op){
    case 1:
        printf("\nCreting First Set*******");
        create(set1);
        printf("\nCreating Second Set*****");
        create(set2);
        break;
    case 2: printf("\nFirst Set :\n");
        print(set1);
        printf("\n\nSecond Set :\n");
        print(set2);
        printf("\n\nThird Set :\n");
        print(set3);
        break;
    case 3: Union(set1,set2,set3);print(set3);break;
    case 4: intersection(set1,set2,set3);print(set3);break;
    case 5: difference(set1,set2,set3);print(set3);break;
    case 6: symmdiff(set1,set2,set3);print(set3);break;
     }
  }while(op!=7);
  return 0;
 }

