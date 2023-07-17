#!/bin/bash

# Set the directory path
directory=~/Desktop/CMPT255/ass3/students
make_file=~/Desktop/CMPT255/ass3/a3_sol/makefile
announcment=~/Desktop/CMPT255/ass3/a3_sol/Announcement.h
JingleNet=~/Desktop/CMPT255/ass3/a3_sol/JingleNet.h
JingelNet_ann=~/Desktop/CMPT255/ass3/a3_sol/JingleNet_announcer.h
Queue=~/Desktop/CMPT255/ass3/a3_sol/Queue.h
Queue_base=~/Desktop/CMPT255/ass3/a3_sol/Queue_base.h

test_1=~/Desktop/CMPT255/ass3/a3_sol/jinglenet_input1.txt
test_2=~/Desktop/CMPT255/ass3/a3_sol/jinglenet_input2.txt
test_3=~/Desktop/CMPT255/ass3/a3_sol/jinglenet_input3.txt
test_4=~/Desktop/CMPT255/ass3/a3_sol/jinglenet_input4.txt
test_5=~/Desktop/CMPT255/ass3/a3_sol/jinglenet_input5.txt
test_6=~/Desktop/CMPT255/ass3/a3_sol/jinglenet_input6.txt

check_test_1=~/Desktop/CMPT255/ass3/a3_sol/output1.txt
check_test_2=~/Desktop/CMPT255/ass3/a3_sol/output2.txt
check_test_3=~/Desktop/CMPT255/ass3/a3_sol/output3.txt
check_test_4=~/Desktop/CMPT255/ass3/a3_sol/output4.txt
check_test_5=~/Desktop/CMPT255/ass3/a3_sol/output5.txt
check_test_6=~/Desktop/CMPT255/ass3/a3_sol/output6.txt





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
	current_filename_pattern="*.cpp"

	# Set the new filename
	new_filename="a3.cpp"

	# Get the path of the text file
	file_path=$(find "$new_directory" -type f -name "$current_filename_pattern")
	# Rename the file
	mv "$file_path" "$new_directory/$new_filename"
        
	# Copy the .cpp and makefiles into the new directory to the new directory
    cp "$make_file" "$new_directory"
    cp "$announcment" "$new_directory"
    cp "$JingleNet" "$new_directory"
    cp "$JingelNet_ann" "$new_directory"
    cp "$Queue" "$new_directory"
    cp "$Queue_base" "$new_directory"
    
    cp "$test_1" "$new_directory"
    cp "$test_2" "$new_directory"
    cp "$test_3" "$new_directory"
    cp "$test_4" "$new_directory"
    cp "$test_5" "$new_directory"
    cp "$test_6" "$new_directory"


    
    # moving into the student directory
    cd "$new_directory"
    
    echo "Compiling...:\n" >> output.txt
    make &>> output.txt
    echo "_________________________________________________________________" >> output.txt
    echo "The complie is done, if yo do not have any errors above, you will have the result of your code bellow. It includes the memeory test." >> output.txt
    
    echo "_________________________________________________________________" >> output.txt
    echo "TEST CASE 1..." >> output.txt
    timeout 10s valgrind ./a3_result.out jinglenet_input1.txt >> output.txt 2>&1
    if [ $? -eq 124 ]; then
	  # The command timed out
	  echo "Program exceeded time limit of 10 seconds." >> output.txt
	  # You can add any cleanup or error handling code here
	else
	  # The command completed within the time limit
	  echo "Program executed successfully." >> output.txt
	  echo "========================================" >> output.txt
	  echo "Checking for the correct output with diff ... " >> output.txt
	  echo "======= start of the differences =======" >>output.txt
	  diff announcements.txt "$check_test_1" >> output.txt
	  echo "======== end of the differences ========" >> output.txt
	  echo "========================================" >> output.txt
	  mv announcements.txt announcements_test1.txt
	fi
	
	echo "TEST CASE 1 is FINISHED" >> output.txt
    echo "_________________________________________________________________" >> output.txt
    
    
    echo "_________________________________________________________________" >> output.txt
    echo "TEST CASE 2..." >> output.txt
    timeout 10s valgrind ./a3_result.out jinglenet_input2.txt >> output.txt 2>&1
    if [ $? -eq 124 ]; then
	  # The command timed out
	  echo "Program exceeded time limit of 10 seconds." >> output.txt
	  # You can add any cleanup or error handling code here
	else
	  # The command completed within the time limit
	  echo "Program executed successfully." >> output.txt
	  echo "========================================" >> output.txt
	  echo "Checking for the correct output with diff ... " >> output.txt
	  echo "======= start of the differences =======" >>output.txt
	  diff announcements.txt "$check_test_2" >> output.txt
	  echo "======== end of the differences ========" >> output.txt
	  echo "========================================" >> output.txt
	  mv announcements.txt announcements_test2.txt
	fi
	
	echo "TEST CASE 2 is FINISHED" >> output.txt
    echo "_________________________________________________________________" >> output.txt
    
    
    echo "_________________________________________________________________" >> output.txt
    echo "TEST CASE 3..." >> output.txt
    timeout 10s valgrind ./a3_result.out jinglenet_input3.txt >> output.txt 2>&1
    if [ $? -eq 124 ]; then
	  # The command timed out
	  echo "Program exceeded time limit of 10 seconds." >> output.txt
	  # You can add any cleanup or error handling code here
	else
	  # The command completed within the time limit
	  echo "Program executed successfully." >> output.txt
	  echo "========================================" >> output.txt
	  echo "Checking for the correct output with diff ... " >> output.txt
	  echo "======= start of the differences =======" >>output.txt
	  diff announcements.txt "$check_test_3" >> output.txt
	  echo "======== end of the differences ========" >> output.txt
	  echo "========================================" >> output.txt
	  mv announcements.txt announcements_test3.txt
	fi
	
	echo "TEST CASE 3 is FINISHED" >> output.txt
    echo "_________________________________________________________________" >> output.txt
    
    
    echo "_________________________________________________________________" >> output.txt
    echo "TEST CASE 4..." >> output.txt
    timeout 10s valgrind ./a3_result.out jinglenet_input4.txt >> output.txt 2>&1
    if [ $? -eq 124 ]; then
	  # The command timed out
	  echo "Program exceeded time limit of 10 seconds." >> output.txt
	  # You can add any cleanup or error handling code here
	else
	  # The command completed within the time limit
	  echo "Program executed successfully." >> output.txt
	  echo "========================================" >> output.txt
	  echo "Checking for the correct output with diff ... " >> output.txt
	  echo "======= start of the differences =======" >>output.txt
	  diff announcements.txt "$check_test_4" >> output.txt
	  echo "======== end of the differences ========" >> output.txt
	  echo "========================================" >> output.txt
	  mv announcements.txt announcements_test4.txt
	fi
	
	echo "TEST CASE 4 is FINISHED" >> output.txt
    echo "_________________________________________________________________" >> output.txt
    
    
    echo "_________________________________________________________________" >> output.txt
    echo "TEST CASE 5..." >> output.txt
    timeout 10s valgrind ./a3_result.out jinglenet_input5.txt >> output.txt 2>&1
    if [ $? -eq 124 ]; then
	  # The command timed out
	  echo "Program exceeded time limit of 10 seconds." >> output.txt
	  # You can add any cleanup or error handling code here
	else
	  # The command completed within the time limit
	  echo "Program executed successfully." >> output.txt
	  echo "========================================" >> output.txt
	  echo "Checking for the correct output with diff ... " >> output.txt
	  echo "======= start of the differences =======" >>output.txt
	  diff announcements.txt "$check_test_5" >> output.txt
	  echo "======== end of the differences ========" >> output.txt
	  echo "========================================" >> output.txt
	  mv announcements.txt announcements_test5.txt
	fi
	
	echo "TEST CASE 5 is FINISHED" >> output.txt
    echo "_________________________________________________________________" >> output.txt
    
    
    echo "_________________________________________________________________" >> output.txt
    echo "TEST CASE 6..." >> output.txt
    timeout 10s valgrind ./a3_result.out jinglenet_input6.txt >> output.txt 2>&1
    if [ $? -eq 124 ]; then
	  # The command timed out
	  echo "Program exceeded time limit of 10 seconds." >> output.txt
	  # You can add any cleanup or error handling code here
	else
	  # The command completed within the time limit
	  echo "Program executed successfully." >> output.txt
	  echo "========================================" >> output.txt
	  echo "Checking for the correct output with diff ... " >> output.txt
	  echo "======= start of the differences =======" >>output.txt
	  diff announcements.txt "$check_test_6" >> output.txt
	  echo "======== end of the differences ========" >> output.txt
	  echo "========================================" >> output.txt
	  mv announcements.txt announcements_test6.txt
	fi
	
	echo "TEST CASE 6 is FINISHED" >> output.txt
    echo "_________________________________________________________________" >> output.txt
    
    mkdir "Results"
    cp "announcements_test1.txt" "Results/announcements_test1.txt"
    cp "announcements_test2.txt" "Results/announcements_test2.txt"
    cp "announcements_test3.txt" "Results/announcements_test3.txt"
    cp "announcements_test4.txt" "Results/announcements_test4.txt"
    cp "announcements_test5.txt" "Results/announcements_test5.txt"
    # cp "announcements_test6.txt" "Results/announcements_test6.txt"
    
    
    cp "output.txt" "Results/output.txt"
    
    zip -r "Result.zip" "Results" 
    
    cd ..
    
done
