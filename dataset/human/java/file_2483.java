import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Main {

	 public static void main(String[] args)throws Exception{

	 Scanner sc = new Scanner(System.in);


		 int n = sc.nextInt();

		 for(int i=0;i<n;i++)
		 {
			 String a = sc.next();
			 String b = sc.next();

			 a = a.trim();
			 b = b.trim();

			 int x = calcSum(a);
			 int y = calcSum(b)  ;

			 String result = tranceResult(x + y);
			 System.out.println(result);

		 }

	 }

	 public static String tranceResult(int num)
	 {

		 
		 String result ="";
		 
		 int tmp;
		 
		 tmp = num/1000;
		 if(tmp > 0){
			 if(tmp ==1)
				 result = result + "m";
			 else
				 result = result + tmp +"m";
		 }
		 
		 tmp = num % 1000 / 100;
		 if(tmp > 0){
			 if(tmp ==1)
				 result = result + "c";
			 else
				 result = result + tmp +"c";
		 }
		 
		 tmp = num % 100 / 10;
		 if(tmp > 0){
			 if(tmp ==1)
				 result = result + "x";
			 else
				 result = result + tmp +"x";
		 }
		 
		 tmp = num % 10;
		 if(tmp > 0){
			 if(tmp ==1)
				 result = result + "i";
			 else
				 result = result + tmp +"i";
		 }
		 
		 return result;
	 }
	 
	 public static  boolean isNumber(String num) {
		    String regex = "^[0-9]*$";
		    Pattern p = Pattern.compile(regex);
		    Matcher m = p.matcher(num);
		    return m.find();
		}

	 public static int calcSum(String str){

		 String[] A = str.split("");
		 int count = 0;

		 for(int i=0;i<A.length;i++)
		 {
			 if(A[i].equals("m"))
			 {
				 
				 if(i >0 &&isNumber(A[i-1]))
					 count += 1000 * Integer.parseInt(A[i-1]);
				 else
					 count += 1000;
			 }

			 if(A[i].equals("c"))
			 {
				 if(i >0 && isNumber(A[i-1]))
					 count += 100 * Integer.parseInt(A[i-1]);
				 else
					 count += 100;
			 }
			 if(A[i].equals("x"))
			 {
				 if(i >0 && isNumber(A[i-1]))
					 count += 10 * Integer.parseInt(A[i-1]);
				 else
					 count += 10;
			 }
			 if(A[i].equals("i"))
			 {
				 if(i >0 && isNumber(A[i-1]))
					 count += Integer.parseInt(A[i-1]);
				 else
					 count += 1;
			 }

		 }

		 return count;

	 }



}
