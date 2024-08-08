/*

//				isim:		Muhammed Iyd
//				Ogr-NO:		b211210569
//				grup:		1-B
//				konu:		Proje
//
//

*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;



class urun {
public:
	string isim;
	double fiyat;
	int stok;
	urun(string _isim = "", double _fiyat = 0, int _stok = 0) {
		isim = _isim;
		fiyat = _fiyat;
		stok = _stok;
	}
	void urunEkle() {

		cout << "eklenecek urunun:" << endl;
		cout << "Urun Adi: "; cin >> isim;
		cout << "Fiyati: "; cin >> fiyat;
		cout << "Stok Adedi: "; cin >> stok;

		ofstream dosya("urun.txt",ios::app);
		dosya << isim << " " << fiyat << " " << stok << endl;
		dosya.close();
	}
	void urunSil(string isim) {
		ifstream dosya;
		dosya.open("urun.txt");
		ofstream yeniDosya("tmp.txt", ios::app);



		while (!dosya.eof()) {
			string okunanSatir, okunanIsim;
			getline(dosya, okunanSatir);
			okunanIsim = okunanSatir.substr(0, isim.length());

			if (isim == okunanIsim) {
				continue;
			}
			else if (okunanIsim != "") {
				yeniDosya << okunanSatir << endl;
			}


		}
		yeniDosya.close();
		dosya.close();

		int x = remove("urun.txt");
		int y = rename("tmp.txt", "urun.txt");
	}
	void urunListele() {

		string baslik = "Isim fiyat stok";
		ifstream dosya("urun.txt");
		string metin;
		cout << baslik << endl;
		while (getline(dosya, metin)) {
			cout << metin << endl;
		}
		dosya.close();

	}
	void urunGuncelle(string urunIsim) {

		cout << "Bilgisi guncellenek urunun:" << endl;
		cout << "Urun Adi: "; cin >> isim;
		cout << "Fiyati: "; cin >> fiyat;
		cout << "Stok Adedi: "; cin >> stok;


		ofstream dosya;
		dosya.open("tmp.txt", ios::app);

		ifstream dosyaOku("urun.txt");
		while (!dosyaOku.eof()) {

			string okunanUrun, arananisim;
			getline(dosyaOku, okunanUrun);
			arananisim = okunanUrun.substr(0, urunIsim.length());

			if (arananisim == urunIsim) {
				dosya << isim << " " << fiyat << " " << stok<< endl;
			}
			else if (okunanUrun != "") {
				dosya << okunanUrun << endl;
			}

		}

		dosya.close();
		dosyaOku.close();
		remove("urun.txt");
		rename("tmp.txt", "urun.txt");
	}
	string urunSatirBul(string urunIsim) {
		ifstream dosya("urun.txt");
		while (!dosya.eof()) {

			string metin, okunanIsim;
			getline(dosya, metin);
			okunanIsim = metin.substr(0, urunIsim.length());
			if (urunIsim == okunanIsim) {
				return metin;
			}
		}
		dosya.close();
		return "";
	}
	urun getUrun(string urunIsim) {
		string metin = urunSatirBul(urunIsim);

		urun u;
		int start, end = -1;
		int index = 0;
		do {
			start = end + 1;
			end = metin.find(" ", start);
			if (index == 0) {
				u.isim = metin.substr(start, end - start);
			}
			else if (index == 1) {
				u.fiyat =stod(metin.substr(start, end - start));

			}
			else {
				u.stok = stod(metin.substr(start, end - start));

			}
			index++;
		} while (end != -1);
		return u;
	}
	void stokGuncelle(string urunIsim, double yeniStok) {
		string metin = urunSatirBul(urunIsim);
		urun u = getUrun(metin);
		ofstream dosya;
		dosya.open("tmp.txt", ios::app);

		ifstream dosyaOku("urun.txt");
		while (!dosyaOku.eof()) {

			string okunanUrun, arananisim;
			getline(dosyaOku, okunanUrun);
			arananisim = okunanUrun.substr(0, u.isim.length());

			if (arananisim == u.isim) {
				dosya << u.isim << " " << u.fiyat << " " << yeniStok << endl;
			}
			else if (okunanUrun != "") {
				dosya << okunanUrun << endl;
			}

		}

		dosya.close();
		dosyaOku.close();
		remove("urun.txt");
		rename("tmp.txt", "urun.txt");
	}

}urunIsleyen;
class malzeme {
public:
	string isim;
	void malzemeYazdir(string malzemeAd) {
		ifstream dosya("malzeme.txt");
		while (!dosya.eof()) {

			string metin, okunanIsim;
			getline(dosya, metin);
			okunanIsim = metin.substr(0, malzemeAd.length());
			if (malzemeAd == okunanIsim) {
				cout << metin << endl;
				getline(dosya, metin);
				while (metin.find(" ") != string::npos) {
					cout << metin << endl;
					getline(dosya, metin);

				}
				break;
			}
		}
		dosya.close();
	}
	void malzemeListele() {

		ifstream dosya("malzeme.txt");
		string metin;
		while (getline(dosya, metin)) {
			cout << metin << endl;
		}
		dosya.close();

	}
	void malzemeEkle() {
		cout << "eklenecek malzemenin ismi: " << endl;
		cin >> isim;

		ofstream dosya("malzeme.txt", ios::app);
		dosya << isim << endl;
		cout << "Hangi urunler var ?";
		while (true) {
			urunIsleyen.urunListele();
			string urunAd;
			cout << "eklemek istedigin urun adi gir....";
			cin >> urunAd;
			string urunSatir = urunIsleyen.urunSatirBul(urunAd);
			dosya << urunSatir << endl;
			cout << "baska urun var mi ? (evet-hayir)";
			string secim;
			cin >> secim;
			if (secim == "evet") {
				continue;
			}
			else{
				break;
			}

		}
		
		dosya.close();
	}
	void malzemeSil(string malzemeAd) {
		ifstream dosya;
		dosya.open("malzeme.txt");
		ofstream yeniDosya("tmp.txt", ios::app);



		while (!dosya.eof()) {
			string okunanSatir;
			getline(dosya, okunanSatir);

			if (malzemeAd == okunanSatir) {
				getline(dosya, okunanSatir);
				while (okunanSatir.find(" ") != string::npos) {
					getline(dosya, okunanSatir);
				}
				if (okunanSatir != "")
					yeniDosya << okunanSatir << endl;
			}
			else if (okunanSatir != "") {
				yeniDosya << okunanSatir << endl;
			}
		}
		yeniDosya.close();
		dosya.close();

		int x = remove("malzeme.txt");
		int y = rename("tmp.txt", "malzeme.txt");
	}
}malzemeIsleyen;
class Yemek {
public:
	string isim;
	string malzemeIsim;
	double maliyet;
	double fiyat;
	string yemekSatirBul(string yemekIsim) {
		ifstream dosya("yemek.txt");
		while (!dosya.eof()) {

			string metin, okunanIsim;
			getline(dosya, metin);
			okunanIsim = metin.substr(0, yemekIsim.length());
			if (yemekIsim == okunanIsim) {
				return metin;
			}
		}
		dosya.close();
		return "";
	}
	Yemek getYemek(string yemekIsim) {
		string metin = yemekSatirBul(yemekIsim);

		Yemek y;
		int start, end = -1;
		int index = 0;
		do {
			start = end + 1;
			end = metin.find(" ", start);
			if (index == 0) {
				y.isim = metin.substr(start, end - start);
			}
			else if (index == 1) {
				y.malzemeIsim = metin.substr(start, end - start);

			}
			else if (index == 2) {
				y.maliyet = stod(metin.substr(start, end - start));

			}
			else {
				y.fiyat = stod(metin.substr(start, end - start));

			}
			index++;
		} while (end != -1);
		return y;
	}
	void yemekListele() {

		string baslik = "Isim malzeme maliyet satis";
		ifstream dosya("yemek.txt");
		string metin;
		cout << baslik << endl;
		while (getline(dosya, metin)) {
			cout << metin << endl;
		}
		dosya.close();

	}
	void yemekEkle() {
		cout << "eklenecek yemegin:" << endl;
		cout << "Yemek adi: "; cin >> isim;
		cout << "Malzeme ismi: "; cin >> malzemeIsim;
		cout << "satis fiyat: "; cin >> fiyat;
		ifstream malzemeDosya("malzeme.txt");

		while (!malzemeDosya.eof()) {

			string metin;
			getline(malzemeDosya, metin);
			if (malzemeIsim == metin) {
				getline(malzemeDosya, metin);
				while (metin.find(" ") != string::npos) {
					maliyet += urunIsleyen.getUrun(metin).fiyat;
					getline(malzemeDosya, metin);
				}
				break;
			}
		}
		malzemeDosya.close();
		ofstream dosya("yemek.txt", ios::app);
		dosya << isim << " " << malzemeIsim << " " <<maliyet << " "<< fiyat << endl;
		dosya.close();
	}
	void yemekSil(string yemekIsim) {
		ifstream dosya;
		dosya.open("yemek.txt");
		ofstream yeniDosya("tmp1.txt", ios::app);



		while (!dosya.eof()) {
			string okunanSatir, okunanIsim;
			getline(dosya, okunanSatir);
			okunanIsim = okunanSatir.substr(0, yemekIsim.length());

			if (yemekIsim == okunanIsim) {
				malzemeIsleyen.malzemeSil(getYemek(yemekIsim).malzemeIsim);
				continue;
			}
			else if (okunanIsim != "") {
				yeniDosya << okunanSatir << endl;
			}


		}
		yeniDosya.close();
		dosya.close();

		int x = remove("yemek.txt");
		int y = rename("tmp1.txt", "yemek.txt");
	}
	double yemekYap(string yemekIsim) {
		Yemek y = getYemek(yemekIsim);
		ifstream dosya;
		dosya.open("malzeme.txt");

		while (!dosya.eof()) {
			string okunanSatir;
			getline(dosya, okunanSatir);

			if (y.malzemeIsim == okunanSatir) {
				getline(dosya, okunanSatir);
				while (okunanSatir.find(" ") != string::npos) {
					urun u = urunIsleyen.getUrun(okunanSatir);
					urunIsleyen.stokGuncelle(u.isim, u.stok - 5);
					getline(dosya, okunanSatir);
				}
			}
		}
		dosya.close();
		return y.fiyat;

	}
}yemekIsleyen;
int main() {
	double toplamSatis = 0;
	while (true) {
		cout << "1_urunler Listele" << endl;
		cout << "2_malzemeler Listele" << endl;
		cout << "3_yemekler Listele" << endl;
		cout << "4_urun ekle" << endl;
		cout << "5_urun sil" << endl;
		cout << "6_urun guncelle" << endl;
		cout << "7_malzeme ekle" << endl;
		cout << "8_malzeme sil" << endl;
		cout << "9_yemek ekle" << endl;
		cout << "10_yemek sil" << endl;
		cout << "11_yemek yap" << endl;
		cout << "12_cikis" << endl;

		int secim;
		cout << endl << endl;
		cin >> secim;

		if (secim == 1) {
			urunIsleyen.urunListele();
		}
		else if (secim == 2) {
			malzemeIsleyen.malzemeListele();
		}
		else if (secim == 3) {
			yemekIsleyen.yemekListele();


		}
		else if (secim == 4) {
			urunIsleyen.urunEkle();


		}
		else if (secim == 5) {
			cout << "Hangi urun sileceksiniz, ismini girniz....";
			string isim;
			cin >> isim;
			urunIsleyen.urunSil(isim);

		}
		else if (secim == 6) {
			cout << "Hangi urun guncelliceksiniz, ismini girniz....";
			string isim;
			cin >> isim;
			urunIsleyen.urunGuncelle(isim);

		}
		else if (secim == 7) {
			malzemeIsleyen.malzemeEkle();

		}
		else if (secim == 8) {
			cout << "Hangi malzeme sileceksiniz, ismini girniz....";
			string isim;
			cin >> isim;
			malzemeIsleyen.malzemeSil(isim);

		}
		else if (secim == 9) {
			yemekIsleyen.yemekEkle();

		}
		else if (secim == 10) {
			cout << "Hangi yemek sileceksiniz, ismini girniz....";
			string isim;
			cin >> isim;
			yemekIsleyen.yemekSil(isim);

		}
		else if (secim == 11) {
			cout << "Hangi yemek yapacaksiniz, ismini girniz....";
			string isim;
			cin >> isim;
			toplamSatis+=yemekIsleyen.yemekYap(isim);

		}
		else if (secim == 12) {
			break;
		}
		else {
			cout << "Yanlis giris lutfen tekrar giriniz" << endl;
		}
		cout << endl << endl << endl << endl;
		system("pause");
		system("CLS");
	}

	cout << "Toplam satis = " << toplamSatis;


	
}
