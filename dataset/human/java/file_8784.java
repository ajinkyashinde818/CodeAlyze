import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main{
  public static void main(String[] args){
	  Scanner sc = new Scanner(System.in);
	  int a=sc.nextInt(),b=sc.nextInt(),k=sc.nextInt();
	  List<Integer> l=new ArrayList<>();
	  for(int i=1;i<=Math.min(a, b);i++) {
		  if(a%i==0&&b%i==0)l.add(i);
	  }
	  System.out.println(l.get(l.size()-k));
  }
	public static List<Long> divisorEnum(long n) {
		List<Long> l=new ArrayList<>();
		for(long i=1;i<=Math.sqrt(n);i++) {
			if(n%i==0) {
				l.add(i);
				if(i!=Math.sqrt(n))l.add(n/i);
			}
		}
		l.sort(null);
		return l;
	}
}
