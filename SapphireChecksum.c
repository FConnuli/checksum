#include <stdio.h>
#include <assert.h>
#include <stdint.h>

/*pokemon sapphire checksum function*/
uint16_t compound_card_crc(const char * data, uint16_t len)
{
	uint16_t x = 0x1121;
	for(uint16_t i = 0; i < len; ++i)
	{
		x ^= data[i];
		for (uint16_t j = 0; j < 8; ++j)
		{
			if (x & 1)
				x = (x >> 1) ^ 0x8408;
			else
				x >>= 1;
		}
	}
	return ~x;
}

/*reads the first 1000 bytes from stdin and outputs the checksum to stdout*/
int main(void) 
{
	int c;
	char in[1000]; 
	for (uint16_t i = 0; i < 1000; i++)
	{
		c = getchar();
		printf("%X  %d \n", c, i);
		assert(c != EOF);
		in[i] = c;
	}
	/*fread(in, 1, 1000, stdin);*/
    /*for (uint16_t i = 0; i < 1000; i++)
	{
		printf("%X  %d \n", in[i], i);
	}*/
	printf("%X", compound_card_crc(in, 1000));
	return 0;
}