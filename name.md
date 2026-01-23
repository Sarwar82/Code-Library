# Cyclic String

## Description

You are given a string `s` of length $n$.

A cyclic shift of `s` is defined as follows:  
choose an index $i$ $(1 \le i \le n)$, and form a new string by moving the prefix $s[1..i-1]$ to the end of the string.

Formally, the cyclic shift starting at position $i$ is:

$$
s[i..n] + s[1..i-1]
$$

Consider the collection of all cyclic shifts of `s`.  
These cyclic shifts are not required to be distinct. If `s` has periodic structure, identical shifts may appear multiple times.

You must choose exactly $k$ cyclic shifts from this collection.
For a chosen set of $k$ cyclic shifts, define their **Longest Common Prefix (LCP)** as the largest integer $L$ such that all $k$ strings share the same prefix of length $L$.

Your task is to determine the maximum possible value of this LCP over all possible choices of $k$ cyclic shifts.

## Input Format

<!-- HOW: Technical schema only. Field names, types, JSON structure. No need to re-explain the problem goal. -->

Input is a JSON object with the following fields:

- `s` (string): the given string of length $n$
- `k` (integer): the number of cyclic shifts to select

Example input:

```json
{
  "s": "ababa",
  "k": 3
}

```

## Output Format

Output is a JSON value (type: integer):

- The maximum possible length of the longest common prefix shared by any selection of exactly $k$ cyclic shifts of `s`.

Example output:

```json
1
```

## Constraints

- $1 \le n \le 10^5$
- $1 \le k \le n$
- `s` consists of lowercase English letters (`a`–`z`)
- Time limit: $3000$ ms
- Memory limit: $256$ MB


## Examples

### Example 1

**Input:**

```json
{
  "s": "ababa",
  "k": 3
}
```

**Output:**

```json
1
```

**Explanation:** 
All cyclic shifts of `"ababa"` are:

- `"ababa"`
- `"babaa"`
- `"abaab"`
- `"baaba"`
- `"aabab"`

One optimal choice of $k = 3$ cyclic shifts is:

- `"ababa"`, `"abaab"`, `"aabab"`

These three strings share a common prefix `"a"` of length $1$.  
No selection of three cyclic shifts has a longer common prefix.
