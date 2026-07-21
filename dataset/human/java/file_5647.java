import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner s=new Scanner(System.in);
		int n=s.nextInt(),k=s.nextInt(),m=s.nextInt();
		StringJoiner sj=new StringJoiner(" ");
		for(int i=0;i<n;++i)
			sj.add(i<k?""+m:"9999999");
		System.out.println(sj);
	}
}
