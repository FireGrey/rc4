#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
	// Initialising Key

	uint8_t key[16] = {0x09, 0x8F, 0x6B, 0xCD, 0x46, 0x21, 0xD3, 0x73, 0xCA, 0xDE, 0x4E, 0x83, 0x26, 0x27, 0xB4, 0xF6};

	int keylength = 16;

	// Initialising Message

	uint8_t message[41] = {0x8E, 0xBB, 0x63, 0x13, 0xE8, 0xEA, 0x01, 0xC2, 0xF0, 0xF3, 0x81, 0xE5, 0x07, 0x1C, 0xB6, 0x63, 0xB3, 0x7E, 0x26, 0x5A, 0x86, 0x25, 0x82, 0x98, 0x86, 0xEA, 0x19, 0x09, 0xE6, 0xB9, 0x5A, 0x22, 0x65, 0xB7, 0xB4, 0xF8, 0x61, 0x16, 0x9D, 0xC7, 0x4A};

	int messagelength = 41;

	// ----- Key Scheduling Algorithm -----
	
	// Initialising S
	
	uint8_t S[255];

	for(int i=0; i<256; i++)
		S[i] = i;
	
	// Key Scheduling	

	for(int i=0, j=0; i<256; i++)
	{
		j = (j + S[i] + key[i % keylength]) % 256;
		uint8_t temp = S[i];
		S[i] = S[j];
		S[j] = temp;
	}
	
	// ----- Pseudo-Random Generation Algorithm -----
	
	// Initialising Keystream Variable

	uint8_t K[messagelength];
	
	//Generating Keystream

	for(int i=0, j=0, count=0; count < messagelength; count++)
	{
		i = (i + 1) % 256;
		j = (j + S[i]) % 256;
		uint8_t temp = S[i];
		S[i] = S[j];
		S[j] = temp;
 		K[count] = S[(S[i] + S[j]) % 256];

		//Printing Ciphertext/Plaintext

 		printf("%c", K[count]^message[count]);
	}
}
