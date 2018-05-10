#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
	FILE *fp;
	char  ch[10000] = { 0 };
	int word_count=0;
	int i=0,state=0;
	fopen_s(&fp,"input.txt", "r");
	if (fp == NULL) exit(1);
	
	for (int j = 0; j < 5; j++) {
		
		fgets(ch, sizeof(ch), fp);
		
		while (ch[i] != '\0') {
			if (isalpha(ch[i])) {
				if (state == 0) {
					++word_count;
					state = 1;
				}
			}
			else if (ch[i] == ' ') state = 0;

			i++;
		}
		printf("%s",ch);
		printf("\tThe number of word = %d\n", word_count);
		word_count = 0;
		i = 0;
		state = 0;
	}
		fclose(fp);
	
}