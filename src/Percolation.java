import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
    private final boolean[] status;// record the status of every item: true for open,false for blocked
    private final int rows,cols;
    private int count = 0;
    private final int longth;   // convert rows*cols to longth
    private final WeightedQuickUnionUF uf,uf1;// union items
    public Percolation(int n) {
        if(n <= 0){
            throw new IllegalArgumentException("n must be bigger than 0 !");
        }
        longth = n * n;
        rows = n;
        cols = n;
        status = new boolean[longth];// allocate memory for status
        uf = new WeightedQuickUnionUF(longth+2);
        uf1 = new WeightedQuickUnionUF(longth+1);

        //reater a tree of n+2, position at longth and longth+1 are for vitual top and bottom respectivly
        for(int i = 0; i < longth - 1; i++){
            status[i]=false;// every item is blocked default
        }
    }

    public void open(int row,int col) { // open the item at(row,col) if not & union it to others which are open and closed to it
        if (row < 1 || row > rows){
            throw new IllegalArgumentException("index rows must between 1 and" + " " + rows);
        }
        if (col < 1 || col > cols){
            throw new IllegalArgumentException("index rows must between 1 and" + " " + cols);
        }
        int pos=revert(row, col);// covert 2D position to 1D position
        if (status[pos]){
            return;// if the item is open,then quit
        }
        count++;
        status[pos] = true;// open the item
        // union items around the current item
        if (row == 1) {
            uf.union(pos,longth);
            uf1.union(pos,longth);
        } //if the item is in the first row ,then union it to the visual top
        if (row == rows){
            uf.union(pos,longth+1);// if the item is in the bottom,then union it to the visual bottom
        }
        // covert the items' positon that are over and below the current item to 1D position
        int up = revert(row - 1,col);
        int down = revert(row + 1,col);
        if (row > 1) {
            if(status[up]){
                uf.union(up, pos);
                uf1.union(up, pos);
            }
        } // if the item'row is bigger than 1 and the item over it is open,then union thenm together
        if (row<rows) {
            if(status[down]){
                uf.union(down, pos);
                uf1.union(down, pos);
            }
        } // if the item'row is less than rows and the item below it is open,then union thenm together
        int left = revert(row, col-1);
        int right = revert(row, col+1);
        if (col > 1) {
            if(status[left]) {
                uf.union(left, pos);
                uf1.union(pos, left);
            }
        } // if the item'col is bigger than 1 and the left item  is open,then union thenm together
        if (col < rows) {
            if (status[right]) {
                uf.union(right, pos);
                uf1.union(pos, right);
            }
        } // if the item'col is less than cols and the right item  is open,then union thenm together

    }

    public boolean percolates() {
        boolean a = uf.connected(longth, longth + 1);
        return a;
        //if the visual top and bottom is connected ,then the table is percolated
    }

    public boolean isOpen(int row,int col) { //validate item at(row,col) open or not
        if(row < 1 || row > rows){
            throw new IllegalArgumentException("index rows must between 1 and" + " " + rows);
        }
        if(col < 1 || col > cols){
            throw new IllegalArgumentException("index rows must between 1 and" + " " + cols);
        }
        int pos = (row - 1) * rows + col - 1;
        return status[pos];
    }

    public boolean isFull(int row,int col) {
        if(row < 1 || row > rows){
            throw new IllegalArgumentException("index rows must between 1 and" + " " + rows);
        }
        if(col < 1 || col > cols){
            throw new IllegalArgumentException("index rows must between 1 and" + " " + cols);
        }
        int pos = (row - 1) * rows + col - 1;
        return uf1.connected(pos, longth);
    }

    public int numberOfOpenSites() {
        return count;
    }

    private int revert(int row,int col){
        int a = (row - 1) * rows + col - 1;
        return a;
    }

    public static void main(String[] args) {
        int n = StdIn.readInt();
        StdOut.println("please input a integer bigger than 1 to establish a tree");
        Percolation per = new Percolation(n);//  read the first arg to establish a tree
        int row, col;
        StdOut.println("please input integer to union tree");
        StdOut.println("enter Crtl + D to quit...");
        while (!StdIn.isEmpty()) {
            //
            //read two numbers one by one for row and col
            row = StdIn.readInt();
            col = StdIn.readInt();
            per.open(row, col);
        }
        if (per.percolates()) StdOut.println("It is percolated!");
        else StdOut.println("It is not percolated!");
    }
}
