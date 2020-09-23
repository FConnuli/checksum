#include <stdio.h>
#include <assert.h>
#include <stdint.h>

unsigned int crc16(int a1, unsigned int a2)
{
    unsigned int v2; // r2
    unsigned int i; // r3
 
    v2 = 0x1121; // This is the seed
    for ( i = 0; i < a2; i = (i + 1) & 0xFFFF )
        v2 = *(unsigned __int16 *)((char *)crc16_ccitt_table + (2 * (v2 ^ *(unsigned __int8 *)(a1 + i)) & 0x1FF)) ^ (v2 >> 8);
    return ~v2 & 0xFFFF;
}

/*reads the first 1000 bytes from stdin and outputs the checksum to stdout*/
int main(void)
{
	int c;
	char in[1000];
        uint16_t i;
	for (i = 0; i < 1000; i++)
	{
		c = getchar();
		/*printf("%X  %d \n", c, i);*/
		assert(c != EOF);
		in[i] = c;
	}
	/*fread(in, 1, 1000, stdin);*/
    /*for (uint16_t i = 0; i < 1000; i++)
	{
		printf("%X  %d \n", in[i], i);
	}*/
	printf("%X\n", crc16(in, 1000));
	return 0;
}
