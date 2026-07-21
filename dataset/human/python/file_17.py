import std.stdio;
import std.algorithm;
import std.math;
import std.conv;
import std.string;

int readInt(){
  return readln.chomp.to!int;
}

int[] readInts(){
  return readln.chomp.split.to!(int[]);
}

void main(){
  int[] balls = readInts();
  int ret;

  for(int i; i <= balls[3] / balls[0]; i++){
    for(int j; j <= balls[3] / balls[1]; j++){
      int req = balls[3] - (balls[0] * i + balls[1] * j);
      if(req >= 0 && req % balls[2] == 0) ret++;
    }
  }

  writeln(ret);
}
