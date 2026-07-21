#include <stdio.h>
#include <string.h>


int main(void) {

	char str[100000];
	int flag = 0;
	int size;
	int i;
	int count = 0;
	int judge = 0;
	char tmp;
	char* adr;

	scanf("%s", str);

	size = strlen(str);

	
	for ( i = 0; i < size / 2; i++)
	{
		tmp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = tmp;
	}
	

	do
	{
		adr = strstr(str, "remaerd"); 
		if (adr && (adr - str) == count) 
        {
			strncpy(adr, "0000000", 7);
			count += 7; 
			judge = count;
			continue;
		}

		adr = strstr(str, "resare");
		if (adr && (adr - str) == count)
		{
			strncpy(adr, "000000", 6);
			count += 6;
			judge = count;
			continue;
		}

		adr = strstr(str, "maerd");
		if (adr && (adr - str) == count)
		{
			strncpy(adr, "00000", 5);
			count += 5;
			judge = count;
			continue;
		}

		adr = strstr(str, "esare");
		if (adr && (adr - str) == count)
		{
			strncpy(adr, "00000", 5);
			count += 5;
			judge = count;
			continue;
		}

		if (judge == count) break;

	} while (adr);

	adr = str;

	for ( i = 0; i < size; i++)
	{
		if (*adr != 48) {
			flag = 1;
			break;
		}
		adr++;
	}
	

	if (flag) printf("NO");
	else printf("YES");


	return 0;

}
