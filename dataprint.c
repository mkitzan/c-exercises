
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define BUFFER 256
#define noop


void dtoa(char *buffer, double num, int round) {
    sprintf(buffer, "%d.%d", (int) num, (int) ((num - (int) num) * pow(10, round)));
}

char *make_border(char *border, int border_len, int *col_lens, int cols, char edge) {
    int i, j, curr;
    int k = 0;
    
    for(i=0; i<cols; i++) {
        curr = *(col_lens+i);
        
        border[k++] = '*';
        for(j=0; j<curr; j++) {
            border[k++] = '-';
        }
    }
    
    border[k++] = '*';
    border[k] ='\0';
    
    return border;
}

int max_lens(int *max, void *labels, void *results, int cols, int rows, int buffer_val, int round) {
    int i, j, sum, len;
    char buffer[BUFFER];
    
    for(i=0; i<cols; i++) {
        max[i] = strlen((char *)labels+(BUFFER*i)) + buffer_val;
    }
    
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            dtoa(buffer, *((double *)results+(i*cols + j)), round); // a way to index 2D arrays from 'type *pointer'
            
            len = strlen(buffer) + buffer_val; 
            if(len > max[j]) {
                max[j] = len;
            }
        }
    }
    
    for(i=0, sum=1; i<cols; i++) {
        sum += max[i] + 1;
    }
    
    return sum;
}

void print_row(void *curr_row, int cols, int *col_lens, int round, char type) {
    int i, j;
    char buffer[BUFFER];
    
    for(i=0; i<cols; i++) {
        if(type == 'd') {
            dtoa(buffer, *((double *)curr_row+i), round);
        } else {
            strncpy(buffer, (char *)(curr_row+(BUFFER*i)), BUFFER);
        }
        
        printf("|%s", buffer);
        for(j=0; j<(col_lens[i]-strlen(buffer)); j++) {
            printf(" ");
        }
    }
    
    printf("|\n");
}

void printer(void *labels, void *results, int cols, int rows, int *col_lens, char *border, int round) {
    int i;
    
    printf("%s\n", border);
    
    print_row(labels, cols, col_lens, round, 's');
    
    printf("%s\n", border);
    
    for(i=0; i<rows; i++) {
        print_row((double *)results+(cols*i), cols, col_lens, round, 'd');    
    }
    
    printf("%s\n", border);
} 

void table(void *labels, void *results, int cols, int rows, char edge, int buffer, int round) {
    int col_sum;
    int col_lens[cols];
    
    col_sum = max_lens(col_lens, labels, results, cols, rows, buffer, round);
    char border[col_sum+1];
    
    make_border(border, col_sum, col_lens, cols, edge);
    
    printer(labels, results, cols, rows, col_lens, border, round);
}

int main(int argc, char *argv[]) {
    // test example
    char labels[5][BUFFER] = {"Date", "Temp High", "Temp Low", "Humidity", "Wind"};
    double results[3][5] = {{20180501, 9.0, 6.0, 100, 6}, 
                            {20180601, 7.0, 4.0, 87, 18},
                            {20180701, 6.0, 5.0, 94, 16}};
                        
    table(labels, results, 5, 3, '*', 1, 2); 
    
    return 0;
}
