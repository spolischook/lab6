/*
Target MCU: ATmega8515
Target device: OpenSys EV8031
*/
#include <avr/io.h>
#define __DELAY_BACKWARD_COMPATIBLE__
//#define F_CPU 100000UL
#include <util/delay.h>

#define PORT_ZUMMER PORTB
#define ZUMMER PB6

typedef unsigned char byte;

void wait(int time) {
    unsigned int k = 0;
    if (++k < time) {
        for (byte i = 0; i < 70; i++) _delay_ms(10);
    }
}

void playNote(float note, byte dur) {
    unsigned int k = 0;
    if (!note) {
        for(k=0; k < dur*50; k++)
        {
            _delay_ms(1);
        }
        return;
    }
    for(k=0; k < dur*50/note; k++)
    {
        _delay_ms(note);
        PORT_ZUMMER &= ~_BV(ZUMMER);
        _delay_ms(note);
        PORT_ZUMMER |= _BV(ZUMMER);
    }
    _delay_ms(10);
}

int main(void) {
    DDRB = _BV(PB6);
    float C = 1.915; // 500/261;
    float Cs = 500 / 277;
    float D = 1.7; // 500/294;
    float Ds = 500 / 311;
    float E = 1.515; // 500/330;
    float F = 1.463; // 500/349;
    float Fs = 1.351; // 500 / 370;
    float G = 1.275; // 500 / 392;
    float Gs = 1.205; // 500 / 415;
    float A = 1.136; // 500 / 440;
    float As = 1.073; // 500 / 466;
    float B = 1.012; // 500 / 494;
    float C2 = 0.956; // 500 / 523;
    float C2s = 0.903; // 500 / 554;
    float D2 = 0.852; // 500 / 587;
    float D2s = 0.804; // 500 / 622;
    float E2 = 0.759; // 500 / 659;
    float F2 = 0.716; // 500 / 698;
    float F2s = 0.676; // 500 / 740;
    float G2 = 0.638; // 500 / 784;
    float G2s = 0.602; // 500 / 830;
    float A2 = 0.568; // 500 / 880;
    float A2s = 0.536; // 500 / 932;
    float B2 = 0.506; // 500 / 988;
    float C3 = 0.478; // 500 / 1047;
    float duration = 100;

    PORTB = 0xFF;
    float delay;
    unsigned int k = 0;
    for (;;) {

        // V lesu rodilas` elechka
//        float music[28] = {C, A, A, G, A, F, C, C, C, A, A, As, G, C2, C2, D, D, As, As, A, G, F, F, A, A, G, A, F};
//        byte musiD[28] =  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1, 1,  3,  1, 1, 1,  1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 4};

        // Trava u doma
        float music[47] = {E2,G2,A2,0,G2,A2,G2,E2,E2,0,A,C2,D2,0,B,G,E,A,A,0,E2,G2,A2,0,G2,A2,G2,C3,A2,0,A,C2,D2,0,B,G,E,A,A,0,E,A,B,C2,E2,E2,0};
        byte musiD[47]  = { 1, 1, 4,5, 1, 1, 1, 1, 5,5,1, 1, 4,5,1,1,1,1,5,5, 1, 1, 4,5, 1, 1, 1, 1, 5,5,1, 1, 4,5,1,1,1,1,5,8,1,1,1, 1, 1, 1,15};

        for (int j = 0; j <= 46; j++) {
            playNote(music[j], musiD[j]);
        }
    }
}
