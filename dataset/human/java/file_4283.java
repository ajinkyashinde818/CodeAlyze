import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
        public static void main(String[] args) throws Exception {
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                StringTokenizer st;
                int n = Integer.parseInt(br.readLine());

                int a[] = new int[n];
                st = new StringTokenizer(br.readLine());
                for(int i=0 ; i<n ; i++) {
                        a[i] = Integer.parseInt(st.nextToken());
                }

                int b[] = new int[n];
                st = new StringTokenizer(br.readLine());
                for(int i=0 ; i<n ; i++) {
                        b[i] = Integer.parseInt(st.nextToken());
                }

                int c[] = new int[n];
                st = new StringTokenizer(br.readLine());
                for(int i=0 ; i<n-1 ; i++) {
                        c[i] = Integer.parseInt(st.nextToken());
                }

                long sum = b[a[0]-1];
                int last = a[0];
                for(int i=1 ; i<n ; i++) {
                        int x = a[i];
                        if(x == last+1) {
                                sum += c[x-2];
                        }
                        sum += b[x-1];
                        last = x;
                }

                System.out.println(sum);
        }
}
