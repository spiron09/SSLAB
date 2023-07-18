import java.util.*;

public class LRU_FIFO {
    static int frameSize, numOfFrames, numOfMisses = 0, numOfHits = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter frame size: ");
        frameSize = sc.nextInt();

        int memory[] = new int[frameSize];

        System.out.print("Enter no of frames: ");
        numOfFrames = sc.nextInt();

        int pages[] = new int[numOfFrames];

        System.out.println("Enter frames: ");
        for (int i = 0; i < numOfFrames; i++)
            pages[i] = sc.nextInt();

        System.out.println("\n1. FIFO\n2. LRU\n3. Exit\n");
        int choice = sc.nextInt();

        switch (choice) {
            case 1:
                runFIFO(pages, memory);
                break;
            case 2:
                runLRU(pages, memory);
                break;
            case 3:
                System.exit(0);
        }
    }

    static void runFIFO(int pages[], int memory[]) {
        int nextFrameIndex = 0; // Keeps track of the index to insert the next page
        for (int i = 0; i < numOfFrames; i++) {
            if (isPageInMemory(memory, frameSize, pages[i])) {
                numOfHits++;
                // System.out.println(Arrays.toString(memory) + " HIT");
            } else {
                numOfMisses++;
                memory[nextFrameIndex] = pages[i];
                nextFrameIndex = (nextFrameIndex + 1) % frameSize;
                // System.out.println(Arrays.toString(memory) + " MISS");
            }
            
        }
        System.out.println("FIFO Algorithm");
        System.out.println("Number of Misses: " + numOfMisses);
        System.out.println("Number of Hits: " + numOfHits);
    }

    static void runLRU(int pages[], int memory[]) {
        int timeStamps[] = new int[frameSize];
        Arrays.fill(timeStamps, -1); // Initialize all elements of timeStamps to -1
        for (int i = 0; i < numOfFrames; i++) {
            boolean found = false;
            int page = pages[i];
            for (int j = 0; j < frameSize; j++) {
                if (memory[j] == page) {
                    timeStamps[j] = i;
                    found = true;
                    numOfHits++;
                    break;
                }
            }
            if (!found) {
                numOfMisses++;
                int lru = 0;
                for (int j = 1; j < frameSize; j++) {
                    if (timeStamps[j] < timeStamps[lru])
                        lru = j;
                }
                memory[lru] = page;
                timeStamps[lru] = i;
            }
        }
        System.out.println("LRU Algorithm");
        System.out.println("Number of Misses: " + numOfMisses);
        System.out.println("Number of Hits: " + numOfHits);
    }

    static boolean isPageInMemory(int memory[], int frameSize, int page) {
        for (int i = 0; i < frameSize; i++)
            if (memory[i] == page)
                return true;
        return false;
    }
}