import java.util.Scanner;

public class bankers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Input number of processes
        System.out.print("Enter the number of processes: ");
        int n = sc.nextInt();
        
        // Input number of resources
        System.out.print("Enter the number of resources: ");
        int m = sc.nextInt();

        // Declare the necessary arrays BM
        int[][] allocation = new int[n][m]; // Allocation matrix
        int[][] max = new int[n][m]; // Maximum demand matrix
        int[][] need = new int[n][m]; // Need matrix
        int[] available = new int[m]; // Available resources
        int[] safeSequence = new int[n]; // Safe sequence array

        // Input allocation matrix
        System.out.println("Enter the allocation matrix:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                allocation[i][j] = sc.nextInt();
            }
        }

        // Input maximum demand matrix
        System.out.println("Enter the maximum demand matrix:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                max[i][j] = sc.nextInt();
            }
        }

        // Input available resources
        System.out.println("Enter the available resources:");
        for (int i = 0; i < m; i++) {
            available[i] = sc.nextInt();
        }

        // Calculate the need matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                need[i][j] = max[i][j] - allocation[i][j];
            }
        }

        // Output the need matrix
        System.out.println("Need matrix:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(need[i][j] + " ");
            }
            System.out.println();
        }

        // Initialize the work and finish arrays
        int[] work = available.clone();
        boolean[] finish = new boolean[n];

        // Find a safe sequence
        int count = 0;
        while (count < n) {
            boolean found = false;
            for (int i = 0; i < n; i++) {
                if (!finish[i] && checkResources(work, need[i])) {
                    // Add the process to the safe sequence
                    for (int j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }
                    safeSequence[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
            if (!found) {
                System.out.println("The system is in an unsafe state.");
                return;
            }
        }

        // Print the safe sequence
        System.out.println("The system is in a safe state.");
        System.out.print("Safe sequence: ");
        for (int i = 0; i < n; i++) {
            System.out.print("P" + safeSequence[i]);
            if (i != n - 1) {
                System.out.print(" -> ");
            }
        }
    }

    // Helper function to check if the resources are available
    public static boolean checkResources(int[] work, int[] need) {
        for (int i = 0; i < work.length; i++) {
            if (work[i] < need[i]) {
                return false;
            }
        }
        return true;
    }
}