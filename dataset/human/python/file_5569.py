import std.stdio;
import std.conv;
import std.string;
import std.typecons;
import std.algorithm;
import std.array;
import std.range;
import std.math;
import std.regex : regex;
import std.container;
import std.bigint;


void main()
{
  auto s = readln.chomp.to!(char[]).array;
  int i, res;
  i = res = 0;
  while (i != s.length / 2) {
    //writeln(i);
    if (s[i] != s[$-i-1]) {
      if (s[i] == 'x') {
        s.insertInPlace(s.length-i, 'x');
      } else if (s[$-i-1] == 'x') {
        s.insertInPlace(i, 'x');
      } else {
        res = -1;
        break;
      }
      res++;
    } 
   /*s.writeln;
   readln();*/
   i++; 
  }
  res.writeln;
}
