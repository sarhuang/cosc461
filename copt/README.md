# copt

## How to run copt
./test_sh copt_executable

## More details about copt
### Matrix Initialize
I only used the procedure integration or inlining optimization. Instead of using the functions
check() and set(), I replaced the function calls with the bodies of the procedures.
There was no difficulty with implementing this approach. This operation was the easiest to
identity an opportunity for optimization.

### Array Initialize
I implemented loop unrolling using an unroll factor of 4. I made copies of the loop body so the
for loop doesn’t require more loop branch testing. I also used loop invariant code motion
because the array elements are being multiplied by a constant that does not need to be
calculated repeatedly in the loop body. The loop invariant code motion is shown by the mod =
(X % Y) * Z.
At first, it was a little challenging figuring out how to make it faster. Originally, I experimented
with using a while loop and only decremented one by one. I also tried implementing a for loop
like shown above beforehand, but I incremented the variable i in the loop body.

### Factorial
I implemented tail recursion elimination by getting rid of the recursive call all together. Instead of
calculating the factorial recursively, I did it iteratively with a for loop.
This operation took me a while to figure out despite it’s simple solution because I thought I was
tied down to putting all of my optimized code in factorial_opt(). While it is probably
possible to place all the code in one function, I figured it was alright if I made my own helper
function, so I could reuse the code for factorial_unopt()and focus more on fixing hte
helper function.

### Matrix Multiplication
I implemented loop interchange by swapping the j and k for loop arguments. I also did dead
assignment elimination because res[i * n + j] = 0; was not needed since the array
elements are intialized later on in the nested loops.
This operation was easy to optimize because the main change was swapping two for loops. It’s
also really surprising how one little change cuts the time significantly.
