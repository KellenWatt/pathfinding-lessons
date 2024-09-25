# Pathfinding and Data Structures in C

Welcome to the C track. Congratulations! You've picked both the simplest and most compilcated langauge to do 
this sort of thing. This isn't meant to teach the language, so good luck!

## Requirements

### [Ruby](https://www.ruby-lang.org/en/downloads/) 
You won't be messing with Ruby at all directly, but it is used to generate the test runners in each exercise.
As such, it is a strict requirement.

### [Bazel](https://bazel.build/start)
Bazel is a build tool designed for multi-language programs, but it's especially useful for simple(-ish) 
platform-independent C/C++ compilation. 

It's recommended to install on most major platforms using (Bazelisk)[https://bazel.build/install/bazelisk],
which is essentially a wrapper around Bazel. The differences are not important in this context however.

## Running the Tests
Each exercise has a suite of tests that accompany it, and allow you to check if your implementation does what 
it should. To run the tests in each exercise, run
'''
bazel run //main:<exercise-name>-test
'''
where you replace `<exercise-name>` with the name of the exercise you're currently working on (so it would be 
`linked-list-test` for "linked-list").
