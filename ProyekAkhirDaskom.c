/*
Creator :
1. Albert HM
2. Wildan Firdaus

Kodingan ini kami buat dalam rangka mememnuhi tugas akhir mata kuliah dasar komputer
*/


#include<stdio.h> // Pada tahap awal, kami melakukan include terhadap library yang akan dibutuhkan pada saat compiling program
#include<stdlib.h>
#include<string.h>

int opta, loop1=1; // inisialisasi variable input dan status looping
char sn[30], sp[30], u1n[30], u1p[30], u2n[30], u2p[30], u3n[30], u3p[30], an[30], ap[30], a[4];
// inisialisasi variable username dan password
// inisialisasi variable dan penetapan nilai dari variable data user dan data kuliah

//User1
char d1_na[50]="Abi Buba", d1_te[20]="Berlin", d1_ta[20]="22 Maret 1995", d1_al[100]="Jalan Raya 1, Depok", d1_go[3]="AB";
char sel_11[15]="   Elmg-01   ", sel_12[15]="             ", sel_13[15]="             ", sel_14[15]="             ";
char rab_11[15]="   MTLs-01   ", rab_12[15]="             ", rab_13[15]="             ", rab_14[15]="             ";
char kam_11[15]="   Elmg-01   ", kam_12[15]="             ", kam_13[15]="  Sinsis-01  ", kam_14[15]="             ";
char jum_11[15]="   DKom-01  ", jum_12[15]="            ", jum_13[15]="    RE-01   ", jum_14[15]="            ";
//User2
char d2_na[50]="Bob Sudoku", d2_te[20]="Kyoto", d2_ta[20]="12 April 1995", d2_al[100]="Jalan Raya 2, Depok", d2_go[3]="B";
char sel_21[15]="   Elmg-01   ", sel_22[15]="             ", sel_23[15]="             ", sel_24[15]="             ";
char rab_21[15]="   MTLs-01   ", rab_22[15]="             ", rab_23[15]="             ", rab_24[15]="             ";
char kam_21[15]="   Elmg-01   ", kam_22[15]="             ", kam_23[15]="  Sinsis-01  ", kam_24[15]="             ";
char jum_21[15]="   DKom-01  ", jum_22[15]="            ", jum_23[15]="    RE-01   ", jum_24[15]="            ";
//User3
char d3_na[50]="Charlie", d3_te[20]="London", d3_ta[20]="2 Februari 1995", d3_al[100]="Jalan Raya 3, Depok", d3_go[3]="O";
char sel_31[15]="   Elmg-01   ", sel_32[15]="             ", sel_33[15]="             ", sel_34[15]="             ";
char rab_31[15]="   MTLs-01   ", rab_32[15]="             ", rab_33[15]="             ", rab_34[15]="             ";
char kam_31[15]="   Elmg-01   ", kam_32[15]="             ", kam_33[15]="  Sinsis-01  ", kam_34[15]="             ";
char jum_31[15]="   DKom-01  ", jum_32[15]="            ", jum_33[15]="    RE-01   ", jum_34[15]="            ";

/*  Catatan
sn = Sign in name
sp = sign in password
u1n = User 1 name
u1p = User 1 password
an = Admin name
ap = Admin password
*/

/*
menggunakan fgetc(stdin) seteleh penggunaan scanf agar tidak terjadi error pada fgets
menggunakan <nama var>[strcspn(<nama var>, "\r\n")]
*/

