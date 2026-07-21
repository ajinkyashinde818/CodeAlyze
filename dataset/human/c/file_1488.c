#include <stdio.h>
int main()
{char n,m,a,b;
scanf("%c %c",&n,&m);
{if(n=='A')
a=10;
else if(n=='B')
a=11;
else if(n=='C')
a=12;
else if(n=='D')
a=13;
else if(n=='E')
a=14;
else if(n=='F')
a=15;
}
{if(m=='A')
b=10;
else if(m=='B')
b=11;
else if(m=='C')
b=12;
else if(m=='D')
b=13;
else if(m=='E')
b=14;
else if(m=='F')
b=15;
}
if(a>b) printf(">\n");
else if(a==b) printf("=\n");
else if(a<b) printf("<\n");

return 0;	
}
