import java.util.*;
import java.io.*;
import java.math.*;

public class Main
{
	static long bin_sr(long n){
		long l=0l,r=n,res=0l;

		while(l<=r){
			long mid=l+(r-l)/2l;
			if(mid*(mid+1l)/2l<n-mid){
				l=mid+1l;
				res=mid;
			}
			else
				r=mid-1l;
		}

		return res+1l;
	}
    public static void process()throws IOException
    {
      	long n=nl();
      	long res=0l,cnt;
      	ArrayList<Long> li = new ArrayList<>();

      	cnt=0l;
      	if(n%2l==0){
      		while(n%2==0){
      			cnt++;
      			n/=2l;
      		}
      		li.add(cnt);
      	}

      	for(long i=3;i<=Math.sqrt(n);i+=2){
      		if(n%i!=0)
      			continue;
      		cnt=0l;
      		while(n%i==0){
      			cnt++;
      			n/=i;
      		}
      		li.add(cnt);
      	}

      	if(n>2)
      		li.add(1l);

      	for(Long i : li){
      		if(i==1){
      			res++;
      			continue;
      		}
      		//long parts=(long)(Math.log(i)/Math.log(2))+((Math.log(i)%Math.log(2)!=0)?1l:0l);
      		long parts=bin_sr(i);
      		res+=parts;
      	}
      	pn(res);
    }


    static FastReader sc;
    static PrintWriter out;
    public static void main(String[]args)throws IOException
    {
        out = new PrintWriter(System.out);
        sc=new FastReader();

        long s = System.currentTimeMillis();
        int t=1;
        //t=ni();
        while(t-->0)
            process();

        out.flush();
        System.err.println(System.currentTimeMillis()-s+"ms");
    }
    
    
    static void pn(Object o){out.println(o);}
    static void p(Object o){out.print(o);}
    static int ni()throws IOException{return Integer.parseInt(sc.next());}
    static long nl()throws IOException{return Long.parseLong(sc.next());}
    static double nd()throws IOException{return Double.parseDouble(sc.next());}
    static String nln()throws IOException{return sc.nextLine();}
    static long gcd(long a, long b)throws IOException{return (b==0)?a:gcd(b,a%b);}
    static int gcd(int a, int b)throws IOException{return (b==0)?a:gcd(b,a%b);}
    static int bit(long n)throws IOException{return (n==0)?0:(1+bit(n&(n-1)));}
    
    static long mod=(long)1e9+7l;

    static<T> void r_sort(T arr[],int n){
        Random r = new Random(); 
        for (int i = n-1; i > 0; i--){ 
            int j = r.nextInt(i+1); 
                  
            T temp = arr[i]; 
            arr[i] = arr[j]; 
            arr[j] = temp; 
        } 
        Arrays.sort(arr); 
    }
    
/////////////////////////////////////////////////////////////////////////////////////////////////////////
    static class FastReader{ 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader(){ 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 
  
        String next(){ 
            while (st == null || !st.hasMoreElements()){ 
                try{ st = new StringTokenizer(br.readLine()); } catch (IOException  e){ e.printStackTrace(); } 
            } 
            return st.nextToken(); 
        } 
  
        String nextLine(){ 
            String str = ""; 
            try{ str = br.readLine(); } catch (IOException e) { e.printStackTrace(); } 
            return str; 
        } 
    } 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
