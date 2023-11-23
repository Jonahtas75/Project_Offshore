#include <avr/io.h>
#include <util/delay.h>

#define INPUT_KNOP_X PF1
#define INPUT_KNOP_Y PF2
#define SEND_KNOP PF3

int x = 0;
int y = 0;
int xButtonPressed = 0;
int yButtonPressed = 0;

void send_Coords()
{
    for (int i = x; i > 0; i--) //geeft de coordinaten weer doormiddel van aantal lichtsignaaltjes
    {
        PORTB &= ~(1 << PB7);
        _delay_ms(500);
        PORTB |= (1 << PB7);
        _delay_ms(500);
    }
    for (int i = y; i > 0; i--)
    {
        PORTB &= ~(1 << PB6);
        _delay_ms(500);
        PORTB |= (1 << PB6);
        _delay_ms(500);
    }

    x = 0; //reset de coordinaten
    y = 0;
}

int main(void)
{
    DDRB |= (1 << PB7) | (1 << PB6);
    PORTB = 0b11111111;

    while (1)
    {
        if ((PINF & (1 << INPUT_KNOP_X)) == 0)
        {
            if (!xButtonPressed)
            {
                PORTB &= ~(1 << PB7);
                x++;
                if (x > 10)
                {
                    x = 0;
                }
                xButtonPressed = 1;
            }
        }
        else
        {
            PORTB |= (1 << PB7);
            xButtonPressed = 0;
        }

        if ((PINF & (1 << INPUT_KNOP_Y)) == 0)
        {
            if (!yButtonPressed)
            {
                PORTB &= ~(1 << PB6);
                y++;
                if (y > 10)
                {
                    y = 0;
                }
                yButtonPressed = 1;
            }
        }
        else
        {
            PORTB |= (1 << PB6);
            yButtonPressed = 0;
        }

        if ((PINF & (1 << SEND_KNOP)) == 0)
        {
            send_Coords();
        }
    }

    return 0;
}