void menuuser1() {
	int loopz=1, loop2=1, loop3=1, m1, m2, m3, k1, k1a, ubah1, dk1, em1, mtl1, re1, sin1; // deklarasi variable lokal

	while(loopz) {
		system("cls");
		printf("_____________________________________________________________________________________\n");
		printf("                            SISTEM INFORMASI PERKULIAHAN\n\n                                  UNIVERSITAS DEPOK\n");
		printf("_____________________________________________________________________________________\n");
		printf("[1] Lihat Data\n[2] Lihat Kelas\n\n[9] Help\n[0] Logout\n\nPilih menu: ");
		scanf("%d", &m1);		// meminta masukkan user
        fgetc(stdin); // memakan \n scanf
		switch(m1) {
			case 0: // apabila keluar
				loopz=0;
				system("cls");
				break;
			case 1: // melihat identitas diri
				while(loop2) {
					system("cls");
					printf("\n                                  IDENTITAS DIRI\n");
					printf("_____________________________________________________________________________________\n");
					printf(" Nama           : %s\n", d1_na);
					printf(" Tempat lahir   : %s\n", d1_te);
					printf(" Tanggal lahir  : %s\n", d1_ta);
					printf(" Alamat         : %s\n", d1_al);
					printf(" Golongan darah : %s\n", d1_go);
					printf(" IP Terakhir    : 3.51\n");
					printf(" IPK            : 3.65\n");
					printf("_____________________________________________________________________________________");
					printf("\n\n[1] Edit\n[2] Kembali\n\nPilih menu: ");
					scanf("%d", &m2); // meminta masukkan 
                    fgetc(stdin);// memakan \n scanf
					system("cls");
					if (m2 == 1) {
						printf("[1] Nama\n[2] Tempat lahir\n[3] Tanggal lahir\n[4] Alamat\n[5] Golongan darah\n\n[0] Kembali\n\nPilih data yang ingin diubah :");
						scanf("%d", &m3); // meminta inputan yang ingin di edit
                        fgetc(stdin);
						system("cls");
						switch(m3) {
							case 1:
								printf("Nama baru:\n"); // edit nama
								fgets(d1_na, 50, stdin);
                                d1_na[strcspn(d1_na, "\r\n")] = 0; // membuang \n dari fgets
								break;
							case 2:
								printf("Tempat lahir baru:\n"); // edit Tempat lahir
								fgets(d1_te, 20, stdin);
                                d1_te[strcspn(d1_te, "\r\n")] = 0;
								break;
							case 3:
								printf("Tanggal lahir baru:\n"); // edit Tanggal lahir
								fgets(d1_ta, 20, stdin);
                                d1_ta[strcspn(d1_ta, "\r\n")] = 0;
								break;
							case 4:
								printf("Alamat baru:\n"); // edit alamat
								fgets(d1_al, 100, stdin);
                                d1_al[strcspn(d1_al, "\r\n")] = 0;
								break;
							case 5:
								printf("Golongan darah baru:\n"); // edit golongan darah
								fgets(d1_go, 3, stdin);
                                d1_go[strcspn(d1_go, "\r\n")] = 0;
								break;
							case 0: // kembali
								break;
							default: // selain itu
								printf("Input salah!\n\n");
								system("pause");
								break;
						}
					}
					else if(m2 == 2) { // keluar dari lihat data
						break;
					}
					else {
						printf("Input salah!\n\n");
						system("pause");
					}	
				}
				break;
			case 2: // lihat jadwal
				loop3=1;
				while(loop3) {
					system("cls");
					printf("\n                                JADWAL PERKULIAHAN\n");
					printf("____________________________________________________________________________________\n");
					printf("     Pukul     |    Senin    |   Selasa    |    Rabu     |    Kamis    |    Jumat   \n");
					printf("_______________|_____________|_____________|_____________|_____________|____________\n");
	    			printf("  08.00-09.30  |             |%s|%s|%s|%s\n", sel_11, rab_11, kam_11, jum_11);
	    			printf("               |             |             |             |             |            \n");
					printf("  10.00-12.30  |             |%s|%s|%s|%s\n", sel_12, rab_12, kam_12, jum_12);
					printf("               |             |             |             |             |            \n");
					printf("  13.00-15.30  |             |%s|%s|%s|%s\n", sel_13, rab_13, kam_13, jum_13);
					printf("               |             |             |             |             |            \n");
					printf("  16.00-18.30  |             |%s|%s|%s|%s\n", sel_14, rab_14, kam_14, jum_14);
					printf("_______________|_____________|_____________|_____________|_____________|____________\n\n[1] Ubah Kelas\n\n[0] Kembali\n\nPilih menu: ");
					scanf("%d", &k1); // meminta input ubah kelas atau kembali
					system("cls");
					if(k1 == 1) {
						printf("[1] Dasar Komputer\n[2] Elektromagnetika\n[3] Material Teknik Listrik\n[4] Rangkaian Elektronika\n[5] Sinyal dan Sistem\n\nPilih menu: ");
						scanf("%d", &ubah1); // kelas yang ingin diubah
						system("cls");
						switch(ubah1) {
							case 1: // Untuk daskom
								printf("\n                                UBAH JADWAL\n");
								printf("____________________________________________________________________________________\n");
								printf("[1] Dasar Komputer - 01    Jumat, 08.00-09.30\n[2] Dasar Komputer - 02    Selasa, 13.00-15.30\n[3] Dasar Komputer - 03    Rabu, 13.00-15.30\n");
								printf("____________________________________________________________________________________\n\n");
								printf("Pilih menu: \n"); // memilih yang tersedia
								scanf("%d", &dk1);
								system("cls");
								if(dk1 == 1) {
									strcpy(jum_11, "   DKom-01  "); // memngubah nilai pada tabel jadwal
									strcpy(sel_13, "             ");
									strcpy(rab_13, "             ");
								}
								else if(dk1 == 2) {
									strcpy(jum_11, "            ");
									strcpy(sel_13, "   DKom-02   ");
									strcpy(rab_13, "             ");
								}
								else if(dk1 == 3) {
									strcpy(jum_11, "            ");
									strcpy(sel_13, "             ");
									strcpy(rab_13, "   DKom_03   ");
								}
								else {
									printf("\n                                UBAH JADWAL\n");
									printf("____________________________________________________________________________________\n");
									printf("Input salah!\n\n");
									system("pause");
								}
								break;
							case 2: // elektromagnetika
								printf("\n                                UBAH JADWAL\n");
								printf("____________________________________________________________________________________\n");
								printf("[1] Elektromagnetika - 01    Selasa dan Kamis, 08.00-09.30\n[2] Elektromagnetika - 02    Kamis dan Jumat, 16.00-18.30\n");
								printf("____________________________________________________________________________________\n\n");
								printf("Pilih menu: \n");
								scanf("%d", &em1);
								system("cls");
								if(em1 == 1) {
									strcpy(sel_11, "   Elmg-01   ");
									strcpy(kam_11, "   Elmg-01   ");
									strcpy(kam_14, "             ");
									strcpy(jum_14, "            ");
								}
								else if(em1 == 2) {
									strcpy(sel_11, "             ");
									strcpy(kam_11, "             ");
									strcpy(kam_14, "   Elmg-01   ");
									strcpy(jum_14, "   Elmg-01  ");
								}
								else {
									printf("\n                                UBAH JADWAL\n");
									printf("____________________________________________________________________________________\n");
									printf("Input salah!\n\n");
									system("pause");
								}
								break;
							case 3: // Material Teknik Listrik
								printf("\n                                UBAH JADWAL\n");
								printf("____________________________________________________________________________________\n");
								printf("[1] Material Teknik Listrik - 01    Rabu, 08.00-09.30\n[2] Material Teknik Listrik - 02    Rabu, 13.00-15.30\n");
								printf("____________________________________________________________________________________\n\n");
								printf("Pilih menu: \n");
								scanf("%d", &mtl1);
								system("cls");
								if(mtl1 == 1) {
									strcpy(rab_11, "   MTLs-01   ");
									strcpy(rab_13, "             ");
								}
								else if(mtl1 == 2) {
									strcpy(rab_11, "             ");
									strcpy(rab_13, "   MTLs-02   ");
								}
								else {
									printf("\n                                UBAH JADWAL\n");
									printf("____________________________________________________________________________________\n");
									printf("Input salah!\n\n");
									system("pause");
								}
								break;
							case 4: // Rangkaian Elektronika
								printf("\n                                UBAH JADWAL\n");
								printf("____________________________________________________________________________________\n");
								printf("[1] Rangkaian Elektronika - 01    Jumat, 08.00-09.30\n[2] Rangkaian Elektronika - 02    Jumat, 13.30-15.30\n[3] Rangkaian Elektronika - 03    Jumat, 13.00-15.30\n");
								printf("____________________________________________________________________________________\n\n");
								printf("Pilih menu: \n");
								scanf("%d", &re1);
								system("cls");
								if(re1 == 1) {
									strcpy(jum_11, "    RE-01   ");
									strcpy(jum_13, "            ");
								}
								else if(re1 == 2) {
									strcpy(jum_11, "            ");
									strcpy(jum_13, "    RE-02   ");
								}
								else if(re1 == 3) {
									strcpy(jum_11, "            ");
									strcpy(jum_13, "    RE_03   ");
								}
								else {
									printf("\n                                UBAH JADWAL\n");
									printf("____________________________________________________________________________________\n");
									printf("Input salah!\n\n");
									system("pause");
								}
								break;
							case 5: // Sinyal dan Sistem
								printf("\n                                UBAH JADWAL\n");
								printf("____________________________________________________________________________________\n");
								printf("[1] Sinyal dan Sistem - 01    Kamis, 13.00-15.30\n[2] Sinyal dan Sistem - 02    Kamis, 13.00-15.30\n");
								printf("____________________________________________________________________________________\n\n");
								printf("Pilih menu: \n");
								scanf("%d", &sin1);
								system("cls");
								if(sin1 == 1) {
									strcpy(kam_13, "  Sinsis-01  ");
								}
								else if(sin1 == 2) {
									strcpy(kam_13, "  Sinsis-02  ");
								}
								else {
									printf("\n                                UBAH JADWAL\n");
									printf("____________________________________________________________________________________\n");
									printf("Input salah!\n\n");
									system("pause");
								}
								break;
						}
					}
					else if(k1 == 0) { // keluar
						break;
					}
					else {
						printf("\n                                JADWAL PERKULIAHAN\n");
						printf("____________________________________________________________________________________\n");
						printf("Input salah!\n\n");
						system("pause");
					}
				}
				break;
			case 9: // mencetak bantuan
				system("cls");
				printf("_____________________________________________________________________________________\n");
				printf(">Pada menu Lihat Data, Anda dapat melihat dan mengubah data diri.\n Untuk mengubah data, anda akan dialihkan untuk memilih data yang ingin diganti.\n\n");
				printf(">Pada menu Lihat Kelas, Anda dapat menilhat kelas dan diberikan opsi untuk mengubah\n jadwal kelas. Anda dapat memilih jadwal untuk setiap matakuliah yang memiliki\n jadwal lebih dari satu.\n");
				printf("_____________________________________________________________________________________\n\n");
				system("pause");
				break;
			default: // selain input diatas
				system("cls");
				printf("_____________________________________________________________________________________\n");
				printf("                            SISTEM INFORMASI PERKULIAHAN\n\n                                  UNIVERSITAS DEPOK\n");
				printf("_____________________________________________________________________________________\n");
				printf("Input salah!\n\n");
				system("pause");
				break;
		}
	}
}

