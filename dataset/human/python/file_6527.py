import std.stdio, std.array, std.string, std.conv, std.algorithm;
import std.typecons, std.range, std.random, std.math, std.container;
import std.numeric, std.bigint, core.bitop, core.stdc.stdio;

void main() {
    auto S = readln.chomp;
    auto Q = readln.chomp.to!int;

    DList!dchar que;
    foreach (s; S) que.insertBack(s.to!dchar);
    bool flag = false;

    while (Q--) {
        auto s = readln.split;
        if (s[0] == "1") {
            flag ^= 1;
        } else {
            auto f = s[1].to!int;
            auto c = s[2].to!dchar;
            if ((f == 1 && !flag) || (f == 2 && flag)) {
                que.insertFront(c);
            } else {
                que.insertBack(c);
            }
        }
    }

    dchar[] ans;

    if (!flag) foreach (s; que) ans ~= s;
    else foreach_reverse (s; que) ans ~= s;

    ans.writeln;
}
