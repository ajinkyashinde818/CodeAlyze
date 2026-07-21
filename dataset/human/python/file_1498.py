import std.stdio, std.string, std.array, std.conv, std.algorithm, std.typecons, std.range, std.container, std.math, std.algorithm.searching, std.functional,std.mathspecial;

void main(){
    auto mn=readln.split.map!(to!int).array;
    auto m=mn[0];
    auto n=mn[1];
    string[] as;
    string[] bs;
    foreach(i;0..m)as~=readln.chomp;
    foreach(i;0..n)bs~=readln.chomp;
    foreach(x;0..(m-n+1))
    outer:foreach(y;0..(m-n+1)){
        foreach(dx;0..n)
            foreach(dy;0..n){
                if(as[x+dx][y+dy]!=bs[dx][dy])continue outer;
            }
        writeln("Yes");
        return;
    }
        writeln("No");
        return;
}
