import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		int q=sc.nextInt();
		int r=1;
		int t;
		int f;
		char c;
		StringBuffer head=new StringBuffer();
		StringBuffer tail=new StringBuffer();
		for(int i=0;i<q;i++){
			t= sc.nextInt();
			if(t==1){
				r=r*(-1);
			}else{
				f=sc.nextInt();
				c=sc.next().toCharArray()[0];
				if(r*(f*2-3)==1){
					tail.append(c);
				}else{
					head.append(c);
				}
			}
		}
		head.reverse();
		StringBuffer str=new StringBuffer();
		str.append(head);
		str.append(s);
		str.append(tail);
		if(r==-1){
			str.reverse();
		}
		System.out.println(str);
	}
}
