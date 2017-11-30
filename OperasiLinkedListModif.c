#include <stdio.h>
#include <stdlib.h>

//Developed By
//Albert Harazaki Mendrofa 1506672496
//Faria Ulfah 1506672395
//Andyta Rehulina 1506727141

typedef struct node
{
    int data;
    struct node* next;
} node;

typedef void (*callback)(node* data);

void display(node* n)
{
    if(n != NULL)
        printf("%d ", n->data);
}

node* remove_back(node* head) //untuk penghapusan node terakhir
{
    if(head == NULL)
        return NULL;
 
    node *cursor = head;
    node *back = NULL;
    while(cursor->next != NULL)
    {
        back = cursor;
        cursor = cursor->next;
    }
 
    if(back != NULL)
        back->next = NULL;
 
    /* if this is the last node in the list*/
    if(cursor == head)
        head = NULL;
 
    free(cursor);
 
    return head;
}

node* remove_front(node* head) // untuk penghapusan node pertama
{
    if(head == NULL)
        return NULL;
    node *front = head;
    head = head->next;
    front->next = NULL;
    /* is this the last node in the list */
    if(front == head)
        head = NULL;
    free(front);
    return head;
}

node* create(int data,node* next) //pembuatan node baru
{
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL)
    {
        printf("Error creating a new node.\n");
        exit(0);
    }
    new_node->data = data; //pengisian nilai element
    new_node->next = next; //perujukan
 
    return new_node;
}

node* prepend(node* head,int data) //untuk push
{
    node* new_node = create(data,head); //membuat node baru
    head = new_node;
    return head;
}

node* append(node* head, int data) //untuk append
{
    if(head == NULL)
        return NULL;
	
    node *cursor = head; // menuju ke node terakhir
    while(cursor->next != NULL)
        cursor = cursor->next;
 
 
    node* new_node =  create(data,NULL); //pembuatan node baru
    cursor->next = new_node;
 
    return head;
}

void traverse(node* head,callback f) //untuk menampilkan linked list
{
    node* cursor = head;
    while(cursor != NULL)
    {
        f(cursor);
        cursor = cursor->next;
    }
}

node* search(node* head,int data) //untuk mencari node spesifik
{
 
    node *cursor = head;
    while(cursor!=NULL)
    {
        if(cursor->data == data)
            return cursor;
        cursor = cursor->next;
    }
    return NULL;
}

node* remove_any(node* head,node* nd) //untuk menghapus node bebas
{
    if(nd == NULL) //jika list kosong
        return NULL;
	
    if(nd == head) // apabila rupanya node pertaman
        return remove_front(head);
 
    if(nd->next == NULL) // apabila node terakhir
        return remove_back(head);
 

    node* cursor = head; // jika node berada di tengah (itu ampe return)
    while(cursor != NULL)
    {
        if(cursor->next == nd)
            break;
        cursor = cursor->next;
    }
 
    if(cursor != NULL)
    {
        node* tmp = cursor->next;
        cursor->next = tmp->next;
        tmp->next = NULL;
        free(tmp);
    }
    return head;
 
}

node* insert_after(node *head, int data, node* prev)
{
    if(head == NULL || prev == NULL)
        return NULL;
    /* find the prev node, starting from the first node*/
    node *cursor = head;
    while(cursor != prev)
        cursor = cursor->next;
 
    if(cursor != NULL)
    {
        node* new_node = create(data,cursor->next);
        cursor->next = new_node;
        return head;
    }
    else
    {
        return NULL;
    }
}

int main()
{
	int pilih,data;
 
    node* head = NULL;
    node* tmp = NULL;
    callback disp = display;
	
	while(1)
	{
		system("cls");
		printf("\nLinked List: ");
        traverse(head,disp);

		printf ("\n\n1. Tambah Node Baru Pada Head");
		printf ("\n2. Tambah Node Baru pada Tail");
		printf ("\n3. Tambah Node Baru Setelah Node yang Ditentukan");
		printf ("\n4. Menghapus Node");
		printf ("\n5. Keluar");
		printf ("\nPilih : ");
		scanf ("%d", &pilih);

		switch (pilih){	
		case 1: // Push
            printf("Silihkan masukkan nilai elemen yang ingin dipush :");
            scanf("%d",&data);
            head = prepend(head,data);
            break;
        case 2: //Append
            printf("Silihkan masukkan nilai elemen yang ingin diappend :");
            scanf("%d",&data);
            head = append(head,data);
            break;
		case 3: //Insert
			printf("Masukkan nilai node sebelumnya :");
			scanf("%d",&data);
			tmp = search(head,data);
			if(tmp != NULL)
			{
				printf("Silihkan masukkan nilai elemen yang ingin disisipkan :");
				scanf("%d",&data);
				head = insert_after(head,data,tmp);
			}
			else
			{
				printf("Element dengan nilai %d tidak ditemukan.",data);
				system("pause");
			}
			break;
		case 4: // Delete
            printf("Silihkan masukkan nilai elemen yang ingin dihapus :");
            scanf("%d",&data);
            tmp = search(head,data);
            if(tmp != NULL)
            {
                remove_any(head,tmp);
            }
            else
            {
                printf("Element dengan nilai %d tidak ditemukan.",data);
				system("pause");
            }
            break;
		case 5:
			return 0;
		}
	}
}
