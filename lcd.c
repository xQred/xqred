#include<reg51.h>
sbit rs=P1^0;
sbit rw=P1^1;
sbit e=P1^2;

void delay(unsigned int t)
{
	unsigned int i,j;
	for(i=0; i < t; i++)
	{
		for(j=0; j < 1275; j++);  // Inner loop for delay
	}
}

void cmd(unsigned char ch)
{
	rs = 0;
	rw = 0;
	P2 = ch;
	e = 1;
	delay(20);  // Increase delay if needed
	e = 0;
}

void dat(unsigned char ch)
{
	rs = 1;
	rw = 0;
	P2 = ch;
	e = 1;
	delay(20);  // Increase delay if needed
	e = 0;
}

void main()
{
	unsigned char ch[] = "ISQUAREIT";
	unsigned int i, k;

	cmd(0x38);  // Initialize LCD in 8-bit mode
	cmd(0x01);  // Clear display
	cmd(0x0C);  // Display ON, Cursor OFF
	cmd(0x83);  // Position cursor at column 3
	cmd(0x06);  // Move cursor right

	// Display the characters of "ISQUAREIT"
	for(i = 0; ch[i] != '\0'; i++)
	{
		dat(ch[i]);
	}

	cmd(0xC3);  // Move cursor to next line for scrolling text

	// Loop for scrolling text with added delay for slower scrolling
	while(1)
	{
		for(k = 0; k < 16; k++)
		{
			cmd(0x1C);   // Command for shifting display
			delay(100);  // Additional delay for slower scrolling
		}
	}
}