void menuuser2() { // serupa dengan menuuser1
	int loopz=1, loop2=1, loop3=1, m1, m2, m3, k1, k1a, ubah1, dk1, em1, mtl1, re1, sin1;

	while(loopz) {
		system("cls");
		printf("_____________________________________________________________________________________\n");
		printf("                            SISTEM INFORMASI PERKULIAHAN\n\n                                  UNIVERSITAS DEPOK\n");
		printf("_____________________________________________________________________________________\n");
		printf("[1] Lihat Data\n[2] Lihat Kelas\n\n[9] Help\n[0] Logout\n\nPilih menu: ");
		scanf("%d", &m1);		
        fgetc(stdin);
		switch(m1) {
			case 0:
				loopz=0;
				system("cls");
				break;
			case 1:
				while(loop2) {
					system("cls");
					printf("\n                                  IDENTITAS DIRI\n");
					printf("_____________________________________________________________________________________\n");
					printf(" Nama           : %s\n", d2_na);
					printf(" Tempat lahir   : %s\n", d2_te);
					printf(" Tanggal lahir  : %s\n", d2_ta);
					printf(" Alamat         : %s\n", d2_al);
					printf(" Golongan darah : %s\n", d2_go);
					printf(" IP Terakhir    : 3.51\n");
					printf(" IPK            : 3.65\n");
					printf("_____________________________________________________________________________________");
					printf("\n\n[1] Edit\n[2] Kembali\n\nPilih menu: ");
					scanf("%d", &m2);
                    fgetc(stdin);
					system("cls");
					if (m2 == 1) {
						printf("[1] Nama\n[2] Tempat lahir\n[3] Tanggal lahir\n[4] Alamat\n[5] Golongan darah\n\n[0] Kembali\n\nPilih data yang ingin diubah :");
						scanf("%d", &m3);
                        fgetc(stdin);
						system("cls");
						switch(m3) {
							case 1:
								printf("Nama baru:\n");
								fgets(d2_na, 50, stdin);
                                d1_na[strcspn(d2_na, "\r\n")] = 0;
								break;
							case 2:
								printf("Tempat lahir baru:\n");
								fgets(d2_te, 20, stdin);
                                d1_te[strcspn(d2_te, "\r\n")] = 0;
								break;
							case 3:
								printf("Tanggal lahir baru:\n");
								fgets(d2_ta, 20, stdin);
                                d1_ta[strcspn(d2_ta, "\r\n")] = 0;
								break;
							case 4:
								printf("Alamat baru:\n");
								fgets(d2_al, 100, stdin);
                                d1_al[strcspn(d2_al, "\r\n")] = 0;
								break;
							case 5:
								printf("Golongan darah baru:\n");
								fgets(d2_go, 3, stdin);
                                d1_go[strcspn(d2_go, "\r\n")] = 0;
								break;
							case 0:
								break;
							default:
								printf("Input salah!\n\n");
								system("pause");
								break;
						}
					}
					else if(m2 == 2) {
						break;
					}
					else {
						printf("Input salah!\n\n");
						system("pause");
					}	
				}
				break;
			case 2:
				loop3=1;
				while(loop3) {
					system("cls");
					printf("\n                                JADWAL PERKULIAHAN\n");
					printf("____________________________________________________________________________________\n");
					printf("     Pukul     |    Senin    |   Selasa    |    Rabu     |    Kamis    |    Jumat   \n");
					printf("_______________|_____________|_____________|_____________|_____________|____________\n");
	    			printf("  08.00-09.30  |             |%s|%s|%s|%s\n", sel_21, rab_21, kam_21, jum_21);
	    			printf("               |             |             |             |             |            \n");
					printf("  10.00-12.30  |             |%s|%s|%s|%s\n", sel_22, rab_22, kam_22, jum_22);
					printf("               |             |             |             |             |            \n");
					printf("  13.00-15.30  |             |%s|%s|%s|%s\n", sel_23, rab_23, kam_23, jum_23);
					printf("               |             |             |             |             |            \n");
					printf("  16.00-18.30  |             |%s|%s|%s|%s\n", sel_24, rab_24, kam_24, jum_24);
					printf("_______________|_____________|_____________|_____________|_____________|____________\n\n[1] Ubah Kelas\n\n[0] Kembali\n\nPilih menu: ");
					scanf("%d", &k1);
					system("cls");
					if(k1 == 1) {
						printf("[1] Dasar Komputer\n[2] Elektromagnetika\n[3] Material Teknik Listrik\n[4] Rangkaian Elektronika\n[5] Sinyal dan Sistem\n\nPilih menu: ");
						scanf("%d", &ubah1);
						system("cls");
						switch(ubah1) {
							case 1:
								printf("\n                                UBAH JADWAL\n");
								printf("____________________________________________________________________________________\n");
								printf("[1] Dasar Komputer - 01    Jumat, 08.00-09.30\n[2] Dasar Komputer - 02    Selasa, 13.00-15.30\n[3] Dasar Komputer - 03    Rabu, 13.00-15.30\n");
								printf("____________________________________________________________________________________\n\n");
								printf("Pilih menu: \n");
								scanf("%d", &dk1);
								system("cls");
								if(dk1 == 1) {
									strcpy(jum_21, "   DKom-01  ");
									strcpy(sel_23, "             ");
									strcpy(rab_23, "             ");
								}
								else if(dk1 == 2) {
									strcpy(jum_21, "            ");
									strcpy(sel_23, "   DKom-02   ");
									strcpy(rab_23, "             ");
								}
								else if(dk1 == 3) {
									strcpy(jum_21, "            ");
									strcpy(sel_23, "             ");
									strcpy(rab_23, "   DKom_03   ");
								}
								else {
									printf("\n                                UBAH JADWAL\n");
									printf("____________________________________________________________________________________\n");
									printf("Input salah!\n\n");
									system("pause");
								}
								break;
							case 2:
								printf("\n                                UBAH JADWAL\n");
								printf("____________________________________________________________________________________\n");
								printf("[1] Elektromagnetika - 01    Selasa dan Kamis, 08.00-09.30\n[2] Elektromagnetika - 02    Kamis dan Jumat, 16.00-18.30\n");
								printf("____________________________________________________________________________________\n\n");
								printf("Pilih menu: \n");
								scanf("%d", &em1);
								system("cls");
								if(em1 == 1) {
									strcpy(sel_21, "   Elmg-01   ");
									strcpy(kam_21, "   Elmg-01   ");
									strcpy(kam_24, "             ");
									strcpy(jum_24, "            ");
								}
								else if(em1 == 2) {
									strcpy(sel_21, "             ");
									strcpy(kam_21, "             ");
									strcpy(kam_24, "   Elmg-01   ");
									strcpy(jum_24, "   Elmg-01  ");
								}
								else {
									printf("\n                                UBAH JADWAL\n");
									printf("____________________________________________________________________________________\n");
									printf("Input salah!\n\n");
									system("pause");
								}
								break;
							case 3:
								printf("\n                                UBAH JADWAL\n");
								printf("____________________________________________________________________________________\n");
								printf("[1] Material Teknik Listrik - 01    Rabu, 08.00-09.30\n[2] Material Teknik Listrik - 02    Rabu, 13.00-15.30\n");
								printf("____________________________________________________________________________________\n\n");
								printf("Pilih menu: \n");
								scanf("%d", &mtl1);
								system("cls");
								if(mtl1 == 1) {
									strcpy(rab_21, "   MTLs-01   ");
									strcpy(rab_23, "             ");
								}
								else if(mtl1 == 2) {
									strcpy(rab_21, "             ");
									strcpy(rab_23, "   MTLs-02   ");
								}
								else {
									printf("\n                                UBAH JADWAL\n");
									printf("____________________________________________________________________________________\n");
									printf("Input salah!\n\n");
									system("pause");
								}
								break;
							case 4:
								printf("\n                                UBAH JADWAL\n");
								printf("____________________________________________________________________________________\n");
								printf("[1] Rangkaian Elektronika - 01    Jumat, 08.00-09.30\n[2] Rangkaian Elektronika - 02    Jumat, 13.30-15.30\n[3] Rangkaian Elektronika - 03    Jumat, 13.00-15.30\n");
								printf("____________________________________________________________________________________\n\n");
								printf("Pilih menu: \n");
								scanf("%d", &re1);
								system("cls");
								if(re1 == 1) {
									strcpy(jum_21, "    RE-01   ");
									strcpy(jum_23, "            ");
								}
								else if(re1 == 2) {
									strcpy(jum_21, "            ");
									strcpy(jum_23, "    RE-02   ");
								}
								else if(re1 == 3) {
									strcpy(jum_21, "            ");
									strcpy(jum_23, "    RE_03   ");
								}
								else {
									printf("\n                                UBAH JADWAL\n");
									printf("____________________________________________________________________________________\n");
									printf("Input salah!\n\n");
									system("pause");
								}
								break;
							case 5:
								printf("\n                                UBAH JADWAL\n");
								printf("____________________________________________________________________________________\n");
								printf("[1] Sinyal dan Sistem - 01    Kamis, 13.00-15.30\n[2] Sinyal dan Sistem - 02    Kamis, 13.00-15.30\n");
								printf("____________________________________________________________________________________\n\n");
								printf("Pilih menu: \n");
								scanf("%d", &sin1);
								system("cls");
								if(sin1 == 1) {
									strcpy(kam_23, "  Sinsis-01  ");
								}
								else if(sin1 == 2) {
									strcpy(kam_23, "  Sinsis-02  ");
								}
								else {
									printf("\n                                UBAH JADWAL\n");
									printf("____________________________________________________________________________________\n");
									printf("Input salah!\n\n");
									system("pause");
								}
								break;
						}
					}
					else if(k1 == 0) {
						break;
					}
					else {
						printf("\n                                JADWAL PERKULIAHAN\n");
						printf("____________________________________________________________________________________\n");
						printf("Input salah!\n\n");
						system("pause");
					}
				}
				break;
			case 9:
				system("cls");
				printf("_____________________________________________________________________________________\n");
				printf(">Pada menu Lihat Data, Anda dapat melihat dan mengubah data diri.\n Untuk mengubah data, anda akan dialihkan untuk memilih data yang ingin diganti.\n\n");
				printf(">Pada menu Lihat Kelas, Anda dapat menilhat kelas dan diberikan opsi untuk mengubah\n jadwal kelas. Anda dapat memilih jadwal untuk setiap matakuliah yang memiliki\n jadwal lebih dari satu.\n");
				printf("_____________________________________________________________________________________\n\n");
				system("pause");
				break;
			default:
				system("cls");
				printf("_____________________________________________________________________________________\n");
				printf("                            SISTEM INFORMASI PERKULIAHAN\n\n                                  UNIVERSITAS DEPOK\n");
				printf("_____________________________________________________________________________________\n");
				printf("Input salah!\n\n");
				system("pause");
				break;
		}
	}
}

