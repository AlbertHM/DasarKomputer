//Header penumpang
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct nodep //Deklarasi Struktur Linked List Penumpang
{
	char nama[20]; // nama
	char notelp[20]; //no telphone
	unsigned long nik; //no ktp
	int opb; //operator bus(kode)
	struct nodep* next;
}nodep;

nodep* createp(char nama[20],char notelp[20],unsigned long nik,int opb,nodep* next)
{
    nodep* new_node = (nodep*)malloc(sizeof(nodep));
    if(new_node == NULL)
    {
        printf("Error creating a new node.\n");
        exit(0);
    }
    strcpy(new_node->nama,nama);
	strcpy(new_node->notelp,notelp);
	new_node->nik = nik;
	new_node->opb = opb;
    new_node->next = next;
 
    return new_node;
}

nodep* prependp(nodep* head, char nama[20], char notelp[20], unsigned long nik, int opb)
{
    nodep* new_node = createp(nama, notelp, nik, opb,head);
    head = new_node;
    return head;
}

nodep* appendp(nodep* head, char nama[20], char notelp[20], unsigned long nik, int opb)
{
    /* go to the last node */
    nodep *cursor = head;
    while(cursor->next != NULL)
        cursor = cursor->next;
 
    /* create a new node */
    nodep* new_node =  createp(nama, notelp, nik, opb,NULL);
    cursor->next = new_node;
 
    return head;
}

nodep* searchp(nodep* head,unsigned long nik) //Pencarian data berdasarkan NIK
{ 
    nodep *cursor = head;
    while(cursor!=NULL)
    {
        if(cursor->nik == nik)
            return cursor;
        cursor = cursor->next;
    }
    return NULL;
}

nodep* remove_frontp(nodep* head)
{
    if(head == NULL)
        return NULL;
    nodep *front = head;
    head = head->next;
    front->next = NULL;
    if(front == head) //jika merupakan node terakhir
        head = NULL;
    free(front);
    return head;
}
 
nodep* remove_backp(nodep* head) //menghapus linked list apabila dibelakang
{
    if(head == NULL)
        return NULL;
 
    nodep *cursor = head;
    nodep *back = NULL;
    while(cursor->next != NULL)
    {
        back = cursor;
        cursor = cursor->next;
    }
 
    if(back != NULL)
        back->next = NULL;

    if(cursor == head) //jika yang dihapus merupakan node terakhir
        head = NULL;
 
    free(cursor);
 
    return head;
}
 
nodep* remove_anyp(nodep* head,nodep* nd) //fungsi pusat penghapus node 
{
    if(nd == NULL)
        return NULL;
	
    if(nd == head) //jika merupakan node pertama
	{
        return remove_frontp(head);
	}

    if(nd->next == NULL) //jika merupakan node terakhir
	{
		return remove_backp(head);
	}

    nodep* cursor = head; //jika ditengah
    while(cursor != NULL)
    {
        if(cursor->next == nd)
            break;
        cursor = cursor->next;
    }
 
    if(cursor != NULL)
    {
        nodep* tmp = cursor->next;
        cursor->next = tmp->next;
        tmp->next = NULL;
        free(tmp);
    }
    return head;
 
}

int countp(nodep *head) //menghitung jumlah node pada linked list
{
    nodep *cursor = head; //set cursor
    int c = 0;
    while(cursor != NULL)
    {
        c++;
        cursor = cursor->next;
    }
    return c;
}

void printallp(nodep *head) //mencetak seluruh elemen linked list penumpang
{
	nodep *cursor = head;
	printf("%-4s|%-20s|%-9s|%-20s|%-s\n","No.","Nama","NIK","No.Telp","Kode Bus");
	if(cursor == NULL)
	{
		printf("Belum ada entry data...");
		return;
	}
	int c = 1;
	while(cursor != NULL)
	{
		printf("[%03i]%-21s%-10lu%-21s%-7i\n", c, cursor->nama, cursor->nik, cursor->notelp, cursor->opb);
		cursor = cursor->next;
		c++;
	}
}

