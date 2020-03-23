
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class SocialNetworkConnUF {
    //int[][] timestamp = new int[][]{{1, 2}, {1, 0}, {7, 8}, {6, 7}, {1, 5}, {4, 9}, {0, 3}, {0, 4}, {1, 6}, {5, 9}};
    int[] point;
    int count;    //the num of leave root
    int[] size;  //the root num of tree
    private WeightedQuickUnionUF uf;

    public SocialNetworkConnUF(int num)
    {
        this.point = new int[num];
        this.size = new int[num];
        count = size.length;
        for (int i = 0; i < this.point.length; i++)
        {
            this.point[i] = i;
        }
        for (int i = 0; i<size.length; i++) {
            size[i] = 1;
        }
    }

    public void union(int q, int p){
        int root1 = root(q);
        int root2 = root(p);
        if (root1 == root2) return;
        if (size[root1] < size[root2]) {
            point[root1] = point[root2];
            size[root2] += size[root1];
        }
        else {
            point[root2] = point[root1];
            size[root1] = size[root2];
        }
        count --;
    }

    public int root(int i){
        while (point[i] != i){
            point[i] = point[point[i]];
            i = point[i];
        }
        return i;
    }

    public static void main(String[] args){
        SocialNetworkConnUF suf = new SocialNetworkConnUF(10);
        int count = 1;
        while (true){
            //Scanner scanner = new Scanner(System.in);
            //int q = scanner.nextInt();
            //int p = scanner.nextInt();
            int q = StdIn.readInt();
            int p = StdIn.readInt();
            suf.union(q,p);
            if (suf.count == 1) {
                StdOut.println("all points connected in log " + count);
            }
            StdOut.println(suf.count);
            count++;
        }
    }
}
