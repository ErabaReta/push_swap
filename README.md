# push_swap
algorithm to sort numbers with push_swap instructions.

You have at your disposal a set of integer values, 2 stacks (A and B), and a set of instructions
to manipulate both stacks.

the push_swap program made calculates and displays
on the standard output the smallest program, made of Push swap language instructions,
that sorts the integers received as arguments.

## The rules:
• You have 2 stacks named a and b.

• At the beginning:
◦ The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.
◦ The stack b is empty.

• The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:

sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

rrr : rra and rrb at the same time.

## the bonus part:
progaram named checker  created to check whether the list of instructions generated by the push_swap program actually
sorts the stack properly.

## using makefile:
to compile all the medatory functions into object files then archive them to a push_swap progarmuse the command:
> make

or you can use:
> make all

for the bonus part use:
> make bonus

to delete the object files you can use:
>make clean

and to the delete the object files and the program you can use:
> make fclean 

rebuilding the library will be done if you use:
> make re
