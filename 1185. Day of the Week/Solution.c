char* dayOfTheWeek(int day, int month, int year) {  // Faster than 100% solutions!!!
  int totDays, mDays[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
  char *week[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

  totDays = (year - 1971) * 365 + (year - 1969) / 4;
  totDays += mDays[month - 1] + day + 3;
  if (((year % 4) == 0 && (year % 100 != 0)) || ((year % 400) == 0)) {
    if (month > 2) {
      totDays++;
    }
  }
  totDays %= 7;
  return week[totDays];
}