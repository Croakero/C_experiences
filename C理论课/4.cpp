#include "stdio.h"
#include<limits.h>

void bit_prshort(short x)
{
    short i = 0;
    short n = sizeof(short) * CHAR_BIT; /* CHAR_BIT ��limits.h�ж��� */
    short mask = 1 << (n-1);         /* �߼���mask=100����0 */

    for ( i=1; i<=n; ++i ) {
         putchar ( ! ( x & mask ) ? '0': '1');
         x<<=1;
         if ( ! ( i % CHAR_BIT ) && i<n )
             putchar(' ');
    }
}
int main(void)
{
	short i;
    scanf("%d",&i);
    bit_prshort(i);
    return 0;
}

