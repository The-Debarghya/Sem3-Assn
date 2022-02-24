#include <stdio.h>
unsigned int f_recur(unsigned int n){
	if(n==1)
		return 0;
	else if(n==2)
		return 1;
	else
		return f_recur(n-1)+f_recur(n-2);//the recursive call statement
}
unsigned int f_iter(unsigned int n){
	if(n==1)
		return 0;
	else if(n==2)
		return 1;
	unsigned int a=0;
	unsigned int b=1;
	n-=2;
	while(n-->0) {
		unsigned int c=a+b;
		a=b;
		b=c;
	}
	return b;
}
int main()
{
	unsigned int n;
	scanf("%d", &n);
	printf("%d\n", /*f_iter(n)*/f_recur(n));
  return 0;
}
