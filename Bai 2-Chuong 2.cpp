#include <stdio.h>
#include <stdlib.h>
void Nhap(float*a, int hang, int cot){
	int i, j;
	for (int i = 0; i < hang; i++){
		for (int j = 0; j < cot; j++){
			printf("Nhap phan tu a[%d][%d]: ", i, j);
			scanf("%f", a+i*cot+j);
		}
	}
}
void In(float*a, int hang, int cot){
	int i, j;
	printf("Mang hai chieu vua nhap la: ");
	for (int i = 0; i < hang; i++){
		for (int j = 0; j < cot; j ++){
			printf("%.2f ", *(a+i*cot+j));
		}
		printf("\n");
	}
}
int main(){
	float*a;
	int hang, cot;
	printf("Nhap so hang va so cot: ");
	scanf("%d%d", &hang, &cot);
	a = (float*) malloc(hang * cot * sizeof(float));
	if ( a == NULL){
		printf("Bo nho khong du de cap phat!\n");
		exit(0);
	}
	Nhap(a, hang, cot);
	printf("\nDu lieu ma tran ban dau:\n");
	In(a, hang, cot);
	free(a);
	a = NULL;
	return 0;
}