void menuuser3() { // serupa dengan menuuser1
	int loopz=1, loop2=1, loop3=1, m1, m2, m3, k1, k1a, ubah1, dk1, em1, mtl1, re1, sin1;

	while(loopz) {
		system("cls");
		printf("_____________________________________________________________________________________\n");
		printf("                            SISTEM INFORMASI PERKULIAHAN\n\n                                  UNIVERSITAS DEPOK\n");
		printf("_____________________________________________________________________________________\n");
		printf("[1] Lihat Data\n[2] Lihat Kelas\n\n[9] Help\n[0] Logout\n\nPilih menu: ");
		scanf("%d", &m1);		
        fgetc(stdin);
		switch(m1) {
			case 0:
				loopz=0;
				system("cls");
				break;
			case 1:
				while(loop2) {
					system("cls");
					printf("\n                                  IDENTITAS DIRI\n");
					printf("_____________________________________________________________________________________\n");
					printf(" Nama           : %s\n", d3_na);
					printf(" Tempat lahir   : %s\n", d3_te);
					printf(" Tanggal lahir  : %s\n", d3_ta);
					printf(" Alamat         : %s\n", d3_al);
					printf(" Golongan darah : %s\n", d3_go);
					printf(" IP Terakhir    : 3.51\n");
					printf(" IPK            : 3.65\n");
					printf("_____________________________________________________________________________________");
					printf("\n\n[1] Edit\n[2] Kembali\n\nPilih menu: ");
					scanf("%d", &m2);
                    fgetc(stdin);
					system("cls");
					if (m2 == 1) {
						printf("[1] Nama\n[2] Tempat lahir\n[3] Tanggal lahir\n[4] Alamat\n[5] Golongan darah\n\n[0] Kembali\n\nPilih data yang ingin diubah :");
						scanf("%d", &m3);
                        fgetc(stdin);
						system("cls");
						switch(m3) {
							case 1:
								printf("Nama baru:\n");
								fgets(d3_na, 50, stdin);
                                d3_na[strcspn(d3_na, "\r\n")] = 0;
								break;
							case 2:
								printf("Tempat lahir baru:\n");
								fgets(d3_te, 20, stdin);
                                d3_te[strcspn(d3_te, "\r\n")] = 0;
								break;
							case 3:
								printf("Tanggal lahir baru:\n");
								fgets(d3_ta, 20, stdin);
                                d3_ta[strcspn(d3_ta, "\r\n")] = 0;
								break;
							case 4:
								printf("Alamat baru:\n");
								fgets(d3_al, 100, stdin);
                                d3_al[strcspn(d3_al, "\r\n")] = 0;
								break;
							case 5:
								printf("Golongan darah baru:\n");
								fgets(d3_go, 3, stdin);
                                d3_go[strcspn(d3_go, "\r\n")] = 0;
								break;
							case 0:
								break;
							default:
								printf("Input salah!\n\n");
								system("pause");
								break;
						}
					}
					else if(m2 == 2) {
						break;
					}
					else {
						printf("Input salah!\n\n");
						system("pause");
					}	
				}
				break;
			case 2:
				loop3=1;
				while(loop3) {
					system("cls");
					printf("\n                                JADWAL PERKULIAHAN\n");
					printf("____________________________________________________________________________________\n");
					printf("     Pukul     |    Senin    |   Selasa    |    Rabu     |    Kamis    |    Jumat   \n");
					printf("_______________|_____________|_____________|_____________|_____________|____________\n");
	    			printf("  08.00-09.30  |             |%s|%s|%s|%s\n", sel_31, rab_31, kam_31, jum_31);
	    			printf("               |             |             |             |             |            \n");
					printf("  10.00-12.30  |             |%s|%s|%s|%s\n", sel_32, rab_32, kam_32, jum_32);
					printf("               |             |             |             |             |            \n");
					printf("  13.00-15.30  |             |%s|%s|%s|%s\n", sel_33, rab_33, kam_33, jum_33);
					printf("               |             |             |             |             |            \n");
					printf("  16.00-18.30  |             |%s|%s|%s|%s\n", sel_34, rab_34, kam_34, jum_34);
					printf("_______________|_____________|_____________|_____________|_____________|____________\n\n[1] Ubah Kelas\n\n[0] Kembali\n\nPilih menu: ");
					scanf("%d", &k1);
					system("cls");
					if(k1 == 1) {
						printf("[1] Dasar Komputer\n[2] Elektromagnetika\n[3] Material Teknik Listrik\n[4] Rangkaian Elektronika\n[5] Sinyal dan Sistem\n\nPilih menu: ");
						scanf("%d", &ubah1);
						system("cls");
						switch(ubah1) {
							case 1:
								printf("\n                                UBAH JADWAL\n");
								printf("____________________________________________________________________________________\n");
								printf("[1] Dasar Komputer - 01    Jumat, 08.00-09.30\n[2] Dasar Komputer - 02    Selasa, 13.00-15.30\n[3] Dasar Komputer - 03    Rabu, 13.00-15.30\n");
								printf("____________________________________________________________________________________\n\n");
								printf("Pilih menu: \n");
								scanf("%d", &dk1);
								system("cls");
								if(dk1 == 1) {
									strcpy(jum_31, "   DKom-01  ");
									strcpy(sel_33, "             ");
									strcpy(rab_33, "             ");
								}
								else if(dk1 == 2) {
									strcpy(jum_31, "            ");
									strcpy(sel_33, "   DKom-02   ");
									strcpy(rab_33, "             ");
								}
								else if(dk1 == 3) {
									strcpy(jum_31, "            ");
									strcpy(sel_33, "             ");
									strcpy(rab_33, "   DKom_03   ");
								}
								else {
									printf("\n                                UBAH JADWAL\n");
									printf("____________________________________________________________________________________\n");
									printf("Input salah!\n\n");
									system("pause");
								}
								break;
							case 2:
								printf("\n                                UBAH JADWAL\n");
								printf("____________________________________________________________________________________\n");
								printf("[1] Elektromagnetika - 01    Selasa dan Kamis, 08.00-09.30\n[2] Elektromagnetika - 02    Kamis dan Jumat, 16.00-18.30\n");
								printf("____________________________________________________________________________________\n\n");
								printf("Pilih menu: \n");
								scanf("%d", &em1);
								system("cls");
								if(em1 == 1) {
									strcpy(sel_11, "   Elmg-01   ");
									strcpy(kam_11, "   Elmg-01   ");
									strcpy(kam_14, "             ");
									strcpy(jum_14, "            ");
								}
								else if(em1 == 2) {
									strcpy(sel_31, "             ");
									strcpy(kam_31, "             ");
									strcpy(kam_34, "   Elmg-01   ");
									strcpy(jum_34, "   Elmg-01  ");
								}
								else {
									printf("\n                                UBAH JADWAL\n");
									printf("____________________________________________________________________________________\n");
									printf("Input salah!\n\n");
									system("pause");
								}
								break;
							case 3:
								printf("\n                                UBAH JADWAL\n");
								printf("____________________________________________________________________________________\n");
								printf("[1] Material Teknik Listrik - 01    Rabu, 08.00-09.30\n[2] Material Teknik Listrik - 02    Rabu, 13.00-15.30\n");
								printf("____________________________________________________________________________________\n\n");
								printf("Pilih menu: \n");
								scanf("%d", &mtl1);
								system("cls");
								if(mtl1 == 1) {
									strcpy(rab_31, "   MTLs-01   ");
									strcpy(rab_33, "             ");
								}
								else if(mtl1 == 2) {
									strcpy(rab_31, "             ");
									strcpy(rab_33, "   MTLs-02   ");
								}
								else {
									printf("\n                                UBAH JADWAL\n");
									printf("____________________________________________________________________________________\n");
									printf("Input salah!\n\n");
									system("pause");
								}
								break;
							case 4:
								printf("\n                                UBAH JADWAL\n");
								printf("____________________________________________________________________________________\n");
								printf("[1] Rangkaian Elektronika - 01    Jumat, 08.00-09.30\n[2] Rangkaian Elektronika - 02    Jumat, 13.30-15.30\n[3] Rangkaian Elektronika - 03    Jumat, 13.00-15.30\n");
								printf("____________________________________________________________________________________\n\n");
								printf("Pilih menu: \n");
								scanf("%d", &re1);
								system("cls");
								if(re1 == 1) {
									strcpy(jum_31, "    RE-01   ");
									strcpy(jum_33, "            ");
								}
								else if(re1 == 2) {
									strcpy(jum_31, "            ");
									strcpy(jum_33, "    RE-02   ");
								}
								else if(re1 == 3) {
									strcpy(jum_31, "            ");
									strcpy(jum_33, "    RE_03   ");
								}
								else {
									printf("\n                                UBAH JADWAL\n");
									printf("____________________________________________________________________________________\n");
									printf("Input salah!\n\n");
									system("pause");
								}
								break;
							case 5:
								printf("\n                                UBAH JADWAL\n");
								printf("____________________________________________________________________________________\n");
								printf("[1] Sinyal dan Sistem - 01    Kamis, 13.00-15.30\n[2] Sinyal dan Sistem - 02    Kamis, 13.00-15.30\n");
								printf("____________________________________________________________________________________\n\n");
								printf("Pilih menu: \n");
								scanf("%d", &sin1);
								system("cls");
								if(sin1 == 1) {
									strcpy(kam_33, "  Sinsis-01  ");
								}
								else if(sin1 == 2) {
									strcpy(kam_33, "  Sinsis-02  ");
								}
								else {
									printf("\n                                UBAH JADWAL\n");
									printf("____________________________________________________________________________________\n");
									printf("Input salah!\n\n");
									system("pause");
								}
								break;
						}
					}
					else if(k1 == 0) {
						break;
					}
					else {
						printf("\n                                JADWAL PERKULIAHAN\n");
						printf("____________________________________________________________________________________\n");
						printf("Input salah!\n\n");
						system("pause");
					}
				}
				break;
			case 9:
				system("cls");
				printf("_____________________________________________________________________________________\n");
				printf(">Pada menu Lihat Data, Anda dapat melihat dan mengubah data diri.\n Untuk mengubah data, anda akan dialihkan untuk memilih data yang ingin diganti.\n\n");
				printf(">Pada menu Lihat Kelas, Anda dapat menilhat kelas dan diberikan opsi untuk mengubah\n jadwal kelas. Anda dapat memilih jadwal untuk setiap matakuliah yang memiliki\n jadwal lebih dari satu.\n");
				printf("_____________________________________________________________________________________\n\n");
				system("pause");
				break;
			default:
				system("cls");
				printf("_____________________________________________________________________________________\n");
				printf("                            SISTEM INFORMASI PERKULIAHAN\n\n                                  UNIVERSITAS DEPOK\n");
				printf("_____________________________________________________________________________________\n");
				printf("Input salah!\n\n");
				system("pause");
				break;
		}
	}
}

