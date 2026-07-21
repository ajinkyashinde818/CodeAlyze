import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main  implements Runnable {

    public static void main(String[] args) {

        new Thread(null, new Main(), "", 16 * 1024 * 1024).start();

    }

    public void run() {
    	FastScanner sc = new FastScanner(System.in);
		//long n = Long.parseLong(sc.next());
    	//int[] ar = new int[3];
    	//ar[0]=Integer.parseInt(sc.next());
    	//ar[1]=Integer.parseInt(sc.next());
    	//ar[2]=Integer.parseInt(sc.next());
    	//Arrays.parallelSort(ar);
		int n = Integer.parseInt(sc.next());
		int m = Integer.parseInt(sc.next());
		//int q = Integer.parseInt(sc.next());
		//int r = Integer.parseInt(sc.next());
		//int a = Integer.parseInt(sc.next())-1;
		//int b = Integer.parseInt(sc.next())-1;
		//int c = Integer.parseInt(sc.next())-1;
		//int d = Integer.parseInt(sc.next())-1;
		//String s = sc.next();
		//int k = Integer.parseInt(sc.next());
		//int m = Integer.parseInt(sc.next());
		//int x2000 = Integer.parseInt(sc.next());
		//int t = Integer.parseInt(sc.next());
		//int k = 0;
		//int k = Integer.parseInt(sc.next());
		///String str = sc.next();
		//char c[] = str.toCharArray();
		//char a[][] = new char[n];
		//int atmp[] = new int[h];
		//int max= 0;
		//int blackar[][] = new int[h*w][2];
		//int p=0;
		//ArrayList<MyClass> lists = new ArrayList<>();;
		//lists = new ArrayList;
		int[] a = new int[m];
		int flag = 0;
		if (m > 0)
		{
			a[0] = Integer.parseInt(sc.next());
			for(int i = 1; i < m; i++)
			{
				a[i] = Integer.parseInt(sc.next());
				if(a[i-1]+1==a[i])
				{
					flag = 1;
				}
			}
		}
		//xx 1
		//xxx 2
		//xxxx 3
		//xxxxx 4
		//xxxxxx xoxoxx 221 3 2111 4 1111 1 = 8
		//xxxxxxx 222 1 2211
		int ans = 0;
		if(flag == 1)
		{
			ans = 0;
		}
		else if(n == 1)
		{
			ans = 1;
		}
		else
		{
			int[] tt = new int[n+1];
			int cp = 0;
			if(cp < m && a[cp] == 0)
			{
				tt[0] = 0;
				cp++;
			}
			else
			{
				tt[0] = 1;
			}
			if(cp < m && a[cp] == 1)
			{
				tt[1] = 0;
				cp++;
			}
			else
			{
				tt[1] = 1;
			}
			for(int i = 2; i < n+1; i++)
			{
				if(cp < m && a[cp] == i)
				{
					tt[i] = 0;
					cp++;
				}
				else
				{
					tt[i] = tt[i-1]+tt[i-2];
					if(tt[i] >= 1000000007)
					{
						tt[i] -= 1000000007;
					}
				}
			}
			ans = tt[n];
		}

		PrintWriter out = new PrintWriter(System.out);
		out.println(ans);

		out.flush();
	}

    static class FastScanner {
        private BufferedReader reader = null;
        private StringTokenizer tokenizer = null;
        public FastScanner(String in) {
        	StringReader sr = new StringReader(in);
            reader = new BufferedReader(new BufferedReader(sr));
            tokenizer = null;
        }
        public FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        public String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }

            return tokenizer.nextToken("\n");
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public long nextInt() {
            return Integer.parseInt(next());
        }

    }

}
