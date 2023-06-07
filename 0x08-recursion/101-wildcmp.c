#include "main.h"

/**
 * wildcmp - compares two strings and returns 1 if they can be considered
 * identical, otherwise returns 0
 * @s1: the first string to compare
 * @s2: the second string to compare (can contain '*')
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
    /* If we've reached the end of both strings, they are identical */
    if (*s1 == '\0' && *s2 == '\0')
        return (1);

    /* If we've reached the end of s2 but not s1, check if remaining chars in s2 are all '*' */
    if (*s2 == '\0')
    {
        while (*s1 != '\0')
        {
            if (*s1 != '*')
                return (0);
            s1++;
        }
        return (1);
    }

    /* If the characters at this position are the same, move on to the next character */
    if (*s1 == *s2)
        return (wildcmp(s1 + 1, s2 + 1));

    /* If the character in s2 is '*', try matching the current character in s1 with the next character in s2 or skip the '*' */
    if (*s2 == '*')
        return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));

    /* If none of the above conditions are true, the strings are different */
    return (0);
}

