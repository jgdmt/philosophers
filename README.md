# Philosophers

**Philosophers** is a simulation of the classic dining philosophers problem, a common exercise in concurrent programming.

## Project Overview

In the dining philosophers problem, a group of philosophers sit around a table. Each philosopher alternates between thinking and eating. There is a fork between each pair of philosophers, and a philosopher must pick up both the left and right forks to eat. The challenge is to design a program where the philosophers can eat without leading to a deadlock.

## Features

- Simulates the dining philosophers problem using threads and mutexes.
- Handles synchronization to avoid data-races.
- Configurable number of philosophers and simulation parameters.
- Provides detailed output showing the state of each philosopher (thinking, eating, or sleeping).
- Bonus is about semaphores but has not been implemented yet.

## Installation

To set up **Philosophers** simulation, follow these steps:

   ```bash
   cd philo
   git clone https://github.com/jgdmt/philosophers.git
   ```
To run the simulation:
  ```bash
  ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
