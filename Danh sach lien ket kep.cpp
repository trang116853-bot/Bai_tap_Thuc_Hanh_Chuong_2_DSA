#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char hoten[30];
    int masv;
    float d1, d2, d3;
} Data;
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char hoten[30];
    int masv;
    float d1, d2, d3;
} Data;

typedef struct tagNode {
    Data infor;
    struct tagNode *prev; 
    struct tagNode *next; 
} Node;

typedef struct {
    Node *pHead;  
    Node *pTail;
    int spt;
} DList; 

/////////////////////////////////////
void initList(DList *L) {
    L->pHead = NULL;
    L->pTail = NULL;
    L->spt = 0;
}

/////////////////////////////////////
int emptyList(DList L) {
    return (L.spt == 0); 
}

/////////////////////////////////////
void insert_Head(DList *L, Data x) {
    Node *pp;
	pp = (Node*) malloc(sizeof(Node));
    pp->infor = x;
    pp->prev = NULL;
    pp->next = NULL;

    if (emptyList(*L)) {
        L->pHead = pp;
        L->pTail = pp;
    } else {
        L->pHead->prev = pp; 
        pp->next = L->pHead;
        L->pHead = pp;
    }
    L->spt++;
}

/////////////////////////////////////
void insert_Tail(DList *L, Data x) {
    Node *pp;
	pp = (Node*) malloc(sizeof(Node));
    pp->infor = x;
    pp->prev = NULL;
    pp->next = NULL;

    if (emptyList(*L)) {
        L->pHead = pp;
        L->pTail = pp;
    } else {
        L->pTail->next = pp;
        pp->prev = L->pTail; 
        L->pTail = pp;
    }
    L->spt++;
}

/////////////////////////////////////
void insert_After(DList *L, Node *q, Data x) {
	Node *pp;
    if (NULL == q)return;
	else {
        pp = (Node*) malloc(sizeof(Node));
        pp->infor = x;
        pp->next = q->next;
        q->next->prev=pp;
        pp->prev = q;
        if(q == L->pTail)L->pTail = pp;
        q->next=pp;
        L->spt++;
    }
}

/////////////////////////////////////

void del_Head(DList *L) {
	Node *pp;
    if (emptyList(*L)) {
        printf("Danh sach rong, khong the xoa!\n");
        return;
    }
    else{
    	pp = L->pHead;
    	L->pHead = pp->next;
    	if (L->pHead!=NULL) L->pHead->prev = NULL;    	
    	free(pp);
    	L->spt--;
    	if(L->pHead == NULL) L->pTail = NULL;
    	printf("Da xoa nut dau danh sach!\n");
	}
}
/////////////////////////////////////

void del_After(DList *L, Node *q) {
	Node *pp;
    if (NULL == q) return;
    else{
    pp = q->next; 
    q->next = pp->next;

    if (pp->next != NULL) pp->next->prev = q; 
    free(pp);
    L->spt--;
    if (NULL == L->pTail || pp ==L->pTail)
    	L->pTail = q;
	}
}


/////////////////////////////////////
Node* search(DList L, int ma) {
    Node *pp = L.pHead;
    while (pp != NULL && pp->infor.masv != ma) {
        pp = pp->next;
    }
    return pp;
}

void del_Tail(DList *L) {
    if (emptyList(*L)) {
        printf("Danh sach rong, khong the xoa!\n");
        return;
    }
    Node *pp = L->pTail;
    L->pTail = pp->prev;
    
    if (L->pTail == NULL) {
        L->pHead = NULL;
    } else {
        L->pTail->next = NULL;
    }
    free(pp);
    L->spt--;
    printf("Da xoa nut cuoi danh sach!\n");
}
void del_K(DList *L, int k) {
    Node *p = search(*L, k);
    if (p == NULL) {
        printf("Khong tim thay sinh vien co ma %d!\n", k);
        return;
    }
    if (p == L->pHead) {
        del_Head(L);
    } else if (p == L->pTail) {
        del_Tail(L);
    } else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
        L->spt--;
        printf("Da xoa sinh vien co ma %d!\n", k);
    }
}
///////////////////////////////////////
void nhap(Data *x) {
    printf("Nhap ma sv: ");
    scanf("%d", &(x->masv));
    if (x->masv > 0) {
        printf("Nhap ho ten: ");
        scanf("%s", (x->hoten));
        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
    }
}

void in(Data x) {
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 3: %.2f\n", 
            x.hoten, x.masv, x.d1, x.d2, x.d3);
}


void processList(DList L) {
    if (emptyList(L)) {
        printf("Danh sach rong!\n");
        return;
    }
    Node *pp = L.pHead;
    while (pp != NULL) {
        in(pp->infor);
        pp = pp->next;
    }
}


