#include <stdio.h>

int is_leap_year(int year) {
    if (year % 400 == 0) return 1;
    if (year % 100 == 0) return 0;
    if (year % 4 == 0) return 1;
    return 0;
}

int days_in_month(int year, int month) {
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else if (month == 2) {
        return is_leap_year(year) ? 29 : 28;
    } else {
        return 31;
    }
}

int main() {
    int sundays_on_first = 0;
    int day_of_week = 1; // 1900년 1월 1일은 월요일로 시작

    for (int year = 1901; year <= 2000; year++) {
        for (int month = 1; month <= 12; month++) {
            if (day_of_week % 7 == 0) {
                sundays_on_first++;
            }
            day_of_week += days_in_month(year, month);
        }
    }

    printf("20세기 동안 매월 1일이 일요일인 경우의 수: %d\n", sundays_on_first);

    return 0;
}
