#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int list,password,semesterA;
char select,select2,select3,ipa='1',ips='2',select4;
float fisika,kimia,biologi,matematika,ekonomi,sejarah,geografi,sosiologi,a,b,c,d,x;
char name[256];
char filename[256];
char nis[256];
char temp1[256];
char temp2[256];
char temp3[256];
char str1;
char txt[] = ".txt";
char semester[1];
int limit;
float y;
int closeprogram(){
	printf("Menutup Program...\n");
	exit(0);
}
int inputpilihanrapor() {
	scanf("%c", &select);
	switch(select) {
		case '1':
			admin();
			admin1();
			addrapor();
			break;
			
		case '2':
			seerapor();
			break;
			
		case '3':
			admin();
			admin2();
			removefile();
			break;
		case '4' :
			closeprogram();
			break;
		default:
			printf("Input salah! silahkan pilih ulang\n\n");
			system("pause");
			system("cls");
			menu();
		}
}

int pilihanjurusan () {
	fflush(stdin);
	printf("Siswa jurusan apa?\n[1] IPA\n[2] IPS\n\nInput disini: ");
	scanf("%c", &select2);
	switch(select2) {
		case '1' :
			inputnilaiipa();
			break;
		case '2':
			inputnilaiips();
			break;
		default:
			printf("Input invalid!\n");
			system("pause");
			pilihanjurusan();
	}
}

int inputpilihanipa() {
	fflush(stdin);
	printf("Apakah anda telah yakin dengan nilai anda?\n[1] Ya\n[2] Tidak\n\nSilahkan input disini: ");
	scanf("%c", &select3);
	switch(select3) {
	case '1':
		addtotxtipa();
		printf("Nilai siswa telah tersimpan");
		break;
	case '2':
		inputnilaiipa();
		break;
	default:
		printf("Input invalid!");
		system("pause");
		inputpilihanipa;
	}
}

int addtotxtipa() {
	FILE *fptr;
	FILE *fptr2;
	FILE *fptr3;
	fptr = fopen(filename,"a");
	fprintf(fptr,"%f\n",fisika);
	fprintf(fptr,"%f\n",kimia);
	fprintf(fptr,"%f\n",biologi);
	fprintf(fptr,"%f\n",matematika);
	fprintf(fptr,"%c\n",ipa);
	fclose(fptr);
}

int inputpilihanips() {
	fflush(stdin);
	printf("Apakah anda telah yakin dengan nilai anda?\n[1] Ya\n[2] Tidak\n\nSilahkan input di sini: ");
	scanf("%c", &select3);
	switch(select3) {
	case '1':
		addtotxtips();
		printf("Nilai siswa telah tersimpan");
		break;
	case '2':
		inputnilaiips();
		break;
	default:
		printf("Input invalid!");
		system("pause");
		inputpilihanips;
	}
}

int addtotxtips() {
	FILE *fptr;
	FILE *fptr2;
	FILE *fptr3;
	fptr = fopen(filename,"a");
	fprintf(fptr,"%f\n",ekonomi);
	fprintf(fptr,"%f\n",sejarah);
	fprintf(fptr,"%f\n",geografi);
	fprintf(fptr,"%f\n",sosiologi);
	fprintf(fptr,"%c\n",ips);
}

int inputnilaiipa() {
	printf("Masukkan nilai Fisika: ");
	scanf("%f", &fisika);
	printf("Masukkan nilai Kimia: ");
	scanf("%f", &kimia);
	printf("Masukkan nilai Biologi: ");
	scanf("%f", &biologi);
	printf("Masukkan nilai Matematika: ");
	scanf("%f", &matematika);
	system("cls");
	printf("Nilai Fisika: %.2f\nNilai Kimia: %.2f\nNilai Biologi: %.2f\nNilai Matematika: %.2f\n\n",fisika,kimia,biologi,matematika);
	inputpilihanipa();
}

int inputnilaiips() {
	printf("Masukkan nilai Ekonomi: ");
	scanf("%f", &ekonomi);
	printf("Masukkan nilai Sejarah: ");
	scanf("%f", &sejarah);
	printf("Masukkan nilai Geografi: ");
	scanf("%f", &geografi);
	printf("Masukkan nilai Sosiologi: " );
	scanf("%f", &sosiologi);
	system("cls");
	printf("Nilai Ekonomi: %.2f\nNilai Sejarah: %.2f\nNilai Geografi: %.2f\nNilai Sosiologi: %.2f\n\n",ekonomi, sejarah,geografi,sosiologi);
	inputpilihanips();
}

