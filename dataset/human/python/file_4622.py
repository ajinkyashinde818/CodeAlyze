import std.stdio;
import std.string;
import std.algorithm;
import std.range;
import std.array;
import std.conv;


ubyte toNum(dchar e)
{
    if('a' <= e && e <= 'z')
        return cast(ubyte)(e - 'a');
    else
        return cast(ubyte)(e - 'A' + 26);
}

char toChar(ubyte u)
{
    if(u < 26)
        return cast(char)('a' + u);
    else
        return cast(char)('A' + u - 26);
}


void main()
{
    while(1){
        uint N = readln().chomp().to!uint;
        if(N == 0)
            break;

        auto kc = array(readln().chomp().split().map!(to!uint)).cycle;
        auto st = array(readln().chomp().map!toNum);
        foreach(i, ubyte e; st){
            e = (e + 52 - kc[i]) % 52;
            write(toChar(e));
        }

        writeln();
    }
}
