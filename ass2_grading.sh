#!/bin/bash

# Set the directory path
directory=~/Desktop/CMPT255/ass2/students
make_file=~/Desktop/CMPT255/ass2/sol/makefile
test_basic=~/Desktop/CMPT255/ass2/sol/Stringlist_test.cpp
test_0=~/Desktop/CMPT255/ass2/sol/Stringlist_undo_testing_0.cpp
test_1=~/Desktop/CMPT255/ass2/sol/Stringlist_undo_testing_1.cpp
test_2=~/Desktop/CMPT255/ass2/sol/Stringlist_undo_testing_2.cpp
test_3=~/Desktop/CMPT255/ass2/sol/Stringlist_undo_testing_3.cpp
test_4=~/Desktop/CMPT255/ass2/sol/Stringlist_undo_testing_4.cpp
test_5=~/Desktop/CMPT255/ass2/sol/Stringlist_undo_testing_5.cpp
test_6=~/Desktop/CMPT255/ass2/sol/Stringlist_undo_testing_6.cpp
test_7=~/Desktop/CMPT255/ass2/sol/Stringlist_undo_testing_7.cpp
test_8=~/Desktop/CMPT255/ass2/sol/Stringlist_undo_testing_8.cpp

stack_sol=~/Desktop/CMPT255/ass2/sol/Stack_sol.h

time_machine_text=~/Desktop/CMPT255/ass2/sol/time_machine1.txt
base_class=~/Desktop/CMPT255/ass2/sol/Wordlist_base.h


