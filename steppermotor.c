#include <reg51.h>

void delay(unsigned int time) {
    unsigned int i;
    TMOD = 0x10;      // Set Timer 1 in Mode 1 (16-bit timer mode)
    
    for(i = 0; i < time; i++) {
        TH1 = 0xFF;   // Load TH1 for delay
        TL1 = 0x49;   // Load TL1 for delay (adjust these values as needed)
        
        TR1 = 1;      // Start Timer 1
        while (TF1 == 0);  // Wait for Timer 1 overflow
        TR1 = 0;      // Stop Timer 1
        TF1 = 0;      // Clear overflow flag
    }
}

void main() {
    while(1) {
        P0 = 0x09;    // Step 1
        delay(100);
        
        P0 = 0x0A;    // Step 2
        delay(100);
        
        P0 = 0x06;    // Step 3
        delay(100);
        
        P0 = 0x05;    // Step 4
        delay(100);
    }
}
