#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "oplinkpenumpang.h"
#include "oplinkbus.h"

/*
Developed by :
1. Albert Harazaki Mendrofa 1506672496
2. Kerisna Manto 1506733516
In order to fullfill Algoritm and Programming Course Final Project
*/

//deklarasi
nodep* headp = NULL;
nodep* tmpp = NULL;
nodeb* headb = NULL;
nodeb* tmpb = NULL;

char trayek[5][20]={"JKT-BDG","JKT-SRG","JKT-JOG","JKT-SBY","JKT-MLG"};

//Dummy
int konf();
void bentar();
void error(int i);
void userengine();
void opbusengine();
void mainengine();

int konf()
{
	int input;
	system("cls");
	printf("Apakah anda ingin melanjutkan proses yang sedang berlangsung?[1 untuk iya, selain itu tidak]\n");
	scanf("%i",&input);
	return input;
}

void error(int i) // Error Handler
{
	system("cls");
	printf(">>Error!\n\n");
	printf("Error [%03d]:\n",i);
	switch(i)
	{
		case 1:
			printf("Input tidak valid, harap masukkan input sesuai dengan pilihan yang tersedia!");
			break;
		case 2:
			printf("Maaf, anda tidak dapat melanjutkan pembelian karena NIK telah terdaftar.");
			break;
		case 3:
			printf("Maaf, anda tidak dapat melanjutkan pembelian karena kode operator bus tidak terdaftar");
			break;
		case 4:
			printf("Maaf, nomor NIK anda tidak terdaftar.");
			break;
		case 5:
			printf("Maaf, bus dengan kode yang anda masukkan tidak terdaftar dalam sistem.");
			break;
		case 6:
			printf("Maaf, pendaftaran tidak dapat dilanjutkan karena kode bus sudah terdaftar");
			break;
		case 7:
			printf("Maaf, pendaftaran tidak dapat dilanjutkkan karena nilai tidak wajar");
			break;
	}
	bentar();
}

void bentar()
{
	printf("\n\nTekan apapun untuk melanjutkan...");
	getch();
}

void userengine()
{
	int input, p;
	char tnama[20];
	char tnotelp[20];
	unsigned long tnik;
	int topb;
	while(1)
	{
		system("cls");
		printf(">> Menu Calon Penumpang Bis\n\n");
		printf("[1] Beli Tiket\n[2] Lihat Status Tiket\n[3] Lihat Trayek\n[4] Batalkan Tiket\nPilihan :");
		scanf("%i",&input);
		system("cls");
		switch(input)
		{
			case 1: //Beli Tiket
				printf(">> Beli Tiket\n\n");
				printf("Nama\t: ");
				scanf(" %[^\n]s ",&tnama);
				printf("NIK\t: ");
				scanf("%lu",&tnik);
				printf("No.Telp\t: ");
				scanf("%s",&tnotelp);
				printf("Kode Bus: ");
				scanf("%i",&topb);
				tmpp = searchp(headp, tnik);//search for existing NIK				
				if(tmpp != NULL) //cek NIK sudah terdaftar atau belum
				{
					error(2); //nik telah terdaftar
					continue;
				}
				tmpb = searchb(headb, topb);
				if(tmpb == NULL)
				{
					error(3); //kode bus tidak terdaftar
					continue;
				}
				if(countp(headp)==0) //Prepend or append based on existence of the linked list
				{					
					headp=prependp(headp, tnama,tnotelp,tnik,topb);
				}
				else
				{
					headp=appendp(headp, tnama,tnotelp,tnik,topb);
				}
				printf("Pendaftaran berhasil!");
				bentar();
				break;
			case 2: //Lihat Status tiket
				printf(">> Cek Status Tiket\n\n");
				printf("Masukkan nik anda : ");
				scanf("%lu",&tnik);
				tmpp = searchp(headp, tnik); //pengecekan NIK
				if(tmpp != NULL)
				{					
					printf("%-4s|%-20s|%-9s|%-20s|%-s\n","No.","Nama","NIK","No.Telp","Kode Bus");
					printf("[001]%-21s%-10lu%-21s%-7i", tmpp->nama, tmpp->nik, tmpp->notelp, tmpp->opb);
					tmpb = searchb(headb,topb);		
					if(tmpb == NULL)
					{
						printf("\n\nMohon maaf, bus yang anda pilih telah dibatalkan keberangkatannya.. Harap segera membatalkan tiket anda dan memesan yang baru");
					}
					else
					{
						printf("\n\nTiket anda tidak bermasalah :)");
					}
					bentar();
				}
				else
				{
					error(4); //tidak terdaftar
				}
				break;
			case 3: //Lihat Pilihan Trayek				
				printf(">> Daftar Operator Bus\n\n");				
				printallb(headb);
				bentar();
				break;
			case 4: //Batalkan tiket
				printf(">> Pembatalan Tiket\n\n");
				printf("Masukkan nik anda : ");
				scanf("%lu",&tnik);
				tmpp = searchp(headp,tnik); //pengecekan NIK
				if(tmpp != NULL)
				{					
					p = konf();
					if(p == 1)
					{
						remove_anyp(headp,tmpp);
					}
					else
					{
						continue;
					}
				}
				else
				{
					error(4); //tidak terdaftar
				}
				break;
			case 5:		//return to main,  request password
				system("cls");
				scanf("%i",&input);
				if(input==1234)
				{
					return;
				}
				else
				{
					printf("Akses Ditolak\n\n");
					bentar();
					continue;
				}
				return;
			default: //error handler
				error(1);
				break;
		}
		free(tmpp);
		free(tmpb);
	}
}

