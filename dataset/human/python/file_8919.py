void main()
{
    dchar[] s = readln.chomp.to!(dchar[]);

    reverse(s);
    string[] words = ["dream", "dreamer", "erase", "eraser"];
    dchar[][] rev = new dchar[][](4);
    foreach (i, x; words)
    {
        rev[i] = x.to!(dchar[]);
        reverse(rev[i]);
    }

    long index;
    bool ok = true;
    while (index < s.length)
    {
        bool check;
        foreach (x; rev)
        {
            long len = x.length;
            if (index + len > s.length) continue;

            if (s[index..index+len] == x)
            {
                check = true;
                index += len;
                break;
            }
        }

        if (!check)
        {
            ok = false;
            break;
        }
    }

    writeln(ok ? "YES" : "NO");
}

import std.stdio;
import std.string;
import std.array;
import std.conv;
import std.algorithm;
import std.range;
import std.math;
import std.numeric;
import std.container;
import std.typecons;
import std.ascii;
import std.uni;
