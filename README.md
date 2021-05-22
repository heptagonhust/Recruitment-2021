# HUST Heptagon 2021 Recruitment

## Introduction

Because of the huge cost of computational resources and the processing time needed, numerous problems such as cryptology, many body quantum mechanics, and quantum machine learning still can't be solved effectively even utilizing the most powerful supercomputers today. However, quantum computers, which are based on the quantum mechanics, have demonstrated huge advantages in these fields by benefiting from the advanced quantum algorithms. Among those quantum algorithms, the Shor large number decomposition algorithm as well as the Grover quantum search algorithm are the two most renowned. They have raised interest from the scientists and is inspiring further development of quantum computing and quantum information. Unfortunately, the development curve of the quantum computer hardware is still not very step, and there is no actual quantum computer which can be used for solving practical science or cryptology issues. Thus, the quantum systems are still simulated by using the classical computers.

QuEST is a new simulator of universal quantum circuits. QuEST is capable of simulating generic quantum circuits of general one-qubit and two-qubits and multi-qubit controlled gates, on pure and mixed states, represented as state-vectors and density matrices under the presence of decoherence.

Describing the state of an n-bit classical register requires just n bits while describing the state of an n-qubit quantum register requires 2^n complex numbers. As a result, simulating a quantum computer using a classical machine is believed to be exponentially expensive with respect to the number of qubits. But despite this, classical simulation of quantum computation is crucial for the study of new algorithms and architectures.

## Evaluation

In this recruitment, we provide three workloads including **basic**, **medium** and **advance**. You can find them in the example directory.

For each workload, two output files will be generated: **probs.dat** and **stateVector.dat**. The former describes the probability of every qubit that equals to 1, while the latter provides the amplitude of the first ten state vectors, which are complex numbers including real and imagine parts. The evaluation will follow the rules below:

1. The output files in each workload should be the exact same as the given references of probs.dat and stateVector.dat.

2. The execution time will be evaluated by the number listed in the screen output file *.log on the ground that 1st condition is fulfilled. However, since the computing platform used by participants will impact the execution time, its specifics will be considered in scoring process.

3. Proposals written with clarity and rigorous description will benefit for higher score.

4. You can optimize the source code of QuEST. But please note that the provided circuit workload-basic.cpp, workload-medium.cpp and workload-advance.cpp should not be modified. Any changes to them will void the score.

## Build

To build QuEST and workloads, you need to use `cmake`, `make`, and a C/C++ compiler. You can get useful information by STFW, RTFM and RTFSC.

## Hints

### Basic

This workload contains unitary gates and mystery gates. When running the workload, see the system-monitor e.g. htop/glances/dstat to find out the behaviors and parallel levels. Then try to apply some parallel methods to the codes, and note that all the changes in source codes(excluding workload source) should keep the outputs exact same.

### Medium

It's hard to run this workload in a single node, so feel free to implement the distributed optimizations.

### Advance

Common optimizations probably make no sense here, you should try something more advanced parallel technics like pipelining. We know that it's too difficult for freshmen to work it out, so you can just write your ideas down in the final proposal for evaluations.

## Submit

You should write a writeup/proposal(either one is OK) on all three workloads to let us know your works even failed tries.

For our final evaluations, you should submit the writeup/proposal and the packages of your source codes(if you prepare three versions for three workloads respectively, you should archive all three tallballs).

We strongly recommend that you should use git to preserve the full history of the project. And attach your GitHub repository link when submitting your work.

Deadline: XXX

## Hardware Provided

Basic Workload use no more than ~2GB memory(use ~1GB normally), so we recommend you to run the basic in your local PC.

TODO

## Reference

[QuEST](https://quest.qtechtheory.org)

