#include "str.h"
#define Maxlen 50
char *String[10];
int Count=0;
void  readstr(char **str){
	*str=(char *)(malloc(Maxlen*sizeof(char)));
	printf("Enter String(Maxlen=%d):",Maxlen-1);
	scanf("\n%[^\n]s",*str);
}
char* rmwsp(char *str){
	char *strsp;
	int len=str_len(str),i=0,j=0;
	strsp=(char *)(malloc(len * sizeof(char)));
	while(str[i]!='\0'){
		if(str[i]!=' '){
			strsp[j]=str[i];
			j++;
		}
		i++;
	}
	strsp[i]='\0';
	return strsp;
}
void replace(char **str,char oldchar,char newchar){
  char *temp = *str;
  for (int j = 0; j < str_len(*str); j++) {
    if (temp[j] == oldchar) {
      temp[j] = newchar;
    }
  }
  printf("The changed string:%s\n", temp);
}
int main(){
	int choice,value;
  char temp[50];
	while(1){
		printf("Enter Choice\n--------------------\n");
		printf("1.Create A String\n2.Find Length Of String\n3.Compare 2 Strings\n4.Concatenate 2 Strings\n5.Swap 2 Strings\n");
		printf("6.Search for a substring\n7.Replace any letter with another in a string\n");
		printf("8.Count Number Of Words In the String\n9.Remove Space from String\n10.Reverse A String\n11.Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				readstr(&String[Count]);
				printf("%s\n",String[0]);
				break;
			case 2:
				readstr(&String[Count]);
				printf("Length = %d\n",str_len(String[Count]));
				break;
			case 3:
				printf("For comparing:\n");
				readstr(&String[Count+1]);
				value=strcomp(String[Count],String[Count+1]);
				if(value==0){
					printf("Both Are Same\n");
				}
				else if (value>0){
					printf("%s > %s\n",String[Count],String[Count+1]);
				}
				else{
					printf("%s < %s\n",String[Count],String[Count+1]);
				}
				break;
			case 4:
        printf("To Concatenate:\n");
        readstr(&String[Count]);
        readstr(&String[Count+1]);
				int l1=str_len(String[Count]),l2=str_len(String[Count+1]);
				String[Count+2]=(char *)(malloc((l1+l2+1)*sizeof(char)));
        copystr(String[Count+2],concatstr(String[Count],String[Count+1]));
				printf("The Concatinated String is :\n%s\n",String[Count+2]);
				break;
			case 5:
        readstr(&String[Count]);
        readstr(&String[Count+1]);
        copystr(temp, String[Count]);
        copystr(String[Count],String[Count+1]);
        copystr(String[Count+1],temp);
        printf("String1: %s String2: %s\n",String[Count],String[Count+1]);
				break;
			case 6:
        printf("Main string:\n");
        readstr(&String[Count]);
        printf("Substring you want to find:\n");
        readstr(&String[Count+1]);
        if(issub(String[Count+1],String[Count])){
						printf("Substring\n");
				}
				else{
            printf("Not A Substring\n");
        }
				break;
			case 7:
        readstr(&String[Count]);
				char oldchar,newchar;
        printf("Enter the charecter to be replaced :");
				scanf(" %c",&oldchar);
				printf("Enter the new charecter to be replaced by :");
				scanf(" %c",&newchar);
				replace(&String[Count],oldchar,newchar);
				break;
			case 8:
        readstr(&String[Count]);
        printf("The number of words in %s is %d\n",String[Count],wordcount(String[Count]));
        break;
			case 9:
        readstr(&String[Count]);
        copystr(String[Count],rmwsp(String[Count]));
        printf("The Changed String is :\n%s\n",String[Count]);
        break;
			case 10:
        readstr(&String[Count]);
        copystr(String[Count],revstr(String[Count]));
        printf("The Reversed String is :\n%s\n",String[Count]);
        break;
			case 11:
				exit(0);
		}
	}
  return 0;
}
