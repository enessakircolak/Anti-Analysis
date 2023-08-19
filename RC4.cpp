
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct rc4_state
{
    int x, y, m[256];
};

void rc4_setup(struct rc4_state* s, unsigned char* key, int length)
{
    int i, j, k, * m, a;

    s->x = 0;
    s->y = 0;
    m = s->m;

    for (i = 0; i < 256; i++)
    {
        m[i] = i;
    }

    j = k = 0;


    for (i = 0; i < 256; i++)
    {
        a = m[i];
        j = (unsigned char)(j + a + key[k]);
        m[i] = m[j]; 
        m[j] = a;
        if (++k >= length) k = 0;
    }
}

void rc4_crypt(struct rc4_state* s, unsigned char* data, int length)
{
    int i, x, y, * m, a, b;

    x = s->x;
    y = s->y;
    m = s->m;

    for (i = 0; i < length; i++)
    {
        x = (unsigned char)(x + 1); a = m[x];
        y = (unsigned char)(y + a);
        m[x] = b = m[y];
        m[y] = a;
        data[i] ^= m[(unsigned char)(a + b)];
    }

    s->x = x;
    s->y = y;
}

int main()
{
    char key[128] = { "HackViser" };
    char data[32] = { 79,52,55,-52,-109,-27,17,-30,57};
    struct rc4_state* s;
    s = (struct rc4_state*)malloc(sizeof(struct rc4_state));

    printf("key : %s\n", key);
    printf("raw : %s\n", data);
    rc4_setup(s, (unsigned char*)key, strlen(key));
    
    int i;
    for (i = 0; i < 256; i++) {
        printf("%d ", s->m[i]);
    }
    printf("\n");
    
    rc4_setup(s, (unsigned char*)key, strlen(key));
    rc4_crypt(s, (unsigned char*)data, strlen(data));
    printf("encrypt  : %s\n", data);

    cout << "bytes : ";
    for (int j = 0; j < sizeof(data); j++) {
        cout << int(data[j]) << ",";
    }
    cout <<endl;

    rc4_setup(s, (unsigned char*)key, strlen(key));
    rc4_crypt(s, (unsigned char*)data, strlen(data));
    printf("decrypt  : %s\n", data);

    //cout << int(data[0]);
    //cout<<"HELLO"<<endl;
    return 0;
}