import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdStats;
import edu.princeton.cs.algs4.StdRandom;

public class PercolationStats{
    private final double CONFIDENCE_95=1.96;
    private int times; // times for experiment times,count for open sites every experiment
    private double[] p; // record the status for every site,true for open, false for blocked
    public PercolationStats(int n,int trials) {
        if (n<= 0 || trials<= 0){
            throw new IllegalArgumentException("n and trials should be bigger than 0 !");
        }
        p=new double[trials]; // allocate memory for p
        times=trials;
        int row, col, count;
        for (int i = 0; i < trials; i++) {
            count = 0; // clear the value of count for a new test
            Percolation per = new Percolation(n);
            while (!per.percolates()) { // quit until table is percolated
                do { // select a block site randomly
                    row=StdRandom.uniform(n) + 1;
                    col=StdRandom.uniform(n) + 1;
                }while (per.isOpen(row, col));
                per.open(row, col);
                count++; // cout plus one when a new site opens
            }
            p[i] = count/(double)(n * n); // calculate rate of open sites every experiment
        }
    }

    public double mean() { // calculate the average rate of the all experiments
        double sum = 0;
        sum = StdStats.mean(p);
        return sum;
    }

    public double stddev(){
        double sum = 0;
        sum = StdStats.stddev(p);
        return sum;
    }

    public double confidenceLo() {
        double a = mean() - CONFIDENCE_95 * stddev() / Math.sqrt((double) times);
        return a;
    }

    public double confidenceHi() {
        double a = mean() + CONFIDENCE_95 * stddev() / Math.sqrt((double) times);
        return a;
    }

    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]); // the first args for n which decides the size of table
        int T = Integer.parseInt(args[1]); // the second args for T which decides the experiment times
        PercolationStats per=new PercolationStats(n,T);
        StdOut.println("mean                     =" + per.mean());
        StdOut.println("stddev                   =" + per.stddev());
        StdOut.println("95%% confidence interval = [" + per.confidenceLo()+","+per.confidenceLo()+"]");
    }
}
