import std.stdio;
import std.conv;
import std.string;

void main()
{
    int[] input = readln.split.to!(int[]);
    int k = input[0];
    int s = input[1];
    long ans = 0;

    foreach_reverse (i; 0..k + 1) {
        foreach_reverse (j; 0..k + 1) {
            auto tmp = s - i - j;
            if (tmp <= k && tmp >= 0){
                ans++;
            }
        }
    }

    writeln(ans);
}
