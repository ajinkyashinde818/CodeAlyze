import java.util.*;
public class Main {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int num = s.nextInt();
        while(num!=0){
            int max = 0;
            int out = 0;
            char[][] data = new char[num][num];
            for(int i=0 ; i<num ; i++){
                String in = s.next();
                for(int j=0 ; j<num ; j++)
                    data[i][j] = in.charAt(j);
            }
            boolean one = false;
            for(int k=0 ; k<num ; k++){
                for(int l=0; l<num; l++){
                    if(data[k][l]=='.'){
                        one = true;
                        int m = 0;
                        while((l+m)<(num-1) && data[k][l+m]=='.')
                            m++;
                        if((m+k)>=num)
                            m = num - k - 1;
                        for(out=m ; out>=0 ; out--){
                            boolean flag = false;                            
                            for(int o=0 ; o<=out ; o++){
                                for(int p=0 ; p<=out ; p++){
                                    if(data[k+o][l+p]=='*'){
                                        flag = true;
                                        break;
                                    }
                                }
                                if(flag)
                                    break;                                    
                            }
                            if(!flag)
                                break;
                        }
                        if(out>max)
                            max = out; 
                    }      
                }
            }
            if(one)
                System.out.println(max+1);
            else
                System.out.println("0");
            num = s.nextInt();
        }
    }
}
