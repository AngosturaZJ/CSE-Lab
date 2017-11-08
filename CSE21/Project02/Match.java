import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.ArrayList;

public class Match {

	public ArrayList<Student> readFile() {
		System.out.print("Enter the file name: ");
		Scanner kbd = new Scanner(System.in);
		String filename = kbd.next();
		return readFile(filename);
	}
	
	public ArrayList<Student> readFile(String filename) {
		int count = 0;
		ArrayList<Student> s_array = new ArrayList<Student>();
		
		try {
			Scanner scan = new Scanner ( new FileReader(filename) );

			while (scan.hasNextLine()) {
				String s = scan.nextLine();
				Student pp = new Student();
				
				Scanner input = new Scanner (s);
				input.useDelimiter("\t|-");
	
                pp.setname(input.next());
                pp.setgender(input.next().charAt(0));
                
                Date birthday = new Date(Integer.parseInt(input.next()), Integer.parseInt(input.next()), Integer.parseInt(input.next()));
                pp.setbirthday(birthday);
                
                Preference pref = new Preference(Integer.parseInt(input.next()), Integer.parseInt(input.next()), Integer.parseInt(input.next()), Integer.parseInt(input.next()));
                pp.setpreference(pref);
                
                s_array.add(pp);
                count = count + 1;
                input.close();
			} 
			scan.close();
		} catch ( NoSuchElementException e){
			System.out.println(e); 
			
		} catch (FileNotFoundException e) {
			System.out.println(e);
		}
		return s_array;
	}
	
	public void CheckCompatibility(ArrayList<Student> st) {
		int currentScore, maxScore, index, i , j;
		for (i = 0; i < st.size(); i++){
	        maxScore = 0;
	        index = -1;
			for (j = 0; j < st.size() ; j++){
			    if ((i!=j) && (!st.get(i).getmatched()) && (!st.get(j).getmatched())){
				    currentScore = st.get(i).compare(st.get(j));
				    if (currentScore > maxScore){
				    	maxScore = currentScore;
				    	index = j;
				    } 				        
			    }
			}
            if (index != -1){
            	st.get(i).setmatched(true);
            	st.get(index).setmatched(true);
            	System.out.println(st.get(i).getname() + " matches with " + st.get(index).getname() + " with the sore " + maxScore);
            }
            else if (!st.get(i).getmatched()){
            	System.out.println(st.get(i).getname() + " has no matches ");
            }
            else{
            	;
            }
		}		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Match test = new Match();
		ArrayList<Student> st = test.readFile();
		test.CheckCompatibility(st);
	}

}
