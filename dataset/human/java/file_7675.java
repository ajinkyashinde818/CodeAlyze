import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		long k=sc.nextLong();
		int[] array = new int[n];
		for(int i=0;i<n;i++) array[i]=sc.nextInt();
		int[] list = new int[n];
		list[0]=0;
		int now = 0,count=0,next;
		while(true) {
			next = array[now]-1;
			count++;
			if(list[next]!=0) {
				count = count-list[next];
				break;
			}
			list[next]=count;
			now=next;
		}
		if(k<list[next]) {
			for(int i=0;i<n;i++) {
				if(list[i]==k) {
					System.out.println(i+1);
					break;
				}
			}
		}else {
			k-=list[next];
			for(int i=0;i<n;i++) {
				if(list[i]==list[next]+(k%count)) {
					System.out.println(i+1);
					break;
				}
			}
		}
	}
}
