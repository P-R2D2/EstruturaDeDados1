#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	
	char banana[50];
	int quantidade=0,i;
	gets(banana);
	for (i = 0; i < strlen(banana); i++) {
        if (banana[i] != ' ' && isalpha(banana[i]) != 0)
            quantidade++;
    }
    printf("%d", quantidade);
	
}
