#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void user();
int u;

void admin();
FILE *f_film, *f_film2, *f_jadwal, *f_jadwal2;
void addfilm();
void addtanggal();
void checkpenonton();
void removefilm();
void removetanggal();

void penonton();
void sortingfilm();
void choosetanggal();
void findfilm();

int i, f, j, n=0, n_t;
int y_n;
char find[500];
struct {
	char film[500], desk[999], tanggal[100], waktu[100], kursi[100];
}d, temp[100], temp2;
int main() {
	system("cls");
	
	//Pemilihan User (Switch case)
	user();
	//Penonton
	//Daftar film yang tersedia (List)
	//Pemilihan tanggal dan waktu (Switch case)
	//Jumlah pembelian tiket (Amount of)
	//Mencari film (Search)
	
	//Admin
	//Input daftar film (File sekuensial write)
	//Input deskripsi film (File sekuensial write)
	//Input tanggal dan waktu (File sekuensial write)
	//Riwayat penonton (??)
	//Hapus Film (File Sekuensial remove)
	return 0;
}

void user() { //Menu User
	system("cls");
	printf("=================================================\n");
	printf("=         *            *            *           =\n");
	printf("====== Selamat Datang di Bioskop D'THEATRE ======\n");
	printf("=      ^                ^                ^      =\n");
	printf("=================================================\n");
	printf("Pilihlah user :\n");
	printf("[1] Admin\n[2] Penonton\n");
	scanf("%d", &u);
	switch (u) {
		case 1:admin();break;
		case 2:penonton();break;
		default :printf("Who are you? RESTART\n\nPencet 'enter' untuk kembali.\n\n");system("pause");user();break;
	}
}

void admin() { //Menu Admin
	system("cls");
	printf("================================================\n");
	printf("=                                              =\n");
	printf("================== Menu Admin ==================\n");
	printf("=                                              =\n");
	printf("================================================\n");
	printf("[1] Tambah Film\n[2] Tambah Tanggal\n[3] Cek Total Penonton\n[4] Hapus Film\n[5] Hapus Tanggal\n[6] Menu User\n");
	scanf("%d", &u); getchar();
	switch (u) {
		case 1:addfilm();break;
		case 2:addtanggal();break;
		case 3:checkpenonton();break;
		case 4:removefilm();break;
		case 5:removetanggal();break;
		case 6:user();break;
		default : printf("Tidak ada menu ini pencet 'enter' untuk kembali.\n\n");system("pause");admin();break;
	}
}

void addfilm() { //Input daftar, deskripsi film (File sekuensial appandent)
	system("cls");
	printf("================================================\n");
	printf("=                                              =\n");
	printf("========== Penambahan Film D'THEATRE ===========\n");
	printf("=                                              =\n");
	printf("================================================\n");
	f_film = fopen("film.dat","ab");
	printf("Berapa film yang akan ditambahkan? : ");
	scanf("%d", &f); getchar();
	system("cls");
	printf("================================================\n");
	printf("=                                              =\n");
	printf("========== Penambahan Film D'THEATRE ===========\n");
	printf("=                                              =\n");
	printf("================================================\n");	
	for (i=1; i<=f; i++) {	
		printf("[%d] Nama Film     \t: ", i);
		gets(d.film);
		printf("    Deskripsi Film\t: ");
		gets(d.desk);
		printf("    Kuota Kursi   \t: ");
		gets(d.kursi);
		fwrite(&d, sizeof(d), 1, f_film);
		printf("\n");
	}
	fclose(f_film);
	printf("\nFilm tersebut berhasil ditambah, pencet 'enter' untuk kembali\n\n");
	system("pause");
	admin();
}

void addtanggal() { //Input tanggal dan waktu (File sekuensial write)
	system("cls");
	printf("================================================\n");
	printf("=                                              =\n");
	printf("==== Penambahan Tanggal dan Waktu D'THEATRE ====\n");
	printf("=                                              =\n");
	printf("================================================\n");
	f_jadwal = fopen("jadwal.dat","ab");
	printf("Berapa tanggal dan waktu yang akan ditambahkan? : ");
	scanf("%d", &j); getchar();
	system("cls");
	printf("================================================\n");
	printf("=                                              =\n");
	printf("==== Penambahan Tanggal dan Waktu D'THEATRE ====\n");
	printf("=                                              =\n");
	printf("================================================\n");
	for (i=1; i<=j; i++) {
		printf("[%d] Tanggal\t: ", i);
		gets(d.tanggal);
		printf("    Waktu  \t: ");
		gets(d.waktu);
		fwrite(&d,sizeof(d),1,f_jadwal);
		printf("\n");
	}
	fclose(f_jadwal);
	printf("\nTanggal tersebut berhasil ditambah, pencet 'enter' untuk kembali\n\n");
	system("pause");
	admin();
}