void menuadmin()
{	
    int optb,loop=1,challenge; // deklarasi variable awal
    while(loop) {
		printf("\nMENU ADMIN\n\n");
		printf("____________________________________________________________________________________\n");
		printf("                                   List User siak\n");
		printf("____________________________________________________________________________________\n");
		printf(" No\t%-30sPassword\n","Username");
		printf("____________________________________________________________________________________\n");
    	printf("[1]\t%-30s\t%s\n\n",u1n,u1p);
		printf("[2]\t%-30s\t%s\n\n",u2n,u2p);
		printf("[3]\t%-30s\t%s\n",u3n,u3p);
		printf("____________________________________________________________________________________");
		printf("\n\n[9] Help\n[0] Logout\n\nPilih menu: ");
		scanf("%d", &optb); // mengambil input
		fgetc(stdin); // memakan \n dari scanf
		system("cls");
		switch(optb) {
            case 1:
            	printf("Masukkan password admin: ");
                fgets(sp, 30, stdin); // meminta password admin kembali sebagai verifikasi ulang.
                sp[strcspn(sp, "\r\n")] = 0; // membuang \n dari fgets diatas
                challenge = strcmp(sp, ap); // membandingkan masukan dengan password database
                if(challenge == 0) {
					printf("\nUsername lama: %s\nMasukkan username yang baru untuk user1: ",u1n);
                    fgets(u1n, 30, stdin); // mengambil username baru
                    u1n[strcspn(u1n, "\r\n")] = 0; // membuang \n dari fgets diatas
                    printf("\nPassword lama: %s\nMasukkan password yang baru untuk user1: ",u1p);
                    fgets(u1p, 30, stdin);// mengambil passwird baru
                    u1p[strcspn(u1p, "\r\n")] = 0;// membuang \n dari fgets diatas
                    printf("\n\nPerubahan telah disimpan!\n");
                    system("pause");
                    system("cls");
                }
                else {
					printf("Password salah!\n\n");
					system("pause");
                }
                break;         
            case 2: // serupa dengan diatas
            	printf("Masukkan password admin: ");
                fgets(sp, 30, stdin);
                sp[strcspn(sp, "\r\n")] = 0;
                challenge = strcmp(sp, ap);
                if(challenge == 0) {
					printf("\nUsername lama: %s\nMasukkan username yang baru untuk user2: ", u2n);
                    fgets(u2n, 30, stdin);
                    u2n[strcspn(u2n, "\r\n")] = 0;
                    printf("\nPassword lama: %s\nMasukkan password yang baru untuk user2: ", u2p);
                    fgets(u2p, 30, stdin);
                    u2p[strcspn(u2p, "\r\n")] = 0;
                    printf("\n\nPerubahan telah disimpan!\n");
                    system("pause");
                    system("cls");
                }
                else {
					printf("Password salah!\n\n");
					system("pause");
                }
                break;
            case 3: // serupa dengan diatas
            	printf("Masukkan password admin: ");
                fgets(sp, 30, stdin);
                sp[strcspn(sp, "\r\n")] = 0;
                challenge = strcmp(sp, ap);
                if(challenge == 0) {
					printf("\nUsername lama: %s\nMasukkan username yang baru untuk user3: ", u3n);
                    fgets(u3n, 30, stdin);
                    u3n[strcspn(u3n, "\r\n")] = 0;
                    printf("\nPassword lama: %s\nMasukkan password yang baru untuk user3: ", u3p);
                    fgets(u3p, 30, stdin);
                    u3p[strcspn(u3p, "\r\n")] = 0;
                    printf("\n\nPerubahan telah disimpan!\n");
                    system("pause");
                    system("cls");
                }
                else {
					printf("Password salah!\n\n");
					system("pause");
                }
                break;
            case 9: // mencetak teks bantuan
            	printf("____________________________________________________________________________________\n");
                printf(" Pada menu admin, anda dapat mengedit list user pada SIP.\n Untuk mengeditnya, sebagai contoh anda ingin mengedit user 1., \n maka masukkan input 1, lalu masukkan password admin, \n baru setelahnya merubah data user. \n");
                printf(" Maka data user sudah berubah. Setelah selesai, masukkan input 0. \n Untuk keluar dari menu admin tekan 0\n");
                printf("____________________________________________________________________________________\n\n");
                system("pause");
                system("cls");
                break;
            case 0: // keluar menu admin dan kembali ke menu login
                loop=0;
                break;
            default: // apabila input selain diatas
                printf("Input tidak dikenali.");
                system("pause");
                break;
    	}
    }
}

