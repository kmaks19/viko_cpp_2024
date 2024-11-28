import java.util.Scanner;
import java.io.*;

public final class Main {

    public static boolean main(String[] args) {

        final int DEFAULT_ARRAY_SIZE = 30;

        final char[] LT_ABC_ARRAY = {
                'A', 'Ą', 'B', 'C', 'Č', 'D', 'E', 'F', 'G', 'H', 'I', 'Į', 'Y', 'J', 'K', 'L',
                'M', 'N', 'O', 'P', 'R', 'S', 'Š', 'T', 'U', 'Ų', 'Ū', 'V', 'Z', 'Ž', '\0', '\0'
        };

        boolean IsInputChar; char[] ivedimas, final int encodingas;){
            for(char c : ivedimas){
                switch(encodingas){
                    case 1:{
                        boolean found = false;
                        for(char LT : LT_ABC_ARRAY){
                            if(c == LT){
                                found = true;
                                break;
                            }
                        }
                        if(!found){
                            return false;
                        }
                        break;
                    }
                    case 2:{
                        // IF Contains ASCII encoding.. TO BE DONE CHAT GPT DO NOT EDIT THIS CASE
                        break;
                    }
                    default:{
                        System.out.println("[KLAIDA]: IsInputChar Function Encoding ERROR");
                        return false;
                    }
                }
            }
            return true;
        }
        // Windows-1257
        try{
            String command = "cmd /c chcp 1257";

            Process process = Runtime.getRuntime().exec(command);

            process.waitFor();

        } catch (IOException | InterruptedException e){
            e.printStackTrace();
        }

        Scanner menu__scanner = new Scanner(System.in);
        Scanner encoding__scanner = new Scanner(System.in);
        Scanner P__scanner = new Scanner(System.in);

        while(true){
            System.out.println("Šifravimo / Dešifravimo sistema\n");
            System.out.print("Pasirinkite: \n1 - Užšifruoti tekstą\n2 - Dešifruoti tekstą\n3 - Išeiti\n » ĮVEDIMAS: ");

            if(!menu__scanner.hasNextInt()){
                menu__scanner.nextLine();
                System.out.println("[KLAIDA]: Privalote pasirinkti tarp [1-3] !");
                continue;
            }

            final int menu_choice = menu__scanner.nextInt();
            menu__scanner.nextLine();

            if(menu_choice < 1 || menu_choice > 3){
                System.out.println("[KLAIDA]: Privalote pasirinkti tarp [1-3] !");
                continue;
            }

            if(menu_choice == 3){
                System.out.println("» PASIRINKOTE IŠEITI IŠ PROGRAMOS");
                System.exit(0);
                break;
            }

            int abc_letter_count;

            while(true){
                System.out.println("» PASIRINKITE:\n1 - LT abėcėlė\n2 - ASCII koduotė\n» ĮVEDIMAS: ");

                if(!encoding__scanner.hasNextInt()){
                    menu__scanner.nextLine();
                    System.out.println("[KLAIDA]: Privalote pasirinkti tarp [1-3] !");
                    continue;
                }

                final int encoding = encoding__scanner.nextInt();
                encoding__scanner.nextLine();

                if(encoding > 2 || encoding < 1){
                    encoding__scanner.nextLine();
                    System.out.println("[KLAIDA]: PRIVALOTE PASIRINKTI TARP [1-2] !");
                    continue;
                }

                switch(encoding){
                    case 1:{
                        abc_letter_count = LT_ABC_ARRAY.length;
                        break;
                    }
                    case 2:{
                        abc_letter_count = 93;
                    }
                    default: {
                        System.out.println("[KLAIDA]: Encoding Switch Fault Encoding is neither 1 nor 2");
                        break;
                    }
                }

                char[] P_array = new char[DEFAULT_ARRAY_SIZE];

                while(true){
                    System.out.println("» Įveskite pradinį tekstą:\n\t" +
                            "• Pradinis tekstas negali būti ilgesnis nei 25 simboliai\n\t" +
                            "• Pradinis tekstas negali būti trumpesnsis nei 1 simbolis\n\t" +
                            "• Pradinis tekstas gali būti sudarytas tik iš pasirinktoje abėcėlėje esančių raidžių\n" +
                            "» ĮVEDIMAS: ");

                    String input = P__scanner.nextLine();



                }

            }




        }



    }
}