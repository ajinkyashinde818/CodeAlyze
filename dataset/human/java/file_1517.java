import java.util.Scanner;
public class Main {
 
	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner scan = new Scanner(System.in);
		int A =scan.nextInt();
		int B =scan.nextInt();
		int counts=0;
        char[][] a = new char[A][A];
        char[][] b = new char[B][B];
        for(int i=0;i<A;i++){
        	char[] c=scan.next().toCharArray();
        	for(int f=0;f<A;f++){
        	a[i][f] =c[f];
        	}
        }
        for(int i=0;i<B;i++){
        char[] c=scan.next().toCharArray();
        	for(int f=0;f<B;f++){
        	b[i][f] =c[f];
        	}
        }
        for(int j=0;j<=A-B;j++){
        for(int g=0;g<=A-B;g++){
        	counts=0;
        for(int i=0;i<B;i++){
        	int count =0;
        	for(int f=0;f<B;f++){
        		if(a[i+j][f+g]==b[i][f]){
        			count++;
        		}else{
        			break;
        		}
        	}
        	if(count==B){
        		counts++;
        	}else{
        		break;
        	}
        	if(counts==B){
        		System.out.println("Yes");
        		System.exit(0);
        	}
        }
        }
	}
        System.out.println("No");
	}
	public static char[] cha(String s){
		char a[] = new char[s.length()];
		for(int i=0;i<s.length();i++){
			a[i]=s.charAt(i);
		}
		return a;
	}}
