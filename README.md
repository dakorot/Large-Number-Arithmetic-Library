<h1> Large Number Arithmetic Library </h1>

<h3>Description</h3>
<p>Large Number Arithmetic Library is a C-based university assignment that aims to develop a
library for performing arithmetical operations on large hexadecimal numbers that cannot be represented using
the standard word size. The library supports a range of operations, including addition, subtraction,
multiplication, division, exponentiation, Barrett reduction, and Montgomery reduction.</p>

<h3>Details</h3>
<p>The library contains conversion functions for converting hexadecimal strings of up to 256 characters to
arrays of 32 elements, each representing a 32-bit number. By using pointers, the library allows for efficient
processing of the converted numbers by the supported operations. The library also includes an executable file
for testing the implemented functions. The output of the functions is converted back to hexadecimal format for
display on the screen.</p>

<h3>Libraries</h3>
<ul>
  <li>stdio.h</li>
  <li>stdlib.h</li>
  <li>stdint.h</li>
  <li>math.h</li>
</ul>
