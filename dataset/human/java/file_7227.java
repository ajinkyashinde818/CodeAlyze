import java.util.Scanner;

/**
 * Another way to put the question is to calculate the longest arc between two houses around the circle. the
 * houses will be visited in such a way that the arc won't be passed through.
 * substract the length of the longest arc from the circumference(k) of the circular pond. that is the answer
 */
public class Main {
    public static void main(String[] args) {
        final Scanner input = new Scanner(System.in);
        int k= input.nextInt();
        int n=input.nextInt();

       int maxArc =0,northToFirst=0,lastToNorth=0;



        //for the first case
        int cur=0,prev=0;

        //get the dis

        for (int i = 1; i <= n; i++) {
            prev =cur;
            cur =input.nextInt();

            //get the distance between the zero point(north) and first house
            if(i==1){
               northToFirst = cur;
            }
            //get the distance between the last house and the zero point (north)
            if(i==n){
                lastToNorth = k-cur;
            }

            //compare every other arcs
            if(i>=2){
                int arc = cur-prev;
                if(arc > maxArc){
                    maxArc = arc;
                }
            }


        }
        //check the last arc. i.e. spack between the first and last houses

        if((lastToNorth + northToFirst) > maxArc){
            maxArc = lastToNorth + northToFirst;
        }

        //answer, i.e min distance around the lake is

        System.out.println(k-maxArc);


    }
}
