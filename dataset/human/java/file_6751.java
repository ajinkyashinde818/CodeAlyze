import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int n = sc.nextInt();
		int[] a = new int[n];
		for(int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		Main.MergeSort(a, a.length);
		
		int max = (k - a[n-1]) + a[0];
		for(int i = 1; i < n; i++) {
			if (a[i] - a[i-1] > max) {
				max = a[i] - a[i-1];
			}
		}
		System.out.println(k - max);
	}
	
	
	static void MergeSort(int[] a,int num) {
		int mid = (num+1)/2;
		int[] left = new int[mid];
		int[] right = new int[num-mid];

		
		if(num > 1) {
			
			for(int i = 0; i < mid; i++) {left[i] = a[i];}
			for(int i = 0; i < num-mid; i++) {right[i] = a[mid+i];}
			MergeSort(left, mid);
			MergeSort(right, num-mid);
			Main.merge(a, left, right);
		}
	}
	static void merge(int[] a, int[] left, int[] right) {
		int i = 0, j = 0;
		while( i < left.length || j < right.length) {

			if(j >= right.length || (i < left.length && left[i] < right[j])) {
				a[i+j] = left[i];
				i++;
			}else {
				a[i+j] = right[j];
				j++;
			}
		}
	}
	
}
