import java.util.Scanner;

public class Main {

	static char[] mcxi={'m','c','x','i'};
	static int[] m={1000,100,10,1};
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int N = cin.nextInt();
		while(N--!=0){
			String s1=cin.next();
			String s2=cin.next();
			System.out.println(toStr(toInt(s1)+toInt(s2)));
		}
	}
	static int toInt(String ss){
		char[] s = (" "+ss+" ").toCharArray();
		int re=0;
		for(int j = 0;j<4;j++){
			for(int i = 0;i<s.length;i++){
				if(s[i]==mcxi[j]){
					if(Character.isDigit(s[i-1])){
						re+=m[j]*(s[i-1]-'0');
					}
					else{
						re+=m[j];
					}
				}
			}			
		}

		return re;
	}
	static String toStr(int a){
		String re = "";
		int b = 0;
		for(int i = 0;i<4;i++){
			b=a/m[i];
			if(b>0){
				if(b==1){
					re+=mcxi[i];
				}
				else{
					re+=""+b+mcxi[i];
				}
			}
			a=a%m[i];
		}

		return re;
	}
}
