#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Developed by ALbert HM
//1506672496

struct datam
{
	char nama[30];
	char npm[20];
	char notel[20];
};

struct datam mahasiswa[10];

void error()
{
	system("cls");
	printf("Error!\n\n");
	system("pause");
}

int main()
{
	int opta,i,j,k;
	for(i=0;i<10;i++)
	{
		strcpy(mahasiswa[i].nama ,"-");
		strcpy(mahasiswa[i].npm ,"0");
		strcpy(mahasiswa[i].notel ,"0");
	}
	while(1)
	{
		system("cls");
		printf("Data Mahasiswa NG\n");
		printf("Selamat datang di program data mahasiswa!\n\n");
		printf("Menu :\n");
		printf("[1] Isi data mahasiswa\n");
		printf("[2] Lihat data mahasiwa\n");
		printf("[3] Keluar\n\n");
		printf("Pilihan anda : ");
		scanf("%i",&opta);
		switch(opta)
		{
			case 1:
				while(1)
				{
					system("cls");					
					printf("Data Mahasiswa NG\n");
					printf(">>Edit\n\n");
					for(i=0;i<10;i++)
					{
						printf("[%i] %s\n",i+1,mahasiswa[i].nama);
					}
					printf("Silahkan pilih data yang ingin di edit(0 untuk keluar) : ");
					scanf("%i",&j);
					if(j<0 || j>10)
					{
						error();
						continue;						
					}
					else if(j==0)
					{
						break;
					}
					j--;
					system("cls");
					printf("Masukkan data!\n\nNama\t: ");
					//getch();
					scanf(" %[^\n]s ",&mahasiswa[j].nama);
					//fgets(mahasiswa[j].nama, 50, stdin);
					//mahasiswa[j].nama[strcspn(mahasiswa[j].nama, "\r\n")] = 0;
					printf("NPM\t: ");
					scanf("%s",&mahasiswa[j].npm);
					printf("No. Telp: ");
					scanf("%s", &mahasiswa[j].notel);
					printf("\nData tersimpan!");
				}
				//automatic address system
				/*
				printf("Silahkan masukkan jumlah data yang ingin anda masukkan : ");
				scanf("%i",&k);
				if(k<1 || k>10)
				{
				error();
				}
				for(i=0;i<10;i++)
				{
					system("cls");
					printf("Masukkan data!\n\nNama : ");
					scanf(" %[^\n]s ",&mahasiswa[i].nama);
					//fgets(mahasiswa[i].nama, 50, stdin);
					//mahasiswa[i].nama[strcspn(mahasiswa[i].nama, "\r\n")] = 0;
					printf("NPM : ");
					scanf("%s",&mahasiswa[i].npm);
					printf("No. Telp :");
					scanf("%s", &mahasiswa[i].notel);
					printf("\nData tersimpan!");
				}
				*/				
				break;
			case 2:
				system("cls");
				printf("Data Mahasiswa NG\n");
				printf(">>Lihat data\n\n");
				printf("No%-30s%-20s%-10s\n"," Nama","NPM","No.Telp");
				for(i=0;i<10;i++)
				{
					printf("%i %-30s%-20s%-20s\n",i+1,mahasiswa[i].nama,mahasiswa[i].npm,mahasiswa[i].notel);
				}
				system("pause");
				break;
			case 3:
				return 0;
			default:
				system("cls");
				printf("Error!\n\n");
				system("pause");
				break;
		}
	}
}
