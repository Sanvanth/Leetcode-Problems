class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        # Step 1: Split the string into words using split() which handles multiple spaces
        words = s.split()
        
        # Step 2: Reverse the list of words
        reversed_words = words[::-1]
        
        # Step 3: Join the reversed list of words with a single space
        return ' '.join(reversed_words)
