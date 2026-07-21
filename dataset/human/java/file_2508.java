import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			String line;
			/* input */
			line = br.readLine();

			int n = Integer.parseInt(line);
			if(n==0) return;

			for(int k=0;k<n;k++){
				String ex[] = br.readLine().split(" ");
				String sum ="";
				int m=0,c=0,x=0,i=0;
				for(int j=0;j<=1;j++){
					int ii = ex[j].indexOf("i");
					if(ii>-1){
						if(ii==0){
							i += 1;
						} else {
							if(Character.isDigit(ex[j].charAt(ii-1))){
								i += Integer.parseInt(ex[j].substring(ii-1,ii));
							} else {
								i += 1;
							}
						}
					}
					if(i>=10){
						x += 1;
						i -= 10;
					}
					int xi = ex[j].indexOf("x");
					if(xi>-1){
						if(xi==0){
							x += 1;
							if(x>=10){
								c += 1;
								x -= 10;
							}
						} else {
							if(Character.isDigit(ex[j].charAt(xi-1))){
								x += Integer.parseInt(ex[j].substring(xi-1,xi));
							} else {
								x += 1;
							}
						}
					}
					if(x>=10){
						c += 1;
						x -= 10;
					}
					int ci = ex[j].indexOf("c");
					if(ci>-1){
						if(ci==0){
							c += 1;
						} else {
							if(Character.isDigit(ex[j].charAt(ci-1))){
								c += Integer.parseInt(ex[j].substring(ci-1,ci));
							} else {
								c += 1;
							}
						}
					}
					if(c>=10){
						m += 1;
						c -= 10;
					}
					int mi = ex[j].indexOf("m");
					if(mi>-1){
						if(mi==0){
							m += 1;
						} else {
							if(Character.isDigit(ex[j].charAt(mi-1))){
								m += Integer.parseInt(ex[j].substring(mi-1,mi));
							} else {
								m += 1;
							}
						}
					}
				}
				String ms = ((m==0)?"":(m==1)?"m":(m+"m"));
				String cs = ((c==0)?"":(c==1)?"c":(c+"c"));
				String xs = ((x==0)?"":(x==1)?"x":(x+"x"));
				String is = ((i==0)?"":(i==1)?"i":(i+"i"));
				sum = ms + cs + xs + is;
				System.out.println(sum);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
