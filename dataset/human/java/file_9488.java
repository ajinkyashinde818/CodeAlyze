import java.io.*;
import java.util.*;

public class Main{
    static class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){br = new BufferedReader(new InputStreamReader(System.in));}
        public FastReader(String fileName) throws FileNotFoundException{br = new BufferedReader(new FileReader(fileName));}
        String next(){while (st == null || !st.hasMoreElements()){try{st = new StringTokenizer(br.readLine());}catch (IOException  e){e.printStackTrace();}}return st.nextToken();}
        int nextInt(){return Integer.parseInt(next());}
        long nextLong(){return Long.parseLong(next());}
        double nextDouble(){return Double.parseDouble(next());}
        char[][] readCharArray(int n,int m) {
            String str;
            char[][] arr = new char[n][m];
            for(int i=0;i<n;i++) {
                str=nextLine();
                for(int j=0;j<n;j++) {
                    arr[i][j]=str.charAt(j);
                }
            }
            return arr;
        }
        char[][] readCharArray(int n){
            return readCharArray(n,n);
        }
        int[] readArray(int n){int[] a=new int[n];for (int i=0; i<n; i++) a[i]=nextInt();return a;}
        long[] readLongArray(int n){long[] a=new long[n];for (int i=0; i<n; i++) a[i]=nextLong();return a;}
        String nextLine(){String str = "";try{str = br.readLine();}catch (IOException e){e.printStackTrace();}return str;}
    }
    static void printArray(int[] arr){
        for(int x:arr){
            System.out.print(x+" ");
        }
        System.out.println();
    }
    static final Random random=new Random();
    static void ruffleSort(int[] a) {
        int n=a.length;//shuffle, then sort
        for (int i=0; i<n; i++) {
            int oi=random.nextInt(n), temp=a[oi];
            a[oi]=a[i]; a[i]=temp;
        }
        Arrays.sort(a);
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        FastReader st = new FastReader();
        int n = st.nextInt();
        int d1,d2,count=0;
        boolean test=true;
        while(n-- > 0) {
        	d1 = st.nextInt();d2 = st.nextInt();
        	if(d1==d2) {
        		count++;
        		if(count==3) {
        			System.out.println("Yes");
        			test=false;
        			break;
        		}
        	}
        	else {
        		count=0;
        	}
        }
        if(test) System.out.println("No");
    }
}
