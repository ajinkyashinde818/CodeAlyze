import java.util.*;
 
public class Main {
	public static void main(String[] args) {
		Integer q,i,t,f,t1;
		String ans,start;
		Scanner sc = new Scanner(System.in);

		t1=0;
		start="";
		ans=sc.next();
		q=sc.nextInt();
		
		StringBuffer ans_buf = new StringBuffer(ans);
		StringBuffer start_buf = new StringBuffer(start);

		for (i=0;i<q;i++){
			t=sc.nextInt();
			if(t==1){
				t1++;
			} else{
				f=sc.nextInt();
				if((t1+f)%2==0){
					ans_buf.append(sc.next());
				} else {
					start_buf.append(sc.next());
				}
			}
		}

		if(t1%2==1){
			ans=ans_buf.reverse().toString() + start_buf.toString();
		}else{
			ans=start_buf.reverse().toString() + ans_buf.toString();
		}
				System.out.println(ans);
		sc.close();
	}
}
