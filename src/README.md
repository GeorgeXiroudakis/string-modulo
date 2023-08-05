George Xiroudakis-csd5067

i) It can be achieved by using the sizeof keyword,
with the sizeof(the_array_to_copy_or_concat_to) we'll get 
the number of chars it can hold. In each case we have to make
sure that that copasity is greater or equal tha the char we plan
to add in it
So let s1 be the_array_to_copy_or_concat_to)
s2 the array_to_copy_or_concat_from
and num the third arg in the ncopy and nconcat
in copy it would be assert(sizeof(s1) >= ms_lenght(s))

in ncopy assert(sizeof(s1) >= num) 

in concat assert(sizeof(s1) >= ms_length(s1) + ms_lenght(s2))

in nconcat assert(sizeof(s1) >= ms_length(s1) + num)


ii)the n variances could easily check if the num if negative 
with assert(num >= 0)


I believe i handled the assignment as expected.


By far the biggest help came from the documentation of the 
string.h library as i had to fully Understand the functionality
of the function to be able to replicate them. Plus some googling 
mainly for the vim editor and its plugins as i decide to mainly use 
it from now and on.       
