bool isOneBitCharacter(int* bits, int bitsSize) {
    for (int i = bitsSize - 2; i >= 0; i--) {
        if (bits[i] == 0) {
            return true;
        } else {
            return !isOneBitCharacter (bits, i + 1);
        }
    }

    return true;
}


bool isOneBitCharacter(int* bits, int bitsSize) {  // Faster than 100% solutions
    int expect = true;

    for (int i = bitsSize - 2; i >= 0; i--) {
        if (bits[i] == 0) {
            return expect;
        }
        expect = !expect;
    }

    return expect;


    // for (int i = bitsSize - 2; i >= 0; i--) {
    //     if (bits[i] == 0) {
    //         return true;
    //     } else {
    //         return !isOneBitCharacter (bits, i + 1);
    //     }
    // }

    // return true;
}