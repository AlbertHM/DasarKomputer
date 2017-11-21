#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int opta, jumlahtiket[100], jurusan[100];
unsigned long nik[100];

//Dummy section
void pesan(int jt[100], int ju[100], unsigned long nik[100]);
void lihatrekap();
void ubahpesanan();
void error(int tipe);
void bantuan();
void keluar();
//Dummy section


void pesan(int jt[100], int ju[100], unsigned long nik[100])
{
	int i, j, rpt=1, tempjt=0, tempj=0;
	unsigned long tempnik=0;
	for(i=0;i<100;i++) //mencari posisi array yang kosong
	{
		if(ju[i]==0)
		{
			break;
		}
	}
	while(rpt==1) // mengisi NIK
	{
		system("cls");
		printf("Silahkan masukkan nomor KTP anda : ");
		scanf("%lu",&tempnik);
		for(j=0;j<100;j++) // mengecek apakah NIK sudah terdaftar
		{
			if(nik[j]==0)
			{
				rpt=0;
				break;
			}
			else if(tempnik == nik[j]) // NIK sudah terdaftar
			{
				error(2);
				return; // kembali ke menu utama
			}
		}
		if(rpt==1)
		{
			continue;
		}
		if(tempnik<1) //NIK tidak wajar
		{
			error(3);
			continue;
		}
		else
		{
			nik[i] = tempnik;
			rpt=0;
		}		
	}
	rpt=1;
	while(rpt==1) // memilih jurusan
	{
		system("cls");
		printf("Silahkan masukkan nomor KTP anda : %lu\n", nik[i]);
		printf("[+] Pilihan Jurusan\n[1]Jakarta-Bandung\n[2]Jakarta-Surabaya\n[3]Jakarta-Serang\n[4]Jakarta-Jogja\n");
		printf("Silahkan masukkan pilihan jurusan anda : ");
		scanf("%i",&tempj);
		if(tempj>4 || tempj<1)
		{
			error(1);
			continue;
		}
		ju[i]=tempj;
		break;
	}
	while(rpt==1) // menentukan jumlah tiket
	{
		system("cls");
		printf("Silahkan masukkan nomor KTP anda : %lu\n", nik[i]);
		printf("Silahkan masukkan pilihan jurusan anda : ");
		switch(ju[i])
		{
			case 1:
				printf("(1) Jakarta-Bandung\n");
				break;
			case 2:
				printf("(2) Jakarta-Surabaya\n");
				break;
			case 3:
				printf("(3) Jakarta-Serang\n");
				break;
			case 4:
				printf("(4) Jakarta-Jogja\n");
				break;
		}
		printf("Silahkan masukkan jumlah tiket yang anda beli : ");
		scanf("%i", &tempjt);
		if(tempjt<1)
		{
			error(4);
			continue;
		}
		jt[i] = tempjt;
		rpt=0;
	}
	printf("\nTerima kasih telah memesan, silahkan ambil struk dan lanjutkan pembayaran di kasir.\n\n");
	system("pause");
}

