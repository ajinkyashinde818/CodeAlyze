import java.util.*;
import java.math.*;
import java.text.*;

public class Main {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		for(int i=0; i<n; i++){
			int a = trans(in.next());
			int b = trans(in.next());
			int c = a+b;
			output(c);
		}
	}
	
	public static int trans(String str){
		char[] ch = str.toCharArray();
		int flag = 0;
		int num = 0;
		for(int i=0; i<str.length(); i++){
			String tmp = String.valueOf(ch[i]);
			if(tmp.equals("m")){
				if(flag == 0) num = num+1000;
				else num = num+flag*1000;
				flag = 0;
			}
			else if(tmp.equals("c")){
				if(flag == 0) num = num+100;
				else num = num+flag*100;
				flag = 0;
			}
			else if(tmp.equals("x")){
				if(flag == 0) num = num+10;
				else num = num+flag*10;
				flag = 0;
			}
			else if(tmp.equals("i")){
				if(flag == 0) num = num+1;
				else num = num+flag;
				flag = 0;
			}
			else{
				flag = Integer.valueOf(tmp);
			}
		}
		return num;
	}
	
	public static void output(int c){
		int d1,d2,d3,d4;
		d1 = c/1000;
		c = c-d1*1000;
		d2 = c/100;
		c = c-d2*100;
		d3 = c/10;
		d4 = c-d3*10;
		if(d1==1){
			System.out.print("m");
		}else if(d1>1){
			System.out.print(d1+"m");
		}
		if(d2==1){
			System.out.print("c");
		}else if(d2>1){
			System.out.print(d2+"c");
		}
		if(d3==1){
			System.out.print("x");
		}else if(d3>1){
			System.out.print(d3+"x");
		}
		if(d4==1){
			System.out.print("i");
		}else if(d4>1){
			System.out.print(d4+"i");
		}
		System.out.println();
	}
}
