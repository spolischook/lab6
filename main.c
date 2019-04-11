/*
Target MCU: ATmega8515
Target device: OpenSys EV8031
*/

F_CPU = 1000000;


#include <avr/io.h>
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>

#define PORT_ZUMMER PORTB
#define ZUMMER PB6

typedef unsigned char byte;

unsigned int k=0;

void playNote(uint16_t period, uint16_t duration, int bpm, int temp)
{
    uint16_t taktTime = 60000 / bpm;
    uint16_t noteTime = taktTime / duration;
    int periodCount = (noteTime * 1000) / (period * 2);

    _delay_us(period);
    PORT_ZUMMER &= ~_BV(ZUMMER);
    _delay_us(period);
    PORT_ZUMMER |= _BV(ZUMMER);
    if(++k >= periodCount)
    {
        k=0;
        for(byte i=0; i<70; i++) _delay_ms(10);
    }

}

int main(void)
{
    DDRB = _BV(PB6);
    PORTB = 0xFF;
    int n = 0;

    uint16_t notePer[] = {
            1908, // C4
            1805, // C4#
            1701, // D4
            1608, // D4#
            1515, // E4
            1429, // F4
            1351, // F4#
            1275, // G4
            1205, // G4#
            1136, // A4
            1073, // A4#
            1012, // B4
            956   // C5
    };

    for(;;)
    {
        playNote(1805, 2, 80, 2);
    }
    return 0;
}