void lihatrekap(int jt[100], int ju[100], unsigned long nik[100])
{
	int i = 0, j, urut = 1, ok=0;
	int dummyjt[100], dummyju[100], tempjt, tempju;
	unsigned long dummynik[100], tempnik;
	for(i=0;i<100;i++) //penyalinan array
	{
		dummyjt[i] = jt[i];
		dummyju[i] = ju[i];
		dummynik[i] = nik[i];
	}
	while(urut!=4)
	{
		system("cls");
		printf("Lihat Rekap\n\n");/*
				
		for(j=0;j<100;j++)
		{
			printf("bla%i\t%lu\t\t%i\t\t%i\n",j+1,dummynik[j],dummyjt[j],dummyju[j]);
		}*/
		printf("No.\tNIK\t\tJumlah Tiket\tJurusan\n");
		switch(urut)
		{
			case 1: //berdasarkan urutan pemesanan
				for(j=0;j<100;j++)
				{
					if(ju[j]==0)
					{
						break;
					}
					printf("%i\t%lu\t\t%i\t\t",j+1,nik[j],jt[j],ju[j]);
					switch(ju[j])
					{
						case 1:
							printf("(1) Jakarta-Bandung\n");
							break;
						case 2:
							printf("(2) Jakarta-Surabaya\n");
							break;
						case 3:
							printf("(3) Jakarta-Serang\n");
							break;
						case 4:
							printf("(4) Jakarta-Jogja\n");
							break;
					}
				}
				break;
			case 2: //berdasarkan jumlah tiket(banyak->sedikit)
				ok=0;
				while(ok==0)
				{
					ok=1;
					for(j=0;j<99;j++) //bubble sort
					{
						if(dummyjt[j]<dummyjt[j+1])
						{
							tempjt = dummyjt[j];
							tempju = dummyju[j];
							tempnik = nik[j];
							dummyjt[j] = dummyjt[j+1];
							dummyju[j] = dummyju[j+1];
							dummynik[j] = dummynik[j+1];
							dummyjt[j+1] = tempjt;
							dummyju[j+1] = tempju;
							dummynik[j+1] = tempnik;
							ok=0;
						}
					}
				}
				for(j=0;j<100;j++)
				{
					if(ju[j]==0) //stop jika kosong
					{
						break;
					}
					printf("%i\t%lu\t\t%i\t\t",j+1,dummynik[j],dummyjt[j],dummyju[j]);
					switch(dummyju[j])
					{
						case 1:
							printf("(1) Jakarta-Bandung\n");
							break;
						case 2:
							printf("(2) Jakarta-Surabaya\n");
							break;
						case 3:
							printf("(3) Jakarta-Serang\n");
							break;
						case 4:
							printf("(4) Jakarta-Jogja\n");
							break;
					}
				}
				break;
			case 3: //berdasarkan jurusan(kecil->besar)
				ok=0;
				while(ok==0)
				{
					ok=1;
					for(j=0;j<99;j++) //bubble sort
					{
						if(dummyju[j]<dummyju[j+1])
						{
							tempjt = dummyjt[j];
							tempju = dummyju[j];
							tempnik = nik[j];
							dummyjt[j] = dummyjt[j+1];
							dummyju[j] = dummyju[j+1];
							dummynik[j] = dummynik[j+1];
							dummyjt[j+1] = tempjt;
							dummyju[j+1] = tempju;
							dummynik[j+1] = tempnik;
							ok=0;
						}
					}
				}/*
				
				for(j=0;j<100;j++)
				{
					printf("bla%i\t%lu\t\t%i\t\t%i\n",j+1,dummynik[j],dummyjt[j],dummyju[j]);
				}*/
				for(j=0;j<100;j++)
				{
					if(ju[j]==0) //lewati jika kosong
					{
						continue;
					}
					printf("%i\t%lu\t\t%i\t\t",j+1,dummynik[j],dummyjt[j],dummyju[j]);
					switch(dummyju[j])
					{
						case 1:
							printf("(1) Jakarta-Bandung\n");
							break;
						case 2:
							printf("(2) Jakarta-Surabaya\n");
							break;
						case 3:
							printf("(3) Jakarta-Serang\n");
							break;
						case 4:
							printf("(4) Jakarta-Jogja\n");
							break;
					}
				}
				break;
		}
		printf("\nMenu :\n[1]Berdasarkan urutan pengisian\n[2]Berdasarkan Jumlah tiket\n[3]Berdasarkan Jurusan\n[4]Keluar\nPilihan :");
		scanf("%i", &urut);
		if(urut>4 || urut<1)
		{
			error(1);
			urut = 1;
			continue;
		}
	}
		
}

void ubahpesanan(int jt[100], int ju[100], unsigned long nik[100])
{
	printf("Sedang terjadi masalah server...\n\n");
	system("pause");
}

void bantuan() //mencetak menu bantuan
{
	printf("Bantuan\n");
	printf("Langkah-langkah yang harus diperhatikan sebelum memesan tiket : \n");
	printf("*1. Siapkan NIK anda\n");
	printf("*2.Tentukan tujuan anda\n");
	printf("*3.Tentukan jumlah tiket yang ingin anda pesan\n");
	system("pause");
}

void keluar() //untuk keluar dari program
{
	printf("Terima kasih telah memesan tiket\n\n");
	system("pause");
}

void error(int tipe)
{
	system("cls");
	if(tipe==1)
	{
		printf("Input yang dimasukkan tidak sesuai, harap masukkan input sesuai dengan pilihan\n\n");
		system("pause");
	}
	else if(tipe==2)
	{
		printf("Nomor NIK anda telah terdaftar sebelumnya\n\n");
		system("pause");
	}
	else if(tipe==3)
	{
		printf("Masukkan yang anda berikan tidak wajar\n\n");
		system("pause");
	}
	else if(tipe==4)
	{
		printf("Masukkan yang anda berikan harus lebih besar dari 0\n\n");
		system("pause");
	}
}

int main()
{
    int x;
	for(x=0;x<100;x++) //pengisian array kosong
	{
		jumlahtiket[x]=0;
		jurusan[x]=0;
		nik[x]=0;
	}
	while(1)
    {
		system("cls");
		printf("Program pendaftaran tiket bus SinarJaya\n");
		printf("[1] Pesan Tiket\n");
		printf("[2] Lihat Rekap\n");
		printf("[3] Ubah Pesanan\n");
		printf("[4] Bantuan\n");
		printf("[5] Keluar\n");
		printf("Pilihan : ");
		scanf("%d", &opta);
		system("cls");
		switch(opta)
		{
			case 1:
				pesan(jumlahtiket, jurusan, nik);
				break;
			case 2:
				lihatrekap(jumlahtiket, jurusan, nik);
				break;
			case 3:
				ubahpesanan(jumlahtiket, jurusan, nik);
				break;
			case 4:
				bantuan();
				break;
			case 5:
				keluar();
				return 0;
			default:
				error(1);
				break;
		}
	}
}
