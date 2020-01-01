// 2017280075  Şiyar Utkan 
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <limits>
#include <typeinfo>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <windows.h>
#include <numeric>
int main(){
using namespace std;
	//Kaç satýr olduðunu sayýyoruz.
    //ilk iki satýrdan sonra öðrencilerin sýralanacaðýný biliyoruz.
    //satýr sayýsýndan iki çýkardýðýmýzda kaç öðrenci olduðunu bulacaðýz.	
	//https://stackoverflow.com/questions/3482064/counting-the-number-of-lines-in-a-text-file
	unsigned int satirSayisi = 0;
	int soruSayisi;
	
    FILE *infile = fopen("input.txt", "r");
    int ch;
	while (EOF != (ch=getc(infile)))
        
		if ('\n' == ch)
            ++satirSayisi;
    printf("Satir Sayisi:""\n");
	printf("%u\n", satirSayisi);
fclose(infile);
int ogrenciSayisi= (satirSayisi-2);
std::cout<<"Ogrenci Sayisi:"<<std::endl;
std::cout<<ogrenciSayisi<<std::endl;


//Soru sayýsýný buluyorum.
ifstream oku3("input.txt");
	int satir;
		oku3>>soruSayisi;
oku3.close();
cout<<"Soru Sayisi:"<<std::endl;
cout<<soruSayisi<<std::endl;
	
	//ÖNEMLÝ!!! input.txt dosyasýnda boþ býrakýlmýþ sorular için "b" yazýldýðý varsayýlmýþtýr. "A,b,B" gibi.

vector <string> v;
vector <string> d;
ifstream oku("input.txt");
ofstream yaz("ogrenciCevaplari.txt");

string line;

int c=0;
while(getline(oku, line)){
	stringstream ss(line);

	v.push_back(line);
	
}

oku.close();




for(int x=2;x<satirSayisi;x++){
	yaz<<v[x]<<endl;

	
}
yaz.close();
//v[1] cevap anahtaridir.
cout<<"Cevap Anahtari:"<<endl;
cout<<v[1]<<endl;

  
//ogrenci numaralari için ve cevaplari için iki vektör tanýmladým
vector <string> n;
vector <string> o;

//yeni dosya oluþturup verinin bir kýsmýný oraya atma fikrini edindiðim yer:
//https://stackoverflow.com/questions/25076739/how-to-delete-a-specific-row-in-a-text-file-using-fstream/43983581
ifstream oku2("ogrenciCevaplari.txt");
string ogrenciNumarasi,ogrenciCevap;
string linee;
while(getline(oku2, linee)){
	stringstream ss(linee);
	getline(ss,ogrenciNumarasi, ',');
	getline(ss, ogrenciCevap);
	n.push_back(ogrenciNumarasi);
	o.push_back(ogrenciCevap);	
}
//stringstream için: https://youtu.be/_IzYGiuX8QM?list=WL
oku2.close();  
cout<<"Ogrenci Numaralari ve Cevaplari:"<<endl;
  for(int x=0;x<ogrenciSayisi;x++){


	cout<<n[x]<<endl;
	cout<<o[x]<<endl;

}
ofstream output("output.txt");
string boss[]={"b"};
int dogruSayisi,bosSayisi;

int b_yanlisSayisi;
vector <int> puanlar;

int b=0;


for(int z=0;z<ogrenciSayisi;z++){


for(int t=0;t<((soruSayisi*2)-1);t++){

	if(o[z][t]==boss[0][0]){
		bosSayisi++;
	}
	if(o[z][t]!=v[1][t]){
		b_yanlisSayisi++;
	}
	
}

int yanlisSayisi=b_yanlisSayisi-bosSayisi;
int dogruSayisi= soruSayisi-yanlisSayisi-bosSayisi;

int puan=dogruSayisi*4-yanlisSayisi;
cout<<"Dogru Sayisi:"<<endl;
cout<<dogruSayisi<<endl;

cout<<"Yanlis Sayisi:"<<endl;
cout<<yanlisSayisi<<endl;
if(puan<0){
	puan=0;
}
if(puan>soruSayisi*4){
	puan=100;
}
else{
	puan=puan*100/(soruSayisi*4);
}
cout<<"Puan:"<<endl;
cout<<puan<<endl;
//puanlarý vektörümüze aktarýyoruz.
puanlar.push_back(puan);

//her döngü tur attýðýnda valuelarý sýfýrlamak için koyduðum operator iþlemi.
dogruSayisi -= dogruSayisi;
bosSayisi -= bosSayisi;
b_yanlisSayisi -= b_yanlisSayisi;
yanlisSayisi -=  yanlisSayisi;
puan -=  puan;
}

for(int c;c<ogrenciSayisi; c++){

cout<<puanlar[c]<<endl;
}
sort(puanlar.begin(), puanlar.end()); 
//sorting iþlemi için:https://www.geeksforgeeks.org/sorting-a-vector-in-c/
for(int c;c<ogrenciSayisi; c++){
output<<n[c]<<":";
output<<puanlar[c]<<endl;
}
       //http://www.cplusplus.com/forum/beginner/232457/
	   const double sum = std::accumulate( puanlar.begin(), puanlar.end(), 0.0 );


        std::cout << "Ortalama: " << sum / puanlar.size() << '\n' ;


        const double median = ( puanlar[ogrenciSayisi/2] + puanlar[ (ogrenciSayisi-1)/2 ] ) / 2.0 ;
        std::cout << "Medyan: " << median << '\n' ;


        const double range = puanlar.back() - puanlar.front() ;
        std::cout << "Aciklik: " << range << '\n' ;
        output<<"En dusuk not:"<<puanlar.front()<<","<<"En yuksek not:"<<puanlar.back()<<endl;
        output<<"Ortalama:"<<sum/puanlar.size()<<","<<"Medyan:"<<median;
        
output.close();
getch();
return 0;


}



