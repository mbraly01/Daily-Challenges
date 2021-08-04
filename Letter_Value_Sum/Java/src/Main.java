import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
       Scanner scanner = new Scanner(System.in);
       boolean isValid = false;
       int total = 0;
       String str = "";

       while (!isValid) {
           System.out.println("Enter a string (no special characters. only letters): ");

           str = scanner.nextLine();
           str = str.toLowerCase();
           isValid = true;
           for (int i = 0; i < str.length(); i ++) {
               total += (int)str.charAt(i);
               if (!Character.isLetter(str.charAt(i))) {
                   isValid = false;
                   total = 0;
                   break;
               }
           }
       }
       total -= 96*str.length();

       System.out.println(total);

    }
}
