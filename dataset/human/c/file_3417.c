#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	static char S[100032];
	char *p = S;
	fgets(S, sizeof(S), stdin);

	while ( *p != '\0' && *p != '\n' ){
		if ( strncmp(p, "erase", 5) == 0 ){
			if ( *(p+5) == 'r' ){
				p += 6;
			} else if ( *(p+5) == 'd' || *(p+5) == 'e' ){
				p += 5;
			} else if ( *(p+5) == '\n' ){
				break;
			} else {
				printf("NO\n");
				return 0;
			}
		} else if ( strncmp(p, "dream", 5) == 0 ){
			if ( *(p+5) == 'd' ){
				p += 5;
			} else if ( *(p+5) == 'e' ){
				if ( strncmp(p+5, "erase", 5) == 0 ){
					p += 5;
				} else if ( *(p+6) == 'r' ){
					p += 7;
				} else {
					printf("NO\n");
					return 0;
				}
			} else if ( *(p+5) == '\n' ){
				break;
			} else {
				printf("NO\n");
				return 0;
			}
		} else {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
