#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int * readFile(char* inputFile){

    FILE *stream;
    char line[4];
    size_t len = 0;
    ssize_t nread;
    char c;
    int fileLen = 0;

    stream = fopen(inputFile, "r");
    if(stream == NULL){
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    for(c = getc(stream); c!= EOF; c = getc(stream)){
        if(c == '\n')
            fileLen = fileLen + 1;
    }

    printf("The file has %d lines\n", fileLen);

    int *nums = malloc(fileLen + 1);

    int count = 0 ;

    rewind(stream);

    // while((nread = getline(&line, &len, stream)) != -1){
    //     printf("getline return value: %ld", nread);
    //     int x;
    //     sscanf(line, "%d", &x);
    //     nums[count] = x;
    //     count = count + 1;
    //     printf("%d - %d\n", count, x);
    //
    // }
    do{
        int x;
        sscanf(line, "%d", &x);
        nums[count] = x;
        count = count + 1;
        printf("%d - %d\n", count, x);

    } while((fgets(line, 4, stream)))

    nums[fileLen] = -1;
    printf("Nums[LastIndex] = %d", nums[fileLen]);

    return nums;
}


int main(int argc, char *argv[]) {

    int *z;

    z = readFile(argv[1]);

    printf("Got here!");

    int count = 0;
    int total = 0;
    while(z[count] != -1){
        total = total + z[count];
    }

    printf("Total: %d\n", total);

    return 0;
}

