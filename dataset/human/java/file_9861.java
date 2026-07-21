import java.util.Scanner;

public class Main {

	int value = -1;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int X = sc.nextInt();
		Book book[] = new Book[N];
		Main main = new Main ();
		for (int i=0;i<N;i++) {
			Book b = main.new Book();
			b.c = sc.nextInt();
			b.a = new int[M];
			for (int j=0;j<M;j++) {
				b.a[j] = sc.nextInt();
			}
			book[i]= b;
		}
		main.dfs(book, new int[M], 0, 0, X);
		System.out.println(main.value);
	}

	public void dfs(Book[] b,int []value,int now,int price,int X) {
		if (now==b.length) {
			return ;
		}
		dfs(b,value,now+1,price,X);
		int a[] = new int[value.length];
		for (int i=0;i<value.length;i++) {
			a[i] = value[i];
		}
		for (int i=0;i<value.length;i++) {
			a[i] +=b[now].a[i];
		}
		price +=b[now].c;
		if (checkValue(a,X)==true) {
			if (this.value ==-1||price<this.value) {
				this.value = price;
			}
			return;
		}
		dfs(b,a,now+1,price,X);
	}

	public boolean checkValue (int [] value,int X) {
		for (int i=0;i<value.length;i++) {
			if (value[i]<X) {
				return false;
			}
		}
		return true;
	}

	public class Book {
		int c;
		int a[];
	}

}
