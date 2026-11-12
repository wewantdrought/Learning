/*
Practice session: November 10, 2026

Rules for today
---------------
- Write every line of C++ yourself; no implementation is provided.
- Complete the answer areas in order.
- Compile after small changes with:
  clang++ -std=c++17 -Wall -Wextra practice.cpp -o practice
- Use Sections 1-4 of CPP_PRIMER.md as a reference.
- Do not use hash tables, std::reverse, or material from later sections.
*/

/*
Setup
-----
Write all #include directives required by the exercises. Decide whether to use
std:: prefixes or a using directive. Do not write main() yet; its prompt is at the
bottom so that all function definitions can appear before it.
*/

// Write the setup directly below.

#include <iostream>
#include <vector>
using namespace std;


/*
Exercise 1: Output and a vector
-------------------------------
Write a function named printValues that receives a vector of integers without
copying it. Use a loop to print every value on one line, separated by spaces.

It will later receive: 4, 7, 2, 9, 6
Expected output: 4 7 2 9 6
*/

// Write Exercise 1 directly below.

void printValues(const vector<int>& nums) {
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        if (i > 0) {
            cout << " ";
        }
        cout << nums[i];
    }
}

/*
Exercise 2: Sum and average
---------------------------
Write a function named sumValues that receives a vector of integers without
copying it and returns its sum as long long.

Then write a function named averageValue. It must use sumValues, return a double,
and avoid integer division. You may assume the vector is nonempty.

For 4, 7, 2, 9, 6:
Expected sum: 28
Expected average: 5.6
*/

// Write Exercise 2 directly below.

long long sumValues(const vector<int>& nums) {
    long long res = 0;
    for (long long i : nums) {
        res += i;
    }
    return res;
}

double averageValue(const vector<int>& nums) {
    return static_cast<double>(sumValues(nums)) / nums.size();
}

/*
Exercise 3: Count even values
-----------------------------
Write a function named countEven that receives a vector of integers without
copying it and returns how many values are even. Use a loop, an if statement, and
the remainder operator.

Expected result for 4, 7, 2, 9, 6: 3
*/

// Write Exercise 3 directly below.



/*
Exercise 4: Find the largest value
----------------------------------
Write a function named findLargest that receives a vector of integers without
copying it and returns the largest value. Do not use a library algorithm. You may
assume the vector is nonempty.

Expected result for 4, 7, 2, 9, 6: 9

After writing it, explain in a comment why the vector parameters in Exercises
1-4 should use const and a reference.
*/

// Write Exercise 4 and your explanation directly below.


/*
Exercise 5: Reverse a string manually
-------------------------------------
Write a function named reverseText that receives a string and returns a reversed
copy. Use an index loop or a reverse loop. Do not use std::reverse.

Input: hello
Expected result: olleh
*/

// Write Exercise 5 directly below.


/*
Exercise 6: Letter frequencies
------------------------------
Write a function named printLetterFrequencies that receives a lowercase string.
Use array<int, 26> to count its letters, then print only letters with counts above
zero. Before running it, write a comment with the indices produced by 'b' - 'a',
'a' - 'a', and 'n' - 'a'.

Input: banana
Expected output:
a: 3
b: 1
n: 2
*/

// Write Exercise 6 and the three predicted indices directly below.


/*
Assemble and test the program
-----------------------------
Write main() here. Create the vector {4, 7, 2, 9, 6}, call every function above,
and print labeled results. Test reverseText with "hello" and
printLetterFrequencies with "banana". Compare the complete output with every
success check above.
*/

// Write main() directly below.

int main(){
    cout << "#1";
    vector<int> nums1 = {4, 7, 2, 9, 6};
    printValues(nums1);
    
    cout << "#2";
    return 0;
}
