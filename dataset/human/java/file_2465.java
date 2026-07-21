import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{
	static char flag[] = new char[]{'m', 'c', 'x', 'i'};
	static int num[] = new int[]{1000, 100, 10, 1};
	public static void main(String[] args)throws IOException{
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader reader = new BufferedReader(isr);
		Main app = new Main();
		
		int n = Integer.valueOf(reader.readLine());
		for(int i = 0; i < n; i++){
			System.out.println((app.change(app.sum(reader.readLine()))));
		}
		reader.close();
	}
	public int sum(String str){
		String s[] = str.split(" ");
		int res = 0, hoge = 1;
		char c;
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < s[i].length(); j++){
				c = s[i].charAt(j);
				if('2' <= c && c <= '9'){
					hoge = c - '0';
					continue;
				}else{
					res += hoge * set(c);
				}
				hoge = 1;
			}
		}
		return res;
	}
	public String change(int n){
		String res = "";
		int hoge = 0;
		for(int i = 0; i < 4; i++){
			while(n >= num[i]){
				n -= num[i];
				hoge++;
			}
			if(hoge == 1){
				res += flag[i];
			}else if(hoge != 0){
				res += String.valueOf(hoge) + flag[i];
			}
			hoge = 0;
		}
		return res;
	}
	public int set(char c){
		switch(c){
		case 'm' : return 1000;
		case 'c' : return 100;
		case 'x' : return 10;
		case 'i' : return 1;
		}
		return 0;
	}
}
