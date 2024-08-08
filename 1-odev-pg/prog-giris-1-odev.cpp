
//1-odev-progamlamaya-giris


#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

double oku(string s, double min, double max)
{
	double sayi;
	do
	{
		cout << s; cin >> sayi;
		if (!(sayi >= min && sayi <= max)) 
		{
			cout << "Hata, Lutfen (" << min << "-" << max << ") araliginda sayi girinz\n";
		}
	} while (!(sayi >= min && sayi <= max));
	return sayi;
}

struct Tarih {
	int gun;
	int ay;
	int yil;
};

struct Ogrenci {
	string isim;
	string soyisim;
	string no;
	double kisa_sinav_1;
	double kisa_sinav_2;
	double odev_1;
	double odev_2;
	double proje;
	double vize;
	double Final;
	double ortalma;
	double yil_ici;
	Tarih dogum_tarih;

	void yil_ici_hesapla() {
		yil_ici = 0.5 * vize + 0.07 * kisa_sinav_1 + 0.07 * kisa_sinav_2 + 0.1 * odev_1 + 0.1 * odev_2 + 0.16 * proje;
	}
	void ortalama_hesapla() {
		yil_ici_hesapla();
		ortalma = yil_ici * 0.55 + Final * 0.45;
	}
	void ekrana_yaz(){
		cout << left;
		cout << "isim: " << setw(12) << isim;
		
		cout << setw(8) << "soyisim: " << setw(12) << soyisim;
		
		cout << setw(5) << "no: " << setw(9) << no;
		
		cout << setw(15) << "dogum tarihi:" <<setw(2)<<dogum_tarih.gun << "." << setw(2) << dogum_tarih.ay << "." <<setw(7)<< dogum_tarih.yil;
		
		cout << setw(12) << "kisa sinav 1: " << setw(6) << kisa_sinav_1;
		
		cout << setw(12) << "kisa sinav 2: " << setw(6) << kisa_sinav_2;
		
		cout << setw(8) << "odev 1: " << setw(6) << odev_1;
		
		cout << setw(8) << "odev 2: " << setw(6) << odev_2;
		
		cout << setw(7) << "proje: " << setw(6) << proje;
		
		cout << setw(6) << "vize: " << setw(6) << vize;
		
		cout << setw(7) << "final: " << setw(6) << Final;
		
		cout << setw(10) << "ortalma: " << setw(6) << ortalma;
		
		cout << endl;
	}
	void kullanici_giris() {
		kisa_sinav_1 = oku("Kisa Sinav 1 Notunu Girniz......",0,100);
		kisa_sinav_2 = oku("Kisa Sinav 2 Notunu Girniz......", 0, 100);
		odev_1 = oku("Odev 1 Notunu Girniz......", 0, 100);
		odev_2 = oku("Odev 2 Notunu Girniz......", 0, 100);
		proje = oku("Proje Notunu Girniz......", 0, 100);
		vize = oku("Vize Notunu Girniz......", 0 ,100);
		Final = oku("Final Notunu Girniz......", 0, 100);
		ortalama_hesapla();
	}
	void isim_soyisimm_no_tarih_ata(string i, string s, string n,Tarih trh) {
		isim = i;
		soyisim = s;
		no = n;
		dogum_tarih = trh;
	}

};


