import java.util.*;
import java.io.*;
 
public class Main {
    public static void main(String[] args) throws Exception {
        FastScanner sc = new FastScanner();
        
    	PrintWriter out = new PrintWriter(System.out);
    	
    	int rpi = sc.nextInt();
    	int n = sc.nextInt();
    	int[] as = new int[n];
    	
    	for(int i=0; i<n; i++){
    	    as[i] = sc.nextInt();
    	}
    	
    	int max=as[0]+rpi-as[n-1], tmp=0;
    	for(int i=1; i<n; i++){
    	    tmp=as[i]-as[i-1];
    	    if(tmp>max) max=tmp;
    	}
    	
    	out.println(rpi-max);
    	out.flush();
    }
    
    static void disp_que(ArrayDeque<Integer> dt){		//上手くいかなかった時用
        int a=0;
        PrintWriter out = new PrintWriter(System.out);
        while(dt.size()>0){
            a=dt.removeLast();
            out.print(a);
        }
        out.println("\n");
    }
    
    static void show_b2d_array(boolean[][] dt, int lit_x, int lit_y){
        PrintWriter out = new PrintWriter(System.out);
    	for(int i=0; i<dt[0].length; i++){
    		for(int j=0; j<dt.length; j++){
    		    if((i==lit_y) && (j==lit_x)) out.print("X");
    		    else if(dt[j][i]) out.print("O");
    		    else out.print(".");
    		}
    		out.println();
    	}
    }
    	
    private static ArrayList<Integer> nextPerm(ArrayList<Integer> former){
        int pivot=-1;
        int ln = former.size();
        for(int i = ln; i>1; i--){
            if(former.get(i-2) < former.get(i-1)){
                pivot = i-2;
                break;
            }
        }
        if(pivot==-1) return null;
        int pivot_fig = former.get(pivot);
        
        int min_pos=pivot+1;
        int min=former.get(min_pos);
        for(int i=ln-1; i > pivot+1; i--){
            if((former.get(i) < min)&&(former.get(i) > pivot_fig)){
                min_pos=i;
                min=former.get(min_pos);
            }
        }
        Collections.swap(former, pivot, min_pos);
        Collections.sort(former.subList(pivot+1, ln));
        return former;
        
    }
    private static int factorial(int n) {
        int ans=1;
        for(int i=n; i>0; i--){
            ans*=i;
        }
        return ans;
    }
    	
	
    public static int[][] combSort(int[][] origin, int ln){
        int h=ln*10/13, tmp=0;
        boolean fin=true;
        while((h>1)||(!fin)){
            fin=true;
            for(int i=0; i < ln-h; i++){
                if(origin[i][0] > origin[i+h][0]){
                    tmp=origin[i][0];
                    origin[i][0]=origin[i+h][0];
                    origin[i+h][0]=tmp;
                    tmp=origin[i][1];
                    origin[i][1]=origin[i+h][1];
                    origin[i+h][1]=tmp;
                    fin=false;
                }
            }
            h *=10;
            h/=13;
        }
        return origin;
    }

    public static int binarySearch(int[] dt, int target){
        int left=0, right=dt.length-1;
        int mid=-1;
        
        while(left<=right){
            mid = (right+left)/2;
            if(dt[mid] == target){
                return mid;
            }
            if(dt[mid] < target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return -1;
    }
}


class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        }else{
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }
    
    private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
    private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
    public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
    public String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while(isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    public long nextLong() {
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while(true){
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            }else if(b == -1 || !isPrintableChar(b)){
                return minus ? -n : n;
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
        return (int) nl;
    }
    public double nextDouble() { return Double.parseDouble(next());}
}
