import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int r = scn.nextInt();
      	int ans = 0;
      	if(n>=10) ans = r;
      	if(n<10) ans = r + 100*(10-n);
      	System.out.println(ans);
	}
}
