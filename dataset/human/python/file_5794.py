import std.stdio;
import std.algorithm;
import std.math;
import std.conv;
import std.string;

T readNum(T)(){
  return readStr.to!T;
}

T[] readNums(T)(){
  return readStr.split.to!(T[]);
}

string readStr(){
  return readln.chomp;
}

void main(){
  auto n = readNum!int;
  auto a = readNums!int;
  auto b = readNums!int;
  auto c = readNums!int;

  int prev, ret;
  foreach(i; 0 .. n){
    ret += b[a[i]-1];
    if(i != 0 && a[i] == prev+1) ret += c[a[i]-2];
    prev = a[i];
  }

  writeln(ret);
}
