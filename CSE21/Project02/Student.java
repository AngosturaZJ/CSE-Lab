
public class Student {
	
	private String name;
	private char gender;
	private Date birthday;
	private Preference pref;
	private boolean matched;
	
	public Student () {
		this.name = "";
		this.gender = 'M';
		this.birthday = new Date(0, 0, 0);
		this.pref = new Preference(0, 0, 0, 0);
		this.matched = false;
	}
	
	public String getname() {
		return name;
	}
	
	public void setname(String name) {
		this.name = name;
	}
	
	public char getgender() {
		return gender;
	}
	
	public void setgender(char gender) {
		this.gender = gender;
	}
	
	public Date getbirthday() {
		return birthday;
	}

	public void setbirthday(Date birthday) {
		this.birthday.setyear(birthday.getyear());
		this.birthday.setmonth(birthday.getmonth());
		this.birthday.setday(birthday.getday());
	}
	
	public Preference getpreference() {
		return pref;
	}
	
	public void setpreference(Preference pref) {
		this.pref.set_quiet_Time(pref.get_quiet_Time());
		this.pref.setmusic(pref.getmusic());
		this.pref.setreading(pref.getreading());
		this.pref.setchatting(pref.getchatting());
	}
	
	public boolean getmatched(){
		return matched;
	}
	
	public void setmatched(boolean matched){
		this.matched = matched;
	}
	
	public int compare(Student st){
		int score = 0;
		if (this.gender != st.gender)
			return 0;
		int max_score = 100, min_score = 0;
		score = (40 - this.pref.compare(st.pref)) + (60 - Math.abs(this.birthday.compare(st.birthday)));
		if (score > max_score)
			return max_score;
		else if (score < min_score)
			return min_score;
		else
			return score;
	}


}
