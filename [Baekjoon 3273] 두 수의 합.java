import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Vector;

public class Main {
	
	static Scanner scanner = new Scanner(System.in);
	static int N, x;
	static Vector<Integer> a;
	
	static void input() {
		N = scanner.nextInt();
		a = new Vector<Integer>(N);
		for(int i=0; i<N; i++)
			a.add(scanner.nextInt());
		x = scanner.nextInt();
	}
	
	static void solution() {
		int low, high, mid, count;
		Collections.sort(a);
		count = 0;
		for(int i=0; i<N; i++) {
			int u = a.get(i);
			low = 0; high = N - 1;
			while(low <= high) {
				mid = (low + high)/2;
				if(u + a.get(mid) == x) {
					count++;
					break;
				}
				else if(u + a.get(mid) < x) {
					low = mid + 1;
				}
				else {
					high = mid - 1;
				}
			}
		}
		System.out.println(count / 2);
	}
	
	public static void main(String[] args) {		
		input();
		solution();
		scanner.close();
	}
}
