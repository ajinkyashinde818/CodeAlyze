import java.util.*;
import java.util.Arrays;
import java.util.Set;
public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String S=sc.next();
        int[]a=new int[3];
        for(int i=0;i<3;i++){
            a[i]=0;
        }
        for(int i=0;i<3;i++){
            if(S.charAt(i)=='a'){
                a[0]++;
            }
            if(S.charAt(i)=='b'){
                a[1]++;
            }
            if(S.charAt(i)=='c'){
                a[2]++;
            }

        }
        if((a[0]>0)&&(a[1]>0)&&(a[2]>0)){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
        
        }
        
        
    }
