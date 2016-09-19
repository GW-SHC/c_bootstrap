# Bootstrapping C - Project 2
## GWU Systems Hacking Club

In this project, you will write a Ring Buffer and interate it into the webserver code to make a simple order queue. Let's pretend that you work in a developement job and your boss told you to make a dashboard showing the number of tickets remaining. One quirk about this job is that you must work on tickets in the order they are assigned. You should make one page to output the number of tickets remaining in your queue, along with the abiltiy to add one (with a title (and maybe some other metadata?) you give) and remove the top ticket from the queue. You should define a `struct` to store all relevant information about a ticket and track all the open tickets in a ring buffer.

**TODO** how does the webserver handle POSTing data via forms? That may affect what kind of info we can track.

## Background
A ring buffer is a very heavily used data structure in systems code. It is a fixed size buffer that can store a constant number of items. One of the most important aspects is that the buffer "wraps around" the end of the array. and goes back to the beginning. You should implement a buffer using an array and some integers to track metadata. You will need to track the following values:
 - An array to store the data
 - The size of the buffer (number of items that can be stored)
 - The index in the array of the head of the queue (next item to be completed)
 - The index in the array of the tail of the queue (where the next item gets inserted)

You may need to take into account the following things:
 - [modulo operator](https://en.wikipedia.org/wiki/Modulo_operation)
 - Be careful: since the buffer is "circular" you will need to be careful about the bounds. What do you want to happen when you try and insert an item into a full buffer? How about when you try and remove an item from an empty buffer? How can you determine these scenarios using the data we're tracking above?

Implementations you may see on the internet will use pointers (a concept we haven't covered yet). Don't fret - you can still complete this code without using pointers.

