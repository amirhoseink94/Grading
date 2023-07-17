#!/bin/bash

# Set the directory path
directory=~/Desktop/CMPT255/ass1/students
make_file=~/Desktop/CMPT255/ass1/sol/makefile
main1_cpp=~/Desktop/CMPT255/ass1/sol/ass1_sol_1.cpp
main2_cpp=~/Desktop/CMPT255/ass1/sol/ass1_sol_2.cpp
main3_cpp=~/Desktop/CMPT255/ass1/sol/ass1_sol_3.cpp
main4_cpp=~/Desktop/CMPT255/ass1/sol/ass1_sol_4.cpp
main5_cpp=~/Desktop/CMPT255/ass1/sol/ass1_sol_5.cpp
main6_cpp=~/Desktop/CMPT255/ass1/sol/ass1_sol_6.cpp
main7_cpp=~/Desktop/CMPT255/ass1/sol/ass1_sol_rf.cpp
small_text=~/Desktop/CMPT255/ass1/sol/small.txt
time_machine_text=~/Desktop/CMPT255/ass1/sol/time_machine1.txt
base_class=~/Desktop/CMPT255/ass1/sol/Wordlist_base.h


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
	new_filename="Wordlist.h"

	# Get the path of the text file
	file_path=$(find "$new_directory" -type f -name "$current_filename_pattern")
	# Rename the file
	mv "$file_path" "$new_directory/$new_filename"
        
	# Copy the .cpp and makefiles into the new directory to the new directory
    cp "$make_file" "$new_directory"
    cp "$main1_cpp" "$new_directory"
    cp "$main2_cpp" "$new_directory"
    cp "$main3_cpp" "$new_directory"
    cp "$main4_cpp" "$new_directory"
    cp "$main5_cpp" "$new_directory"
    cp "$main6_cpp" "$new_directory"
    cp "$main7_cpp" "$new_directory"
    cp "$small_text" "$new_directory"
    cp "$time_machine_text" "$new_directory"
    cp "$base_class" "$new_directory"
    
    # moving into the student directory
    cd "$new_directory"
    
    echo "Compiling...:\n" >> output.txt
    make &>> output.txt
    echo "_________________________________________________________________" >> output.txt
    echo "The complie is done, if yo do not have any errors above, you will have the result of your code  bellew. It includes the memeory test." >> output.txt
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
    echo "TEST CASE 7 (handeling a big file) is running..." >> output.txt
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
    
    cd ..
    
done