# Loop through each file in the directory
for file in "$directory"/*; do
	filename=$(basename "$file")
	
	# tokenizing the name and make a file for each student
	first_token="${filename%%_*}"
	
	new_directory="$directory/$first_token"
    mkdir -p "$new_directory"
	
	echo "$new_directory"
	
    # Move the file into the new directory
    mv "$file" "$new_directory"
    
	# Set the current filename pattern to search for
	current_filename_pattern="*.h"

	# Set the new filename
	new_filename="Stringlist.h"

	# Get the path of the text file
	file_path=$(find "$new_directory" -type f -name "$current_filename_pattern")
	# Rename the file
	mv "$file_path" "$new_directory/$new_filename"
        
	# Copy the .cpp and makefiles into the new directory to the new directory
    cp "$make_file" "$new_directory"
    cp "$test_basic" "$new_directory"
    cp "$test_0" "$new_directory"
    cp "$test_1" "$new_directory"
    cp "$test_2" "$new_directory"
    cp "$test_3" "$new_directory"
    cp "$test_4" "$new_directory"
    cp "$test_5" "$new_directory"
    cp "$test_6" "$new_directory"
    cp "$test_7" "$new_directory"
    cp "$test_8" "$new_directory"

	cp "$stack_sol" "$new_directory"
    
    # moving into the student directory
    cd "$new_directory"
    
    echo "Compiling...:\n" >> output.txt
    make &>> output.txt
    echo "_________________________________________________________________" >> output.txt
    echo "The complie is done, if yo do not have any errors above, you will have the result of your code  bellew. It includes the memeory test." >> output.txt
    echo "_________________________________________________________________" >> output.txt
    echo "BASIC TEST CASE is running..." >> output.txt
    timeout 10s valgrind ./a_basic.out >> output.txt 2>&1
    if [ $? -eq 124 ]; then
	  # The command timed out
	  echo "Program exceeded time limit of 10 seconds." >> output.txt
	  # You can add any cleanup or error handling code here
	else
	  # The command completed within the time limit
	  echo "Program executed successfully." >> output.txt
	fi
	echo "BASIC TEST CASE is FINISHED" >> output.txt
    echo "_________________________________________________________________" >> output.txt
    echo "TEST CASE 0 is running..." >> output.txt
    timeout 10s valgrind ./a0.out >> output.txt 2>&1
    if [ $? -eq 124 ]; then
	  # The command timed out
	  echo "Program exceeded time limit of 10 seconds." >> output.txt
	  # You can add any cleanup or error handling code here
	else
	  # The command completed within the time limit
	  echo "Program executed successfully." >> output.txt
	fi
	echo "TEST CASE 0 is FINISHED" >> output.txt
    echo "_________________________________________________________________" >> output.txt
    echo "TEST CASE 1 is running..." >> output.txt
    timeout 10s valgrind ./a1.out >> output.txt 2>&1
    if [ $? -eq 124 ]; then
	  # The command timed out
	  echo "Program exceeded time limit of 10 seconds." >> output.txt
	  # You can add any cleanup or error handling code here
	else
	  # The command completed within the time limit
	  echo "Program executed successfully." >> output.txt
	fi
	echo "TEST CASE 1 is FINISHED" >> output.txt
    echo "_________________________________________________________________" >> output.txt
    echo "TEST CASE 2 is running..." >> output.txt
    timeout 10s valgrind ./a2.out >> output.txt 2>&1
    if [ $? -eq 124 ]; then
	  # The command timed out
	  echo "Program exceeded time limit of 10 seconds." >> output.txt
	else
	  # The command completed within the time limit
	  echo "Program executed successfully." >> output.txt
	fi
	echo "TEST CASE 2 is FINISHED" >> output.txt
    echo "_________________________________________________________________" >> output.txt
    echo "TEST CASE 3 is running..." >> output.txt
    timeout 10s valgrind ./a3.out >> output.txt 2>&1
    if [ $? -eq 124 ]; then
	  # The command timed out
	  echo "Program exceeded time limit of 10 seconds." >> output.txt
	else
	  # The command completed within the time limit
	  echo "Program executed successfully." >> output.txt
	fi
	echo "TEST CASE 3 is FINISHED" >> output.txt
    echo "_________________________________________________________________" >> output.txt
    echo "TEST CASE 4 is running..." >> output.txt
    timeout 10s valgrind ./a4.out >> output.txt 2>&1
    if [ $? -eq 124 ]; then
	  # The command timed out
	  echo "Program exceeded time limit of 10 seconds." >> output.txt
	else
	  # The command completed within the time limit
	  echo "Program executed successfully." >> output.txt
	fi
	echo "TEST CASE 4 is FINISHED" >> output.txt
    echo "_________________________________________________________________" >> output.txt
    echo "TEST CASE 5 is running..." >> output.txt
    timeout 10s valgrind ./a5.out >> output.txt 2>&1
    if [ $? -eq 124 ]; then
	  # The command timed out
	  echo "Program exceeded time limit of 10 seconds." >> output.txt
	else
	  # The command completed within the time limit
	  echo "Program executed successfully." >> output.txt
	fi
	echo "TEST CASE 5 is FINISHED" >> output.txt
    echo "_________________________________________________________________" >> output.txt
    echo "TEST CASE 6 is running..." >> output.txt
    timeout 10s valgrind ./a6.out >> output.txt 2>&1
    if [ $? -eq 124 ]; then
	  # The command timed out
	  echo "Program exceeded time limit of 10 seconds." >> output.txt
	else
	  # The command completed within the time limit
	  echo "Program executed successfully." >> output.txt
	fi
	echo "TEST CASE 6 is FINISHED" >> output.txt
    echo "_________________________________________________________________" >> output.txt
    echo "TEST CASE 7 is running..." >> output.txt
    timeout 10s valgrind ./a7.out >> output.txt 2>&1
    if [ $? -eq 124 ]; then
	  # The command timed out
	  echo "Program exceeded time limit of 10 seconds." >> output.txt
	else
	  # The command completed within the time limit
	  echo "Program executed successfully." >> output.txt
	fi
	echo "TEST CASE 7 is FINISHED" >> output.txt
    echo "_________________________________________________________________" >> output.txt
    echo "TEST CASE 8 is running..." >> output.txt
    timeout 10s valgrind ./a8.out >> output.txt 2>&1
    if [ $? -eq 124 ]; then
	  # The command timed out
	  echo "Program exceeded time limit of 10 seconds." >> output.txt
	else
	  # The command completed within the time limit
	  echo "Program executed successfully." >> output.txt
	fi
	echo "TEST CASE 8 is FINISHED" >> output.txt
    echo "_________________________________________________________________" >> output.txt
    
    cd ..
    
done
