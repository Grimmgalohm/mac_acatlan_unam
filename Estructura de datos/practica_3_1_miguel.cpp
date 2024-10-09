#include <stdio.h>

int main(){
	int x[8] = {0};
	int y[8] = {0};
	
	for(int i=0;i<6;i++){
		printf("Cara %d\n", i+1);
		for(int j=0;j<8;j++){
			if(j==0 || j==7){
				for(int k=0;k<8;k++){
					y[k]=1;
					printf("%d", y[k]);	
				}
			}
			else{
				for(int k=0;k<8;k++){
					if(k==0 || k==7){
						y[k]=1;
					}
					else{
						y[k]=0;
					}
					printf("%d", y[k]);
				}
			}
			printf("\n");
		}
		printf("\n");
	}
}
