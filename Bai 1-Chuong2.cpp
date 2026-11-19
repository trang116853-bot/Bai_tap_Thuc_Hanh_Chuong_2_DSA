#include <stdio.h>
void Nhap(float*a, int n){
	for(int i = 0; i < n; i++){
		printf("Nhap phan tu a[%d]: ", i);
		scanf("%f", a+i);
	}
}
void In(float*a, int n){
	printf("Mang mot chieu vua nhap la: ");
	for(int i = 0; i < n; i++){
		printf("%.2f ", *(a+i));
	}
	printf("\n");
}
int main(){
	float a[100];
	int n;
	printf("Nhap n phan tu: ");
	scanf("%d", &n);
	Nhap(a, n);
	In(a, n);
	return 0;
}
