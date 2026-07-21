import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String X =sc.next();
        String Y =sc.next();
        int numX;
        int numY;
        
        if(X.equals("A")){
            numX=1;
        }else if(X.equals("B")){
            numX=2;
        }else if(X.equals("C")){
            numX=3;
        }else if(X.equals("D")){
            numX=4;
        }else if(X.equals("E")){
            numX=5;
        }else if(X.equals("F")){
            numX=6;
        }else{
            numX=0;
        }
        
        if(Y.equals("A")){
            numY=1;
        }else if(Y.equals("B")){
            numY=2;
        }else if(Y.equals("C")){
            numY=3;
        }else if(Y.equals("D")){
            numY=4;
        }else if(Y.equals("E")){
            numY=5;
        }else if(Y.equals("F")){
            numY=6;
        }else{
            numY=0;
            
        }
        
        if(numX<numY){
            System.out.println("<");
        }else if(numX>numY){
            System.out.println(">");
        }else{
            System.out.println("=");
        }
        
        
   }
}
