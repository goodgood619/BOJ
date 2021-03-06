import java.io.*;
import java.util.Arrays;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().split(" ")[0]);
        for(int tc = 1;tc<=t;tc++) {
            int n = Integer.parseInt(br.readLine().split(" ")[0]);
            int[] a = new int[n];
            String[] input2 = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(input2[i]);
            }
            Arrays.sort(a);
            int m = Integer.parseInt(br.readLine().split(" ")[0]);
            String[] input3 = br.readLine().split(" ");
            for (int i = 0; i < m; i++) {
                int find = Integer.parseInt(input3[i]);
                int lower = lowerbound(0, n - 1, a, find);
                if(a[lower] == find) bw.write("1\n");
                else bw.write("0\n");
            }
        }
        bw.flush();
        bw.close();
    }
    private static int lowerbound(int left,int right,int[] a,int num) {
        while(left<right) {
            int mid = (left+right) / 2;
            if(a[mid]<num) left = mid+1;
            else right = mid;
        }
        return right;
    }
}