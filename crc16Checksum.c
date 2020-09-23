#include <stdio.h>
#include <assert.h>
#include <stdint.h>


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
	printf("%X\n", compound_card_crc(in, 1000));
	return 0;
}
