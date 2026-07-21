import java.util.*;
import java.lang.*;
import java.math.*;

public class Main {
	Scanner sc = new Scanner(System.in);
	
	class MCXI{
		int value;
		MCXI(String str){
			char[] ch = str.toCharArray();
			int digit=1;
			int ptr =0;
			value = 0;
			for(;;){
				if(ptr >= ch.length){
					break;
				}
				if(ch[ptr] == 'm'){
					value += digit*1000;
					digit = 1;
				}else if(ch[ptr] == 'c'){
					value += digit*100;					
					digit = 1;
				}else if(ch[ptr] == 'x'){
					value += digit*10;
					digit = 1;
				}else if(ch[ptr] == 'i'){
					value += digit;
					digit = 1;
				}else{
					digit = ch[ptr]-'0';
				}
				ptr++;
			}
		}
	}
	String getString(int num){
		String ret = "";
		int m = num/1000;
		int c = (num%1000)/100;
		int x = (num%100)/10;
		int i = num%10;
		if(m != 0){
			if(m != 1){
				ret+=m;
			}
			ret+="m";
		}
		if(c != 0){
			if(c != 1){
				ret+=c;
			}
			ret+="c";
		}
		if(x != 0){
			if(x != 1){
				ret+=x;
			}
			ret+="x";
		}
		if(i != 0){
			if(i != 1){
				ret+=i;
			}
			ret+="i";
		}
		return ret;
	}
	void run(){
		int n = sc.nextInt();
		for(int i = 0; i < n ;i++){
			MCXI a = new MCXI(sc.next());
			MCXI b = new MCXI(sc.next());
			int sum = a.value + b.value;
			System.out.println(getString(sum));
		}		
	}
	public static void main(String[] args){
		Main m = new Main();
		m.run();
	}
}
