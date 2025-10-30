Given two strings, determine if they are anagrams of each other. An anagram is a word or phrase formed by rearranging the letters of another word or phrase, using all original letters exactly once.

REQUIREMENTS:
-Must use a DICTIONARY (hash table) with CLOSED HASHING
-Must use LINEAR PROBING for collision resolution (key = (key + 1) % MAX)
-Must track CHARACTER FREQUENCIES in the hash table
-Must handle EMPTY and DELETED states properly
-Returns true if strings are anagrams, false otherwise

CONSTRAINTS:
-Input strings contain only ASCII characters
-CASE-SENSITIVE: 'A' and 'a' are treated as different characters
-Strings of DIFFERENT LENGTHS are NOT anagrams

FUNCTIONS:
-initDict() → initialize dictionary with EMPTY markers
-insert() → insert character and track frequency
-delete() → remove/decrement character frequency
-isMember() → check if character exists with frequency > 0
-isAnagram() → main function to check if two strings are anagrams