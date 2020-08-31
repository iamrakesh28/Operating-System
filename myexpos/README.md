# Operating System Lab
This repository follows the roadmap at https://exposnitc.github.io/Roadmap.html to build the eXpOS (eXperimental Operating System).

## File Organization
1. Assignments
1. expl
1. spl
1. xfs-interface
1. xsm

### Assignments
It contains the assignment solutions for each of the stages at the Roadmap. Each stage assignment solution is in a seperate folder. A folder contains the expl, spl, etc files required for the assignment.

### expl
ExpL (Experimental Language) Compiler is used to write programs which can be run on eXpOS (eXperimental Operating System). The compiler compiles the program written in ExpL and translates it into machine code which is simulated on the machine. The folder(/expl_progs) contains the user programs.

### spl
SPL (System Programmer’s Language) Compiler is used in the implementation of an operating system on XSM (eXperimental String Machine). The compiler compiles the code written in SPL and translates it into machine code which is simulated on the machine. The folder(/spl_progs) contains several kernel modules.

### xfs-interface
It has an executable `xfs-interface`. XFS (eXperimental File System) Interface is an external interface to access the file system of the eXpOS. The filesystem is simulated on a binary file called ”disk.xfs”. The interface can format the disk, load/remove files, list files and copy blocks to a UNIX file.

### xsm
The XSM (eXperimental String Machine) Simulator is used to simulate the XSM hardware.
