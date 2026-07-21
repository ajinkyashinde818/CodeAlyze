import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
      	int cnt = 0;
      	int a,b;
      	boolean nzj = true;
		
      	for(int i = 0;i < n && nzj;i++){
          a = sc.nextInt();
          b = sc.nextInt();
          if(a == b) cnt++;
          else cnt = 0;
          if(cnt == 3) nzj = false;
        }
      	
		if(!nzj) System.out.println("Yes");
      	else System.out.println("No");
	}
}
