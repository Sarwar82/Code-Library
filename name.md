# Prime Number Game

## Description

You are given two strings `s` and `t`. Your goal is to transform string `s` into string `t` using the following process.
You may perform the operation at most once, defined as follows:
1. Choose a subarray $[l,r]$ of string `s` and discard all characters outside this subarray.  
   The cost of selecting this subarray is
   
$$f(l,r) = r - l + 1$$

2. From the remaining substring, you may remove any number of characters.  
   If you remove $x$ characters, the cost of this step is

$$
x + 1
$$

3. You may rearrange the remaining characters in any order at no additional cost.
   
After performing these steps, the resulting string must be exactly equal to `t`.

The total cost of the operation is defined as:

$$
(r - l + 1) \times (x + 1)
$$

Your task is to determine the minimum possible cost to convert `s` into `t`.  
If it is impossible, output `-1`.







## Input Format

Input is a JSON object with the following fields:

- `s` (string): the initial string $s$
- `t` (string): the target string $t$

Example input:

```json
{
  "s": "abcde",
  "t": "ace"
}

```

## Output Format

Output is a JSON value (type: integer):


- The minimum cost to transform `s` into `t`
- Output `-1` if the transformation is not possible

Example output:

```json
15
```

## Constraints

- \(1 \le n \le 10^5\)
- \(1 \le q \le 10^5\)
- \(1 \le \texttt{nums}[i] \le 65535\)
- For each query \([i,x]\): \(1 \le i \le n\) and \(1 \le x \le 65535\)
- Time limit: \(1000\text{ms}\)
- Memory limit: \(256\text{MB}\)

## Examples

### Example 1

**Input:**

```json
{
  "nums": [2, 4, 8],
  "queries": [
    [1, 16],
    [3, 1]
  ]
}
```

**Output:**

```json
[7, 6]
```

**Explanation:**

- After update \([1,16]\), the array becomes \([16,4,8]\).
  There are \(7\) non-empty subsets \(S \subseteq \{1,2,3\}\) for which Arpa wins:
  \[
  \{1\},\{2\},\{3\},\{1,2\},\{1,3\},\{2,3\},\{1,2,3\}.
  \]

- After update \([3,1]\), the array becomes \([16,4,1]\).
  There are \(6\) non-empty subsets \(S \subseteq \{1,2,3\}\) for which Arpa wins:
  \[
  \{1\},\{2\},\{1,2\},\{1,3\},\{2,3\},\{1,2,3\}.
  \]
