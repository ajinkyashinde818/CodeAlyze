import std.algorithm,
       std.string,
       std.array,
       std.range,
       std.stdio,
       std.conv;

void main() {
  int[] nm = readln.chomp.split.to!(int[]);
  int n = nm[0],
      m = nm[1];
  int[][] routes;
  routes.length = n + 1;

  foreach (i; m.iota) {
    int[] ab = readln.chomp.split.to!(int[]);
    int ta = ab[0],
        tb = ab[1];

    routes[tb] ~= ta;
  }

  bool flag;


  foreach (route1; routes[n]) {
    foreach (route; routes[route1]) {
      if (route == 1) {
        flag = true;
        break;
      }
    }
    if (flag) break;
  }

  writeln(flag ? "POSSIBLE" : "IMPOSSIBLE");
}
