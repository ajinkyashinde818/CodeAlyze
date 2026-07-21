import std.algorithm;
import std.array;
import std.ascii;
import std.container;
import std.conv;
import std.format;
import std.math;
import std.range;
import std.stdio;
import std.string;
import std.typecons;

bool is_parindrome(string s)
{
  ulong len = s.length;
  for (int i = 0; i < len / 2; ++i) {
    if (s[i] != s[len - 1 - i]) {
      return false;
    }
  }
  return true;
}

void main()
{
  string str = readln.chomp;
  string dst = "";
  int[] index;
  foreach (int i, c; str) {
    if (c == 'x') {
      continue;
    }
    dst ~= c;
    index ~= i;
  }
  if (!dst.is_parindrome) {
    writeln = -1;
    return;
  }
  if (dst.length == 0) {
    writeln = 0;
    return;
  }
  int right;
  int left;
  if (dst.length % 2 == 1) {
    right = index[dst.length / 2] + 1;
    left = index[dst.length / 2] - 1;
  } else {
    right = index[dst.length / 2];
    left = index[dst.length / 2 - 1];
  }
  // stderr.writeln(left, " ", right);
  int cnt = 0;
  while (0 <= left && right < str.length) {
    if (str[left] == str[right]) {
      --left;
      ++right;
      continue;
    }
    if (str[left] == 'x') {
      ++cnt;
      --left;
    }
    else if (str[right] == 'x') {
      ++cnt;
      ++right;
    }
    else {
      writeln = -1;
      return;
    }
  }
  cnt += left + 1 + str.length - right;
  bool dame = false;
  for (; 0 <= left; --left) {
    dame |= str[left] != 'x';
  }
  for (; right < str.length; ++right) {
    dame |= str[right] != 'x';
  }
  if (dame) {
    writeln = -1;
    return;
  }
  cnt.writeln;
}
