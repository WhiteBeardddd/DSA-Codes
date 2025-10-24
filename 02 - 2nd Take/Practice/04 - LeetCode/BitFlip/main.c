int minBitFlips(int start, int goal) {
    int count = 0;
    int maskValue = start ^ goal; // XOR

    while (maskValue != 0){
        count = count + (maskValue & 1);
        maskValue = maskValue >> 1;
    }

    return count;
}