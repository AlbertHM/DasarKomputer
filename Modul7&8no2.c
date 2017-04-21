#include<stdio.h>

int exit, opta, inpnilai, optb;

int main()
{
	exit = 0;
	while(!exit)
	{
		printf("Selamat datang di program kuliah terpadu, silahkan pilih menunya :\n");
		printf("[1]Input Nilai\n[2]Lihat Jadwal\n[3]Lihat Dosen\n[4]Lihat Ruang Kelas\n[5]Exit\n");
		printf("Input anda :"); scanf("%d",&opta);
		switch(opta)
		{
			case 1:
				printf("Silahkan masukkan nilai anda\n");
				scanf("%d",&inpnilai);
				printf("==============Nilai sudah disimpan :)==============\n");
				break;
			case 2:
				printf("Silahkan pilih jadwal kelas anda :\n");
				printf("[1] Rabu Jam 08.00, Prof. Rudy, K.107\n");
				printf("[2] Jumat Jam 13.00, Dr. Retno W, S.203]\n");
				printf("[3] Sabtu Jam 10.00, Hadaiq M.Kom, B.2204\n");
				printf("Pilihan :");
				scanf("%d",&optb);
				printf("==============Jadwal sudah disimpan :)==============\n");
			case 3:
				switch(optb)
				{
					case 1:
						printf("Dosen anda adalah Prof. Rudy\n");
					case 2:
						printf("Dosen anda adalah Dr. Retno W\n");						
					case 3:
						printf("Dosen anda adalah Hadaiq M.Kom\n");
					default:
						printf("Terjadi galat\n");
				}
			case 4:
			switch(optb)
				{
					case 1:
						printf("Ruangan anda adalah K.107\n");
					case 2:
						printf("Ruangan anda adalah S.203\n");						
					case 3:
						printf("Ruangan anda adalah B.2204\n");
					default:
						printf("Terjadi galat\n");
				}
			case 5:
				return 0;
			default:
				printf("Terjadi galat\n");
		}
	}
}
