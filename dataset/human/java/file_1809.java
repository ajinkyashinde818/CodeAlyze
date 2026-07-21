import java.io.PrintStream;
    import java.util.Scanner;
	
	public class Main {
        private static final PrintStream so = System.out;
        private static final Scanner     sc = new Scanner(System.in);
    
        public static void main(String[] args) {
            int n = sc.nextInt();
            int g = sc.nextInt();
            
            int[] p = new int[n + 1];
            int[] comp = new int[n + 1];
            int[] maxUnComp = new int[n + 1];
            
            for (int i = 1; i <= n; i++) {
                p[i] = sc.nextInt();
                maxUnComp[i] = 100*(i) * (p[i] - 1);
                comp[i] = maxUnComp[i] + 100*i + sc.nextInt();
            }
            
            int ans = Integer.MAX_VALUE;
            for (int pattern = 0; pattern < 1 << n; pattern++) {
                int sumS = sum(comp, pattern, n); // score
                int needed = g - sumS;
                int idx = firstIdxOf0(pattern, n) + 1;
                
                if (needed > maxUnComp[idx]) continue;
                int sumQ = sum(p   , pattern, n); // number of questions to solve
                sumQ += idx == 0 ? 0 : Math.max(ceil(needed, 100*idx), 0);
                ans = Math.min(ans, sumQ);
            }
            so.println(ans);
        }
        
        // ^q^
        static int ceil(int a, int b) {
            return (a + b - 1) / b;
        }
        
        static int sum(int[] a,int bits, int numBits) {
            int sum = 0;
            int mask = 1;
            for (int i = 0; i < numBits; i++) 
                if ((bits >> i & mask) == 1)
                    sum += a[i+1];
            return sum;
        }
        
        static int firstIdxOf0(int bits, int numBits) {
            int mask = 1;
            for (int i = numBits - 1; i >= 0; i--)
                if ((bits >> i & mask) == 0)
                    return i;
            return -1;
        }
    }
