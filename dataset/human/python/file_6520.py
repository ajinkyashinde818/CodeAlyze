import std.stdio, std.conv, std.string, std.algorithm, std.math, std.array, std.container;

string s;
int q;

void main() {
  s = readln.chomp;
  readf("%d\n", &q);
  bool reversed = false;
  string l = "";
  string r = "";
  for(int i=0; i<q; i++) {
    string query = readln.chomp;
    if(query[0] == '1') reversed = !reversed;
    else {
      bool add_head = query[2]=='1';
      if(reversed) {
        if(add_head) r = r ~ query[4];
        else l = query[4] ~ l;
      }
      else {
        if(add_head) l = query[4] ~ l;
        else r = r ~ query[4];
      }
    }
  }
  if(reversed) {
    char[] s2 = s.dup;
    char[] l2 = l.dup;
    char[] r2 = r.dup;
    std.algorithm.reverse(s2);
    std.algorithm.reverse(l2);
    std.algorithm.reverse(r2);
    writeln(r2 ~ s2 ~ l2);
  }
  else {
    writeln(l ~ s ~ r);
  }
}
