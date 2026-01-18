# Prime Number Game

## Description

You are given two strings `s` and `t`. Your goal is to transform string `s` into string `t` using the following process.
You may perform the operation at most once, defined as follows:
1. Choose indices $l$ and $r$ $(1 \le l \le r \le |s|)$ and keep the substring $s[l..r]$.  
All characters outside this substring are removed.  
The cost of this step is $r - l + 1$.

2. From the remaining substring, remove exactly $x$ characters.  
The cost of this step is $x + 1$.

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

- $1 \le |s|, |t| \le 10^5$
- Time limit: $2000$ ms
- Memory limit: $256$ MB


## Examples

### Example 1

**Input:**

```json
{
  "s": "abcde",
  "t": "ace"
}

```

**Output:**

```json
15
```
**Explanation:**

One optimal choice is:

- Select subarray `"abcde"` → cost $= 5$
- Remove $2$ characters → cost $= 2 + 1 = 3$
- Rearrange remaining characters to form `"ace"`

- Total cost: $5 * 3 = 15$

### Example 2

**Input:**

```json
{
  "s": "abcd",
  "t": "xyz"
}
```



**Output:**

```json
-1
```
**Explaination**

No subarray of `s` contains the required characters to form `t`, so the transformation is impossible.



