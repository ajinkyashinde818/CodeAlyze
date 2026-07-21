import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
 
public class Main {
	   
	public static void main(String[] args) throws IOException {
		 // TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String S= br.readLine();
			String T= br.readLine();
			String Alpha= "abcdefghijklmnopqrstuvwxyz";
			int[] Arrs = new int[26];
			int[] Arrt = new int[26];
			for(int i=0;i<Alpha.length();i++){
				char ch=Alpha.charAt(i);
				int count=0;
				for(int a=0;a<S.length();a++){
					char ch1=S.charAt(a);
					if(ch==ch1){
						count++;
					}
				}
				Arrs[i]=count;
			}
			for(int i=0;i<Alpha.length();i++){
				char ch=Alpha.charAt(i);
				int count=0;
				for(int a=0;a<T.length();a++){
					char ch1=T.charAt(a);
					if(ch==ch1){
						count++;
					}
				}
				Arrt[i]=count;
			}
			String s="";
			for(int x=0;x<Arrs.length;x++){
				char ch=Alpha.charAt(x);
				for(int y=0;y<Arrs[x];y++){
					s+=String.valueOf(ch);
				}
			}
			String t="";
			for(int x=Arrt.length-1;x>-1;x--){
				char ch=Alpha.charAt(x);
				for(int y=0;y<Arrt[x];y++){
					t+=String.valueOf(ch);
				}
			}
			if(s.length()>t.length()){
				int check=0;
				for(int z=0;z<t.length();z++){
					char ch1 = s.charAt(z);
					char ch2 = t.charAt(z);
					int index1=Alpha.indexOf(ch1);
					int index2=Alpha.indexOf(ch2);
					if(index1<index2){
						check=1;
						break;
					}
				}
				if(check==0){
					System.out.println("No");
				}
				else{
					System.out.println("Yes");
				}
			}
			else if(s.length()<t.length()){
				int check=0;
				for(int z=0;z<s.length();z++){
					char ch1 = s.charAt(z);
					char ch2 = t.charAt(z);
					int index1=Alpha.indexOf(ch1);
					int index2=Alpha.indexOf(ch2);
					if(index1<index2){
						check=1;
						break;
					}
				}
				int e=0;
				for(int z=0;z<s.length();z++){
					char ch1 = s.charAt(z);
					char ch2 = t.charAt(z);
					if(ch1!=ch2){
						e=1;
					}
				}
				if(e==0){
					System.out.println("Yes");
				}
				else if(e==1){
					if(check==0){
						System.out.println("No");
					}
					else{
						System.out.println("Yes");
					}
				}
				
			}
			else if(s.length()==t.length()){
				int check=0;
				for(int z=0;z<t.length();z++){
					char ch1 = s.charAt(z);
					char ch2 = t.charAt(z);
					int index1=Alpha.indexOf(ch1);
					int index2=Alpha.indexOf(ch2);
					if(index1<index2){
						check=1;
						break;
					}
				}
				if(check==0){
					System.out.println("No");
				}
				else{
					System.out.println("Yes");
				}
			}
			//System.out.println(s +" "+t);
			
	}
}
