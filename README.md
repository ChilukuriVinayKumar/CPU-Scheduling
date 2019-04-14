# Scheduling
priority preemption + Round robin
Ques. 7.  Design a scheduling program to implements a Queue with two levels:
Level 1 : Fixed priority preemptive Scheduling
Level 2 : Round Robin Scheduling For a Fixed priority preemptive Scheduling (Queue 1), the Priority 0 is highest priority. 
If one process P1 is scheduled and running , another process P2 with higher priority comes. The New process (high priority) process P2 preempts currently running process P1 and process P1 will go to second level queue. Time for which process will strictly execute must be considered in the multiples of 2..
All the processes in second level queue will complete their execution according to round robin scheduling.
Consider: 1. Queue 2 will be processed after Queue 1 becomes empty. 
          2. Priority of Queue 2 has lower priority than in Queue 1. 
Sample Test case:
  TestCase1::
  5
  0 11 2
  5 28 0
  12 2 3 
  2 10 1
  9 16 4
  Output::
![Screenshot (68)](https://user-images.githubusercontent.com/47757720/56092086-13846700-5ed5-11e9-9650-9edf766a2db1.png)
 TestCase2::
 4
 0 3 2
 4 5 2
 18 9 5
 2 8 5
 Oputut::
![Screenshot (69)](https://user-images.githubusercontent.com/47757720/56092126-84c41a00-5ed5-11e9-80a8-9f5d82b391f5.png)
 TestCase3::
 4
 0 3 2
 4 5 2
 18 9 5
 22 8 2
 Output::
![Screenshot (70)](https://user-images.githubusercontent.com/47757720/56092127-85f54700-5ed5-11e9-974e-37ff558b425a.png)
