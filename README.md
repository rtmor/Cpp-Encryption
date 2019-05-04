## C++ Encryption Project
**Final Product**

* **Completed Tasks**
   1. **Rewrote essential functions (now in working order)**
   2. **Proper input validation**
      1. Inputting a character or string when int was desired would break
         functions and application. Now characters and strings are handled with
         a (!cin) exception - forcing it to clear error flags and ignore
         inappropriate cin buffer.
   3. **Proper error handling**
      1. Input of a number out of menu range informs user of error and returns
         to top of function.
      2. Input of a char or string informs user of error and returns to top of
         function
   4. **Moved local variables to private data as needed.**
   5. **Addressed function overload issue by including overload in prototype**
      functions
   6. **Wrote clear_screen() function:**
      1. Determines compiler's architecture to clear_screen between function
         calls regardless of Windows or Linux environment.
   7. **Wrote sleep() function:**
      1. Creates a timed pause after error to display error message prior to
         clear of screen and returning to function top.
   8. **Replaced menu if/if else/else for better error handling.**
   9. **Reorganized bruteforce() function to what is expected of assignment
      requirements**
