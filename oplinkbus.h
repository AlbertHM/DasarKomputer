typedef struct nodeb //Deklarasi Struktur Linked List Operator Bus
{
	char nama[20]; //Nama
	int jurusan; //Trayek
	int kapasitas; //Kapasitas
	int opb; //Kode Unik
	struct nodeb* next;
}nodeb;

nodeb* createb(char nama[20], int jurusan, int kapasitas, int opb, nodeb* next)
{
    nodeb* new_node = (nodeb*)malloc(sizeof(nodeb));
    if(new_node == NULL)
    {
        printf("Error creating a new node.\n");
        exit(0);
    }
    strcpy(new_node->nama,nama);
	new_node->jurusan = jurusan;
	new_node->kapasitas = kapasitas;
	new_node->opb = opb;
    new_node->next = next;
 
    return new_node;
}

nodeb* prependb(nodeb* head, char nama[20], int jurusan, int kapasitas, int opb)
{
    nodeb* new_node = createb(nama, jurusan, kapasitas, opb, head);
    head = new_node;
    return head;
}

nodeb* appendb(nodeb* head, char nama[20], int jurusan, int kapasitas, int opb)
{
    /* go to the last node */
    nodeb *cursor = head;
    while(cursor->next != NULL)
        cursor = cursor->next;
 
    /* create a new node */
    nodeb* new_node =  createb(nama, jurusan, kapasitas, opb,NULL);
    cursor->next = new_node;
 
    return head;
}

nodeb* searchb(nodeb* head, int opb) //Pencarian data berdasarkan NIK
{ 
    nodeb *cursor = head;
    while(cursor!=NULL)
    {
        if(cursor->opb == opb)
            return cursor;
        cursor = cursor->next;
    }
    return NULL;
}

nodeb* remove_frontb(nodeb* head)
{
    if(head == NULL)
        return NULL;
    nodeb *front = head;
    head = head->next;
    front->next = NULL;
    if(front == head) //jika merupakan node terakhir
        head = NULL;
    free(front);
    return head;
}
 
nodeb* remove_backb(nodeb* head) //menghapus linked list apabila dibelakang
{
    if(head == NULL)
        return NULL;
 
    nodeb *cursor = head;
    nodeb *back = NULL;
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
 
nodeb* remove_anyb(nodeb* head,nodeb* nd) //fungsi pusat penghapus node 
{
    if(nd == NULL)
        return NULL;
	
    if(nd == head) //jika merupakan node pertama
	{
        return remove_frontb(head);
	}

    if(nd->next == NULL) //jika merupakan node terakhir
	{
		return remove_backb(head);
	}

    nodeb* cursor = head; //jika ditengah
    while(cursor != NULL)
    {
        if(cursor->next == nd)
            break;
        cursor = cursor->next;
    }
 
    if(cursor != NULL)
    {
        nodeb* tmp = cursor->next;
        cursor->next = tmp->next;
        tmp->next = NULL;
        free(tmp);
    }
    return head;
 
}

int countb(nodeb *head) //menghitung jumlah node pada linked list
{
    nodeb *cursor = head; //set cursor
    int c = 0;
    while(cursor != NULL)
    {
        c++;
        cursor = cursor->next;
    }
    return c;
}

void printallb(nodeb *head) //mencetak seluruh elemen linked list penumpang
{
	nodeb *cursor = head;	
	printf("%-4s|%-20s|%-6s|%-5s|%-7s\n","No.","Nama","Jurusan","Kap","Kode Bus");
	if(cursor == NULL)
	{
		printf("Belum ada entry data...");
		return;
	}
	int c = 1;
	while(cursor != NULL)
	{
		printf("[%03i]%-21s%-8i%-6i%-7i\n",c,cursor->nama,cursor->jurusan,cursor->kapasitas,cursor->opb);
		cursor = cursor->next;
		c++;
	}
}

