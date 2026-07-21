import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//List<String> list=new ArrayList<String>(Arrays.asList(s.split("")));
		List<Integer> list=new ArrayList<Integer>();
		//int[] array = new int[2000000];
		int k = sc.nextInt();
		int n = sc.nextInt();
		for(int i=0;n>i;i++) {
			int a=sc.nextInt();
			list.add(a);
		}
		Collections.sort(list);
		int count=0;
		List<Integer> list_check=new ArrayList<Integer>();
		for(int i=0;n-1>i;i++) {
			count=count+list.get(i+1)-list.get(i);
			list_check.add(list.get(i+1)-list.get(i));
		}
		count=count+k+list.get(0)-list.get(n-1);
		list_check.add(k+list.get(0)-list.get(n-1));
		int max = Collections.max(list_check);
		System.out.println(count-max);

	}
}
