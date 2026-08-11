#include <stdio.h>
#include <unistd.h>
int main(void) {

        FILE* fp = fopen("/dev/urandom", "a");
        char* ln = NULL;
        size_t n = 4096;

        printf("> ");
        fflush(stdout); 
        while(n = getline(&ln, &n, stdin)) {
        for (int i = 0; i < n; i++) {
                fwrite(&ln[i], 1, 1, fp);
                fflush(fp);
                sleep(1);
        }
        printf("> ");
        fflush(stdout);
        }
} 
