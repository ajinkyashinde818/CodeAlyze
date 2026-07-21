void main() {
    int[] tmp = readln.split.to!(int[]);
    int n = tmp[0], m = tmp[1];
    string[] a = new string[n], b = new string[m];
    foreach (i; 0 .. n) {
        a[i] = readln.chomp;
    }
    foreach (i; 0 .. m) {
        b[i] = readln.chomp;
    }
    bool ok;
    foreach (i; 0 .. n-m+1) {
        foreach (j; 0 .. n-m+1) {
            bool check = true;
            foreach (k; 0 .. m) {
                if (a[j+k][i..i+m] != b[k]) {
                    check = false;
                }
            }
            if (check) ok = true;
        }
    }
    writeln(ok ? "Yes" : "No");
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
