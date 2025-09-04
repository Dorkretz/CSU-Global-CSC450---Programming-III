/*
 * Demonstrates a simple thread-safe counter with count up and count down operations.
 * The Counter class provides synchronized methods to increment and decrement
 * a counter, printing its value at each step. The {@code Main} class runs these
 * operations in separate threads, ensuring that counting up completes before counting down.
 */
class Counter {
    private int count = 0;
    public synchronized void countUp() {
        while (count < 20) {
            count++;
            System.out.println("Count Up: " + count);
            try {
                Thread.sleep(100); // Delay for visibility
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
    public synchronized void countDown() {
        while (count > 0) {
            System.out.println("Count Down: " + count);
            count--;
            try {
                Thread.sleep(100); // Delay for visibility
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}
public class Main {
    public static void main(String[] args) {
        Counter counter = new Counter();

        Thread thread1 = new Thread(counter::countUp);
        Thread thread2 = new Thread(counter::countDown);

        thread1.start();
        try {
            thread1.join(); // Wait for thread1 to finish
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
        thread2.start();
    }
}
