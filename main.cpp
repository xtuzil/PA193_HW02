#include <iostream>
int sArr[4];
int retNeg() {
    return -1;
}

void test(char * arg, int*mArrS, int*mArrH) {
    float flt = 1.234;
    int val = 5;
    int cast = flt + val;
    unsigned int unsign = retNeg();
    char buff[64],dest[9],dest2[2],inpt[5];
    strncpy(buff, arg, sizeof(buff));
    int arrS[4] = {};
    int* arrH = new int[4];
    char * srcBuf = new char[5];
    for (int i=0; i<5; ++i)  {
        mArrS[i] = 1;
        mArrH[i] = 1;
        sArr[i] = 1;
        arrS[i] = 1;
        arrH[i] = 1;
        srcBuf[i] = 'a';
    }
    sArr[10] = 5;
    arrS[10] = 5;
    mArrS[10] = 5;
    arrH[10] = 5;
    mArrH[10] = 5;
    strncpy(dest, &srcBuf[retNeg()], 9);
    strcpy(dest2, srcBuf);
    fflush(stdout);
    scanf("%s", inpt);
    int x = INT_MAX, y = 1;
    int intOF = x + y;
}

int main(int argc, char * argv[]) {
    char buf[64];
    sprintf(buf, argv[1]);
    int mArrS[5] = {};
    int * mArrayH = new int[5];
    test(argv[1], mArrS, mArrayH);
    return 0;
}