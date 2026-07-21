import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Iterator;
import java.util.Collections;
import java.util.Comparator;
import java.util.Random;

class Main{
        public static void main(String args[]){
                Scanner sc = new Scanner(System.in);
                String s = sc.next();
                int a=0,b=0,c=0;
                for(int i=0;i<3;i++){
                        if(s.charAt(i)=='a'){
                                a ++;
                        }else if(s.charAt(i)=='b'){
                                b ++;
                        }else if(s.charAt(i)=='c'){
                                c ++;
                        }
                }
                if(a==1&&b==1&&c==1){
                        System.out.print("Yes");
                }else{
                        System.out.print("No");
                }
        }
}
