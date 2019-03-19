#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    float x       = 500;
    float v       = -50;
    float g       = -5;
    float t       = 1;
    int   comb    = 120;
    char  fmt[37] = "Alt: %6.2f  Vel: %6.2f  Comb: %d %s";

    float x0;
    float v0;
    float resp;
    float a;
    float vf;

    char msg[34];

    printf("Simulação de alunissagem\n\n");
    printf("(Digite a quantidade de combustível a queimar)\n");

    while (x > 0) {

        if (comb > 0) {
            printf(fmt, x, v, comb, " Queima = ");
            scanf("%f", &resp);

            if (resp > comb) {
                resp = comb;
            }

            comb = comb - resp;
            a = g + resp;

        } else {
            printf(fmt, x, v, comb, "\n");
            a = g;
        }

        x0 = x;
        v0 = v;
        x  = x0 + v0 * t + a * t * t / 2;
        v  = v0 + a * t;
    }

    vf = sqrt(v0 * v0 + 2 * -a * x0);

    printf(">>>CONTATO! Velocidade final: %6.2f\n", -vf);

    if (vf == 0) {
        printf(">>>Alunissagem perfeita!");

    } else if (vf <= 2) {
        printf(">>>Alunissagem dentro do padrão.");

    } else if (vf <= 10) {
        printf(">>>Alunissagem com avarias leves.");

    } else if (vf <= 20) {
        printf(">>>Alunissagem com avarias severas.");

    } else {
        printf(">>>Modulo lunar destruído no impacto.");
    }

    printf("\n");

    return 0;
}
