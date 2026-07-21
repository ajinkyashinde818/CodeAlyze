import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double xs = sc.nextDouble();
        double ys = sc.nextDouble();
        double xg = sc.nextDouble();
        double yg = sc.nextDouble();
        int N = sc.nextInt();
        double[] x = new double[N+2];
        double[] y = new double[N+2];
        double[] r = new double[N+2];
        for (int i=0;i<N;i++) {
            x[i] = sc.nextDouble();
            y[i] = sc.nextDouble();
            r[i] = sc.nextDouble();
        }
        x[N]=xs;y[N]=ys;r[N]=0;x[N+1]=xg;y[N+1]=yg;r[N+1]=0;

        ArrayList<ArrayList<double[]>> edge = new ArrayList<ArrayList<double[]>>();
        for (int i=0;i<N+2;i++) {
            ArrayList<double[]> add = new ArrayList<double[]>();
            edge.add(add);
        }
        for (int i=0;i<N+2;i++) {
            for (int j=0;j<N+2;j++) {
                if (i==j) continue;
                double dist = Math.pow(Math.pow(x[i]-x[j], 2)+Math.pow(y[i]-y[j], 2), 0.5);
                double[] add = {j, Math.max(dist-r[i]-r[j], 0)};
                edge.get(i).add(add);
            }
        }

        double[] dist_arr = new double[N+2];
        Arrays.fill(dist_arr, -1);
        double[] first = {N, 0};
        PriorityQueue<double[]> pq = new PriorityQueue<double[]>((o1, o2)->Double.compare(o1[1], o2[1]));
        pq.add(first);
        while (!pq.isEmpty()) {
            double[] rem = pq.poll();
            if (dist_arr[(int)rem[0]]!=-1) continue;
            dist_arr[(int)rem[0]] = rem[1];
            for (double[] tmp : edge.get((int)rem[0])) {
                double[] add = {tmp[0], rem[1]+tmp[1]};
                if (dist_arr[(int)tmp[0]]==-1) pq.add(add);
            }
        }
        System.out.println(dist_arr[N+1]);
        // System.out.println(Arrays.toString(dist_arr));
        // System.out.println(edge);
    }
}
