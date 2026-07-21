import std.stdio, std.conv, std.string, std.algorithm,
       std.math, std.array, std.container, std.typecons;

int solve() {
  auto s = readln.chomp;
  int i=0, j=(s.length-1).to!int;
  char x = 'x';
  int res = 0;
  while(i<j) {
    if(s[i]==x&&s[j]==x) { i++; j--; continue; }
    if(s[i]==x&&s[j]!=x) { i++; res++; continue; }
    if(s[i]!=x&&s[j]==x) { j--; res++; continue; }
    if(s[i]!=x&&s[j]!=x) {
      if(s[i]==s[j]) { i++; j--; continue; }
      else return -1;
    }
  }
  return res;
}

void main() {
  solve.writeln;
}
