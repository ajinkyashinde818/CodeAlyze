#include <stdio.h>

int main(int argc, char **argv)
{
	char str[10];
	memset( str,'\0',sizeof(str));
    int cnt=0;
  	fgets(  str,sizeof(str),stdin );
    for( int i=0; i<2; i++ )
    {
      if( *(str+i)=='9' )
      {
        cnt++;
      }
    }
    printf("%s\n",(cnt>0 ? "Yes" : "No"));
    fflush( stdout );
}
