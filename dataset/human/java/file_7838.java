import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n;
		long k;
		int a[];
		int test = 0;

		if(test == 0) {
			n = sc.nextInt();
			k = sc.nextLong();

			a = new int[n+1];
			for(int i = 1; i < n+1; i++) {
				a[i] = sc.nextInt();
			}
		} else if(test == 1) {//テストデータ1
			n = 200000;
			n = 199999;
			k = 1000000000000000000l;
			k = 1000000000000000000l;
			k = 1;

			a = new int[n+1];
			for(int i = 1; i < n+1; i++) {
				a[i] = (i%n+1);
//				a[i] = (i%2+1);
			}
		} else if(test == 2) {//テストデータ2
			n = 2;
			k = 2;

			a = new int[n+1];
			for(int i = 1; i < n+1; i++) {
				a[i] = (i%n+1);
			}
		} else if(test == 3){//テストデータ3
			n = 5;
			k = 1;

			a = new int[n+1];
			for(int i = 1; i < n+1; i++) {
				a[i] = (i%n+1);
				if(i==5)a[i]=3;
			}
		} else {
			n = sc.nextInt();
			k = sc.nextLong();

			a = new int[n+1];
			for(int i = 1; i < n+1; i++) {
				a[i] = sc.nextInt();
			}
		}

		int s[] = new int[n+1];//町[1]からx回テレポートした先の町を示すショートカットデータ
		int sloop[] = new int[n+1];//町[1]からx回テレポートした先の町を示すショートカットデータ
		int passed[] = new int[n+1];//通過した町 何番目で通過したか
		for(int i = 1; i < n+1; i++) {
			passed[i] = 0;
		}
		int current_town = 1;
		int head = 0;
		int headCount = 0;
		int loop = n;
		boolean isSubLoop = false;
		s[0] = 1;
		passed[0] = 1;
		for(int i = 1; i < n+1; i++) {
			s[i] = a[current_town];
			if (passed[a[current_town]] > 0 || a[current_town] == current_town) {
				head = a[current_town];
				loop = i;
				break;
			}
			passed[current_town] = i;
			current_town = a[current_town];
		}
		current_town = 1;
		for(int i = 0; i < n+1; i++) {
			if (current_town == head) {
				headCount = i;
				break;
			}
			current_town = a[current_town];
		}
		loop -= headCount;

		current_town = head;
		for(int i = 0; i < n+1; i++) {
			sloop[i] = current_town;
			current_town = a[current_town];
			if (current_town == head) {
				break;
			}
		}

		int res;
		if(k < headCount) {
			res = s[(int)k];
		}else {
			int tmpK = (int)((k - headCount) % (long)loop);
			res = sloop[tmpK];
		}

		if (test != 0) {//print
			System.out.printf("n:%d k:%d\n", n,k);
			System.out.printf("head:%d headCount:%d loop:%d res:%d\n", head,headCount,loop,res);
			for(int i = 1; i < n+1; i++) {
				System.out.printf(" %d", a[i]);
				if(i>100) break;
			}
			System.out.println();
			for(int i = 0; i < n+1; i++) {
				System.out.printf(" %d", s[i]);
				if(i>100) break;
			}
			System.out.println();
			for(int i = 0; i < n+1; i++) {
				System.out.printf(" %d", sloop[i]);
				if(i>100) break;
			}
			System.out.println();
		}


		System.out.printf("%d", res);
	}
}
