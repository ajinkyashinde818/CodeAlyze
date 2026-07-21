import java.io.*;
public class Main {
        public static void main(String[] args) throws IOException {
                BufferedReader a = new BufferedReader(new InputStreamReader(System.in));
                String b;
                String[] c = new String[2];
                int x = Integer.parseInt(a.readLine());
                for(int i = 0;i < x; ++i){
                        int n = Integer.parseInt(a.readLine());
                        b = a.readLine();
                        c[0] = b.substring(0,2*n);
                        c[1] = b.substring(2*n);
                        int count = 0;
                        boolean first = true;
                        boolean last  = false;
                        int j = 0;
                        if(c[0].charAt(2*j) == 'Y'){
                                ++count;
                                last = false;
                                first = false;
                        }
                        if(c[1].charAt(2*j) == 'Y'){
                                ++count;
                                last = true;
                                if(first){
                                        ++count;
                                        first = false;
                                }   
                        }   
                        for(++j;j < n; ++j){
                                if(c[0].charAt(2*j-1) == 'Y' || c[0].charAt(2*j) == 'Y'){
                                        ++count;
                                        first = false;
                                }   
                                if(c[1].charAt(2*j-1) == 'Y' || c[1].charAt(2*j) == 'Y'){
                                        ++count;
                                        if(first){
                                                ++count;
                                                first = false;
                                        }   
                                }

                                if(c[0].charAt(2*j-1) == 'Y' || c[0].charAt(2*j) == 'Y'){
                                        last = false;
                                } else if(c[1].charAt(2*j-1) == 'Y' || c[1].charAt(2*j) == 'Y'){
                                        last = true;
                                }
                        }
                        if(c[0].charAt(2*j-1) == 'Y'){
                                ++count;
                                first = false;
                        }
                        if(c[1].charAt(2*j-1) == 'Y'){
                                ++count;
                                if(first){
                                        ++count;
                                        first = false;
                                }
                        }
                        if(c[0].charAt(2*j-1) == 'Y'){
                                last = false;
                        } else if(c[1].charAt(2*j-1) == 'Y'){
                                last = true;
                        }
                        if(last){
                                ++count;
                        }
                        System.out.println(n+count);
                }
        }
}
