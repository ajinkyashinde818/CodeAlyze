import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	static int m,c,x,i;
	public static StringBuilder sb = new StringBuilder();

	//空白で区切る
	public static String[] cutStr(String str){
		String[] twoStr = new String[2];
		twoStr = str.split(" ");
		return twoStr;
	}

	//文字を数字にする
	public static int toNumber(String str1){
		int number = 0;
		int k=0;

		sb.delete(0, 10);

		sb.append(str1);

		m = sb.indexOf("m");
		c = sb.indexOf("c");
		x = sb.indexOf("x");
		i = sb.indexOf("i");

		if(m==-1){
		}else if(m == k){
			number += 1000;
			k++;
		}else {
			number += Integer.parseInt(sb.substring(k,k+1)) * 1000;
			k+=2;
		}

		if(c==-1){
		}else if(c == k){
			number += 100;
			k++;
		}else{
			number += Integer.parseInt(sb.substring(k,k+1)) * 100;
			k+=2;
		}

		if(x==-1){
		}else if(x == k){
			number += 10;
			k++;
		}else{
			number += Integer.parseInt(sb.substring(k,k+1)) * 10;
			k+=2;
		}

		if(i==-1){
		}else if(i == k){
			number += 1;
			k++;
		}else{
			number += Integer.parseInt(sb.substring(k,k+1)) * 1;
			k+=2;
		}

		return number;
	}

	//数字を足して文字に直す
	public static String addStr(int n, int m){
		String addedStr = null;

		int sum = n + m;
		int sum_m = sum / 1000;
		int sum_c = (sum % 1000) / 100;
		int sum_x = (sum % 100) / 10;
		int sum_i = sum % 10;

		StringBuilder ans = new StringBuilder();
		if (sum_m >= 2) {
			ans.append(sum_m);
		}
		if (sum_m >= 1) {
			ans.append("m");
		}

		if (sum_c >= 2) {
			ans.append(sum_c);
		}
		if (sum_c >= 1) {
			ans.append("c");
		}

		if (sum_x >= 2) {
			ans.append(sum_x);
		}
		if (sum_x >= 1) {
			ans.append("x");
		}

		if (sum_i >= 2) {
			ans.append(sum_i);
		}
		if (sum_i >= 1) {
			ans.append("i");
		}

		addedStr = ans.toString();

		return addedStr;
	}



	public static void main(String[] args) throws IOException {

		BufferedReader br = new  BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();

		int numMax = Integer.parseInt(str);

		String[] answer = new String[numMax];

		for(int j=0;j<numMax;j++){
			str = br.readLine();
			String[] twoStr = cutStr(str);
			int n = toNumber(twoStr[0]);
			int m = toNumber(twoStr[1]);
			str = addStr(n,m);

			answer[j] = str;
		}

		for(int j=0;j<numMax;j++){
		System.out.println(answer[j]);
		}
	}

}
