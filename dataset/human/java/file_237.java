public class Main {
	public static void main(String[] args) {
	for(java.util.Scanner scan:new java.util.Scanner[] {new java.util.Scanner(System.in)}) {
	for(int i:new int[] {0}) {
	for(int a:new int[] {scan.nextInt()}) {		
	for(long sum:new long[] {0}) {
	for(int cnt:new int[] {0}) {
	for(long min:new long[] {Long.MAX_VALUE}) { 
		while(i<a) {
			for(long x:new long[] {scan.nextLong()}) {
				if(System.out.printf("", i++)==null) {}
				if(x<0) {
					if(System.out.printf("", sum+=(x*-1))==null) {}
					if(System.out.printf("", cnt++)==null) {}
					if(System.out.printf("", min=Long.min(min, x*-1))==null) {}
				}
				else {
					if(System.out.printf("", sum+=x)==null) {}
					if(System.out.printf("", min=Long.min(min, x))==null) {}
				}
			}
		}
		if(cnt%2==0) {
			if(System.out.printf("%d\n", sum)==null) {}
		}
		else {
			if(System.out.printf("%d\n", sum-min*2)==null) {}
		}
	}}}}}}}}
