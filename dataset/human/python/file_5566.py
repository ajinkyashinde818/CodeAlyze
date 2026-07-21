void main(){
  import std.stdio, std.string, std.conv, std.algorithm;
  import std.math;
  
  auto s=readln.chomp.to!(char[]);

  char[] t;
  foreach(c; s)if(c!='x') t~=c;
  bool ok=true;
  foreach(i; 0..(t.length/2)) ok&=(t[i]==t[$-i-1]);
  if(!ok){writeln(-1); return;}

  int cnt=0;
  int[] y;
  foreach(c; s){
    if(c=='x') cnt++;
    else y~=cnt, cnt=0;
  }
  y~=cnt;
  int sum=0;
  foreach(i; 0..(y.length/2)) sum+=(y[i]-y[$-i-1]).abs;
  writeln(sum);
}

void rd(T...)(ref T x){
  import std.stdio, std.string, std.conv;
  auto l=readln.split;
  foreach(i, ref e; x){
    e=l[i].to!(typeof(e));
  }
}
