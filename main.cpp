#include <iostream>

int staticArray[5];

int find(char * buf, char c, int length) {
    int res = -1;
    for (int i = 0; i <= length; i++) {
        if (buf[i] == c) return i;
    }
    return res;
}

unsigned int returnNegative () {
    int amount = 0;
    std::string result = "ERROR";
    if (result == "ERROR")
        amount = -1;
    return amount;
}


void testVulnerabilities(char * argBuffer, int * mainArrayOnStack, int * mainArrayOnHeap) {

    // Type overflow/ underflow

    // #1 adding float and integer together, casting result to int
    float floatVal = 1.234;
    int intVal = 5;
    int castResult = floatVal + intVal;
    std::cout << castResult << '\n';

    // #2 Function returns possible negative number which is stored to unsigned int variable
    unsigned int unsignedIntReturn = returnNegative();
    std::cout << unsignedIntReturn << '\n';


    // format string vulnerability
    // #3 memory content from stack is formatted into string
    char buf[64] = {};
    sprintf(buf, argBuffer);
    printf(buf);
    printf("\n");


    // improperly terminated data
    // #4 strcpy do not append null-character at the end of copied string
    char buff[64];
    strncpy(buff, argBuffer, sizeof(buff));
    printf("%s\n",buff);



    // memory coruption

    // #5 static array - access out of bounds
    staticArray[10] = 5;
    // #6 access out of bound with loop
    for (int i = 0; i <= 5; i++) {
        staticArray[i] = 0;
    }

    // #7 array on stack - access out of bounds
    int arrayOnStack[5] = {};
    arrayOnStack[10] = 5;
    // #8 access out of bounds with loop
    for (int i = 0; i <= 5; i++) {
        arrayOnStack[i] = 0;
    }
    // #9 access out of bounds - array from main
    mainArrayOnStack[10] = 5;


    // #10 array on heap - access out of bounds
    int* arrayOnHeap = (int*) malloc(5*sizeof(int));
    arrayOnHeap[10] = 5;
    // #11 access out of bound with loop
    for (int i = 0; i <= 5; i++) {
        arrayOnHeap[i] = 0;
    }
    // #12 access out of bounds - array from main
    mainArrayOnHeap[10] = 5;



    // stack buffer overflow/ under flow

    // #13 Buffer underflow - find return -1 if cant find char in string - results in negative index
    char * srcBuf = new char[5];
    char c = 'a';
    char destBuf[10];
    strncpy(destBuf, &srcBuf[find(srcBuf, c, 5)], 10);

    // #14 buffer overflow
    char stringToCopy[12] = {'B','i','g','g','e','r', ' ', 't', 'h', 'a', 'n'};
    char bufToCopy[5];
    strcpy(bufToCopy, stringToCopy);

    // #15 buffer overflow scanning from cmd
    char cmdInput[5];
    char cmdInput2[5];
    printf("input max 5: ");
    fflush(stdout);
    scanf("%s", cmdInput);
    printf("input2 max 5: ");
    fflush(stdout);
    scanf("%s", cmdInput2);
    printf("input1: %s, input2: %s\n", cmdInput ,cmdInput2);

    // #16 integer overflow
    int x = INT_MAX;
    int y = 1;
    int intOverflow = x + y;
    printf("IntOverflow is: %d \n", intOverflow);




}

int main(int argc, char * argv[]) {

    if (argc < 2) {
        printf("Input one argument");
        return 0;
    }

    int mainArrayOnStack[5] = {};
    int * mainArrayOnHeap = new int[5];

    for (int i=0; i<5; ++i)  {
        mainArrayOnStack[i] = 1;
        mainArrayOnHeap[i] = 1;
    }


    testVulnerabilities(argv[1], mainArrayOnStack, mainArrayOnHeap);
    return 0;
}




