#include <stdio.h>
#include <stdlib.h>

void Conversion(int number, int scale){
	int result = 0;
	int remain = 0;
	if(number != 0){
		result = number % scale;
		Conversion(number/scale, scale);

		if(result < 10){
			printf("%d", result);
		}
		else if(result >= 10){
			printf("%c", 'A' + result - 10);
		}
	}
	else{
		return;
	}
}

int main(int argc, char* argv[], char* env[]){
	int number = -1;
	int scale = -1;
	printf("Input 0 0 to exit!\n");
	printf("please number and scale.\n");
	scanf("%d%d", &number ,&scale);
	
	while(number != 0 && scale != 0){
		Conversion(number, scale);
		printf("\n");
		printf("please number and scale.\n");
		scanf("%d%d", &number ,&scale);
	}
	
	printf("\n");
	printf("exit!\n");

	system("pause");
	return 0;
}