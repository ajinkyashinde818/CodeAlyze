import java.util.*;
import java.io.PrintWriter;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		String s=sc.next();
		int q=sc.nextInt();
		StringBuilder front=new StringBuilder();
		StringBuilder back=new StringBuilder();
		StringBuilder ss=new StringBuilder(s);
		boolean ch=true;
		for(int i=0; i<q; i++){
			int t=sc.nextInt();
			if(t==1){
				ch=!ch;
			}else{
				int f=sc.nextInt();
				char c=sc.next().charAt(0);
				if(f==1){
					if(ch){
						front.append(c);
					}else{
						back.append(c);
						
					}
				}else{
					if(ch){
						
						back.append(c);
					}else{
						front.append(c);
					}
				}
			}
		}
		if(ch){
			front.reverse();
			System.out.println(front+ss.toString()+back);
		}else{
			back.reverse();
			ss.reverse();
			System.out.println(back+ss.toString()+front);
		}
		
	}
}
