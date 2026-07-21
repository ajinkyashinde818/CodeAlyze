import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//List<String> list= new ArrayList<String>(Arrays.asList(s.split("")));
		List<Integer> list=new ArrayList<Integer>();
		//Integer[] array = new Integer[m];
        int n = sc.nextInt();
        long count=0;
        int mai=0;
        int min=1000000000;
        for(int i=0;n>i;i++) {
        	int a = sc.nextInt();
        	if(a<0) {
        		list.add(-a);
        		count=count+-a;
        		mai++;
        		if(-a<min)
        			min=-a;
        	}
        	else {
        		list.add(a);
        		count=count+a;
        		if(a<min)
        			min=a;
        	}
        }
        if(mai%2==0)
        	System.out.println(count);
        else {
        	System.out.println(count-2*min);
        }

	}
}
