from collections import Counter
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        s_dir = Counter(s)
        t_dir = Counter(t)
        return s_dir == t_dir

        