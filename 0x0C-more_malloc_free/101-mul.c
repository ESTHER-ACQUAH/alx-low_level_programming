#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int multiply(const char *num1, const char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int result_len = len1 + len2;
    int *result = calloc(result_len, sizeof(int));
    int carry = 0;

    for (int i = len1 - 1; i >= 0; i--) {
        int n1 = num1[i] - '0';
        int k = result_len - (len1 - i);
        carry = 0;

        for (int j = len2 - 1; j >= 0; j--) {
            int n2 = num2[j] - '0';
            int temp = n1 * n2 + result[k] + carry;
            result[k] = temp % 10;
            carry = temp / 10;
            k--;
        }

        if (carry > 0) {
            result[k] += carry;
        }
    }

    int start = 0;
    while (start < result_len && result[start] == 0) {
        start++;
    }

    if (start == result_len) {
        printf("0\n");
    } else {
        for (int i = start; i < result_len; i++) {
            printf("%d", result[i]);
        }
        printf("\n");
    }

    free(result);
    return (0);
}

int validateNumber(const char *number) {
    int length = strlen(number);
    for (int i = 0; i < length; i++) {
        if (!isdigit(number[i])) {
            printf("Error\n");
            return (98);
        }
    }
    return (0);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error\n");
        return (98);
    }

    int validation1 = validateNumber(argv[1]);
    int validation2 = validateNumber(argv[2]);

    if (validation1 != 0 || validation2 != 0) {
        return (98);
    }

    multiply(argv[1], argv[2]);

    return (0);
i}
