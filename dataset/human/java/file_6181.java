import java.io.*;

class Main{
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int output = 0;
        try{
            String[] keyboardInput = br.readLine().split(" ");
            int K = Integer.parseInt(keyboardInput[0]);
            int S = Integer.parseInt(keyboardInput[1]);
            for(int x = 0; x <= K; x++){
                for(int y = 0; y <= K; y++){
                    if(S - x - y >= 0 && S - x - y <= K){
                        output++;
                    }
                }
            }
            System.out.println(output);
        } catch(IOException e){
            System.out.println(e.getMessage());
        }
    }
}
