# philosophers
This project was an introduction to threading and processes, and how to work on the same memory space. We learned how to manipulate threads. We learned about mutexes and shared memory.

Philosophers are seated around a table with a large dish of spaghetti in the center.
- The philosophers are either eating, thinking or sleeping. They can only do one action at a time.
- There are also forks on the table. There are as many forks as there are philosophers.
- To eat, a philosopher takes the fork on his left and the one on his right, i.e. one fork in each hand.
- The philosophers' routine is to eat (put the forks back when he's finished), sleep and when he wakes up he thinks. The simulation ends if a philosopher dies of hunger.
- Each philosopher needs to eat and must not starve.
- Philosophers do not communicate with each other.
- Philosophers cannot know if one of them is about to die.
- Philosophers must not die!

Each philosopher is represented by a thread. For each philosopher there is a fork. This means that, if there are several philosophers, there is a fork on the left and right for each of them. 
If there is only one philosopher, there will be only one fork on the table. To prevent the philosophers from duplicating the forks, we had to protect their state in memory with a mutex for each one.

The program must take the following arguments:
number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

While the program is running we had to print some data to the screen as the time elapsed since the start of the program, the number of the philosopher and the action he takes.

 ### Skills

  - Unix
  - Rigor
  - Imperative programming 
