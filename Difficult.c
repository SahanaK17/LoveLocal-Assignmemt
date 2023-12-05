#include <stdio.h>

int countDigitOne(int n) {
    int count = 0;
    for (long long i = 1; i <= n; i *= 10) {
        long long divider = i * 10;
        count += (n / divider) * i + fmin(fmax(n % divider - i + 1, 0), i);
    }
    return count;
}

int main() {
    int n;

    printf("Enter a non-negative integer n: ");
    scanf("%d", &n);

    int result = countDigitOne(n);

    printf("Total number of digit 1 appearing: %d\n", result);

    return 0;
}
