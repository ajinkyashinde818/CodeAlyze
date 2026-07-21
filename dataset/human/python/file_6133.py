import std.stdio;
import std.array;
import std.conv;

void main(){
	string[] input = readln.split;
	int A = input[0].to!int;
	int B = input[1].to!int;
	int C = input[2].to!int;
	int cnt;
	while(C > 0){
		C--;
		cnt++;
		if(B > 0){
			B--;
			cnt++;
		}
		else if(A > 0){
			A--;
		}
		else{
			break;
		}
	}
	if(B > 0) cnt += B;
	write(cnt);
}
