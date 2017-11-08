
public class Preference {
	
	private int quiet_Time;
	private int music;
	private int reading;
	private int chatting;
	
	public Preference() {
		this.quiet_Time = 0;
		this.music = 0;
		this.reading = 0;
		this.chatting = 0;
	}
	
	public Preference(int quiet_Time, int music, int reading, int chatting) {
		this.quiet_Time = quiet_Time;
		this.music = music;
		this.reading = reading;
		this.chatting = chatting;
	}
	
	public int get_quiet_Time() {
		return quiet_Time;
	}
	
	public void set_quiet_Time(int quiet_Time) {
		this.quiet_Time = quiet_Time;
	}
	
	public int getmusic() {
		return music;
	}
	
	public void setmusic(int music) {
		this.music = music;
	}
	
	public int getreading() {
		return reading;
	}

	public void setreading(int reading) {
		this.reading = reading;
	}
	
	public int getchatting() {
		return chatting;
	}
	
	public void setchatting(int chatting) {
		this.chatting = chatting;
	}
	
	public int compare(Preference pref){
		return Math.abs(this.quiet_Time - pref.quiet_Time) + Math.abs(this.music - pref.music) + Math.abs(this.reading - pref.reading) + Math.abs(this.chatting - pref.chatting); 
	}
	


}
