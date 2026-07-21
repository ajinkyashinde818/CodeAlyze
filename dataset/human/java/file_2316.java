import java.util.Scanner;
import java.util.stream.IntStream;

public class Main{
	static final Scanner s=new Scanner(System.in);
	
	static char[] chars;
	static{
		String v="abcdefghijklmnopqrstuvwxyz";
		chars=(v.toUpperCase()+v).toCharArray();
	}
	static int getIndex(char c){
		return c<='Z'?c-'A':c-'a'+26;
	}
	
	public static void main(String[] __){
		while(true){
			int n=s.nextInt();
			if(n==0) return;
			
			int[] key=IntStream.range(0,n).map(i->s.nextInt()).toArray();
			char[] str=s.next().toCharArray();
			
			for(int i=0;i<str.length;i++){
				str[i]=chars
						[(getIndex(str[i])
						-key[i%key.length]
						+chars.length)
						%chars.length];
			}
			System.out.println(String.valueOf(str));
		}
	}
}
