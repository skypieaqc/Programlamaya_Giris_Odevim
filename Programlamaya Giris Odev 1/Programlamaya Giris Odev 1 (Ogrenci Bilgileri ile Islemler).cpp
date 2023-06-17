/********************************************************************************************
**					          SAKARYA ÜNİVERSİTESİ										   **
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ							   **
**				         BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ									   **
**				          PROGRAMLAMAYA GİRİŞİ DERSİ									   **
**																						   **
**				            ÖDEV NUMARASI: 1. Ödev										   **
**				            ÖĞRENCİ ADI: AHMET YUNUS ÇAVUŞ								   **
**				            ÖĞRENCİ NUMARASI: B221210082								   **
**				            DERS GRUBU: 1. Öğretim A									   **
*********************************************************************************************/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

struct Ogrenci {
	string adi, soyadi;
	float numara, kisa_sinav1, kisa_sinav2, odev1, odev2, proje, vize, final, basarinotu;
};

struct Tarih {

	int gun, ay, yil;
};

//isimler.
string isimler[30] = { "Nurdan","Sebnem","Irem","Ceren","Zeynep","Ceylin",
	"Zelis","Adel","Feride","Mirza","Anil","Amir","Yahya","Yakup","Umit",
	"Emre","Kerim","Eymen","Uras","Ahmet","Yunus","Ece","Sude","Enes",
	"Kaan","Yavuz","Eda","Tugce","Ada","Elif" };

//soyisimler.
string soyisim[30] = { "Cavus","Yildiz","Gursoy","Bas","Yilmaz","Kaya","Demir","Sahin"
,"Celik","Yildiz","Yilmaz","Ozturk","Aydin","Baydar","Arslan","Dogan","Kilic","Aslan",
"Cetin","Kara","Koc","Kurt","Ozkan","Simsek","Sakmar","Oren","Sonuc","Cavus","Kuru","Aydal" };

//Notlari harfe ceviren fonksiyon.
string nottanharfe(float puan)
{
	string sembol;

	if (puan >= 87 && puan <= 100)
		sembol = "AA";

	else if (puan >= 81 && puan < 87)
		sembol = "BA";

	else if (puan >= 74 && puan < 81)
		sembol = "BB";

	else if (puan >= 67 && puan < 74)
		sembol = "CB";

	else if (puan >= 60 && puan < 67)
		sembol = "CC";

	else if (puan >= 53 && puan < 60)
		sembol = "DC";

	else if (puan >= 46 && puan < 53)
		sembol = "DD";

	else if (puan >= 39 && puan < 46)
		sembol = "FD";

	else if (puan >= 0 && puan < 39)
		sembol = "FF";

	return sembol;
}

//Girilen notun dogrulugunu kontrol eden fonksiyon. 
float dogruluk()
{
	float notunuz;

	do
	{
		cin >> notunuz;

		//Gecerli not girilmez ise kullanici uyarilicak
		if (notunuz < 0 || notunuz > 100) {
			cout << "Lutfen 0 ile 100 arasinda not giriniz: ";
		}

	} while (!(notunuz >= 0 && notunuz <= 100));

	return notunuz;
}

//Basari notunu hesaplayan fonksiyon.
float basarinotuhesap(float kisasinav1, float kisasinav2, float odev1, float odev2, float proje, float vize, float final)
{
	float basari_notu = 0;

	basari_notu = (((vize * 1 / 2) + (kisasinav1 * 7 / 100) + (kisasinav2 * 7 / 100) + (odev1 * 1 / 10) + (odev2 * 1 / 10) + (proje * 16 / 100)) * 55 / 100) + (final * 45 / 100);

	return basari_notu;
}

//Sinif listesini yazdiran fonksiyon.
void siniflistesi(Ogrenci ogr[], Tarih ogrler[], int MEVCUT)
{
	char bekleme;

	//0dan sinif mevcuduna kadar her ogrenciyi listler.
	for (int i = 0; i < MEVCUT; i++)
	{
		string gecici = nottanharfe(ogr[i].basarinotu);

		if (i == 0)
			system("cls");

		if (i % 20 == 0 && i != 0)
		{
			bekleme = _getch();			//Herhangi bir tusa basinca devam eder.
			system("cls");				//Ekrani temizler.
		}
		cout << i + 1 << "." << "\t| " << ogr[i].adi << " " << ogr[i].soyadi << "\t|No:" << ogr[i].numara << "\t| DogumTarihi -> " << ogrler[i].gun << "." << ogrler[i].ay << "." << ogrler[i].yil << "\t| Basari Notu: " << ogr[i].basarinotu << "\t(" << gecici << ")" << endl;
	}
}

