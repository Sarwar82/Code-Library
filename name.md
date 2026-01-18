# Solution Tutorial

## Key Insights

1. Since the remaining characters can be rearranged freely, the order of characters does not matter. Only character frequencies are relevant.
2. A substring of `s` is valid if, for every character, its frequency in the substring is greater than or equal to its frequency in string `t`.
3. Let the length of string `t` be $n$. 
If we select a valid substring of length $len$ from `s`, then we must remove exactly $len - n$ characters to obtain `t`.
4. The total cost for such a choice is:

$$
\text{cost} = len \times (len - n + 1)
$$

5. Since $n$ is constant, minimizing the cost is equivalent to minimizing the value of $len$.
6. Therefore, the problem reduces to finding the shortest substring of `s` whose character frequencies cover those of `t`.
7. This can be solved efficiently using a two-pointer (sliding window) technique, while maintaining a frequency structure to verify whether the current window is valid.




