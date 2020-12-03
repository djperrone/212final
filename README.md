# CSC 212 Final Project

### Project Ideas

- chrome tracing visualization - chrome://tracing/
- python visualization from csv runtimes file
- pass by value vs reference visual
- machine learning - predict runtime of an algorithm based on data from our project
- compare large file searches vs smaller string searches
- use standard library find function to compare correctness 
- for large test cases in order to benchmark algortithm search for a word/sentence in an entire doc or book
- find cost of search as input approaches infinity

## Tentative Outline/Schedule

### Rabin-Karp Algorithm (complete by 11/15)

|Date|Comments|
|---|---|
|11/10|- Completed solution to rabin-karp with limited test cases.<br>- Need to run a lot of test cases to find bugs.|
|11/11|- Compared our solution to the std library find function and found bug<br>-Fixed the bug by doing modulus in the for loop of power function.<br>- Update - Program can now read and search each line of a large text file.<br> - Found bug when searching large textfile - rolling hash gives false positives<br>-Fixed bug by increasing q and adding inner loop to check for false-positives<br> began testing timers in rk|

### Boyer Moore Algorithm (complete by 11/22)
|Date|Comments|
|---|---|
|11/11|- Created a roadmap for the implemntation with a class and nessecary functions.<br> - Made substantial progress on understanding of the algorithm using an online visualization tool that steps through the algorithm for any example you type. Need more understanding of the good and bad suffix tables and preprocessing. <br> - Will probably need to use a map to store the tables. |
|11/12| - Filled out all of the road map except good suffix table. Still unsure of how to fill out good suffix table. <br> - All other functions and parts of the algorithm have been implemented but cannot test until good suffix is implemented. |
|11/13| - Met with professor, he will be working on a document outlining the good-suffix algorithm for us to implement since documentation on it is very varried.|
|12/1| - Got a working program to find pattern in only certain cases. Beleive we need to adjust the good suffix table to consider two cases. |
|12/2| - updated bm with code for two tables for good suffix currently works with all test cases|
    
### Record runtime RK (complete by 11/29)
|Date|Comments|
|---|---|
|11/12|- Need to implement counter to track number of iterations as well as false positives<br> -visual_benchmarking folder contains modded instrumentator to benchmark g++ <br> std::high_res_clock behaves differently per compiler - use steady_clock...still dont know why vscode takes twice as long as visual studio|
|11/14|-Created list of text files to search (8 books) timesd all 8 books and wrote times to csv file |
|11/15 |Added counters to track comps and false positives, write comps/false to csv file |

### Record runtime BM (complete by 11/29)
|Date|Comments|
|---|---|
    
### Generate Plots(complete by 11/29)
|Date|Comments|
|---|---|
    
### Project Report (complete by 12/6)
|Date|Comments|
|---|---|
    
### Class Presentation (12/9?)
|Date|Comments|
|---|---|

