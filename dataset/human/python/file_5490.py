import std.stdio;
import std.conv;
import std.string;
import std.algorithm;
import std.range;
 
void main()
{
    auto input = readln.split;
    auto X = input[0];
    auto Y = input[1];

    (X < Y ? "<" : X > Y ? ">" : "=").writeln;
}
