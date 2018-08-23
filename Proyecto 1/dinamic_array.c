#include <stdio.h>
#include <stdlib.h>

int * array;

void resizeArray(int size) {
    array = (int *) malloc(size);
}

int main() {
    int size;

    printf("Type the size of the desired array");
    scanf("%d", &size);
    
    resizeArray(size);

    for(int i=0; i<5; i++) {
        array[i] = i*i;
        printf("array[%d] = %d\n", i, array[i]);
    }

    printf("the 3rd element has the value of: %d", array[2]);

    return 0;
}