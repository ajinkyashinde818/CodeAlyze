import std.stdio, std.ascii, std.conv, std.math, std.string;

uint strToUint(string str) {
  char[] chars = str.to!(char []);
  uint res = 0;
  foreach(i, c; chars) {
    uint n;
    if (isAlpha(c)) n = (c - 'a') + 10;
    else if (isDigit(c)) n = c - '0';
    res += n;
    if (i != 7) res <<= 4;
  }
  return res;
}

void show(uint n) {
  int integer = (n & 0x7FFFFFFF) >> 7;
  int dec = (n & 0x7F) * 78125;
  int len = 7;
  // 符号ビット
  if (((n >> 31) & 1) == 1) write("-");
  while (len > 1 && (dec % 10) == 0) {
    len--;
    dec /= 10;
  }
  writef("%d.%0*d\n", integer, len, dec);
}

void main() {
  for(int n; readf("%d\n", &n);) {
    foreach(t; 0..n) {
      readln.chomp.strToUint.show;
    }
  }
}