void rastgeleAta(Ogrenci ogrler[]) {
	int i;
	for (i = 0; i < 10; i++) 
	{
		ogrler[i].kisa_sinav_1 = rand() % 41;
		ogrler[i].kisa_sinav_2 = rand() % 41;
		ogrler[i].odev_1 = rand() % 41;
		ogrler[i].odev_2 = rand() % 41;
		ogrler[i].proje = rand() % 41;
		ogrler[i].vize = rand() % 41;
		ogrler[i].Final = rand() % 41;
		ogrler[i].ortalama_hesapla();
	}
	for (i = 10; i < 60; i++)
	{
		ogrler[i].kisa_sinav_1 = rand() % 31+40;
		ogrler[i].kisa_sinav_2 = rand() % 31 + 40;
		ogrler[i].odev_1 = rand() % 31 + 40;
		ogrler[i].odev_2 = rand() % 31 + 40;
		ogrler[i].proje = rand() % 31 + 40;
		ogrler[i].vize = rand() % 31 + 40;
		ogrler[i].Final = rand() % 31 + 40;
		ogrler[i].ortalama_hesapla();
	}
	for (i = 60; i < 75; i++) 
	{
		ogrler[i].kisa_sinav_1 = rand() % 11+70;
		ogrler[i].kisa_sinav_2 = rand() % 11 + 70;
		ogrler[i].odev_1 = rand() % 11 + 70;
		ogrler[i].odev_2 = rand() % 11 + 70;
		ogrler[i].proje = rand() % 11 + 70;
		ogrler[i].vize = rand() % 11 + 70;
		ogrler[i].Final = rand() % 11 + 70;
		ogrler[i].ortalama_hesapla();
	}
	for (i =75; i < 100; i++) 
	{
		ogrler[i].kisa_sinav_1 = rand() % 21+80;
		ogrler[i].kisa_sinav_2 = rand() % 21 + 80;
		ogrler[i].odev_1 = rand() % 21 + 80;
		ogrler[i].odev_2 = rand() % 21 + 80;
		ogrler[i].proje = rand() % 21 + 80;
		ogrler[i].vize = rand() % 21 + 80;
		ogrler[i].Final = rand() % 21 + 80;
		ogrler[i].ortalama_hesapla();
	}

	

}
void ogreinciler_listele(Ogrenci ogrler[]) {
	for (int i = 0; i < 100; i++) 
	{
		ogrler[i].ekrana_yaz();
		if (i % 20 == 0 && i != 0) 
		{
			cin.get();
			cin.ignore();
			system("CLS");
		}
	}
}
double en_yuksek_not(Ogrenci ogrler[]) {

	double max_not = 0;
	for (int i = 0; i < 100; i++)
	{
		if (ogrler[i].ortalma > max_not)
		{
			max_not = ogrler[i].ortalma;
		}
	}
	return max_not;
}
double en_dusuk_not(Ogrenci ogrler[]) {

	double min_not = 100;
	for (int i = 0; i < 100; i++) 
	{
		if (ogrler[i].ortalma < min_not) 
		{
			min_not = ogrler[i].ortalma;
		}
	}
	return min_not;
}
double ortalma(Ogrenci ogrler[]) {
	double toplama = 0;
	for (int i = 0; i < 100; i++) 
	{

		toplama += ogrler[i].ortalma;
	}
	return toplama / 100;
}
double standard_sapma(Ogrenci ogrler[]) {
	double toplama = 0;
	for (int i = 0; i < 100; i++)
	{
		toplama += ogrler[i].ortalma;
	}
	double ortalama = toplama / 100;

	double fark_toplama = 0;
	for (int i = 0; i < 100; i++) 
	{
		fark_toplama += (ogrler[i].ortalma - ortalama) * (ogrler[i].ortalma - ortalama);
	}
	fark_toplama = fark_toplama / 100;
	double standard_sapma= sqrt(fark_toplama);
	return standard_sapma;
}
void bir_aralikta(Ogrenci ogrler[], double min, double max) {
	for (int i = 0; i < 100; i++) 
	{
		if (ogrler[i].ortalma > min && ogrler[i].ortalma < max)
		{
			ogrler[i].ekrana_yaz();
		}
	}
}
void bir_aralikta_altinda(Ogrenci ogrler[],int max) {
	for (int i = 0; i < 100; i++) 
	{
		if (ogrler[i].ortalma < max) 
		{
			ogrler[i].ekrana_yaz();
		}
	}
}
void bir_aralikta_ustunde(Ogrenci ogrler[], int min) {
	for (int i = 0; i < 100; i++) 
	{
		if (ogrler[i].ortalma > min) 
		{
			ogrler[i].ekrana_yaz();
		}
	}
}
int main() {
	
	string isimler [] = { "Ahmet","Cüneyt","Ali","Emre","bayram","fatih","duruk","zumurrut","fatma","sait","luna","ekrem","samat",
						  "yaman","bilal","mahmut","murat","muhammet","cemal","cristiano","nur","zehra","ayşenur","zeyneb","elif",
						  "hülya","nuray","nazlı","meryem","mert" 
	};

	string soyisimler[]	= { "Özdemir","aydin","Yıldırım","Yıldız","Çelik","Demir","Kaya","KIRBAŞ","TUNCER","ASOĞLU","GÖKALP","ŞİMŞEK",
							"bayılmış","DUMAN","AKIN","AKDENİZ","YÜCEL","BATMAZ","ERYILMAZ","ŞAİR","ÖZGÜROL","SÜNER","ÖZÜAK","ÇEPNİ",
							"DEMİREL","AKYILMAZ","TOPALOĞLU","PINARBAŞILI","AKDUR","BÜBER" 
	};


	Ogrenci ogrler[100];

	// isim soyisim numara ve tarih atam dongusu
	for (int i = 0; i < 100; i++) 
	{
		Tarih tarih;
		tarih.gun = rand() % 31 + 1;
		tarih.ay = rand() % 12 + 1;
		tarih.yil = rand() % 10 + 1996;
		string no = "B21"+to_string(i+1);
		ogrler[i].isim_soyisimm_no_tarih_ata(isimler[rand() % 30], soyisimler[rand() % 30], no, tarih);
	}
	
	// rastgele veya kullanici giris secimi:	
	while (true) 
	{
		cout << "notlar kendiniz girecekseniz 1'e, rastgele atam yapacaksaniz 2'ye tuslayin\n";
		int secim;
		cin >> secim;
		if (secim == 1)
		{
			for (int i = 0; i < 100; i++)
			{
				ogrler[i].kullanici_giris();		
			}
			break;
		}
		else if (secim == 2) 
		{
			rastgeleAta(ogrler);
			break;
		}
		else 
		{
			cout << "bir hata var lutfen tekrar deneyin\n\n\n";
		}
	}
	
	cout << endl << endl << endl;
	
	//menu secenekleri
	while (true)
	{
		system("CLS");

		cout << "1.Sinif ogrenciler listele\n";
		cout << "2.Sinifin en yuksek notu\n";
		cout << "3.SInifin en dusuk notu\n";
		cout << "4.Sinifin ortalamasi\n";
		cout << "5.sinifin standard sapmasi\n";
		cout << "6.Basari notu belirli aralikta olanlar listele\n";
		cout << "7.BAsari notu bir degerin altinda olanlar listele\n";
		cout << "8.Basari notu bir degerin ustunde olanlar listele\n";

		int menu_secim;

		cin >> menu_secim;
		if (menu_secim == 1) 
		{
			ogreinciler_listele(ogrler);
			break;
		}
		else if (menu_secim == 2) 
		{
			cout<<"En yuksek not:\t"<<en_yuksek_not(ogrler);
			break;
		}
		else if (menu_secim == 3) 
		{
			cout << "En yuksek not:\t" << en_dusuk_not(ogrler);
			break;
		}
		else if (menu_secim == 4) 
		{
			cout << "Sinifin Ortalamasi:\t"<<ortalma(ogrler);
			break;
		}
		else if (menu_secim == 5) 
		{
			cout << "Sinifin standard sapmasi:\t"<<standard_sapma(ogrler);
			break;
		}
		else if (menu_secim == 6) 
		{
			double alt_deger = oku("alt deger giriniz....", 0, 100);
			double ust_deger = oku("ust deger giriniz....", 0, 100);
			bir_aralikta(ogrler,alt_deger,ust_deger);
			break;
		}
		else if (menu_secim == 7) 
		{
			double ust_deger = oku("ust deger giriniz....", 0, 100);
			bir_aralikta_altinda(ogrler, ust_deger);
			break;
		}
		else if (menu_secim == 8) 
		{
			double alt_deger = oku("alt deger giriniz....", 0, 100);
			bir_aralikta_ustunde(ogrler, alt_deger);
			break;
		}
		else 
		{
			cout << "1-8 arasinda sayi girmeniz lazim....\n";
		}
	}
	return 0;
}