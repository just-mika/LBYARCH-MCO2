## LBYARCH MCO2 - x86-to-C interface programming project
- Amon, Mikaela Nicole
- Filipino, Eunice Marble

### I.) Comparative execution time and short analysis of the performance of the kernels
The following table summarizes the average execution times for the two kernels across all tested sizes and build modes.
| Vector Size (n)  |     C (Debug)    | x86-64 Assembly (Debug) |    C (Release)     | x86-64 Assembly (Release) |
|:----------------:|:----------------:|:-----------------------:|:------------------:|:-------------------------:|
| 2<sup>20</sup>   |    2.423585 ms   |       0.533070 ms       |    0.732075 ms     |         0.520290 ms       |
| 2<sup>24</sup>   |   31.434300 ms   |       9.786205 ms       |    9.008700 ms     |         9.572425 ms       |
| 2<sup>30</sup>   | 5854.377045 ms   |    2542.689880 ms       | 1540.179305 ms     |       578.570510 ms       |

### II.) Screenshot of the program output with the correctness check (C).
- **DEBUG MODE**
    * 2<sup>20</sup>

    ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/db%20mode/img/2_20%20C.png)
    * 2<sup>24</sup>

   ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/db%20mode/img/2_24%20C.png)
    * 2<sup>30</sup>

   ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/db%20mode/img/2_30%20C.png)
  
- **RELEASE MODE**
    * 2<sup>20</sup>

    ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/rl%20mode/img/2_20%20C.png)
    * 2<sup>24</sup>

   ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/rl%20mode/img/2_24%20C.png)
    * 2<sup>30</sup>

   ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/rl%20mode/img/2_30%20C.png)


### III.) Screenshot of the program output, including the correctness check (x86-64).
- **DEBUG MODE**
    * 2<sup>20</sup>

    ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/db%20mode/img/2_20%20ASM.png)
    * 2<sup>24</sup>

   ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/db%20mode/img/2_24%20ASM.png)
    * 2<sup>30</sup>

   ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/db%20mode/img/2_30%20ASM.png)

- **RELEASE MODE**
    * 2<sup>20</sup>

    ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/rl%20mode/img/2_20%20ASM.png)
    * 2<sup>24</sup>

   ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/rl%20mode/img/2_24%20ASM.png)
    * 2<sup>30</sup>

   ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/rl%20mode/img/2_30%20ASM.png)

### IV.) Short videos (5-10mins) showing your source code, compilation, and execution of the C and x86-64
