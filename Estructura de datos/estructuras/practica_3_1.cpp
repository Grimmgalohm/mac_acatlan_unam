#include <stdio.h>

int main(){
	int i,j,k,cubo[7][7][7];
	for(i=0; i<7; i++){
		for(j=0; i<7; i++){
			for(k=0; i<7; i++){
				if((i==0 || i==7)||(j==0 || i==7)||(k==0 || k==7)){
					cubo[i][j][k]=1;
				}else{
					cubo[i][j][k]=0;
				}
			}
		}
	}
	
	
	for(i=0; i<7; i++){
		for(j=0; i<7; i++){
			for(k=0; i<7; i++){
				printf(" %d ", cubo[i][j][0]);
			}
			printf("/n");
		}
	}
}
