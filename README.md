# GCOV: A REPORT ON OPTIMIZATION & TEST CASES 
*README curated by Gianni Joseph Bellucci* 

## -1) Declans Code: 
> **Note: this part includes `declan_rainfall.cc` and `asm_max_element`, which is my assembly version of max_element().** My idea for optimization was to write `max_element()` in ARM32. I did five runs with 10 million inputs fed into our program for both the unoptimized and optimized versions. The unoptimized (but still using -O3) time was 2.9568846 seconds. The optimized (still using -O3) time was 2.916048 seconds. This is approximately a 1% improvement, however the improvement is fairly significantly better the lower down the -Ox (g++ optimizer) route you go. This optimization was ultimately an improvement, even by a small margin. However, when considering simulations or games that must have tens of millions or even billions of operations a second, this is a significant improvement. Especially when taking into considerations other areas of optimization.

## -1.1) Celeste's Code; 
> My part includes `celeste_rainfall.cc` it has three changes in it, which is switching the c++ accumulate for my asm_accum, it is my assembly version of accumulate(). It is an optimized version of accumulate() in ARM32. I did ten runs on each with -O3, and the C++ version had a time of 3.1279461, and the assembly had a time of 17.039352. There is no improvement when the optimizer is on, if it is off, then there is an improvement.

