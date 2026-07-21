import java.lang.*;
import java.util.*;
public class Main{
public static void main(String[] args) 
{
	Scanner scanner=new Scanner(System.in);
	String s=scanner.next();
	int tr=0;
	int ans=1;
	int i=0;
	while(true)
	{	tr=0;
		if(i>=s.length())break;
		String s1=" ",s2=" ",s3=" ",s4=" ";
		if(i+5<=s.length())s1=s.substring(i,i+5);
		if(i+6<=s.length())s2=s.substring(i,i+6);
		if(i+7<=s.length())s3=s.substring(i,i+7);
		if(s1.compareTo("dream")==0)tr=1;
		if(s1.compareTo("erase")==0)tr=2;
		if(s2.compareTo("eraser")==0)tr=4;
		if(s3.compareTo("dreamer")==0){
			if(i+10<=s.length())s4=s.substring(i,i+10);
			if(s4.compareTo("dreamerase")==0)tr=1;
			else tr=3;
		}
		if(tr==0){ans=0;break;}
		if(tr==3){i+=7;continue;}
		if(tr==4){i+=6;continue;}
		if(tr==1 || tr==2)i+=5;
	}
	if(ans==1)System.out.println("YES");
	else System.out.println("NO");
}	
}
