import std.stdio;
import std.string;
import std.range;
import std.conv;

void main()
{
	auto S = readln.chomp;
    switch(S) {
    	case "abc", "acb", "bac", "bca", "cab", "cba":
    		"Yes".writeln;
    		break;
    	default:
    		"No".writeln;
    		break;
    }
}
