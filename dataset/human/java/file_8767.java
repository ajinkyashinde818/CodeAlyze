import java.util.*;

public class Main {
public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int a=sc.nextInt();
		int b=sc.nextInt();
		int k=sc.nextInt();
		int q=0;
		int count=0;
		int answer=0;
		if(b>a){
			q=a;
			a=b;
			b=q;
		}

		for(int i=b;i>0;i--){
			if(a%i==0 && b%i==0){
				count++;
				if(count==k){
					answer=i;
					break;
				}
			}
		}

		System.out.println(answer);

	}
}
