import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Vector;

public class Main {
	
	static Scanner scanner = new Scanner(System.in);
	static int N, M;
	static int A[];
	
	static void input() {
		N = scanner.nextInt();
		M = scanner.nextInt();
		A = new int[N];
		for(int i=0; i<N; i++)
			A[i] = scanner.nextInt();
	}
	
	static void solution() {
		int left, right, sum, count;
		left = sum = count = 0;
		right = -1;
		for(int i=0; i<N; i++) {
			right++;
			sum += A[i];
			while(sum >= M) {
				if(sum == M) count++;
				sum -= A[left];
				left++;
			}
		}
		System.out.println(count);
	}
	
	public static void main(String[] args) {		
		input();
		solution();
		scanner.close();
	}
}
