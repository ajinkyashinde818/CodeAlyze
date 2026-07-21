import java.util.Scanner;

public class Main {

	static long bignum = 1000000000+7;

	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		long k = sc.nextLong();
		int[] a = new int[n+1];
		for(int i =1;i<n+1;i++) {
			a[i] = sc.nextInt();
		}
		
		boolean[] visited = new boolean[n+1];
		int[] visitIndex = new int[n+1];
		visitIndex[0]=1;
		visited[1]=true;



		for(int i =2;i<n+1;i++) {
			visited[i]=false;
		}
		int counter =0;
		int newone = -1;
		for(int i =1;i<n+1;i++) {
			counter++;
			visitIndex[i]=a[visitIndex[i-1]];
			if(visited[visitIndex[i]]) {
				if(visitIndex[i]!=1) {
					newone=visitIndex[i];
				}
				break;
			}else {
				visited[visitIndex[i]]=true;
			}
			
		}
		
		int branch = 0;
		if(newone!=-1) {
			int holder = 1;
			while(true) {
				branch++;
				if(a[holder]==newone) {
					break;
				}
				holder = a[holder];
			}
			if(k<=branch) {
				System.out.println(visitIndex[(int)k]);
			}else {
				k = k-branch;
				k = k-(counter-branch)*(k/(counter-branch));
				System.out.println(visitIndex[(int)k+branch]);
			}
		}else {
			k= k- counter*(k/counter);
			System.out.println(visitIndex[(int)k]);
		}
		
		





	}

	static long divn(int target, int times) {//10_9+7のあまり累乗版
		int sqtimes = (int)Math.sqrt(times);
		long ans = 1;
		for(int i =0;i<sqtimes;i++) {
			ans = (ans * target)%(1000000000+7);
		}
		long holder = ans;
		ans = 1;
		for(int i =0;i<sqtimes;i++) {
			ans = (ans*holder)%(1000000000+7);
		}
		for(int i=0;i<times - sqtimes*sqtimes;i++) {
			ans = (ans * target)%(1000000000+7);
		}
		return ans;
	}

	static long div(long a) {//10_9+7のあまり
		if(a<0)a+=1000000000+7;
		return a%(1000000000+7);
	}

}
/*
class City{
	int order;
	int prefecture;
	int year;
	int number;
	City(int order,int prefecture, int year){
		this.order = order;
		this.prefecture = prefecture;
		this.year = year;
	}
}
*/