void menulogin()
{
    int aplane=1; // deklarasi variable lokal
    int f,g;
    while(aplane) { // looping
    	printf("_____________________________________________________________________________________\n");
		printf("                            SISTEM INFORMASI PERKULIAHAN\n\n                                  UNIVERSITAS DEPOK\n");
		printf("_____________________________________________________________________________________\n");
        printf("LOGIN\n______\n\nSilahkan masukkan 'exit' pada username untuk kembali.\n\nUsername: ");
        fgets(sn, 30, stdin); // pengambilan nilai variable username
        sn[strcspn(sn, "\n")] = 0; // membuang \n
        f = strcmp(sn,a); // membandingkan input username dengan 'exit'
        if(f==0) {
            break; //keluar apabila 'exit'
        }
        printf("Password: ");
        fgets(sp, 30, stdin); // mengambil nilai password
        sp[strcspn(sp, "\r\n")] = 0;
        system("cls");
        f = strcmp(sn, an); g = strcmp(sp, ap); // 0 0 login admin (membandingan masukan user dengan database
        if(!(f||g)) {
            menuadmin(); // memasuki menu admin apabila username dan password admin benar
            continue;
        }
        f = strcmp(sn, u1n); g = strcmp(sp, u1p); // 0 0 login user1
        if(!(f||g)) {
            menuuser1();// memasuki menu user apabila username dan password user benar
            continue;
        }
        f = strcmp(sn, u2n); g = strcmp(sp, u2p); // 0 0 login user2
        if(!(f||g)) {
            menuuser2(); // serupa dengan diatas
            continue;
        }
        f = strcmp(sn, u3n); g = strcmp(sp, u3p); // 0 0 login user3
        if(!(f||g)) {
            menuuser3();// serupa dengan diatas
            continue;
        }
        else { // apabila masukkan tidak ada yang sesuai dengan database
        	printf("_____________________________________________________________________________________\n");
			printf("                            SISTEM INFORMASI PERKULIAHAN\n\n                                  UNIVERSITAS DEPOK\n");
			printf("_____________________________________________________________________________________\n");
			printf("Username atau password salah!\n\n");
        	system("pause");
            system("cls");
        }               
    }
}

