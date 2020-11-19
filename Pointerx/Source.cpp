#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main() {
    int i, j = 0;
    char str[100], * p_left, * p_right;
    printf(" *** Palindrome Verification ***\n");
    printf("Enter a sentence : ");
    scanf("%[^\n]", str);
    for (p_right = str; *p_right != '\0'; p_right++);
    p_right--;
    p_left = str;
    for (i = 0; i < strlen(str); i++) {
        if (*p_left < 58 && *p_left>47) {
            j++;
        }
        p_left++;
    }
    for (p_left = str; p_left < p_right;)
    {
        if (j == strlen(str)) {
            if (*p_left < 58 && *p_left>47) {
                if (*p_left != *p_right)
                {
                    break;
                }
                p_left++;
                p_right--;
            }
        }
        else if (!((*p_left > 64 && *p_left < 91) || (*p_left > 96 && *p_left < 123)))
        {
            p_left++;
        }
        else if (!((*p_right > 64 && *p_right < 91) || (*p_right > 96 && *p_right < 123)))
        {
            p_right--;
        }
        else {
            if (toupper(*p_left) != toupper(*p_right))
            {
                break;
            }
            p_left++;
            p_right--;
        }
    }
    if (p_left < p_right)
    {
        printf("\"%s\" is NOT palindrom.\n", str);
    }
    else
    {
        printf("\"%s\" is PALINDROME.\n", str);
    }
    return 0;
}