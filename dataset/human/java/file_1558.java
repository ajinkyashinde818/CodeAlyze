import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt(); 
        int b = sc.nextInt();
        int c = 0;
		String [] str1 = new String [a];
        String [] str2 = new String [b];
        for(int i=0;i<a;i++){str1[i] = sc.next();                             
                            }
        for(int i=0;i<b;i++){str2[i] = sc.next();                           
                            }
		String s = "No";
        for(int i=0;i<a-b+1;i++){ 
        for(int j=0;j<a-b+1;j++){c=0;                                                
        for(int k=0;k<b;k++){
          if(str1[i+k].substring(j,j+b).equals(str2[k])){c++;} 
          if(c==b){s = "Yes";break;}                       
        }       
                                }                                 
        }      
		System.out.println(s);
	}
}