void opbusengine()
{
	int input, p;
	char tnama[20];
	int tjurusan;
	int tkapasitas;
	int topb;
	while(1)
	{
		system("cls");
		printf(">> Menu operator bus\n\n");
		printallb(headb);
		printf("\n\n");
		printf("[1] Tambah Operator Bus\n[2] Hapus Operator Bus\n[3] Kembali\nPilihan :");
		scanf("%i",&input);
		system("cls");
		switch(input)
		{
			case 1: //Tambah Operator Bus
				printf(">> Pendaftaran Operator Bus\n\n");
				printf("Nama : ");
				scanf(" %[^\n]s ",&tnama);
				printf("Jurusan : ");
				scanf("%i",&tjurusan);
				printf("Kapasitas : ");
				scanf("%i", &tkapasitas);
				if(tkapasitas<3 || tkapasitas>300)
				{
					error(5);
					continue;
				}
				printf("Kode Bus : ");
				scanf("%i",&topb);
				tmpb = searchb(headb,topb);		
				if(tmpb != NULL)
				{
					error(6);
					continue;
				}
				if(countb(headb)==0)
				{					
					headb=prependb(headb, tnama, tjurusan, tkapasitas, topb);
				}
				else
				{
					headb=appendb(headb, tnama, tjurusan, tkapasitas, topb);
				}
				printf("Pendaftaran berhasil!");
				bentar();
				break;
			case 2: //Hapus Operator
				printf("Masukkan kode bus : ");
				scanf("%i",&topb);
				tmpb = searchb(headb,topb);
				p = konf();
				if(p == 1)
				{
					system("cls");
					scanf("%i",&input);
					if(input != 1234)
					{
						printf("Akses Ditolak\n\n");
						bentar();
						continue;
					}
				}
				else
				{
					continue;
				}					
				if(tmpb != NULL)
				{
					remove_anyb(headb,tmpb);
				}
				else
				{
					error(5); // bus tidak ditemukan
				}
				break;
			case 3: //Kembali
				return;
				break;
			default:
				error(1);
				break;
		}
		free(tmpp);
		free(tmpb);
	}
}

void mainengine()
{
	int input;
	while(1)
	{
		system("cls");
		printf(">> Menu Sistem Utama\n\n");
		printf("[1] Lihat Daftar Penumpang\n[2] Lihat Daftar Operator Bus\n[3] Cetak Daftar Penumpang\n[4] Kembali\nPilihan :");
		scanf("%i",&input);
		system("cls");
		switch(input)
		{
			case 1:
				printf(">> Database Penumpang\n\n");
				printallp(headp);
				bentar();
				break;
			case 2:
				opbusengine();
				break;
			case 3:
				printf("Silahkan masukkan kode bus yang ingin dicetak : ");
				scanf("%i",&input);
				break;
			case 4:
				return;
			default:
				error(1);
				break;
		}
	}
}
	
int main()
{ 
	int input;
	
	while(1)
	{
		system("cls");
		printf("Tiket Manajer v2.0 :\n\n");
		printf("[1] Sistem Pembelian Tiket\n");
		printf("[2] Sistem Sentral\n");
		printf("[3] Turn off\n");
		printf("Pilihan : ");
		scanf("%i",&input);
		switch(input)
		{
			case 1:
				userengine();
				break;
			case 2:
				mainengine();
				break;
			case 3:
				system("cls");
				scanf("%i",&input);
				if(input==1234)
				{
					return;
				}
				else
				{
					printf("Akses Ditolak\n\n");
					system("pause");
				}
				return 0;
				break;
			default:
				error(1);
				break;
		}
	}

}
