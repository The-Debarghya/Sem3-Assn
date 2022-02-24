#ifndef STR_H
#define STR_H
#include <stdio.h>
#include <stdlib.h>
int str_len(char* str){
	int i=0;
	while(str[i]!='\0'){
		i++;
	}
	return i;
}
int strcomp(char* str1,char* str2){
	int i=0;
	while(str1[i]!='\0' && str2[i]!='\0'){
		if(str1[i]!=str2[i]){
 			return str1[i]-str2[i];
		}
		i++;
	}
	if(str1[i]=='\0' && str2[i]=='\0'){
		return 0;
	}
	else if(str1[i]=='\0' && str2[i]!='\0'){
		return -1;
	}
	else{
		return 1;
	}
}
char* concatstr(char* str1,char* str2){
	char* str;
	int len1=str_len(str1),len2=str_len(str2);
	str=(char *)(malloc((len1+len2+1)*sizeof(char)));
	int i=0,j=0;
	while(str1[j]!='\0'){
		str[i]=str1[j];
		i++;
		j++;
	}
	j=0;
	while(str2[j]!='\0'){
		str[i]=str2[j];
		i++;
		j++;
	}
	str[i]='\0';
	return str;
}
int wordcount(char *str){
	int ct=0, n;
	n = str_len(str);
	for(int i=0; i<n; i++){
		if(str[i] == ' ' && str[i+1] != ' '){
			ct = ct+1;
		}
		else
			continue;
	}
	return (ct+1);
}
char* revstr(char* str){
	int i,len=str_len(str);
	char * revstr;
	revstr=(char *)(malloc((len+1)*sizeof(char)));
	for(i=0;i<len;i++){
		revstr[i]=str[len-i-1];
	}
	revstr[len]='\0';
	return revstr;
}
void copystr(char *dest,char *src){
	int i=0;
	while(src[i]!='\0'){
		dest[i]=src[i];
		i++;
	}
	dest[i]='\0';
}
int issub(char *str1,char *str2){
	int i,j,k,len1=str_len(str1),len2=str_len(str2),flag=0;
	if(len1>len2){
		return 0;
	}
	else{
		for(i=0;i<len2;i++){
			k=i;
			flag=1;
			for(j=0;j<len1;j++){
				if(str2[k]!=str1[j]){
					flag=0;
					break;
				}
				k++;
			}
			if(flag){
				return 1;
			}
		}
		return 0;
	}
}
#endif
