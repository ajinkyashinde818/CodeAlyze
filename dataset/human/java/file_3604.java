import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
		String x = sc.next();
		String y = sc.next();
		int a;
		a=x.compareTo(y);
		if (a<0){
		System.out.print("<");
        }else if (a>0){
        System.out.print(">");
        }else{
        System.out.print("=");
        }
    }
}