int addrapor() {
	system("cls");
	FILE *fptr;
	printf("Silahkan input nama siswa: ");
	fflush(stdin);
	gets(filename);
	if(strlen(filename)==0){
		return addrapor();
	}
	strcpy(name, filename);
	printf("Silahkan input Semester: ");
	
	scanf("%s", &semester);
	strcat(filename,semester);
	strcat(filename,txt);
	fptr = fopen(filename,"w");
	printf("Silahkan input NIS: ");
	fflush(stdin);
	scanf("%s", nis);
	
	strcat(temp1, name);
	strcat(temp1, "\n");
	strcat(temp1, semester);
	strcat(temp1, "\n");
	strcat(temp1, nis);
	fprintf(fptr, "%s\n", temp1);
	fclose(fptr);
	pilihanjurusan();
}

int seerapor() {
	printf("Masukkan nama siswa yang ingin anda lihat (Nama Lengkap)\n\nInput disini: ");
	scanf("%s", &name);
	printf("Masukkan semester yang sebelumnya dilalui\n\nInput disini: ");
	scanf("%d",&limit);
	for(semesterA=1;semesterA<=limit;semesterA++){
		strcpy(filename,name);
		
		switch(semesterA){
			case 1:strcat(filename, "1");break;
			case 2:strcat(filename, "2");break;
			case 3:strcat(filename, "3");break;
			case 4:strcat(filename, "4");break;
			case 5:strcat(filename, "5");break;
			case 6:strcat(filename, "6");break;
			default:break;
		}
		strcat(filename, txt);
		FILE *fptr;
		fptr = fopen(filename,"r");
		fscanf(fptr,"%s\n%s\n%s\n%f\n%f\n%f\n%f\n%c",&name,&semester,&nis,&a,&b,&c,&d,&select4);
		if(semesterA==1){
		printf("Nama siswa: %s\n",name);
		printf("NIS: %s\n",nis);
		}
		switch(select4) {
		
		case '1':
		printf("=================================\n");	
		printf("Semester: %s\n",semester);
		printf("Nilai Fisika: %.2f\n",a);
		printf("Nilai Kimia: %.2f\n",b);
		printf("Nilai Biologi: %.2f\n",c);
		printf("Nilai Matematika: %.2f\n",d);
		x=(a+b+c+d)/4;
		printf("Rata-rata=%.2f\n\n",x);
		y=y+x;
		break;
	
		case '2':
		printf("=================================\n");
		printf("Semester: %s\n",semester);
		printf("Nilai Ekonomi: %.2f\n",a);
		printf("Nilai Sejarah: %.2f\n",b);
		printf("Nilai Geografi: %.2f\n",c);
		printf("Nilai Sosiologi: %.2f\n",d);
		x=(a+b+c+d)/4;
		printf("Rata-rata=%.2f\n\n",x);
		y=y+x;
		break;
		}
		if(semesterA==limit){
			printf("=================================\n");
			y=y/limit;
			printf("Rata-rata nilai keseluruhan:%f\n",y);
			printf("=================================\n");
		}
	}
}

int admin() {
	system("cls");
	printf("Masukkan password (4 angka bulat positif): ");
	scanf("%d", &password);
}

int admin1() {
	if(password==2707){
		addrapor();
	}
	else{
		printf("\nPassword salah!");
			system("pause");
			system("cls");
			admin();
	}
}

int admin2() {
	if(password==2707){
		removefile();
	}
	else{
		printf("\nPassword salah!");
			system("pause");
			system("cls");
			admin();
	}

	
}

int removefile() {
	printf("Tuliskan  nama dan semester yang ingin datanya anda hapus(Contoh;Putra1): ");
	fflush(stdin);
	gets(name);
	strcat(name,".txt");
	remove(name);
	printf("\nFile anda telah terhapus.");
	system("pause");
	system("cls");
}

int menu() {
	printf("Selamat datang\n\nApa yang anda ingin lakukan?\n1.Menambah dan mengubah rapor siswa(admin only)\n2.Melihat rapor siswa\n3.Menghapus nilai siswa (admin only)\n4.Menutup Program.\n\nSilahkan input disini: ");
	inputpilihanrapor();
}

int main(){
	menu();
	system("cls");
	return main();
}
