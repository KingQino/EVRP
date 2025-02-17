> The main change made by me is on two aspects:
>
> - Fix compile error
> - Add statistical function 

## Usage:

```shell
./evrp HMAGS benchmark/E-n22-k4.evrp output_files/
```



# Electric Vehicle Routing Problem #

*** Paper link [here](https://link.springer.com/article/10.1007/s10489-022-03555-8) ***

### This repository contains algorithms to solve the EVRP (Electric Vehicle Routing Problem) in C++ ###

<a name="algorithms"></a>
#### Algorithms: ####
1. Greedy Search Solution (Only)
2. Genetic Algorithm (GA) + GS
3. Simulated Annealing (SA) + GS
4. Simulated Ant Colony Optimization (SACO) + GS

### Source code
* EVRP.cpp EVRP.hpp
Implementation of the electric vehicle routing problem. 

* stats.cpp stats.hpp
Implementation to store the best solution for the 20 RUNS. 

* HMAGS.cpp, SA.cpp, GreedySearch.cpp, SACO.cpp
Metaheuristic Solution here.

* individual.cpp
algorithm, methods

* main.cpp 
Executable of the source code

/** Implementation Instructions **/ 

Step 1: make a diretory "build" first

```shell
$ mkdir build
```


Step 2: Run this command in CMD (To create an executable file named "file_name"): 
```shell
$ cd build
$ cmake ..
$ make
```

Step 3: Run this command in CMD (To run the executable file):

```shell
$ ./evrp <algorithm> <benchmark_file> <output_file>
```

example:
```shell
$ ./evrp HMAGS ../benchmark/E-n22-k4.evrp ../output_files/
```

To make a solution in graph using python script:
```
$ python3 evrpgraph.py -i <solution-file>
```

```
$ python3 evrpgraph.py -i output_files/1/solution_HMAGS_E-n23-k3.evrp.txt
```

*** Example of solution in graph E-n23-k3.evrp using HMAGS algorithm
![Solution](./tmp-outputs/1/solution_HMAGS_E-n101-k8evrp.png)


The algorithm archived top 3 in competition [CEC-12 (2019)](https://mavrovouniotis.github.io/EVRPcompetition2020/)

|     instances    | (Team1) VNS |           |           |        | (Team2) SA |           |           |        | (Team3) HMAGS |           |           |         |
|:----------------:|:-----------:|:---------:|:---------:|:------:|:----------:|:---------:|:---------:|:------:|:-------------:|:---------:|:---------:|:-------:|
|                  |     min     |    max    |    mean   |  stdev |     min    |    max    |    mean   |  stdev |      min      |    max    |    mean   |  stdev  |
|   E-n22-k4.evrp  | 384.67      | 384.67    | 384.67    | 0.0    | 384.67     | 384.67    | 384.67    | 0.00   | 384.67        | 384.67    | 384.67    | 0.0     |
|   E-n23-k3.evrp  | 571.94      | 571.94    | 571.94    | 0.0    | 571.94     | 571.94    | 571.94    | 0.00   | 571.94        | 571.94    | 571.94    | 0.0     |
|   E-n30-k3.evrp  | 509.47      | 509.47    | 509.47    | 0.0    | 509.47     | 509.47    | 509.47    | 0.00   | 509.47        | 509.47    | 509.47    | 0.0     |
|   E-n33-k4.evrp  | 840.14      | 840.46    | 840.43    | 1.18   | 840.57     | 873.33    | 854.07    | 12.80  | 844.25        | 846.21    | 845.62    | 0.92    |
|   E-n51-k5.evrp  | 529.90      | 548.98    | 543.26    | 3.52   | 533.66     | 533.66    | 533.66    | 0.00   | 529.90        | 553.23    | 542.08    | 8.57    |
|   E-n76-k7.evrp  | 692.64      | 707.49    | 697.89    | 3.09   | 701.03     | 716.77    | 712.17    | 5.78   | 697.27        | 730.92    | 717.30    | 9.58    |
|  E-n101-k8.evrp  | 839.29      | 853.34    | 853.34    | 4.73   | 845.84     | 856.74    | 852.48    | 3.44   | 852.69        | 887.14    | 872.69    | 9.58    |
|  X-n143-k7.evrp  | 16028.05    | 16883.38  | 16459.31  | 242.59 | 16610.37   | 17396.06  | 17188.90  | 170.44 | 16488.60      | 17478.86  | 16911.50  | 282.30  |
|  X-n214-k11.evrp | 11323.56    | 11660.70  | 11482.20  | 76.14  | 11404.44   | 11881.73  | 11680.35  | 116.47 | 11762.07      | 12309.38  | 12007.06  | 156.69  |
|  X-n352-k40.evrp | 27064.88    | 27418.38  | 27217.77  | 86.20  | 27222.96   | 27796.69  | 27498.03  | 155.62 | 28008.09      | 28792.66  | 28336.07  | 205.29  |
|  X-n459-k26.evrp | 25370.80    | 25774.62  | 25582.27  | 106.89 | 25464.84   | 26038.65  | 25809.47  | 157.97 | 26048.21      | 26742.11  | 26345.12  | 185.14  |
|  X-n573-k30.evrp | 52181.51    | 51929.24  | 52548.09  | 278.85 | 51929.24   | 53534.01  | 52793.66  | 577.24 | 54189.62      | 56327.62  | 55327.62  | 548.05  |
|  X-n685-k75.evrp | 71345.40    | 72187.75  | 71770.57  | 197.08 | 72549.90   | 73693.49  | 73124.98  | 320.07 | 73925.56      | 75535.99  | 74508.03  | 409.43  |
|  X-n749-k98.evrp | 81002.01    | 81634.06  | 81327.39  | 176.19 | 81392.78   | 82414.80  | 81848.13  | 275.26 | 84034.73      | 85549.36  | 84759.79  | 376.10  |
| X-n819-k171.evrp | 164289.95   | 165571.48 | 164926.41 | 318.62 | 165069.77  | 166640.37 | 165895.78 | 403.70 | 170965.68     | 173371.76 | 172410.12 | 568.58  |
| X-n916-k207.evrp | 341649.91   | 343338.01 | 342460.70 | 510.66 | 342796.88  | 344521.64 | 343533.85 | 556.98 | 357391.57     | 362422.52 | 360269.94 | 1192.57 |
| X-n1001-k43.evrp | 77476.36    | 78464.68  | 77920.52  | 234.73 | 78053.86   | 79226.81  | 78593.50  | 306.27 | 78832.90      | 79567.00  | 79163.34  | 229.19  |

