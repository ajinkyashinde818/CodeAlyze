import java.io.PrintWriter;
import java.util.Scanner;

public class Main  implements Runnable { //Runnableを実装する

    public static void main(String[] args) {

        new Thread(null, new Main(), "", 16 * 1024 * 1024).start(); //16MBスタックを確保して実行

    }

    public void run() {
		Scanner sc = new Scanner(System.in);
		//Scanner sc = new Scanner("10");
		int n = Integer.parseInt(sc.next());
		int k = 0;
		//int k = Integer.parseInt(sc.next());
		//String str = sc.next();
		//char c[] = str.toCharArray();
		PrintWriter out = new PrintWriter(System.out);
		for (int i = 0; i * (i-1)/2 <= n; i++)
		{
			if(n==i * (i-1)/2)
			{
				k = i;
			}
		}
		if(k == 0) 
		{
			out.println("No");
		}
		else
		{
			out.println("Yes");
			out.println(k);
			int ans[][] = new int[k][n];
			
			int r = 0;
			for(int i = 0; i < k-1; i++)
			{
				int tmp = 0;
				for(int j = r; j < r+(k-1-i);j++)
				{
					ans[i][j] = 1;
					ans[i+tmp+1][j] = 1;
					tmp++;
				}
				r=r+(k-1-i);
				
			}
			for(int i = 0; i < k; i++)
			{
				out.print(k-1);
				out.print(" ");
				for(int j = 0; j < n;j++)
				{
					if(ans[i][j] == 1)
					{
						out.print(j+1);
						out.print(" ");
					}

				}
				out.println("");
			}
		}

		//out.println(ans);
		out.flush();
	}
}
