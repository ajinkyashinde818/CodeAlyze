import std.stdio;
import std.string;
import std.conv;
import std.algorithm;
import std.math;
import std.bigint;

void main(){
  auto qty = readInt();
  auto num = readLongs();
  
  ulong negative = num.count!("a < 0");
  bool zero = num.find(0).length ? true : false;
  
  auto pnum = num.map!(a => abs(a));
  
  auto ret = pnum.sum;
  if(!zero && negative % 2 == 1) ret -= 2 * pnum.minPos.front;
  
  writeln(ret);
}

int readInt(){
  return readln.chomp.to!int;
}

long[] readLongs(){
  return readln.chomp.split.to!(long[]);
}
