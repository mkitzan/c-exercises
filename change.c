#include <stdio.h>
#include <math.h>

#define DENOMS {100, 50, 20, 10, 5, 1, 25, 10, 5, 1}
#define DL 6
#define DS 4


void get_change(int int_part, int fract_part) {
    int i, denoms[DL+DS] = DENOMS;
    
    // print bills de-comp
    printf("Bills\n");
    for(i = 0; i < DL; i++) {
        printf("$%d:\t%d\n", denoms[i], int_part / denoms[i]);
        // mod out accounted for values
        int_part %= denoms[i];
    }
    
    // print change de-comp
    printf("\nChange\n");
    for(i = 0; i < DS; i++) {
        printf("%dc:\t%d\n", denoms[i+DL], fract_part / denoms[i+DL]);
        // mod out accounted for values
        fract_part %= denoms[i+DL];
    }
}


int n_digits(int n, int num) {
    // number of digits in the number
    int digits = (int)log10(num)+1;
    // int-div out numbers after the nth digit
    return (n > digits) ? num : (int)(num / pow(10, digits-n));
}



int change(double diff) {
    get_change((int)diff, (int)(diff*100)%100);
}


int main(int argc, char *argv[]) {
    // exit if too few args
    if(argc < 2) return 1;
    
    int int_part = 0, fract_part = 0;
    // scan out integer part and fractional part of the number
    sscanf(argv[1], "%d.%d", &int_part, &fract_part);
    
    // draw the first two digits of fractional part
    fract_part = n_digits(2, fract_part);
    if(fract_part < 10) fract_part *= 10;

    get_change(int_part, fract_part);
    
    return 0;
}

