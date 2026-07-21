import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//List<String> list= new ArrayList<String>(Arrays.asList(s.split("")));
		//List<Integer> list_gold=new ArrayList<Integer>();
		//Integer[] Republican = new Integer[m];
		List<Integer> list_jun=new ArrayList<Integer>();
		List<Integer> list_tuika=new ArrayList<Integer>();
		int manzoku=0;

		int n = sc.nextInt();

		for(int i=0;n>i;i++) {
			int a = sc.nextInt();
			list_jun.add(a);
		}

		for(int i=0;n>i;i++) {
			int a = sc.nextInt();
			manzoku=manzoku+a;
		}
		for(int i=0;n-1>i;i++) {
			int a = sc.nextInt();
			list_tuika.add(a);
		}
		for(int i=0;n-1>i;i++) {
			if(list_jun.get(i)+1==list_jun.get(i+1))
				manzoku=manzoku+list_tuika.get(list_jun.get(i)-1);
		}

		System.out.println(manzoku);


	}

}
