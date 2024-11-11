#include <reg51.h>

void delay()
{
    int i;
    for(i = 0; i < 100; i++);
}

void main()
{
    int count;

    while (1)
    {
        for(count = 0x00; count < 0xff; count++)
        {
            P0 = count;
            delay();
        }

        for(count = 0xff; count > 0x00; count--)
        {
            P0 = count;
            delay();
        }
    }
}
