#ifndef SET_H
#define SET_H
#include<stdio.h>
#include<stdlib.h>

 /*function returns 1 or 0 depending on whether x belongs
  to set[] or not */

 int member(int set[],int x)
  { int i,n;
    n=set[0]; /* number of elements in the set*/
    for(i=1;i<=n;i++)
      if(x==set[i])
        return(1);

     return(0);
  }
   /*creates set[] with initial elements*/
 void create(int set[])
   {   int n,i;
       set[0]=0;/*make it a null set*/
       printf("\n No. of elements in the set:");
       scanf("%d",&n);
       printf("\n enter set elements :");
       for(i=1;i<=n;i++)
       scanf("%d",&set[i]);
       set[0]=n; //Number of elements.

   }

 void  print(int set[])
  { int i,n;
    n=set[0];/* number of elements in the set */
    printf("\nMembers of the set :-->");
    for(i=1;i<=n;i++)
       printf("%d  ",set[i]);
  }

 /* union of  set1[] and set2[] is stored in set3[]*/

void Union(int set1[],int set2[],int set3[])
  { int i,n;
    /* copy set1[] to set3[]*/
    set3[0]=0;/*make set3[] a null set */
    n=set1[0];/* number of elements in the set*/
    //Union of set1,set2= set1 + (set2-set1)
    for(i=0;i<=n;i++)
        set3[i]=set1[i];

    n=set2[0];
    for(i=1;i<=n;i++)
       if(!member(set3,set2[i]))
        set3[++set3[0]]=set2[i];  // insert and increment no. of elements
   }

/*intersection of set1[] and set2[] is stored in set3[]*/

void intersection(int set1[],int set2[],int set3[])
     {
    int i,n;
    set3[0]=0; /* make a NULL set*/
    n=set1[0];/* number of elements in the set*/
    for(i=1;i<=n;i++)
      if(member(set2,set1[i])) /* all common elements are inserted in set3[]*/
           set3[++set3[0]]=set1[i];  // insert and increment no. of elements
     }

/*difference of set1[] and set2[] is stored in set3[]*/

void difference(int set1[],int set2[],int set3[])
      { int i,n;
    n=set1[0];/* number of elements in the set*/
    set3[0]=0;/*make it a null set*/
    for(i=1;i<=n;i++)
       if(!member(set2,set1[i]))
         set3[++set3[0]]=set1[i];  // insert and increment no. of elements
      }

 void symmdiff(int set1[],int set2[],int set3[])
      { int i,n;
    n=set1[0];/* number of elements in the set*/
    set3[0]=0;/*make it a null set*/
    //Calculate set1-set2
    for(i=1;i<=n;i++)
       if(!member(set2,set1[i]))
         set3[++set3[0]]=set1[i];  // insert and increment no. of elements
    //Calculate set2-set1
    n=set2[0];
    for(i=1;i<=n;i++)
       if(!member(set1,set2[i]))
         set3[++set3[0]]=set2[i];  // insert and increment no. of elements

      }
#endif
