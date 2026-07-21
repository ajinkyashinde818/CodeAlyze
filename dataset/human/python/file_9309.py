import std.stdio, std.conv, std.string, std.algorithm,
       std.math, std.array, std.container, std.typecons;

long n, k;
long[] a;
long[long] nth;

long next(long x) {
  return a[x-1];
}

void main() {
  readf("%d %d\n", &n, &k);
  a = readln.chomp.split.to!(long[]);
  long i=1;
  long c=0;
  while(nth.get(i,0)==0 && k>0) {
    nth[i] = c++;
    i = i.next;
    k--;
  }
  if(k==0) {
    writeln(i);
    return;
  }
  long looplen = c - nth[i];
  long z = k%looplen;
  for(long l=0; l<z; l++) {
    i = i.next;
  }
  i.writeln;
}
