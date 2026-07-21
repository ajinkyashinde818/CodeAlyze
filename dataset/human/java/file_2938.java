import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException{
		FastScanner f = new FastScanner(); //Replace "problem" with problem name
        
        int n = f.nextInt();
        int m = f.nextInt();
        ArrayList<ArrayList<Integer>> boats = new ArrayList<ArrayList<Integer>>();
        for(int i = 0; i < n; i++){
        	boats.add(new ArrayList<Integer>());
        }
        for(int i = 0; i < m; i++){
        	int a = f.nextInt() - 1;
        	int b = f.nextInt() - 1;
        	boats.get(a).add(b);
        	boats.get(b).add(a);
        }
        boolean exit = false;
        for(int i = 0; i < boats.get(0).size(); i++){
        	if(boats.get(boats.get(0).get(i)).contains(n-1)){
        		System.out.println("POSSIBLE");
        		exit = true;
        		break;
        	}
        }
        
        if(!exit){
        	System.out.println("IMPOSSIBLE");
        }
	}

	public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        String nextLine() {
            st = null;
            try {
                return br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return null;
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }
}
