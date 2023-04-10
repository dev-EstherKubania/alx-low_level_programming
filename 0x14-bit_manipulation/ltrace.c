#include <stdio.h>
#include <stdlib.h>

int main(int carg, char *args[]) {
	FILE *fp = popen("ltrace -p 2>&1", "r");
	char buf[255];
    	while (1) {
        if (fgets(buf, 255, fp) != NULL) {
            printf("Captured Text: %s", buf);
        }
    }
    return 0;
}