void processListReverse(DList L) {
    if (emptyList(L)) {
        printf("Danh sach rong!\n");
        return;
    }
    Node *pp = L.pTail;
    while (pp != NULL) {
        in(pp->infor);
        pp = pp->prev;
    }
}

/////////////////////////////////////////
int main() {
    DList L;
    int kt = 0;
    Data x;
    int ma;
    Node *q;
    initList(&L);

    do {
        printf("\n=== Chuong trinh lam viec voi DSLK KEP SV ===\n");
        printf("1: Them nut vao dau danh sach\n");
        printf("2: Them nut vao cuoi danh sach\n");
        printf("3: Them nut vao sau mot nut khac trong danh sach\n");
        printf("4: Xoa nut o dau danh sach\n");
        printf("5: Xoa phan tu o sau phan tu q\n");
        printf("6: Xoa phan tu co khoa K trong danh sach\n");
        printf("7: Xoa phan tu o cuoi danh sach\n");
        printf("8: Duyet nguoc ds (tu cuoi ve dau)\n");
        printf("9: Duyet xuoi ds (tu dau den cuoi)\n");
        printf("0: Thoat\n");
        printf("Moi ban chon: ");
        int chon;
        scanf("%d", &chon);

        switch (chon) {
            case 1: 
                printf("Nhap thong tin sv can them vao dau\n");
                nhap(&x);
                if (x.masv > 0) 
                    insert_Head(&L, x);
                break;

            case 2: 
                printf("Nhap thong tin sv can them vao cuoi\n");
                nhap(&x);
                if (x.masv > 0) 
                    insert_Tail(&L, x);
                break;

            case 3:
                printf("Nhap ma sv cua nut dung truoc: ");
                scanf("%d", &ma);
                q = search(L, ma);
                if (q != NULL) {
                    printf("Nhap thong tin sv can chen\n");
                    nhap(&x);
                    if (x.masv > 0)
                        insert_After(&L, q, x);
                } else {
                    printf("Khong tim thay ma sv %d!\n", ma);
                }
                break;

            case 4: 
                del_Head(&L);
                break;

            case 5:
                printf("Nhap ma sv cua nut q (se xoa nut dung sau nut nay): ");
                scanf("%d", &ma);
                q = search(L, ma);
                if (q != NULL) {
                    if (q->next == NULL) {
                        printf("Nut nay dang o cuoi ds, khong co phan tu nao phia sau de xoa!\n");
                    } else {
                        del_After(&L, q);
                        printf("Da xoa phan tu phia sau sinh vien co ma %d!\n", ma);
                    }
                } else {
                    printf("Khong tim thay ma sinh vien %d!\n", ma);
                }
                break;
			case 6:
                printf("Nhap ma sv (khoa k) can xoa: ");
                scanf("%d", &ma);
                del_K(&L, ma);
                break;
			case 7:
                del_Tail(&L);
                break;
            case 8:
                printf("\n--- Danh sach duyet NGUOC ---\n");
                processListReverse(L);
                break;
			
            case 9: 
                printf("\n--- Danh sach duyet XUOI ---\n");
                processList(L);
                break;    

            case 0: 
                printf("Bye bye\n");
                kt = 1;
                break;
        }
    } while (kt == 0); 

    return 0;
}
typedef struct tagNode {
    Data infor;
    struct tagNode *prev; 
    struct tagNode *next; 
} Node;

typedef struct {
    Node *pHead;  
    Node *pTail;
    int spt;
} DList; 

/////////////////////////////////////
void initList(DList *L) {
    L->pHead = NULL;
    L->pTail = NULL;
    L->spt = 0;
}

/////////////////////////////////////
int emptyList(DList L) {
    return (L.spt == 0); 
}

/////////////////////////////////////
void insert_Head(DList *L, Data x) {
    Node *pp;
	pp = (Node*) malloc(sizeof(Node));
    pp->infor = x;
    pp->prev = NULL;
    pp->next = NULL;

    if (emptyList(*L)) {
        L->pHead = pp;
        L->pTail = pp;
    } else {
        L->pHead->prev = pp; 
        pp->next = L->pHead;
        L->pHead = pp;
    }
    L->spt++;
}

/////////////////////////////////////
void insert_Tail(DList *L, Data x) {
    Node *pp;
	pp = (Node*) malloc(sizeof(Node));
    pp->infor = x;
    pp->prev = NULL;
    pp->next = NULL;

    if (emptyList(*L)) {
        L->pHead = pp;
        L->pTail = pp;
    } else {
        L->pTail->next = pp;
        pp->prev = L->pTail; 
        L->pTail = pp;
    }
    L->spt++;
}

/////////////////////////////////////
void insert_After(DList *L, Node *q, Data x) {
	Node *pp;
    if (NULL == q)return;
	else {
        pp = (Node*) malloc(sizeof(Node));
        pp->infor = x;
        pp->next = q->next;
        q->next->prev=pp;
        q->next=pp;
        pp->prev = q;
        if(q == L->pTail)L->pTail = pp;
        L->spt++;
    }
}

