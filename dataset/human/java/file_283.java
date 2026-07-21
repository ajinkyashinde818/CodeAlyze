import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Main  implements Runnable { //Runnableを実装する

    public static void main(String[] args) {

        new Thread(null, new Main(), "", 16 * 1024 * 1024).start(); //16MBスタックを確保して実行

    }

    public void run() {
		Scanner sc = new Scanner(System.in);
		//Scanner sc = new Scanner("3 -10000000000 5 -4");
		int n = Integer.parseInt(sc.next());
		//int b = Integer.parseInt(sc.next());
		//int t = Integer.parseInt(sc.next());
		//int k = 0;
		//int k = Integer.parseInt(sc.next());
		//String str = sc.next();
		//char c[] = str.toCharArray();
		long a;
		long min= 10000000000l;
		int numofm = 0;
		long ans = 0;
		for (int i = 0; i < n; i++)
		{
			a= Long.parseLong(sc.next());
			if(a<0)
			{
				numofm++;
				if(-a<min)
				{
					min = -a;

				}
				ans = ans-a;
			}
			else
			{
				if(a<min)
				{
					min = a;
				}
				ans = ans+a;
			}
		}
		if(numofm%2==1)
		{
			ans = ans - (2l*min);
		}

		PrintWriter out = new PrintWriter(System.out);
		out.println(ans);
		out.flush();
	}
}
