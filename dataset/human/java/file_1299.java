import java.awt.Point;
import java.util.ArrayDeque;
import java.util.Scanner;
 
public class Main{
	
	static final Scanner sc=new Scanner(System.in);
	public static void main(String[]args){
        int N=sc.nextInt();
        long[]a=new long[N];
        for(int i=0;i<N;i++){
                a[i]=sc.nextLong();
        }
        long[]s=new long[N];
        s[0]=a[0];
        for(int i=1;i<N;i++){
                s[i]=s[i-1]+a[i];
        }
        long min=1000000000;
        long r=0;
        for(int i=0;i<N-1;i++){
                r=s[N-1]-s[i];
                if(Math.abs(r-s[i])<min){
                        min=Math.abs(r-s[i]);
                }

        }
        if(N==2){
                min=Math.abs(a[0]-a[1]);
        }
        System.out.println(min);


		
	}
}
