import java.util.*;
class Main {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();int cnt=0;boolean f=false;
		while(n--!=0) {
			int d1=sc.nextInt(),d2=sc.nextInt();
			if(d1==d2)cnt++;
			else if(d1!=d2)cnt=0;
			if(cnt>=3)f=true;
		}
		if(f)System.out.println("Yes");
		else System.out.println("No");
	}

}
