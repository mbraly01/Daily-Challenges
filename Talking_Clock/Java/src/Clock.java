import java.io.*;
import java.util.*;
import java.text.*;
import com.sun.speech.freetts.Voice;
import com.sun.speech.freetts.VoiceManager;

public class Clock {

    public static String getTimezone() {

        ArrayList<String> timeZoneAbbrev = new ArrayList<>();

        //reads in timezones
        try {
            File file = new File("/Users/mattbraly/Documents/Summer/Daily_Challenges/Talking_Clock/Java/src/TimeZones.csv");
            BufferedReader brTime = new BufferedReader(new FileReader(file));
            String line = "";
            while ((line = brTime.readLine()) != null) {
                String[] lineSplit = line.split(",");
                timeZoneAbbrev.add(lineSplit[0]);
            }
        } catch (FileNotFoundException fileNotFoundException) {

            fileNotFoundException.printStackTrace();
        }
        catch (IOException ioException) {
            ioException.printStackTrace();
        }

        boolean isValid = false;

        String str = "";

        //Gets input
        while (true) {
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter time zone");
            str = sc.nextLine();
            for (int i = 0; i < str.length(); i++) {
                char c = str.charAt(i);
                if (!(c >= 'A' && c <= 'Z') && !(c >= 'a' && c <= 'z')) {
                    break;
                }
                str.toUpperCase();
                for (String timeZone : timeZoneAbbrev) {
                    if (timeZone.equals(str)) {
                        return str;
                    }
                }
            }
            System.out.println("Invalid Input. Try again");

        }
    }

    //Gets gmt time
    public static String getTime(String timezone) {

        SimpleDateFormat sdf = new SimpleDateFormat("HH:mm");

        Date date = new Date();
        sdf.setTimeZone(TimeZone.getTimeZone(timezone));

        return sdf.format(date);
    }

    //Converts String
    public static String finalizeTime(String time) {
        String[] hourMin = time.split(":");

        String finalTime = "It's ";

        boolean isPM = false;
        int hour = Integer.valueOf(hourMin[0]);
        if ( hour > 11) {
            isPM = true;
            hour -= 12;
        }

        if (hour == 0) {
            finalTime += "twelve ";
        }
        else if (hour == 1) {
            finalTime += "one ";
        }
        else if (hour == 2) {
            finalTime += "two ";
        }
        else if (hour == 3) {
            finalTime += "three ";
        }
        else if (hour == 4) {
            finalTime += "four ";
        }
        else if (hour == 5) {
            finalTime += "five ";
        }
        else if (hour == 6) {
            finalTime += "six ";
        }
        else if (hour == 7) {
            finalTime += "seven ";
        }
        else if (hour == 8) {
            finalTime += "eight ";
        }
        else if (hour == 9) {
            finalTime += "nine ";
        }
        else if (hour == 10) {
            finalTime += "ten ";
        }
        else if (hour == 11) {
            finalTime += "eleven ";
        }

        int min = Integer.valueOf(hourMin[1]);
        int minStart = min / 10;
        int minEnd = min % 10;
        if (min < 10 || min > 19) {
            if (minStart == 0) {
                finalTime += " o ";
            }
            else if (minStart == 2) {
                finalTime += "twenty ";
            }
            else if (minStart == 3) {
                finalTime += "thirty ";
            }
            else if (minStart == 4) {
                finalTime += "forty ";
            }
            else if (minStart == 5) {
                finalTime += "fifty";
            }
        }

        if (min == 11) {
            finalTime += "eleven ";
            minStart = 0;
        }
        else if (min == 12) {
            finalTime += "twelve ";
            minStart = 0;
        }
        else if (min == 13) {
            finalTime += "thirteen";
            minStart = 0;
        }
        else {
            if (minEnd == 1) {
                finalTime += "one";
            }
            else if (minEnd == 2) {
                finalTime += "two";
            }
            else if (minEnd == 3) {
                finalTime += "three";
            }
            else if (minEnd == 4) {
                finalTime += "four";
            }
            else if (minEnd == 5) {
                finalTime += "five";
            }
            else if (minEnd == 6) {
                finalTime += "six";
            }
            else if (minEnd == 7) {
                finalTime += "seven";
            }
            else if (minEnd == 8) {
                finalTime += "eight";
            }
            else if (minEnd == 9) {
                finalTime += "nine";
            }

        }

        if (minStart == 1) {
            finalTime += "teen";
        }

        if (isPM == false) {
            finalTime += " A.M.";
        }
        else {
            finalTime += " P.M.";
        }


        return finalTime;
    }

    //Gets computer to talk
    public static void Talk(String time) {
        System.setProperty("freetts.voices", "com.sun.speech.freetts.en.us.cmu_us_kal.KevinVoiceDirectory");
        final VoiceManager voiceManager = VoiceManager.getInstance();
        final Voice voice = voiceManager.getVoice("kevin16");
        voice.allocate();

        voice.speak(time);
    }

    public static void main(String[] args) {

        String time = finalizeTime(getTime(getTimezone()));
        System.out.println(time);
        Talk(time);

    }
}
