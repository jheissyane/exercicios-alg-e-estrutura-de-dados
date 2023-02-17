#include <stdio.h>

int main() {
    int n, h1, m1, h2, m2, t, count;

    scanf("%d", &n);
    count = 0;

    while(n--) {
        scanf("%d %d %d", &h1, &m1, &t);

        h2 = h1;
        m2 = m1 + t;

        if(m2 >= 60) {
            h2 += m2 / 60;
            m2 %= 60;
        }

        if(h2 >= 24) h2 -= 24;

        scanf("%d %d %d", &h1, &m1, &t);

        if(h2 < h1) {
            count++;
        }
        else if(h2 == h1 && m2 < m1) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}