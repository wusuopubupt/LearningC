#include <stdio.h>

static int daytab[2][13] = {
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

/* judge if year is leap year */
int is_leap_year(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 ==0);
}

/* day_of_year : set day of year by month & day */
int day_of_year(int year, int month, int day) {
	if(year < 0) {
		return -1;
	}
	if(month < 1 || month > 12) {
		return -1;
	}
	if(day < 1) {
		return -1;
	}

	int i, j;
	i = is_leap_year(year) ? 0 : 1;
	j = 1;
	if(day > daytab[i][month]) {
		return -1;
	}
	while(j < month) {
		day += daytab[i][j];
		j++;
	}
	return day;
}


/* set month, day from day of year */
void month_day(int year, int year_day, int *p_month, int *p_day) {
	if(year > 0 && year_day < 366) {
		int i, j;
		i = is_leap_year(year) ? 0 : 1;
		j = 1;
		while(j <= 12) {
			if(year_day > daytab[i][j]) {
				year_day -= daytab[i][j];
			}
			else {
				*p_month = j;
				*p_day = year_day;
				break;
			}
			j++;
		}
	}
}

int main() {
	int month;
	int day;
	month_day(2014, 32, &month, &day);

	printf("month: %d, day: %d\n", month, day);
	return 0;
}

