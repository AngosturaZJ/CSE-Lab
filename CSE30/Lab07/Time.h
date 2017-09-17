class Time{

	private:
		int hours;
		int minutes;
		int seconds;

	public:
		Time();

		Time(int hr, int min, int sec);

		~Time();

		int getHours();

		int getMinutes();

		int getSeconds();

		void setHours(int hr);

		void setMinutes(int min);

		void setSeconds(int sec);
};