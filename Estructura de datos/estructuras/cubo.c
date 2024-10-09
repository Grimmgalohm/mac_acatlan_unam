/*
	Creación de un cubo tridimensional de nxnxn
*/
#include <stdio.h>
#define DIM 9

int main(){
	
	int i, j, k, cube[DIM][DIM][DIM],l,m;
	l=round((float)DIM/2)-1;
	/*for(i=0; i<9; i++){
		for(j=0; j<9; j++){
			for(k=0; k<9; k++){
				if( (i==0 || i==8) && (j==0 || j==8) || (k==0 || k==8) ){
					cube[i][j][k]=1;
				}else{
					cube[i][j][k]=0;
				}
			}
		}
	}*/
	printf("%d \n\n\n", l);
	
	/*for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++){
			for(k=0; k<DIM; k++){
				l--;
				if( ( (i==0 || i==DIM-1) && (j==0 || j==DIM-1) || (k==0 || k==DIM-1) ) || ( (i==(int)l&&j==(int)l&&k==(int)l)||(i==(int)l&&j==(int)l&&k==(int)l) ) ){
					cube[i][j][k]=1;
				}else{
					cube[i][j][k]=0;
				}
			}
		}
	}*/
	
	for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++){
			for(k=0; k<DIM; k++){
				l--;
				if( j>=k && k>4){
					cube[i][j][k]=1;
				}else{
					cube[i][j][k]=0;
				}
			}
		}
	}
	
	printf("Cara 1\n\n");
	for(j=0; j<DIM; j++){
		for(k=0; k<DIM; k++){
			printf("%d ",cube[0][j][k]);
		}
		printf("\n");
	}
	
	printf("\n\n");
	for(j=DIM; j>0; j--){
		for(k=DIM; k>0; k--){
			printf("%d ",cube[l][j][k]);
		}
		printf("\n");
	}
	
	return 0;
}
