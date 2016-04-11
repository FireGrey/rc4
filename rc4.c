#include <stdio.h>

int main(void) 
{
		

	// ----- Key Scheduling Algorithm -----
	
	// Initialising S
	
	for(i=0; i<256; i++)
		S[i] = i;
	
	// 
	
	for(i=0, j=0; i<256; i++)
	{
		j = (j + S[i] + key[i % keylength]) % 256;
		int temp = S[i];
		S[i] = S[j];
		S[j] = temp;
	}
	
	// ----- Pseudo-Random Generation Algorithm -----
	
	int i = 0;
	int j = 0;
	
	do
	{
		i = (i + 1) % 256;
		j = (j + S[i] % 256;
		int temp = S[i];
		S[i] = S[j];
		S[j] = temp;
		int keystream = S[S[i] + S[j] % 256];
	}
