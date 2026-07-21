import std.stdio;
import std.algorithm;
import std.string;
import std.range;
import std.array;
import std.conv;
import std.complex;
import std.math;


void main() {
	auto n = to!int(readln().strip());
	while(n > 0){
		string[] s;
		for(int i; i < n; ++i){
			s ~= readln().chomp();
		}
		int[][] yoko = new int[][](n+1,n+1);
		int[][] tate = new int[][](n+1,n+1);
		int[][] square = new int[][](n+1,n+1);
		int maxSquare = 0;
		for(int i = n-1; i >= 0; --i) {
			for(int j = n-1; j >= 0; --j) {
				if(s[i][j] == '.') {
					yoko[i][j] = yoko[i][j+1]+1;
					tate[i][j] = tate[i+1][j]+1;
					square[i][j] = min(yoko[i][j],tate[i][j],square[i+1][j+1]+1);
					maxSquare = max(maxSquare, square[i][j]);
				}else{
					yoko[i][j] = 0;
					tate[i][j] = 0;
					square[i][j] = 0;
				}
			}
		}
		writeln(maxSquare);
		n = to!int(readln().strip());
	}
}
