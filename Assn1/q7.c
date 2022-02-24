#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int ran(int a,int b){
	return a+ rand()%(b-a);
}
int main(){
	srand(time(NULL));
	int P=7919;

	int L;
	int R;
  printf("i \t Li \t\t Ri\n");
	for(int i=0; i<25; i++)	{
		L=ran(1000000, 10000000);//generating a large number
		R=L%P;
		printf("%d \t %d \t %d \n", i+1, L, R);
	}
	return 0;
}
