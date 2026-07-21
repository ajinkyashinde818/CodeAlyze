void main(){
  import std.stdio, std.string, std.conv, std.algorithm;

  string n; rd(n);
  
  if(n[0]=='9' || n[1]=='9') writeln("Yes");
  else writeln("No");

}

void rd(T...)(ref T x){
  import std.stdio, std.string, std.conv;
  auto l=readln.split;
  foreach(i, ref e; x){
    e=l[i].to!(typeof(e));
  }
}
