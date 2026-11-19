#include <stdio.h>
#include <stdlib.h>
void Nhap(float*a, int n){
	int i;
	for(int i = 0; i < n; i++){
		printf("Nhap phan tu a[%d]: ", i);
		scanf("%f", a+i);
	}
}
void In(float*a, int n){
	int i;
	printf("Mang mot chieu vua nhap la: ");
	for(int i = 0; i < n; i++){
		printf("%.2f ", *(a+i));
	}
	printf("\n");
}
int main(){
	float*a;
	int n;
	printf("Nhap n phan tu: ");
	scanf("%d", &n);
	a = (float*) malloc(n*sizeof(float));
	if (a == NULL){
		printf("Bo nho khong du de cap phat!\n");
		exit(0);
	}
	Nhap(a, n);
	printf("\nDu lieu mang ban dau:\n");
	In(a, n);
	free(a);
	a = NULL;
	return 0;
}
