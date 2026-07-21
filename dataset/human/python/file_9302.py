import std.stdio;
import std.algorithm;
import std.math;
import std.conv;
import std.string;
import std.bigint;

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
  auto nk = readNums!long;
  auto a = readNums!int;

  auto visited = new int[](cast(int)nk[0]);

  int now = 1, count = 1;
  int loop_count;
  visited[0] = 1;
  while(true){
    count++;
    now = a[now-1];
    if(visited[now-1] > 0){
      loop_count = count - visited[now-1];
      break;
    } else {
      visited[now-1] = count;
    }
  }

  long move = (nk[1] - visited[now-1] + 1) % loop_count;
  if(nk[1] - visited[now-1] + 1 <= 0){
    move = nk[1];
    now = 1;
  }

  foreach(i; 0 .. move){
    now = a[now-1];
  }

  writeln(now);
}
