import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
    private static FastScanner fs = new FastScanner();
    public static void main(String[] args) {

       int n = fs.nextInt();
       int arr[] = new int[101];
       int flag =0;
       boolean isTrue = false;
       for(int i=3;i<(n+3);i++)
       {
           int a = fs.nextInt();
           int b = fs.nextInt();
           if(a==b && flag==0)
           {
               flag=1;
           }
           else if(flag==1 && a==b)
           {
               flag =2;
           }
           else if(flag ==2 && a==b)
           {
               flag =3;
               isTrue = true;
           }
           else if(a==b || a !=b)
           {
               flag=0;
           }
       }
       if(isTrue) System.out.println("Yes");
       else System.out.println("No");
    }


    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }

        long nextLong() {
            return Long.parseLong(next());
        }
        int  gcd(int a,int b)
        {
            while (b > 0)
            {
                int  temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }
        private int upper(int arr[],int key){
            int low = 0;
            int high = arr.length-1;
            while(low < high){
                int mid = low + (high - low+1)/2;
                if(arr[mid] <= key){
                    low = mid;
                }
                else{
                    high = mid-1;
                }
            }
            return low;
        }
        public int lower(int arr[],int key){
            int low = 0;
            int high = arr.length-1;
            while(low < high){
                int mid = low + (high - low)/2;
                if(arr[mid] >= key){
                    high = mid;
                }
                else{
                    low = mid+1;
                }
            }
            return low;
        }
    }
}
