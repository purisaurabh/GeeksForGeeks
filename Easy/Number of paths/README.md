<h2><a href="https://practice.geeksforgeeks.org/problems/number-of-paths0926/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article">Number of paths</a></h2><h3>Difficulty Level : Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">The problem is to count all the possible paths from top left to bottom right of a <strong>MxN</strong>&nbsp;matrix with the constraints that from each cell you can either move to <strong>right</strong> or <strong>down</strong>.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre style="position: relative;"><span style="font-size:18px"><strong>Input</strong>:
M = 3 and N = 3
<strong>Output:</strong>&nbsp;6
<strong>Explanation</strong>:
Let the given input 3*3 matrix is filled 
as such:
A B C
D E F
G H I
The possible paths which exists to reach 
'I' from 'A' following above conditions 
are as follows:ABCFI, ABEHI, ADGHI, ADEFI, 
ADEHI, ABEFI
</span><div class="open_grepper_editor" title="Edit &amp; Save To Grepper"></div></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre style="position: relative;"><span style="font-size:18px"><strong>Input:</strong>
M = 2 and N = 8
<strong>Output: </strong>8
</span><div class="open_grepper_editor" title="Edit &amp; Save To Grepper"></div></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>numberOfPaths()</strong>&nbsp;which takes the integer <strong>M</strong> and integer <strong>N</strong>&nbsp;as input parameters and returns the number of paths..<br>
<br>
<strong>Expected Time Complexity:</strong> O(m + n - 1))<br>
<strong>Expected Auxiliary Space:</strong> O(1)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong></span><br>
<span style="font-size:18px">1 ≤ M, N&nbsp;≤ 10</span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Zoho</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Mathematical</code>&nbsp;<code>Algorithms</code>&nbsp;