/////////////////////////////////////

void del_Head(DList *L) {
	Node *pp;
    if (emptyList(*L)) {
        printf("Danh sach rong, khong the xoa!\n");
        return;
    }
    else{
    	pp = L->pHead;
    	L->pHead = pp->next;
    	if (L->pHead!=NULL) L->pHead->prev = NULL;    	
    	free(pp);
    	L->spt--;
    	if(L->pHead == NULL) L->pTail = NULL;
    	printf("Da xoa nut dau danh sach!\n");
	}
}
/////////////////////////////////////

void del_After(DList *L, Node *q) {
	Node *pp;
    if (NULL == q) return;
    else{
    pp = q->next; 
    q->next = pp->next;

    if (pp->next != NULL) pp->next->prev = q; 
    free(pp);
    L->spt--;
    if (NULL == L->pTail || pp ==L->pTail)
    	L->pTail = q;
	}
}

/////////////////////////////////////
Node* search(DList L, int ma) {
    Node *pp = L.pHead;
    while (pp != NULL && pp->infor.masv != ma) {
        pp = pp->next;
    }
    return pp;
}

///////////////////////////////////////
void nhap(Data *x) {
    printf("Nhap ma sv: ");
    scanf("%d", &(x->masv));
    if (x->masv > 0) {
        printf("Nhap ho ten: ");
        scanf("%s", (x->hoten));
        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
    }
}

void in(Data x) {
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 3: %.2f\n", 
            x.hoten, x.masv, x.d1, x.d2, x.d3);
}


void processList(DList L) {
    if (emptyList(L)) {
        printf("Danh sach rong!\n");
        return;
    }
    Node *pp = L.pHead;
    while (pp != NULL) {
        in(pp->infor);
        pp = pp->next;
    }
}


void processListReverse(DList L) {
    if (emptyList(L)) {
        printf("Danh sach rong!\n");
        return;
    }
    Node *pp = L.pTail;
    while (pp != NULL) {
        in(pp->infor);
        pp = pp->prev;
    }
}

/////////////////////////////////////////
int main() {
    DList L;
    int kt = 0;
    Data x;
    int ma;
    Node *q;
    initList(&L);

    do {
        printf("\n=== Chuong trinh lam viec voi DSLK KEP SV ===\n");
        printf("1: Them nut vao dau danh sach\n");
        printf("2: Them nut vao cuoi danh sach\n");
        printf("3: Them nut vao sau mot nut khac trong danh sach\n");
        printf("4: Xoa nut o dau danh sach\n");
        printf("5: Xoa phan tu o sau phan tu q\n");
        printf("8: Duyet nguoc ds (tu cuoi ve dau)\n");
        printf("9: Duyet xuoi ds (tu dau den cuoi)\n");
        printf("0: Thoat\n");
        printf("Moi ban chon: ");
        int chon;
        scanf("%d", &chon);

        switch (chon) {
            case 1: 
                printf("Nhap thong tin sv can them vao dau\n");
                nhap(&x);
                if (x.masv > 0) 
                    insert_Head(&L, x);
                break;

            case 2: 
                printf("Nhap thong tin sv can them vao cuoi\n");
                nhap(&x);
                if (x.masv > 0) 
                    insert_Tail(&L, x);
                break;

            case 3:
                printf("Nhap ma sv cua nut dung truoc: ");
                scanf("%d", &ma);
                q = search(L, ma);
                if (q != NULL) {
                    printf("Nhap thong tin sv can chen\n");
                    nhap(&x);
                    if (x.masv > 0)
                        insert_After(&L, q, x);
                } else {
                    printf("Khong tim thay ma sv %d!\n", ma);
                }
                break;

            case 4: 
                del_Head(&L);
                break;

            case 5:
                printf("Nhap ma sv cua nut q (se xoa nut dung sau nut nay): ");
                scanf("%d", &ma);
                q = search(L, ma);
                if (q != NULL) {
                    if (q->next == NULL) {
                        printf("Nut nay dang o cuoi ds, khong co phan tu nao phia sau de xoa!\n");
                    } else {
                        del_After(&L, q);
                        printf("Da xoa phan tu phia sau sinh vien co ma %d!\n", ma);
                    }
                } else {
                    printf("Khong tim thay ma sinh vien %d!\n", ma);
                }
                break;

            case 8:
                printf("\n--- Danh sach duyet NGUOC ---\n");
                processListReverse(L);
                break;

            case 9: 
                printf("\n--- Danh sach duyet XUOI ---\n");
                processList(L);
                break;    

            case 0: 
                printf("Bye bye\n");
                kt = 1;
                break;
        }
    } while (kt == 0); 

    return 0;
}
