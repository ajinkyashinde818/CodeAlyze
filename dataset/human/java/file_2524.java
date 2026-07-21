import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();

		for (int i = 0; i < n; i++) {
			String str = sc.next();
			String str2 = sc.next();
			
			int str11=change(str);
		//	System.out.println(str11);
			int str22=change(str2);
		//	System.out.println(str22);
			int result=str11+str22;
			
			String re=remake(result);
			System.out.println(re);
		}

	}

	public static int change(String sss) {

	
		ArrayList<Integer> list2 = new ArrayList<Integer>();

		int sum = 0;

		for (int i = 0; i < sss.length(); i++) {
			try {
				int sub = Integer.parseInt(""+sss.charAt(i));
				list2.add(sub);
			} catch (Exception e) {
				//list.add("" + sss.charAt(i));
			//	System.out.println(sss.charAt(i));
				if (list2.isEmpty()) {
					sum+=mathda(1,""+sss.charAt(i));
				} else {
					sum+=mathda(list2.remove(0),""+sss.charAt(i));
				}
			}

		}
		return sum;
	}

	public static int mathda(int num, String strstr) {

		switch (strstr) {
		case "m":
			return num * 1000;
		case "c":
			return num * 100;
		case "x":
			return num * 10;
		case "i":
			return num;
		}
		return 0;

	}

	
	public static String remake(int sss) {


	String restr="";
	int sub;
	int now;
	if((sub=sss/1000)>0){
		
		if(sub!=1)restr+=""+sub;
		restr+="m";
		sss=sss%1000;
	}
	
	if((sub=sss/100)>0){
		if(sub!=1)restr+=""+sub;
		restr+="c";
		sss=sss%100;
	}
	
	if((sub=sss/10)>0){
		if(sub!=1)restr+=""+sub;
		restr+="x";
		sss=sss%10;
	}
	if(sss!=0){
		if(sss!=1)restr+=""+sss;
		restr+="i";
	}
	
	return restr;
	
		
	
	}
}
