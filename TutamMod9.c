//Program C paling user friendly pertama w.. hehe....
//Albert Harazaki Mendrofa
//1506672496

#include<stdio.h>
#include<stdlib.h>

int opta, repeat=1, optb, repeatb;

int main()
{
    do
    {
     printf("Selamat datang di program modul 9 Daskom!\n");
     printf("Silahkan pilih menu :\n");
     printf("[1] Kesan\n[2] Saran\n[3] Daftar aslab selama praktikum\n[4] Developer\n[5] Keluar\nPilihan : ");
     scanf("%d", &opta);
     system("cls");
     switch(opta)
     {
                 case 1:
                      printf("Kesan selama praktikum :\n\n");
                      printf("Selama praktikum dasar komputer, saya mendapatkan banyak tambahan ilmu tentang penerapan komputer");
                      printf("baik itu berupa perangkat lunak, perangkat keras, jaringan, dan dasar dari pemrograman.\n\n\n");
                      system("pause");
                      break;
                 case 2:
                      printf("Saran dari praktikan :\n\n");
                      printf("Setelah praktikum dasar komputer, saya memiliki sejumlah saran :\n");
                      printf("1.Untuk praktikum pseudocode, sebaiknya study casenya diberikan yang lebih mudah, pada praktikum");
                      printf("  kalau tidak salah study casenya tentang sorting dan switch case. Bagi saya dan teman-teman yang");
                      printf("  sudah memiliki dasar-dasar pemrograman tentu bukan suatu perkara. Namun masih banyak mahasiswa");
                      printf("  yang baru benar-benar pertama kali itu mengetahui pemrograman dan menjadi kesulitan, diskusi");
                      printf("  saya dengan teman yang lain, mereka memiliki anggapan pemrograman itu susah. Sedangkan sebenarnya");
                      printf("  tidak. Jadi mohon ada pertimbangannya. :)\n\n");
                      printf("2.Untuk tp dan tutam mohon tidak dadakan pemberitahuannya.\n");
                      printf("Ya mungkin itu saja saran dari saya, mohon maaf apabila ada salah kata, semoga kedepannya dapat menjadi lebih baik :)\n\n\n");
                      system("pause");
                      break;
                 case 3:
                      do
                      {
                       repeatb=1;
                       printf("Daftar aslab selama prakitkum:");
                       printf("Silahkan pilih :\n[1]Kandika Bagaskara\n[2]Nur Hazbiy\n[3]Kembali\nPilihan : ");
                       scanf("%d", &optb);
                       system("cls");
                       switch(optb)
                       {
                                   case 1:
                                        printf("Ocang\n");
                                        printf("--");
                                        printf("--\n\n");
                                        system("pause");
                                        break;
                                   case 2:
                                        printf("Hazbiy\n");
                                        printf("--\n\n");
                                        system("pause");
                                        break;
                                   case 3:
                                        repeatb=0;
                                        break;
                                   default:
                                        printf("Terjadi galat pada input!");
                                        break;
                       }
                       system("cls");
                      }
                      while(repeatb==1);
                      break;
                 case 4:
                      printf("Nama\t : Albert Harazaki Mendrofa\nNPM\t : 1506672496\nKelas\t : Daskom 01(Jumat)\n\n");
                      system("pause");
                      break;
                 case 5:
                      printf("Terima kasih telah menjalankan aplikasi ini!\n");
                      repeat = 0;
                      system("pause");
                      break;
                 default:
                         printf("Terjadi galat input!\n\n");
                         system("pause");
                         break;
     }
     system("cls");
     }
    while(repeat);
    return 0;
}
