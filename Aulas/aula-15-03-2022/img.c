#include <stdio.h>
#include <stdlib.h>

unsigned char ** novaMatriz(int W, int H);
void imageFill(unsigned char **img, int w_max, int h_max, unsigned char color);
void drawRect(unsigned char **img, int w_max, int h_max, int w, int h, int x, int y, unsigned char color);
void print_pgn(unsigned char **img, int w_max, int h_max);
void liberaImg(unsigned char **img, int h_max);

int main(void) {
    int h_max, w_max, h, w, x, y, cor, i, qtd_rect;
    unsigned char **img;

    scanf("%d %d %d", &w_max, &h_max, &qtd_rect);

    img = novaMatriz(w_max, h_max);
    imageFill(img, w_max, h_max, 0);

    for(i = 0; i < qtd_rect; i++) {
        w = 10 + rand()%(w_max/2);
        h = 2 + rand()%(h_max/2);
        x = rand()%(w_max - w);
        y = rand()%(h_max - h);
        cor = 1 + rand()%255;

        drawRect(img, w_max, h_max, w, h, x, y, cor);
    }

    print_pgn(img, w_max, h_max);
    liberaImg(img, h_max);

    return 0;
}

unsigned char ** novaMatriz(int W, int H) {
    int i;
    unsigned char **img;

    img = (unsigned char **) malloc(H*sizeof(unsigned char *));

    for(i = 0; i < H; i++) {
        img[i] = (unsigned char *) malloc(W*sizeof(unsigned char));
    }

    return img;
}

void imageFill(unsigned char **img, int w_max, int h_max, unsigned char color) {
    int c, l;

    for(l = 0; l < h_max; l++) {
        for(c = 0; c < w_max; c++) {
            img[l][c] = color;
        }
    }

    return;
}

void drawRect(unsigned char **img, int w_max, int h_max, int w, int h, int x, int y, unsigned char color) {
    int c, l;

    h += x;
    w += y;

    for(l = x; l < h; l++) {
        for(c = y; c < w; c++) {
            if(w > w_max || h > h_max) break;;
            img[l][c] = color;
        }
    }

    return;
}

void print_pgn(unsigned char **img, int w_max, int h_max) {
    int l, c;

    printf("P2\n");
    printf("%d %d\n%d \n", w_max, h_max, 255);

    for(l = 0; l < h_max; l++) {
        for(c = 0; c < w_max; c++) {
            printf("%d ", img[l][c]);
        }
        printf("\n");
    }
}

void liberaImg(unsigned char **img, int h_max) {
    int l, c;

    for(l = 0; l < h_max; l++) {
        free(img[l]);
    }

    free(img);    
}