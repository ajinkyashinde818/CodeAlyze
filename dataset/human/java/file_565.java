import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.TreeMap;
public class Main { 
	static void merge(int arr[], int l, int m, int r) 
    { 
        int n1 = m - l + 1; 
        int n2 = r - m; 

        int L[] = new int [n1]; 
        int R[] = new int [n2]; 
        for (int i=0; i<n1; ++i) 
            L[i] = arr[l + i]; 
        for (int j=0; j<n2; ++j) 
            R[j] = arr[m + 1+ j]; 
        int i = 0, j = 0; 
        int k = l; 
        while (i < n1 && j < n2) 
        { 
            if (L[i] <= R[j]) 
            { 
                arr[k] = L[i]; 
                i++; 
            } 
            else
            { 
                arr[k] = R[j]; 
                j++; 
            } 
            k++; 
        } 
        while (i < n1) 
        { 
            arr[k] = L[i]; 
            i++; 
            k++; 
        } 
        while (j < n2) 
        { 
            arr[k] = R[j]; 
            j++; 
            k++; 
        } 
    } 
    static void sort(int arr[], int l, int r) 
    { 
        if (l < r) 
        { 
            int m = (l+r)/2; 
            sort(arr, l, m); 
            sort(arr , m+1, r); 
            merge(arr, l, m, r); 
        } 
    }
    static void revOrder(int[] arr) {
    	int[] a = new int[arr.length];
		for(int i=0;i<arr.length;i++) {
			a[i] = arr[arr.length-i-1];
		}
		for(int i=0;i<arr.length;i++) arr[i] = a[i];
	}
    static int gcd(int a, int b) {
    	if(a==0) return b;
    	return gcd(b%a, a);
    }

	public static void main(String[] args) {
		try {
			BufferInput in = new BufferInput();
			StringBuilder sb = new StringBuilder();
			int n = in.nextInt();
			int r = in.nextInt();
			if(n<10) {
				r+=100*(10-n);
				System.out.println(r);
			}
			else {
				System.out.println(r);
			}
			//System.out.println(sb);
			
		}catch(Exception e) {}

	}
static class BufferInput {
		
		final private int BUFFER_SIZE = 1 << 16;
		
		private DataInputStream din;
		
		private byte[] buffer;
		
		private int bufferPointer, bytesRead;
		
		public BufferInput() {
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public BufferInput(String file_name) throws IOException {
			din = new DataInputStream(new FileInputStream(file_name));
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public String readLine() throws IOException {
			byte[] buf = new byte[64];
			int cnt = 0, c;
			while ((c = read()) != -1) {
				if (c == '\n')
					break;
				buf[cnt++] = (byte) c;
			}
			return new String(buf, 0, cnt);
		}
		
		public String nextString() throws IOException{
			
			byte c = read();
			while(Character.isWhitespace(c)){
				c = read();
			}
			
			StringBuilder builder = new StringBuilder();
			builder.append((char)c);
			c = read();
			while(!Character.isWhitespace(c)){
				builder.append((char)c);
				c = read();
			}
			
			return builder.toString();
		}
		
		public int nextInt() throws IOException {
			int ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');

			if (neg)
				return -ret;
			return ret;
		}
		
		public int[] nextIntArray(int n) throws IOException {
			int arr[] = new int[n];
			for(int i = 0; i < n; i++){
				arr[i] = nextInt();
			}
			return arr;
		}
		public long nextLong() throws IOException {
			long ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}
		
		public long[] nextLongArray(int n) throws IOException {
			long arr[] = new long[n];
			for(int i = 0; i < n; i++){
				arr[i] = nextLong();
			}
			return arr;
		}
		
		public char nextChar() throws IOException{
			byte c = read();
			while(Character.isWhitespace(c)){
				c = read();
			}
			return (char) c;	
		}
		public double nextDouble() throws IOException {
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();

			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');

			if (c == '.') {
				while ((c = read()) >= '0' && c <= '9') {
					ret += (c - '0') / (div *= 10);
				}
			}

			if (neg)
				return -ret;
			return ret;
		}
		public double[] nextDoubleArray(int n) throws IOException {
			double arr[] = new double[n];
			for(int i = 0; i < n; i++){
				arr[i] = nextDouble();
			}
			return arr;
		}
		private void fillBuffer() throws IOException {
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1)
				buffer[0] = -1;
		}
		private byte read() throws IOException {
			if (bufferPointer == bytesRead)
				fillBuffer();
			return buffer[bufferPointer++];
		}

		public void close() throws IOException {
			if (din == null)
				return;
			din.close();
		}
	}
}
