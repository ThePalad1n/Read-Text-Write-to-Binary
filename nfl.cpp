/*
    Project: Read Text File / Write to Binary File
    Author: Evan Green
    Course: CmpSci 472
    Instructor: F. Ganther
*/


#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Players
{
    char n[100];
    int a;
    char p[100];
    int h;
    int w;
    char t[100];
};
int main()
{
    struct Players bin;
    int line_size;
    line_size = sizeof(struct Players);
    FILE *finput, *foutput;
    // needs to be able to enter n of file for input
    finput = fopen("nfl.txt", "r");
    if (finput == NULL)
    {
        cout << "Could not open input file" << endl;
        return -1;
    }
    // needs to be able to enter n of file for output
    foutput = fopen("nfl.bin", "wb");
    if (foutput == NULL)
    {
        cout << "Could not open output file" << endl;
        return -1;
    }
    char n[100], p[100], t[100];
    int a, h, w;
    while (!feof(finput))
    {

        fscanf(finput, "%[^,],%d,%[^,],%d,%d,%[^\n]", n, &a, p, &h, &w, t);
        cout << n << " " << a << " " << p << " " << h << " " << w << " " << t;
        strcpy(bin.n, n), bin.a = a, strcpy(bin.p, p), bin.h = h, bin.w = w, strcpy(bin.t, t);
        fwrite(&bin, line_size, 1, foutput);
    }
    fclose(finput);
    fclose(foutput);
    return 0;
}