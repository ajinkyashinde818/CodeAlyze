import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;import java.util.Collections;

 
public class Main {
    public static void main(String[] args) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
	    String str=reader.readLine();
	    String s[]=str.split(" ");
	    int e=Integer.parseInt(s[0]);
	    int y=Integer.parseInt(s[1]);

	    StringBuffer sb=new StringBuffer();

	    switch(e){
	    case 0:
		int year=0;
	        if(y<=1911){
		    year=y-1867;
		    sb.append("M");
		}else if(y<=1925){
		    year=y-1911;
		    sb.append("T");
		}else if(y<=1988){
		    year=y-1925;
		    sb.append("S");
		}else if(y<=2016){
		    year=y-1988;
		    sb.append("H");
		}
		sb.append(year);
		break;
	    case 1:
		y+=1867;
		sb.append(y);
		break;
	    case 2:
		y+=1911;
		sb.append(y);
		break;
	    case 3:
		y+=1925;
		sb.append(y);
		break;
	    case 4:
		y+=1988;
		sb.append(y);
		break;
	    }
	    System.out.println(sb);
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
