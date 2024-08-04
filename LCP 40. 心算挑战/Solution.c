static int cmp (const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int maxmiumScore(int* cards, int cardsSize, int cnt){
    int i, temp1 = 0, temp2 = 0,lastOdd = 0, lastEven = 0, score = 0;

    qsort (cards, cardsSize, sizeof (int), cmp);

    for (i = 0; i < cnt; i++) {
        score += cards[i];
        if ((cards[i] & 1) == 0) {
            lastEven = cards[i];
        } else {
            lastOdd = cards[i];
        }
    }

    if ((score & 1) == 0) {
        return score;
    }

    for (i = cnt; i < cardsSize && (lastOdd > 0 || lastEven > 0); i++) {
        if ((cards[i] & 1) == 0) {
            if (lastOdd > 0) {
                temp1 = score - lastOdd + cards[i];
                lastOdd = 0;
            }
        } else {
            if (lastEven > 0) {
                temp2 = score - lastEven + cards[i];
                lastEven = 0;
            }
        }
    }

    score = fmax (temp1, temp2);
    if ((score & 1) != 0) {
        return 0;
    }
    return score;
}