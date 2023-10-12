#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char flag[0x20];

char *gets(char *s);

void setup()
{
	FILE *f = NULL;

	alarm(60);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	f = fopen("flag2.txt", "rt");
	if (f==NULL){
		printf("Failed to read flag2.txt\n");
		exit(0);
	}

	fscanf(f, "%s", flag);
	fclose(f);
}

void vuln(char *str)
{
	char str2[] = "kanazawa";
	char overflowme[16];
	printf("input:");
	scanf("%s", overflowme);
	if (strcmp(str, str2) == 0){
		printf("Hacked!\n");
		printf("The flag is: %s\n", flag);
	}else{
		printf("failed!\n");
	}
}

int main()
{
	setup();

	char string[] = "festival";
	vuln(string);
}

