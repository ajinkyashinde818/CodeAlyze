import std.stdio;
import std.conv;
import std.string;
import std.range;
import std.algorithm;

void main(){
    foreach(i; 0..readln().chomp().to!int()){
        auto input = readln().split();
        (input[0].decode() + input[1].decode()).encode().writeln();
    }
}

int decode(string input){
    int res;
    int qual = 1;
    foreach(c; input){
        switch(c){
            case 'm':
                res += qual * 1000;
                qual = 1;
                break;
            case 'c':
                res += qual * 100;
                qual = 1;
                break;
            case 'x':
                res += qual * 10;
                qual = 1;
                break;
            case 'i':
                res += qual;
                qual = 1;
                break;
            case '2': .. case '9':
                qual = c - '0';
            default:
        }
    }
    return res;
}

unittest{
    assert(decode("m2c4i") == 1204);
    assert(decode("5m2c3x4i") == 5234);
    assert(decode("5m2c3x") == 5230);
}

auto keta = ['m', 'c', 'x', 'i'];

string encode(int input){
    string res;
    foreach(i; 0..4){
        int qual = input / 10 ^^ (3 - i);
        input -= qual * 10 ^^ (3 - i);
        if(qual > 1){
            res ~= text(qual, keta[i]);
        }else if(qual == 1){
            res ~= keta[i];
        }
    }
    return res;
}

unittest{
    assert(encode(5234) == "5m2c3x4i");
    assert(encode(1204) == "m2c4i");
    assert(encode(5230) == "5m2c3x");
}
