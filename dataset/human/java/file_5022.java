import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		String S = sc.next();
		int Q = sc.nextInt();
		String[] front = new String[Q];
		String[] back = new String[Q];
	
		int F = 0,B = 0;
		int count = 0;
		for( int i=0; i<Q; i++ ){
			int a = sc.nextInt();
			if( a==1 ){
				count++;
			}
			if( a==2 ){
				int b = sc.nextInt();
				String ss = sc.next();
				if( b==1 ){
					if( count%2==0 ){
						front[F] = ss;
						F++;
					}else{
						back[B] = ss;
						B++;
					}
				}
				if( b==2 ){
					if( count%2==0 ){
						back[B] = ss;
						B++;
					}else{
						front[F] = ss;
						F++;
					}
				}
			}
		}
		if( count%2!=0 ){
			StringBuffer sb = new StringBuffer(S);
			String STR = sb.reverse().toString();
			for( int i=B-1; i>=0; i-- ){
				System.out.print(back[i]);
			}
			System.out.print(STR);
			for( int i=0; i<F; i++ ){
				System.out.print(front[i]);
			}
		}else{
			for( int i=F-1; i>=0; i-- ){
				System.out.print(front[i]);
			}
			System.out.print(S);
			for( int i=0; i<B; i++ ){
				System.out.print(back[i]);
			}
		}
	}
}
