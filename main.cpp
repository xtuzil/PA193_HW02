#include <iostream>
#include <stdio.h>
#include <string.h>
int sArr[4];
int retNeg() {
    return -1;
}

void test(char * arg, int*mArrS, int*mArrH) {
    float flt = 1.2;
    int val = 5;
    int cast = flt + val;
    unsigned int unsign = retNeg();
    char buff[8],dest[8],dest2[2],inpt[5],srcBuf[5]="ahoj";
    strncpy(buff, arg, sizeof(buff));
    int arrS[4] = {};
    int* arrH = new int[3];
    for (int i=0; i<4; ++i)  {
        mArrS[i] = 1;
        mArrH[i] = 1;
        sArr[i] = 1;
        arrS[i] = 1;
        arrH[i] = 1;
    }
    sArr[6] = 5;
    arrS[6] = 5;
    mArrS[6] = 5;
    arrH[6] = 5;
    mArrH[6] = 5;
    strncpy(dest, &srcBuf[retNeg()], 8);
    strcpy(dest2, srcBuf);
    fflush(stdout);
    scanf("%s", inpt);
    int x = 2147483647, y = 1;
    int intOF = x + y;
}

int main(int argc, char * argv[]) {
    char buf[8];
    sprintf(buf, argv[1]);
    int mArrS[5] = {};
    int * mArrH = new int[5];
    test(argv[1], mArrS, mArrH);
    return 0;
}