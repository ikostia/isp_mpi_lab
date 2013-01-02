ISP MPI verification lab
========================

This is a university lab. The purpose of this
lab is to implement automatic model checking.

Examples of automatic deadlock detection in MPI
programs are provided.

Used tools
==========

MPI - a lib  for distributed systems implementation.
ISP - automatic formal verifier. ISP provides
a possibility to find deadlocks or assertion
failures or *proove* that those are absent. It
is developed to work with MPI and knows the behavior
of its most used functions.

Usage
=====

Compile the C source code into a profiled MPI binary:

  ``$ ispcc -o profiled.binary ./source.c``

Run verification tool on profiled binary in 4 processes
and store results in output log file:

  ``$ isp -n 4 -l analysis.log ./profiled.binary``

Links
=====

http://www.cs.utah.edu/formal_verification/ISP/

