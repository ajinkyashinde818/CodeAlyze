import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;
public class Main {
	public static void main(String[] args)throws Exception{
		Scanner stdIn=new Scanner(System.in);
		String S=stdIn.next();
		int Q=stdIn.nextInt();
		Deque<Character> ans=new ArrayDeque<Character>();
		for(int i=0;i<S.length();i++){
			ans.add(S.charAt(i));
		}
		boolean key=false;
		for(int i=0;i<Q;i++){
			int q=stdIn.nextInt();
			if(q==1)
				if(key==false)
					key=true;
				else
					key=false;
			else{
				int f=stdIn.nextInt();
				char a=stdIn.next().charAt(0);
				if((f==1&&key==false)||(f==2&&key)){
					ans.addFirst(a);
				}
				else{
					ans.add(a);
				}
			}
		}
		int x=ans.size();
		if(key){
			for(int i=0;i<x;i++){
				System.out.print(ans.pollLast());
			}
			System.out.println();
		}
		else{
			for(int i=0;i<x;i++){
				System.out.print(ans.poll());
			}
			System.out.println();
		}
	}
}