int main()
{
	system("mode 85, 30"); // Setting warna daripada program
	system("color 0e");
    strcpy(u1n,"user1"); //mencatuman nilai variable username dan password default
    strcpy(u1p,"pw1");
    strcpy(u2n,"user2");
    strcpy(u2p,"pw2");
    strcpy(u3n,"user3");
    strcpy(u3p,"pw3");
    strcpy(an,"admin");
    strcpy(ap,"admin");
    strcpy(a,"exit");
    while(1) {
        printf("_____________________________________________________________________________________\n");
		printf("                            SISTEM INFORMASI PERKULIAHAN\n\n                                  UNIVERSITAS DEPOK\n");
		printf("_____________________________________________________________________________________\n");
		printf("[1] Sign-in\n[2] Exit\n\nPilihan: ");
        scanf("%d", &opta); //meinta input user, login atau exit
        fgetc(stdin); //menangkap \n dari scanf
        system("cls"); // clear screen
        switch(opta) {
            case 1:
                menulogin(); //masuk menu login apabila input 1
                break;
            case 2:
                return 0; // exit apabila 2
            default:
            	printf("_____________________________________________________________________________________\n");// apabila input selain itu
				printf("                            SISTEM INFORMASI PERKULIAHAN\n\n                                  UNIVERSITAS DEPOK\n");
				printf("_____________________________________________________________________________________\n");
                printf("Input salah!\n\n");
                system("pause");
                break;
        }
    system("cls");
    }
}
