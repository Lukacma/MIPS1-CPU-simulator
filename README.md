# MIPS1-CPU-simulator

### Overview

This a fully working CPU simulator which can run any almost any (See [specs](https://github.com/m8pple/arch2-2019-cw#simulator-inputoutput).) assembly file that uses Mips 1 ISA. Repo also includes the testbench for checking the functionality of the simulator.

This repo was developed from scratch as a coursework for Computer Architecture module and was developed jointly with [Saginsky](https://github.com/Saginsky).  Specs and requirements for this coursework can be found [here](https://github.com/m8pple/arch2-2019-cw).

### Dependencies

Dependecies will be checked and installed when building testbench. However if you would like to install them before that run ``` bin/dependency.sh ```.
## Testbench

### Running the testbench

1. run ``` make testbench``` to compile tests written in c or assembly to binary. Tests to be compiled are stored in ```Testbench/Tests```.

2. run ``` bin/mips_testbench```

The results will be recorded in ```test/output/log.csv```.  The format of the csv file is:

```TestId , Instruction , Status , Author [, Message]```
 
 For more details see [specs](https://github.com/m8pple/arch2-2019-cw#testbench-inputoutput). 

 ### Adding tests

 Test can be added by putting the given assembly file into ```Testbench/Tests``` folder or by including the binary file into ```Testbench/bin``` folder. You also need to include info about this test on the newline of ```Testbench/testinfo.csv``` file in the following format:

 ```Test id, Instruction, Author, Message, Input file, expected output,expected status,timeout```

```Test id, Instruction, Author, Message``` - [specs](https://github.com/m8pple/arch2-2019-cw#testbench-inputoutput)

```Input file``` - name of the file from which the simulator will get inputs. See [specs](https://github.com/m8pple/arch2-2019-cw#simulator-inputoutput).

``` expected output ```- what the simulator should print out into ```stdout```.

``` expected status ``` - exit status of the simulator.

``` timeout ```- how long to wait before killing the process. 

### License

This repo is licensed under MIT license. See ``` LICENSE ```.