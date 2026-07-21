import java.util.*;
	import java.util.Map.Entry;
	 
	 
	 class Main {
		 static int mod =  (int) (Math.pow(10,9)+7);
		 static List<ArrayList<Integer>>  list = new ArrayList<ArrayList<Integer>>();
	    public static void main(String[] args) {
	    	
	        Scanner sc = new Scanner(System.in);
	        int N = sc.nextInt();
	        long K = sc.nextLong();
	        long[] a = new long[N];
	        for (int i=0 ; i<N; i++) {
	            a[i] = Long.parseLong(sc.next())-1;
	        }
	        long ans=Long.MAX_VALUE;
	        int[] first = new int[N];
	        int[] second = new int[N];
	        int tmp=0;
	        boolean flg=false;
	        int min=0;
	        for(int i=1;true;i++) {
	        	tmp=(int) a[tmp];
	        	if(tmp!=0&&first[tmp]==0) {
	        		first[tmp]=i;
	        	} else if(second[tmp]==0) {
	        		second[tmp]=i;
	        		if(flg==false) {
	        			min=tmp;
	        			flg=true;
	        		}
	        	} else {
	        		break;
	        	}
	        }
	        if(K<second[min]) {
	        	for(int i=0;i<N;i++) {
	        		if(first[i]==K) {
	        			System.out.println(i+1);
	        			return;
	        		} 
	        	}
	        } else {
	        	int z =second[min]-first[min];
	        	int t = (int) ((K-first[min])%z);
	        	for(int i=0;i<N;i++) {
		        	if(second[i]!=0&&(second[i]-second[min])%z==t) {
	        			System.out.println(i+1);
	        			return;		        		
		        	}	        		
	        	}
	        }
	    }
	}
