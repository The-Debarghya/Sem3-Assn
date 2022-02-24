#include "list.h"
int main(){
	List L;
	initList(&L);
	insertEnd(&L,12);
	insertEnd(&L,32);
	insertEnd(&L,14);
	insertEnd(&L,4);
	del(&L,3);
    insertEnd(&L,56);
    insertEnd(&L,63);
    insertEnd(&L,88);
	print(L);
	return 0;
}