void checkpenonton() { //Riwayat penonton (Tipe Data dan Komponen)
	system("cls");
	printf("============================================================\n");
	printf("=                                                          =\n");
	printf("==== Total penonton yang sudah menonton film : %d orang ====\n", n_t);
	printf("=                                                          =\n");
	printf("============================================================\n");
	system("pause");
	admin();
}

void removefilm() { //Hapus Film (File Sekuensial remove)
	i=0;
	system("cls");
	printf("====================================\n");
	printf("=                                  =\n");
	printf("==== Penghapusan Film D'THEATRE ====\n");
	printf("=                                  =\n");
	printf("====================================\n");
	char dicari[500];
		f_film = fopen("film.dat", "rb");
		while(fread(&d, sizeof(d), 1, f_film)==1) {
			printf("[%d] Film\t: %s\n", ++i, d.film);
	}
	fclose(f_film);
		f_film = fopen("film.dat", "rb");
		f_film2 = fopen("film2.dat", "wb");
	printf("Masukkan Film yang ingin dihapus : "); 
	gets(dicari);
		while (fread(&d,sizeof(d),1,f_film)==1) {
			if (strcmp(d.film,dicari)!=0) {
				fwrite(&d,sizeof(d),1,f_film2);
			}
		}
	fclose(f_film);
	fclose(f_film2);
	remove("film.dat");
	rename("film2.dat","film.dat");
	i=0;
	system("cls");
	printf("====================================\n");
	printf("=                                  =\n");
	printf("==== Penghapusan Film D'THEATRE ====\n");
	printf("=                                  =\n");
	printf("====================================\n");
	f_film = fopen("film.dat", "rb");
		while(fread(&d, sizeof(d), 1, f_film)==1) {
			printf("[%d] Film\t: %s\n", ++i, d.film);
		}
	fclose(f_film);
	printf("\nFilm tersebut berhasil terhapus, pencet 'enter' untuk kembali\n\n");
	system("pause");
	admin();
}

void removetanggal() { //Hapus Tanggal dan Waktu (File Sekuensial Remove)
	i=0;
	system("cls");
	printf("=================================================\n");
	printf("=                                               =\n");
	printf("==== Penghapusan Tanggal dan Waktu D'THEATRE ====\n");
	printf("=                                               =\n");
	printf("=================================================\n");
	f_jadwal = fopen("jadwal.dat", "rb");	
	printf("Jadwal Film :\n");
	while(fread(&d, sizeof(d), 1, f_jadwal)==1) {
		printf("%s | %s\n", d.tanggal, d.waktu);
	}
	fclose(f_jadwal);
	char dicari[500];
		f_jadwal = fopen("jadwal.dat", "rb");
		f_jadwal2 = fopen("jadwal2.dat", "wb");
	printf("Masukkan Tanggal yang ingin dihapus : "); 
	gets(dicari);
	while (fread(&d, sizeof(d), 1, f_jadwal)==1){
		if (strcmp(d.tanggal, dicari)!=0){
		fwrite(&d, sizeof(d), 1, f_jadwal2);
		}
	}
	fclose(f_jadwal);
	fclose(f_jadwal2);
	remove("jadwal.dat");
	rename("jadwal2.dat","jadwal.dat");
	i=0;
	system("cls");
	printf("=================================================\n");
	printf("=                                               =\n");
	printf("==== Penghapusan Tanggal dan Waktu D'THEATRE ====\n");
	printf("=                                               =\n");
	printf("=================================================\n");
	printf("Jadwal Film : \n");
	f_jadwal = fopen("jadwal.dat", "rb");
	while (fread(&d, sizeof(d), 1, f_jadwal)==1) {
		printf("%s | %s\n", d.tanggal, d.waktu);
	}
	fclose(f_jadwal);
	printf("\nTanggal tersebut berhasil terhapus, pencet 'enter' untuk kembali\n\n");
	system("pause");
	admin();
}

void penonton() {
	system("cls");
	printf("================================================\n");
	printf("=                                              =\n");
	printf("=========== Menu Penonton D'THEATRE ============\n");
	printf("=                                              =\n");
	printf("================================================\n");
	printf("[1] Daftar Film\n[2] Pemilihan Film\n[3] Mencari Film\n[4] Menu User\n");
	scanf("%d", &u); getchar();
	switch (u) {
		case 1:sortingfilm();break;
		case 2:choosetanggal();break;
		case 3:findfilm();break;
		case 4:user();break;
		default : printf("Tidak ada menu ini pencet 'enter' untuk kembali.\n\n");system("pause");penonton();break;
	}
}

