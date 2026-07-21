import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
 

public class Main{
          
    static int[][] round = new int[][]{{1,2,1,2,1,4,1,4},
        {1,2,1,4,1,4,1,2},{1,4,1,2,1,2,1,4},{1,4,1,4,1,2,1,2},
        {2,1,2,1,4,1,4,1},{2,1,4,1,4,1,2,1},{4,1,2,1,2,1,4,1},{4,1,4,1,2,1,2,1}
    };
     
     public static void main(String args[]){
         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
         
         try{ String line;
             while((line=br.readLine())!=null){if(line.isEmpty())break;
                String spl[] = line.split(" ");
                int e[] = new int[8];
                for(int i=0; i<8;i++){
                    e[i]=Integer.parseInt(spl[i]);
                }
                
                int min = Integer.MAX_VALUE;int bestRoundN=-1;
                for(int i=0;i<8;i++){
                    int round1[] = round[i];
                    int amari = 0; 
                    for(int j=0;j<8;j++){
                        amari+= (e[j]-round1[j]<=0)? 0: e[j]-round1[j];
                    }
                    if(amari<min){bestRoundN=i; min=amari;}
                }
                int[] bestRound = round[bestRoundN];
                for(int i=0;i<8;i++){
                    System.out.print(bestRound[i]);
                    if(i!=7)System.out.print(" ");
                }System.out.println("");
               
             } br.close();
            
         }catch(Exception e){e.printStackTrace();}         
     }  
    
     
     
}
