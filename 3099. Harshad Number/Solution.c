int sumOfTheDigitsOfHarshadNumber(int x) {
    int y = x, sum = 0;
    while (y > 0) {
        sum += y % 10;
        y /= 10;
    }

    return (x % sum) == 0 ? sum : -1;
}