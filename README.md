# Calculation-of-the-Bacon-Number

Write a program that uses a given file playedin of csv entries with these columns:
1. actor id (integer)
2. movie id (integer)
The integer values form a dense range starting from 0 to the number of elements enumerated.
Based on this graph and two actor ids, your program must compute the length of the
shortest coworking chain between two actors. Chains are built of actors that acted in the
same movie. For example if Kevin Bacon and Dustin Hoffman worked on the same movie,
the chain length between them is 1. If Dustin Hoffman then worked with Barbra Streisand,
but Barbra Streisand did not work with Kevin Bacon, the shortest chain length is 2. This
extends to arbitrary chain lengths. If no chain can be found, your program should return
-1. The chain length from an actor to himself is defined to be 0.
