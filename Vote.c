#include<stdio.h>
#include<stdlib.h>

int suara[3]={0,0,0};
int pilihan,verif,valid;

void rekap(int hasil[3]);

int main()
{
	while(1)
	{
		valid = 1;
		system("cls");
		printf("-------------------------------------------------------------------------------\n");
		printf("                                  System Pemilu\n");
		printf("-------------------------------------------------------------------------------\n");
		printf("Silahkan pilih calon kandidat yang anda dukung\n");
		printf("[1]Juan Carloz\n");
		printf("[2]Albert HM\n");
		printf("[3]Rudy Anantara\n");
		printf("Suara anda : ");
		scanf("%d",&pilihan);
		switch(pilihan)
		{
			case 1:
				suara[0]++;
				break;
			case 2:
				suara[1]++;
				break;
			case 3:
				suara[2]++;
				break;
			case 1708:
				rekap(suara);
				continue;
			case 106:
				system("cls");
				scanf("%d",&verif);
				if(verif==2810)
				{
					system("cls");
					printf("System Shutdown\n\n");
					system("pause");
					return 0;
				}
			default:
				valid = 0;
				system("cls");
				printf("-------------------------------------------------------------------------------\n");
				printf("                                  System Pemilu\n");
				printf("-------------------------------------------------------------------------------\n");
				printf(">>Error\n\n");
				printf("Input yang anda masukkan tidak valid, harap masukkan input sesuai dengan yang tersedia\n\n");
				system("pause");
				
		}
		if(valid==1)
		{
		system("cls");
		printf("Terimakasih telah memberikan suara dan turut serta memeriahkan pesta demokrasi!\n\n");
		system("pause");
		}
	}
	return 0;
}

void rekap(int hasil[3])
{
	int modus;
	system("cls");
	printf("-------------------------------------------------------------------------------\n");
	printf("                                  System Pemilu\n");
	printf("-------------------------------------------------------------------------------\n");
	printf(">>Rekap hasil pemilu\n\n");
	printf("Juan Carloz \t: %d suara\n",hasil[0]);
	printf("Albert HM \t: %d suara\n",hasil[1]);
	printf("Rudy Anantara \t: %d suara\n\n",hasil[2]);
	system("pause");
}
