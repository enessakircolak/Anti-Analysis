#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <sstream>

typedef  NTSYSAPI void (CALLBACK* LPNTQUERYSYSTEMTIME)(PLARGE_INTEGER);


using namespace std;

void asil() {
    cout << "Mekana giris yapildi";
    int y = 5;
    y++;
    const char* t = "t";
    string m = "OzZayotemAS";
    y = y + (int)t;
    cout << m;
}
void kolpa() {
    cout << "Copluk burasi";
    int sayi1, sayi2, toplam, fark;

    cout << "Lutfen birinci sayiyi giriniz: ";
    cin >> sayi1;

    cout << "Lutfen ikinci sayiyi giriniz: ";
    cin >> sayi2;

    toplam = sayi1 + sayi2;
    fark = sayi1 - sayi2;

    cout << "Toplam = " << toplam << endl;
    cout << "Fark = " << fark << endl;

}

extern "C" int selamcanim(int c,LPTHREAD_START_ROUTINE a, LPTHREAD_START_ROUTINE b);


void main(void)
{
    PLARGE_INTEGER  SystemTime;
    SystemTime = (PLARGE_INTEGER)malloc(sizeof(LARGE_INTEGER));

    HMODULE hNtDll = GetModuleHandleA("ntdll");

    LPNTQUERYSYSTEMTIME fnNtQuerySystemTime = (LPNTQUERYSYSTEMTIME)GetProcAddress(hNtDll, "NtQuerySystemTime");

    if (fnNtQuerySystemTime) {

        //printf("found NtQuerySystemTime function at ntdll.dll address:%p\n", fnNtQuerySystemTime);
        

	  fnNtQuerySystemTime(SystemTime);  	// saatin alındığı ilk nokta
        printf("%llx\n", SystemTime->QuadPart);
        //cout << SystemTime->QuadPart << std::endl;

        std::ostringstream str1;
        str1 <<hex<< SystemTime->QuadPart;
        string result = str1.str();
        int a = result[7], b = result[8];
        //cout << result[6]<<result[7] <<result[8] << " ince ayar" << endl;
        cout << a<<" daenerys stormborn "<<endl;
        
	  fnNtQuerySystemTime(SystemTime);		// saatin alındığı ikinci nokta
        std::ostringstream str2;
        str2 << hex << SystemTime->QuadPart;
        string sonuc = str2.str();
        int c = sonuc[7], d = sonuc[8];

        cout << c << " Challenger"<<endl;
        cout << c << " = ayni mi ? = " << a << endl;

        if (c != a) {  // burada alınan saat eşit mi diye kontrol edip ona göre asm fonksiyonuna 1 veya 0 parametresi atılıyor
            selamcanim(1, (LPTHREAD_START_ROUTINE)asil, (LPTHREAD_START_ROUTINE)kolpa);
            cout << "“THERE IS ALWAYS HOPE.” – ARAGORN";
        }
        else {
            selamcanim(0, (LPTHREAD_START_ROUTINE)asil, (LPTHREAD_START_ROUTINE)kolpa);
            cout << "“BECOME WHO YOU WERE BORN TO BE.”– ELROND";
        }
        

        //printf("%llx\n",SystemTime->HighPart);
        //printf("%llx\n", SystemTime->LowPart);


    }

    free(SystemTime);
}