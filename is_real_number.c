#include <stdio.h>
#include <stdlib.h>

int isRealNumber(char x[]){
	int i=0, cont = 0,cont2=0, tam = 0;
	while(1){
		if(x[tam]=='\0'){
			break;
		}
		if(x[tam]=='.'){
			cont++;
		}
		else if(x[tam]<'0'||x[tam] > '9' ) cont2++;
		tam++;
	}
	while(1){
		if(cont>=2){
			return 0;
			break;
		}
		else if(x[0]=='.'){
			return 0;
			break;
		}
		else if((x[i]<'0') || (x[i]>'9')){
			return 0;
			break;
		}
		else if(cont2>=1){
			return 0;
			break;
		}
		else if(x[tam-1]=='.'){
			return 0;
			break;
		}
		else{
			return 1;
			break;
		}
		i++;
	}
}

int main(){
	char string[1000];
	scanf("%s", string);
	printf("%d\n", isRealNumber(string));
	return 0;
}