#include <stdio.h>
#include <stdlib.h>
typedef struct {
	char hoten[30];
	int masv;
	float d1, d2, d3;
	
}Data;
void Nhap(Data*ds, int n){
	int i;
	for (int  i= 0; i < n; i++){
		printf("\nNhap thong tin sinh vien thu %d: ", i+1);
		printf("\nNhap ma sinh vien: ");
		scanf("%d", &((ds + i)->masv));
		printf("Nhap ho ten: ");
		scanf(" %[^\n]", (ds + i)->hoten);
		printf("Nhap diem 1, diem 2, diem 3: ");
		scanf("%f %f %f", &((ds + i)->d1), &((ds + i)->d2), &((ds + i)->d3));
	}
}
void In(Data*ds, int n){
	int i;
	for (int i = 0; i < n; i++){
		printf("Ho ten: %s | Ma SV: %d | Diem 1: %.2f | Diem 2: %.2f | Diem 3: %.2f\n",(ds + i)->hoten,(ds + i)->masv,(ds + i)->d1, (ds + 1)->d2, (ds + i)->d3;
	}
}
int main(){
	Data*ds;
	int n;
	printf("Nhap so luong sinh vien: ");
	scanf("%d", &n);
	ds = (Data*) malloc(n * sizeof(Data));
	if (ds == NULL){
		printf("Bo nho khong du de cap phat!\n");
		exit(0);
	}
	Nhap(ds, n);
	printf("\nDu lieu ds sinh vien:\n");
	In(ds, n);
	free(ds);
	ds = NULL;
	return 0;
}
