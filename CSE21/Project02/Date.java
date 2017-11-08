
public class Date {
	private int year;
	private int month;
	private int day;
	
	public Date() {
		this.year = 0;
		this.month = 0;
		this.day= 0;
	}
	
	public Date(int month, int day, int year) {
		this.month = month;
		this.day= day;
		this.year = year;
	}
	
	public int getyear() {
		return year;
	}
	
	public void setyear(int year) {
		this.year = year;
	}
	
	public int getmonth() {
		return month;
	}
	
	public void setmonth(int month) {
		this.month = month;
	}
	
	public int getday() {
		return day;
	}
	
	public void setday(int day) {
		this.day = day;
	}
	
	public int dayOfYear() {
		int totalDays = 0;
		switch (month) {
			case 12: totalDays += 30;
			case 11: totalDays += 31;
			case 10: totalDays += 30;
			case 9 : totalDays += 31;
			case 8 : totalDays += 31;
			case 7 : totalDays += 30;
			case 6 : totalDays += 31;
			case 5 : totalDays += 30;
			case 4 : totalDays += 31;
			case 3 : totalDays += 28;
			case 2 : totalDays += 31;
		}
		totalDays += day;
		return totalDays;
	}
     
	public int compare(Date dt){
				
		int diff = 0;
		int max_diff = 60;
        diff = Math.abs((dt.getyear() - this.year) * 365 + dt.dayOfYear() - this.dayOfYear());
		diff = diff / 30;
		if (diff > max_diff)
			return max_diff ;
		else
		    return diff;
	}
	
}
