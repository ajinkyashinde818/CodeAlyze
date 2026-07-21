void main(){
  import std.stdio, std.string, std.conv, std.algorithm;

  auto s=readln.chomp.to!(char[]);

  writeln(s[0..($-8)]);
}


void rd(T...)(ref T x){
  import std.stdio, std.string, std.conv;
  auto l=readln.split;
  foreach(i, ref e; x){
    e=l[i].to!(typeof(e));
  }
}
