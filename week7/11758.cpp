#include <stdio.h>
typedef struct{
    int x, y;
}Point;

int main(){
    Point p[3];
    for (int i = 0; i < 3; i++)
        scanf("%d %d", &p[i].x, &p[i].y);
    int result = (p[1].x - p[0].x)*(p[2].y - p[0].y) - (p[1].y - p[0].y)*(p[2].x - p[0].x);
    if (result < 0) puts("-1");
    else putchar(result > 0 ? '1' : '0');
}