//Sinifini not ortalamasini hesaplayan fonksiyon.
float sinifnotortalamasi(Ogrenci ogr[], int MEVCUT)
{
	float ortalama, notlartoplami = 0;

	//0dan sinif mevcuduna kadar olan basari notlari toplanir.
	for (int i = 0; i < MEVCUT; i++)
	{
		notlartoplami += ogr[i].basarinotu;
	}

	ortalama = notlartoplami / MEVCUT;

	cout << "Sinifin ortalamasi: " << ortalama << endl;

	return ortalama;
}

//Sinifin en yuksek notunu bulan fonksiyon.
float enyukseknot(Ogrenci ogr[], int MEVCUT)
{
	float enbuyuknot = ogr[0].basarinotu;
	int kim = 0;
	string gecici;
	//0dan sinif mevcuduna kadar olan en yuksek notu bulur.
	for (int i = 1; i < MEVCUT; i++)
	{
		if (enbuyuknot < ogr[i].basarinotu)
		{
			enbuyuknot = ogr[i].basarinotu;
			kim = i;
		}
		gecici = nottanharfe(ogr[kim].basarinotu);
	}
	cout << "Sinifin en yuksek notunu alan ogrenci: " << ogr[kim].adi << " " << ogr[kim].soyadi << " ---> Aldigi Not:" << enbuyuknot << " (" << gecici << ")" << endl;

	return enbuyuknot;
}

//Sinifin en dusuk notunu bulan fonksiyon.
float endusuknot(Ogrenci ogr[], int MEVCUT)
{
	float enkucuknot = ogr[0].basarinotu;
	int kim = 0;

	string gecici;
	//0dan sinif mevcuduna kadar olan en dusuk notu bulur.
	for (int i = 1; i < MEVCUT; i++)
	{
		if (enkucuknot > ogr[i].basarinotu)
		{
			enkucuknot = ogr[i].basarinotu;
			kim = i;
		}

		gecici = nottanharfe(ogr[kim].basarinotu);
	}
	cout << "Sinifin en dusuk notunu alan ogrenci:" << ogr[kim].adi << " " << ogr[kim].soyadi << " ---> Aldigi Not: " << enkucuknot << " (" << gecici << ")" << endl;

	return enkucuknot;
}

//Sinifin standart sapmasini hesaplayan fonksiyon.
float standartsapma(Ogrenci ogr[], int MEVCUT)
{
	float ortalama = 0;

	//0dan sinif mevcuduna kadar olan basari notlarini toplanir.
	for (int i = 0; i < MEVCUT; i++)
	{
		ortalama += ogr[i].basarinotu;
	}

	ortalama = ortalama / MEVCUT;			//Ortalama hesaplanir.

	float farklar = 0;

	//0dan sinif mevcuduna kadar olan butun ogrencilerin basari notlarinin ortalamaya uzakliklarinin karesi hesaplanir.
	for (int j = 0; j < MEVCUT; j++)
	{
		farklar += ((ogr[j].basarinotu - ortalama) * (ogr[j].basarinotu - ortalama));
	}

	float standartsapma = 0;

	standartsapma = sqrt(farklar / (MEVCUT - 1));				//Standart sapma hesaplanir.

	cout << "Sinifin standart sapmasi: " << standartsapma << endl;

	return standartsapma;
}

