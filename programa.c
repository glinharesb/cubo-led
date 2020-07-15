#include <16F627A.h>    // biblioteca para o PIC 16F627A
#include <stdlib.h>     // biblioteca para utilizar a função rand

/* configuração do PIC
    * NOWDT:        temporizador watchdog desativado
    * INTRC_IO:     oscilador interno, não utiliza cristal ligado externamente e habilita 
    *               os pinos OSC1 e OSC2 para serem utilizados como pinos de entrada e saída
    * NOPUT:        temporizador de power up desativado
    * NOPROTECT:    proteção de código desativado
    * NOBROWNOUT:   reset por queda de tensão desativado
    * NOLVP:        programação em baixa tensão desativado
    * NOCPD:        proteção da EEPROM desativado
*/
#fuses NOWDT, INTRC_IO, NOPUT, NOPROTECT, NOBROWNOUT, NOLVP, NOCPD
#use delay(clock = 4000000) // PIC irá trabalhar na frequência de 4 MHz

/*  --[[Ordem dos pinos]]--
    -----------------------
    -----|A6|B3|B6|A2|-----
    -----|A3|A5|B0|A1|-----
    -----|B4|B7|A3|A0|-----
    -----|B5|B2|B1|A7|-----
    -----------------------
*/

#define DELAY 100				// 100 milissegundos
#define _DELAY rand() % 350     // 0 até 350 milissegundos aleatóriamente

void desliga() {
    output_a(0x00);     // desativa todos os pinos do PORTA
    output_b(0x00);     // desativa todos os pinos do PORTB
    delay_ms(DELAY);    // intervalo
}

void liga_desliga() {   		// liga e desliga os pinos de 0 até 10 vezes aleatóriamente
    int limite = rand() % 10;	// resulta em um número de 0 até 10 aleatóriamente
    int i = 0;
    while(i <= limite) {
        desliga();

        output_a(0xFF); // ativa todos os pinos do PORTA
        output_b(0xFF); // ativa todos os pinos do PORTB
        delay_ms(DELAY);

        desliga();

        i++;
    }
}

void main() {
    set_tris_a(0x00);   // ativa todos os pinos do TRISA
    set_tris_b(0x00);   // ativa todos os pinos do TRISB
    while(TRUE) {
        liga_desliga();

        // primeira sequência
        output_bit(PIN_A6, TRUE);   // liga o pino A6
        output_bit(PIN_A2, TRUE);
        output_bit(PIN_B5, TRUE);
        output_bit(PIN_A7, TRUE);
        delay_ms(_DELAY);

        liga_desliga();
 
        // segunda sequência
        output_bit(PIN_B7, TRUE);
        output_bit(PIN_B0, TRUE);
        delay_ms(_DELAY);
        output_bit(PIN_B3, TRUE);
        output_bit(PIN_B1, TRUE);
        delay_ms(_DELAY);
        output_bit(PIN_A1, TRUE);
        output_bit(PIN_B2, TRUE);
        delay_ms(_DELAY);
        output_bit(PIN_B2, TRUE);
        output_bit(PIN_B6, TRUE);
        delay_ms(_DELAY);
        output_bit(PIN_A6, TRUE);
        output_bit(PIN_A7, TRUE);
        delay_ms(_DELAY);
        output_bit(PIN_B5, TRUE);
        output_bit(PIN_A2, TRUE);
        delay_ms(_DELAY);
        output_bit(PIN_A3, TRUE);
        output_bit(PIN_A0, TRUE);
        delay_ms(_DELAY);
        output_bit(PIN_B2, TRUE);
        output_bit(PIN_B6, TRUE);
        output_bit(PIN_B4, TRUE);
        delay_ms(_DELAY);

        liga_desliga();

        // terceira sequência
        output_bit(PIN_B7, TRUE);
        output_bit(PIN_B0, TRUE);
        delay_ms(_DELAY);
        output_bit(PIN_A3, TRUE);
        output_bit(PIN_B4, TRUE);
        delay_ms(_DELAY);  
        output_bit(PIN_A1, TRUE);
        output_bit(PIN_A0, TRUE);
        delay_ms(_DELAY);
        output_bit(PIN_B3, TRUE);
        output_bit(PIN_B6, TRUE);
        delay_ms(_DELAY);
        output_bit(PIN_B2, TRUE);
        output_bit(PIN_B1, TRUE);
        delay_ms(_DELAY);
        output_bit(PIN_A6, TRUE);
        output_bit(PIN_A2, TRUE);
        delay_ms(_DELAY);
        output_bit(PIN_B5, TRUE);
        output_bit(PIN_A7, TRUE);
        delay_ms(_DELAY);
    }
}
