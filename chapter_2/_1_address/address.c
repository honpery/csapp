#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len)
{
    for (int i = 0; i < len; i++)
        printf("%.2x", start[i]);

    printf("\n");
}

void show_init(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer)&x, sizeof(void *));
}

int main()
{
    int num = 10;
    float fnum = (float)num;
    int *pnum = &num;

    show_init(num);     // 0a 00 00 00
    show_float(fnum);   // 00 00 20 41
    show_pointer(pnum); // cc 87 ae 5c ff 7f 00 00
}