import java.util.*;

public class HW1
{
    public static void main(String[] args)
    {
        int selection = 0;
        Scanner input = new Scanner(System.in);

        while (selection < 1 || selection > 7) {
            System.out.println("\n\nEnter '1' open the database");
            System.out.println("      '2' to display a record");
            System.out.println("      '3' to update a record");
            System.out.println("      '4' to create a report");
            System.out.println("      '5' to add a record");
            System.out.println("      '6' to delete a record");
            System.out.println("      '7' to quit the program");
            System.out.println("Selection: ");

            selection = input.nextInt();
        }
    }
}