//Belirli not araligindaki ogrencileri listeleyen fonksiyon.
void basarilistesi(Ogrenci ogr[], int MEVCUT)
{
	int deger1, deger2, sayac = 0;
	string gecici;

	cout << "Hangi araliktaki notlari listemek istedigini giriniz: \n";

	cout << "1.Deger:";
	deger1 = dogruluk();

	cout << "2.Deger:";
	deger2 = dogruluk();

	if (deger1 > deger2)
	{
		int gecici;
		gecici = deger1;
		deger1 = deger2;
		deger2 = gecici;
	}

	cout << "-----------------------------------------------\n";
	cout << "Basari notu " << deger1 << " ile " << deger2 << " arasinda olan ogrenciler." << endl;
	cout << "-----------------------------------------------\n";

	//0dan sinif mevcuduna kadar olan butun ogrencilerin belirtilen not araliginda olup olmadigini sorgular.
	for (int i = 0; i < MEVCUT; i++)
	{
		//Eger i.ogrencinin notu belirtilen aralikta ise ogrencinin adi, soyadi ve basari notu ekrana yazdirilir.
		if (ogr[i].basarinotu >= deger1 && ogr[i].basarinotu < deger2)
		{
			gecici = nottanharfe(ogr[i].basarinotu);

			sayac++;
			cout << i + 1 << ".Ogrenci" << "\t|" << ogr[i].adi << " " << ogr[i].soyadi << "\t\t" << "Basari Notu: " << ogr[i].basarinotu << " (" << gecici << ")" << endl;
		}
	}
	if (sayac == 0)
		cout << deger1 << " ve " << deger2 << " arasinda hic ogrenci yoktur." << endl;
}

//Belirli bir notun ustundeki ogrencileri listeleyen fonksiyon.
void basarililarlisteri(Ogrenci ogr[], int MEVCUT)
{
	cout << "Hangi notun ustundeki ogrencileri listelemek istediginiz giriniz: ";
	int not1, sayac = 0;
	not1 = dogruluk();
	string gecici;

	cout << "----------------------------------------------\n";
	cout << "Basari notu " << not1 << " notundan yuksek olan ogrenciler. " << endl;
	cout << "----------------------------------------------\n";

	//0dan sinif mevcuduna kadar olan her ogrencinin basari notunun belirtilen nottan yuksek olup olmadigini sorgular.
	for (int i = 0; i < MEVCUT; i++)
	{

		//Eger i.ogrencinin basari notu belirtilen nottan yuksek ise ogrencinin adi, soyadi ve basari notu ekrana yazdirilir.
		if (ogr[i].basarinotu > not1)
		{
			sayac++;

			gecici = nottanharfe(ogr[i].basarinotu);

			//Eger i.ogrencinin basari notu belirtilen nottan yuksek ise ogrencinin adi, soyadi ve basari notu ekrana yazdirilir.
			cout << i + 1 << "." << "\t|" << ogr[i].adi << " " << ogr[i].soyadi << "\t\t" << "Basari Notu: " << ogr[i].basarinotu << " (" << gecici << ")" << endl;
		}
	}
	if (sayac == 0)
		cout << not1 << " notundan yuksek alan ogrenci yoktur.\n";
}

//Belirli bir degerin altindaki ogrencileri listeleyen fonksiyon.
void basarisizlarlistesi(Ogrenci ogr[], int MEVCUT)
{
	cout << "Hangi notun altindaki ogrencileri listelemek istediginiz giriniz: ";
	int not1, sayac = 0;
	not1 = dogruluk();
	string gecici;

	cout << "-------------------------------------------\n";
	cout << "Basari notu " << not1 << " notundan az olan ogrenciler. " << endl;
	cout << "-------------------------------------------\n";

	//0dan sinif mevcuduna kadar olan her ogrencinin basari notunun belirtilen nottan dusuk olup olmadigini sorgular.
	for (int i = 0; i < MEVCUT; i++)
	{
		//Eger i.ogrencinin basari notu belirtilen nottan dusuk ise ogrencinin adi, soyadi ve basari notu ekrana yazdirilir.
		if (ogr[i].basarinotu < not1)
		{
			sayac++;

			gecici = nottanharfe(ogr[i].basarinotu);

			cout << i + 1 << "." << "\t|" << ogr[i].adi << " " << ogr[i].soyadi << "\t\t" << "Basari Notu: " << ogr[i].basarinotu << " (" << gecici << ")" << endl;
		}
	}
	if (sayac == 0)
		cout << not1 << " notundan dusuk alan ogrenci yoktur.\n";
}


