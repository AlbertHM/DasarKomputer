//Albert HM 1506672496
//Soal Konversi suhu

#include<stdio.h>

int opta,a,c,f,k,r;

int main()
{
	printf("Silahkan pilih jenis suhu masukan\n[1] Celcius\n[2] Reamur\n[3]Fahrenheit\n[4]Kelvin\nNo :");
	scanf("%d". &opta);
	printf("Silahkan masukkan nilai suhunya :"); scanf("%d", &a);
	
	switch(opta)
	{
		case 1: //dari Celcius
			f = a * 1.8 +32;
			k = a + 273.15;
			r = a * 0.8;
			
		case 2: // dari Reamur
			c = a * 1.25;
			f = a * 2.25 +32;
			k = a * 1.25 +273.15;
		case 3: //dari fahrenheit
			c = (a-32)/1.8;
			k = c + 273.15;
			r = c * 0.8;
		case 4: // dari kelvin
			c = a -273.15
			f = c * 1.8 + 32
			r = c * 0.8			
		default:
			printf("Terjadi galat");
			break;
	
