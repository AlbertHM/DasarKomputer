//#include<stdio.h>
//#include<stdlib.h>
#include "Header.h"

int main()
{
	int s1 = 10;
	int s2 = 10;
	int s3 = 10;
	int s4 = 10;
	int s5 = 10;
	int p1 = 2500;
	int p2 = 4000;
	int p3 = 30000;
	int p4 = 20000;
	int p5 = 3000;
	int pilihan, nehi;
	do
	{
		system("cls");
		printf("Selamat datang di toko Intek\n");
		printf("--Menu Utama--\n");
		printf("[1]Lihat stok\n");
		printf("[2]Beli Barang\n");
		printf("[3]Bantuan\n");
		printf("[4]Keluar\n");
		printf("Pilihan : ");
		scanf("%d", &pilihan);
		switch(pilihan)
		{
			case 1:
				lihatstok(s1, s2, s3,  s4,  s5, p1, p2, p3, p4, p5);
				continue;
			case 2:
				bantuan();
				continue;
			case 3:
				bantuan();
				continue;
			case 4:
				system("cls");
				printf("Terima kasih\n\n");
				system("pause");
				return 0;
			default:
				system("cls");
				printf("Input tidak sesuai");
				system("pause");
				system("cls");
				continue;
		}		
	}while(1);
	return 0;
}