int main()
{
	//Sinif mevcudu.
	const int MEVCUT = 100;

	Ogrenci ogrenci[MEVCUT];
	Tarih ogrenciler[MEVCUT]{};

	char tercih;

	//Bilgiler kullanicidan mi yoksa rastgele mi alinicagini belirliyoruz.
	do
	{
		cout << "Ogrencilerin bilgileri rastgele mi dagitilsin? (E/H): ";
		cin >> tercih;
		if (tercih != 'E' && tercih != 'e' && tercih != 'H' && tercih != 'h')
			cout << "Lutfen E/e veya H/h diyin aksi halde isleminiz gerceklestirilemez." << endl;
		cout << endl;
	} while (tercih != 'E' && tercih != 'e' && tercih != 'H' && tercih != 'h');

	//Kullanicinin bilgileri kendisinin girdigi secenek.
	if (tercih == 'h' || tercih == 'H')
	{
		float g1, g2, g3, g4, g5, g6, g7, g8;		//Kolay atama yapabilmek icin g'leri kullaniyorum.

		//0dan sinif mevcuduna kadar olan butun verileri kullanicidan aliyoruz.
		for (int i = 0; i < MEVCUT; i++)
		{

			cout << i + 1 << ". Ogrencinin adini giriniz: ";					//Kullanicidan isim alinir.
			cin >> ogrenci[i].adi;

			cout << i + 1 << ". Ogrencinin soyadini giriniz: ";					//Kullanicidan soyadi alinir.
			cin >> ogrenci[i].soyadi;

			cout << i + 1 << ". Ogrencinin numarasini giriniz giriniz: ";		//Kullanicidan numara alinir.
			cin >> ogrenci[i].numara;

			//Ogrencinin hangi yilda dogdugunu gecerli bir sekilde aliriz.
			do
			{
				cout << i + 1 << ". Ogrencinin hangi yilda dogdugunu giriniz. ";
				cin >> ogrenciler[i].yil;

				//Gecerli yil girilmez ise kullanici uyarilicak
				if (ogrenciler[i].yil < 1940 || ogrenciler[i].yil>2004)
				{
					cout << "Lutfen mumkun olan bir yil giriniz." << endl;
				}
			} while (!(ogrenciler[i].yil >= 1940 && ogrenciler[i].yil <= 2004));

			//Ogrencinin hangi ayda dogdugunu gecerli bir sekilde aliriz.
			do
			{
				cout << i + 1 << ". Ogrencinin hangi ayda dogdugunu sayiyla giriniz. ";
				cin >> ogrenciler[i].ay;

				//Gecerli ay girilmez ise kullanici uyarilicak
				if (ogrenciler[i].ay < 1 || ogrenciler[i].ay>12) {
					cout << "Lutfen gecerli bir ay giriniz." << endl;
				}
			} while (!(ogrenciler[i].ay >= 1 && ogrenciler[i].ay <= 12));

			//Ogrencinin hangi gunde dogdugunu gecerli bir sekilde aliriz.
			do
			{
				cout << i + 1 << ". Ogrencinin hangi gunde dogdugunu sayiyla giriniz. ";
				cin >> ogrenciler[i].gun;

				//Gecerli ay girilmez ise kullanici uyarilicak
				if (ogrenciler[i].gun < 1 || ogrenciler[i].gun>30)
				{
					cout << "Lutfen gecerli bir gun giriniz." << endl;
				}
			} while (!(ogrenciler[i].gun >= 1 && ogrenciler[i].gun <= 30));

			cout << i + 1 << ". Ogrencinin 1.kisa sinav notunu giriniz: ";		//Kullanicidan 1.kisa sinav notu alinir.
			g1 = dogruluk();
			ogrenci[i].kisa_sinav1 = g1;

			cout << i + 1 << ". Ogrencinin 2.kisa sinav giriniz: ";				//KUllanicidan 2.kisa sinav notu alinir.
			g2 = dogruluk();
			ogrenci[i].kisa_sinav2 = g2;

			cout << i + 1 << ". Ogrencinin 1.odev notunu giriniz: ";			//Kullanicidan 1.odev notu alinir.
			g3 = dogruluk();
			ogrenci[i].odev1 = g3;

			cout << i + 1 << ". Ogrencinin 2.odev notunu giriniz: ";			//Kullanicidan 2.odev notu alinir.
			g4 = dogruluk();
			ogrenci[i].odev2 = g4;

			cout << i + 1 << ". Ogrencinin proje notunu giriniz: ";				//Kullanicidan proje notu alinir.
			g5 = dogruluk();
			ogrenci[i].proje = g5;

			cout << i + 1 << ". Ogrencinin vize notunu giriniz: ";				//Kullanicidan vize notu alinir.
			g6 = dogruluk();
			ogrenci[i].vize = g6;

			cout << i + 1 << ". Ogrencinin final notunu giriniz: ";				//Kullanicidan final notu alinir.
			g7 = dogruluk();
			ogrenci[i].final = g7;

			g8 = basarinotuhesap(g1, g2, g3, g4, g5, g6, g7);					//Verilerle basari notu fonksiyon ile hesaplanir.
			ogrenci[i].basarinotu = g8;
		}
	}

	//Bilgilerin rastgele verildigi secenek.
	if (tercih == 'e' || tercih == 'E')
	{
		srand(time(NULL));

		//0dan sinif mevcuduna kadar olan butun veriler rastgele olusturulur.
		for (int i = 0; i < MEVCUT; i++)
		{
			int geciciad = rand() % 30;					//Rastgele isim olusturulur.
			ogrenci[i].adi = isimler[geciciad];

			int gecicisoyad = rand() % 30;				//Rastgele soyisim olusturulur.
			ogrenci[i].soyadi = soyisim[gecicisoyad];

			float numara = rand() % 1000;				//0 ile 1000 arasinda rastgele numara olursuturlur
			ogrenci[i].numara = numara;

			int gecicigun = rand() % 30 + 1;			//1 ile 30 arasinda astgele gun olusturulur.
			ogrenciler[i].gun = gecicigun;

			int geciciay = rand() % 12 + 1;				//1 ile 12 arasinda rastgele ay olusturulur.
			ogrenciler[i].ay = geciciay;

			int geciciyil = rand() % 65 + 1940;			//1940 ile 2004 arasinda rastgele yil olusturulur.
			ogrenciler[i].yil = geciciyil;

			//Sinif mevcudunun %10u 0-40 arasi notlar alir.
			if (i < (MEVCUT * 10 / 100)) {

				ogrenci[i].kisa_sinav1 = rand() % 40;

				ogrenci[i].kisa_sinav2 = rand() % 40;

				ogrenci[i].odev1 = rand() % 40;

				ogrenci[i].odev2 = rand() % 40;

				ogrenci[i].proje = rand() % 40;

				ogrenci[i].vize = rand() % 40;

				ogrenci[i].final = rand() % 40;
			}

			//Sinif mevcudunun % 50si 40-70 arasi notlar alir.
			else if (i < (MEVCUT * 10 / 100) + (MEVCUT * 50 / 100)) {

				ogrenci[i].kisa_sinav1 = rand() % 30 + 40;

				ogrenci[i].kisa_sinav2 = rand() % 30 + 40;

				ogrenci[i].odev1 = rand() % 30 + 40;

				ogrenci[i].odev2 = rand() % 30 + 40;

				ogrenci[i].proje = rand() % 30 + 40;

				ogrenci[i].vize = rand() % 30 + 40;

				ogrenci[i].final = rand() % 30 + 40;
			}

			//Sinif mevcudunun %15 i 70-80 arasi notlar alir.
			else if (i < (MEVCUT * 10 / 100) + (MEVCUT * 50 / 100) + (MEVCUT * 15 / 100)) {

				ogrenci[i].kisa_sinav1 = rand() % 10 + 70;

				ogrenci[i].kisa_sinav2 = rand() % 10 + 70;

				ogrenci[i].odev1 = rand() % 10 + 70;

				ogrenci[i].odev2 = rand() % 10 + 70;

				ogrenci[i].proje = rand() % 10 + 70;

				ogrenci[i].vize = rand() % 10 + 70;

				ogrenci[i].final = rand() % 10 + 70;
			}

			//Sinif mevcudunun %25i 80-100 arasi notlar alir.
			else if (i < (MEVCUT * 10 / 100) + (MEVCUT * 50 / 100) + (MEVCUT * 15 / 100) + (MEVCUT * 25 / 100)) {

				ogrenci[i].kisa_sinav1 = rand() % 20 + 80;

				ogrenci[i].kisa_sinav2 = rand() % 20 + 80;

				ogrenci[i].odev1 = rand() % 20 + 80;

				ogrenci[i].odev2 = rand() % 20 + 80;

				ogrenci[i].proje = rand() % 20 + 80;

				ogrenci[i].vize = rand() % 20 + 80;

				ogrenci[i].final = rand() % 20 + 80;
			}
			//Basari notu hesaplanir.
			float basarinotu;
			basarinotu = basarinotuhesap(ogrenci[i].kisa_sinav1, ogrenci[i].kisa_sinav2, ogrenci[i].odev1, ogrenci[i].odev2, ogrenci[i].proje, ogrenci[i].vize, ogrenci[i].final);
			ogrenci[i].basarinotu = basarinotu;
		}
	}
	char devam;
	do
	{
		cout << "Yapmak istediginiz islemi yanindaki rakami tuslayarak seciniz.\n\n";

		cout << "1. Sinif listesi yazdir.\n";
		cout << "2. Sinifin en yuksek notunu hesapla.\n";
		cout << "3. Sinifin en dusuk notunu hesapla.\n";
		cout << "4. Sinifin not ortalamasini hesapla.\n";
		cout << "5. Sinifin standart sapmasini hesapla.\n";
		cout << "6. Istediginiz basari notu araliginda olan ogrenciler listelensin.\n";
		cout << "7. Istediginiz bir basari notunun altinda kalan ogrenciler listelensin.\n";
		cout << "8. istediginiz bir basari notunun ustunde kalan ogrenciler listelensin.\n\n";

		char secim;
		do
		{
			cout << "Yapmak istediginiz islemi tuslayiniz. ";
			cin >> secim;
			cout << endl;

			if (!(secim == '1' || secim == '2' || secim == '3' || secim == '4' || secim == '5' || secim == '6' || secim == '7' || secim == '8'))
				cout << "Lutfen gecerli bir islem seciniz!\n";

		} while (!(secim == '1' || secim == '2' || secim == '3' || secim == '4' || secim == '5' || secim == '6' || secim == '7' || secim == '8'));

		//Secilen islemi gerceklestirir.
		switch (secim)
		{

		case '1':
			siniflistesi(ogrenci, ogrenciler, MEVCUT);
			cout << endl;
			break;

		case '2':
			enyukseknot(ogrenci, MEVCUT);
			cout << endl;
			break;

		case '3':
			endusuknot(ogrenci, MEVCUT);
			cout << endl;
			break;

		case '4':
			sinifnotortalamasi(ogrenci, MEVCUT);
			cout << endl;
			break;

		case '5':
			standartsapma(ogrenci, MEVCUT);
			cout << endl;
			break;

		case '6':
			basarilistesi(ogrenci, MEVCUT);
			cout << endl;
			break;

		case '7':
			basarisizlarlistesi(ogrenci, MEVCUT);
			cout << endl;
			break;

		case '8':
			basarililarlisteri(ogrenci, MEVCUT);
			cout << endl;
			break;
		}

		do
		{
			cout << "Islem yapmaya devam etmek istiyor musun? (E/H): ";
			cin >> devam;

			cout << endl;

			if ((devam != 'e' && devam != 'E') && (devam != 'H' && devam != 'h'))
				cout << "Lutfen E/e veya H/h tuslarini tuslayin aksi halde devam edemezsiniz.\n";

		} while (devam != 'e' && devam != 'E' && devam != 'H' && devam != 'h');

		system("cls");

	} while (devam == 'e' || devam == 'E');

	//Kullanici programdan cikmak isterse ona gorusuruz diyip 1 saniye bekler.
	if (devam == 'h' || devam == 'H')
	{
		cout << "Tekrar gorusmek uzere, kendinize iyi bakin :)";
		Sleep(1000);
	}
	return 0;
}