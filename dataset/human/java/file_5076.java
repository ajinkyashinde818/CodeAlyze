import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    Deque<String> dque=new ArrayDeque<>();
    String s=sc.next();
    for(int i=0;i<s.length();i++) dque.addLast(s.substring(i, i+1));
    String c="";
    int q=sc.nextInt(),count=0;
    boolean flag=true;
    for(int i=0;i<q;i++) {
    	int t=sc.nextInt();
    	if(t==1) {
    		flag=!flag;
    		count++;
    	}else {
    		int f=sc.nextInt();
    		c=sc.next();
    		if(f==1) {
    			if(flag) {
    				dque.addFirst(c);
    			}else {
    				dque.addLast(c);
    			}
    		}else {
    			if(flag) {
    				dque.addLast(c);
    			}else {
    				dque.addFirst(c);
    			}
    		}
    	}
    	//System.out.println(dque);
    }
    int n=dque.size();
    if(count%2==0) {
    	for(int i=0;i<n;i++) {
    		System.out.print(dque.removeFirst());
    	}
    }else {
    	for(int i=0;i<n;i++) {
    		System.out.print(dque.removeLast());
    	}
    }
    System.out.println();
  }
}
