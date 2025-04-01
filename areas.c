#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRIANGLE 1
#define CIRCLE 2
#define RECTANGLE 3
#define PI 3.1415

int get_int(void);
void triangle(int* result);
void circle(int* result);
void rectangle(int* result);

int main(void)
{
    int area;
    void(*fp)(int*);
    printf("Digite 1 para um triângulo, 2 para um círculo e 3 para um retângulo\n");
    int forma = get_int();
    switch(forma)
    {
        case TRIANGLE:
            fp = triangle;
            break;
        case CIRCLE:
            fp = circle;
            break;
        case RECTANGLE:
            fp = rectangle;
            break;
        default:
            return 0;
    }
    (fp)(&area);
    printf("\n a área é: %i\n", area);
}

int get_int(void)
{
    int x;
    scanf("%i\n", &x); fflush(stdout);
    return x;
}

void triangle(int* result)
{
    printf("Digite o valor do lado 1:\n");
    int x = get_int();
    printf("Digite o valor do lado 2:\n");
    int y = get_int();
    printf("Digite o valor do lado 3:\n");
    int z = get_int();
    int p = (x + y + z)/2;
    *result = sqrt(p*(p - x)*(p - y)*(p - z));
}

void circle(int* result)
{
    printf("Qual o raio?\n");
    int r = get_int();
    *result = PI * r * r;
}

void rectangle(int* result)
{
    printf("Digite o valor da Base:\n");
    int b = get_int();
    printf("Digite o valor da altura:\n");
    int h = get_int();
    *result = b * h / 2;
}
