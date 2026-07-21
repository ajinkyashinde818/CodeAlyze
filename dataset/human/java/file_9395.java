import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
	    String s = "No";
        int count = 0;
        for(int i=0;i<a;i++){int b = sc.nextInt();
                             int c = sc.nextInt();
                             if(b==c){count++;}
                             else{count=0;}
                             if(count>=3){s="Yes";break;}
                            }		       
		System.out.println(s);
	}
}
