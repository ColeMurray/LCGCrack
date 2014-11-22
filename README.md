LCGCrack
========

A Linear Congruence Generator decryption tool. 
Xn = a*Xn-1 + b (mod n)

To run: Place book in LCGCipher folder titled "book1.enc"
Program will return (a,b,m) that satisfy decryption.

Decrypt: substitute a,b,m into their respective locations and run.

<pre>
├───LCGCipher
│       Decrypt.cpp
│       lcgcrack.cpp
│       LCGCrack.h
│       parseEnum.cpp
│
└───SubstitutionCipher
        Decrypt.cpp
        freqDist.xlsx
        FrequencyCount.cpp
        transposition.cpp
</pre>