void sortingfilm() { //Daftar film yang tersedia (List)
	system("cls");
	printf("================================================\n");
	printf("=                                              =\n");
	printf("============ Daftar Film D'THEATRE =============\n");
	printf("=                                              =\n");
	printf("================================================\n");
	int n=0, i=1;
	f_film = fopen("film.dat", "rb");
	while(fread(&d, sizeof(d), 1, f_film)==1) {
		strcpy(temp[n].film, d.film);
		strcpy(temp[n].desk, d.desk);
		strcpy(temp[n].kursi, d.kursi);
		n++;
	}
	fclose(f_film);
	for(i=n-1;i>=1;i--) {
		for(j=1;j<=i;j++) {
			if(strcmp(temp[j-1].kursi,temp[j].kursi)<0) {
				temp2=temp[j-1];
				temp[j-1]=temp[j];
				temp[j]=temp2;
			}
		}
	}
	for (i=0;i<n;i++) {
		printf("Film          \t: %s\n", temp[i].film);
		printf("Deskripsi Film\t: %s\n", temp[i].desk);
		printf("Kuota Kursi   \t: %s\n\n", temp[i].kursi);
	}
	f_film = fopen("film.dat", "rb");
	while(fread(&d, sizeof(d), 1, f_film)==1) {
		strcpy(d.film, temp[n].film);
		strcpy(d.desk, temp[n].desk);
		strcpy(d.kursi, temp[n].kursi);
	}
	fclose(f_film);
	system("pause");
	penonton();
}


void choosetanggal() { //Pemilihan tanggal dan waktu (Switch case)
	i=0;
	system("cls");
	printf("================================================\n");
	printf("=                                              =\n");
	printf("=========== Pemilihan Film D'THEATRE ===========\n");
	printf("=                                              =\n");
	printf("================================================\n");
	f_film = fopen("film.dat", "rb");
	while(fread(&d, sizeof(d), 1, f_film)==1) {
		printf("[%d] Film\t: %s\n", ++i, d.film);
	}
	fclose(f_film);

	f_film = fopen("film.dat", "rb");
	printf("Film yang ingin di tonton : ");
	fflush(stdin);
	gets(find);
	printf("\n");
	i=0;
	while(fread(&d, sizeof(d), 1, f_film)==1) {
		if (strcmp(find, d.film)==0) {
			i=1;
			break;
			}
	}	
	fclose(f_film);
	if (i==1) {
		printf("Film       \t: %s\n", d.film);
		printf("Kuota Kursi\t: %s\n", d.kursi);			
		printf("%s\n\n", d.desk);
		system("pause");
	}
	else {
		printf("Jadwal '%s' tidak ada pada daftar, pencet 'enter' untuk kembali\n\n", find); 
		fclose(f_jadwal);
		system("pause");
		penonton();
	}
	system("cls");
	printf("==========================================================\n");
	printf("=                                                        =\n");
	printf("========== Pemilihan Tanggal dan Waktu D'THEATRE =========\n");
	printf("=                                                        =\n");
	printf("==========================================================\n");
	f_jadwal = fopen("jadwal.dat", "rb");	
	printf("Tanggal dan Waktu :\n");
	while(fread(&d, sizeof(d), 1, f_jadwal)==1) {
		printf("%s | %s\n", d.tanggal, d.waktu);
	}
	fclose(f_jadwal);

	f_jadwal = fopen("jadwal.dat", "rb");
	printf("Jadwal yang inginkan : ");
	fflush(stdin);
	gets(find);
	printf("\n");
	i=0;
	while(fread(&d, sizeof(d), 1, f_jadwal)==1) {
		if (strcmp(find, d.tanggal)==0) {
			i=1;
			break;
		}
	}
	if (i==1) {
		printf("%s | %s\n", d.tanggal, d.waktu);
		printf("Berapa tiket yang akan dibeli = ");
		scanf("%d", &n);
		n_t = n + n_t;
		system("cls");
		printf("Selamat anda telah membeli %d tiket\n\n", n);
		fclose(f_jadwal);
		system("pause");
		penonton();
	}
	else {
		printf("Jadwal '%s' tidak ada pada daftar, pencet 'enter' untuk kembali\n\n", find); 
		fclose(f_jadwal);
		system("pause");
		penonton();	
	}
}



void findfilm() { //Mencari film (Search)
	system("cls");
	printf("================================================\n");
	printf("=                                              =\n");
	printf("=========== Pencarian Film D'THEATRE ===========\n");
	printf("=                                              =\n");
	printf("================================================\n");
	f_film = fopen("film.dat", "rb");
	printf("Nama Film Yang Dicari : ");
	fflush(stdin);
	gets(find);
	while(fread(&d, sizeof(d), 1, f_film)==1) {
		n++;
		if (strcmp(find, d.film)==0) {
			printf("Film       \t: %s\n", d.film);
			printf("Kuota Kursi\t: %s\n", d.kursi);				
			printf("%s\n", d.desk);		
		}
	}
	fclose(f_film);
	printf("\n");
	system("pause");
	penonton();
}
