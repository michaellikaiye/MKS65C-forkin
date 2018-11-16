# MKS65C-forkin

Write a c program that does the following:

  Forks off 2 child processes
  
  Child process instructions:
  
    At the start print its pid
    
    Sleep for a random number of seconds in the range [5, 20]
    
      Each child should sleep for a (potentially) different amount of seconds
      
    At the end print a message that it is finished
		
Parent process instructions

  Before forking, print out some initial message
  
  After the fork, wait for any child to finish
  
  Once a child has finished, print out the pid of the completed child as well as how many seconds it was asleep for.
  
    Do not run any kind of timer, think about how the child could send this information back to the parent.
    
  Print a message that the parent is done and then end the program
  
    The other child might still be running, that's ok.
