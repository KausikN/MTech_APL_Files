# Clean required folders
rm -r results
rm -r actual_outputs
rm -r unzipped

mkdir results
mkdir actual_outputs
mkdir unzipped

# Complete results will be contained in the file results/total.csv
touch results/total.csv
echo "ROLLNUM,TOTAL" >> results/total.csv

# Untar submitted files
echo "Untarring submissions..."
for file in zipfiles/*.zip
do
	echo $file
	len=${#file}
	if [ ! $len -eq 21 ]
	then
		echo "Skipping $file because of wrong uploaded-file name"
		echo "$file,0,0,'wrong uploaded-file name'" >> results/total.csv
		continue
	fi
	unzip $file -d unzipped/
done
echo

# Safety check
numoffiles=`ls -l unzipped/ | wc -l`
if [ $numoffiles -eq 0 ]
then
	echo "Nothing to evaluate!"
	exit 1

fi

#Compile and execute while creating needed directories
cd unzipped
for dir in *
do
	# If directory name is wrong, skip and continue
	len=${#dir}
	if [ ! $len -eq 8 ]
	then
		echo "Skipping $dir because of wrong name/directory/structure"
		echo "$dir,0,0,'directory structure'" >> ../results/total.csv
		continue
	fi
	
	cd $dir
	total=0
    ta=0
	echo "Processing $dir..."
	mkdir ../../actual_outputs/$dir
	mkdir ../../actual_outputs/$dir/sys_out ../../actual_outputs/$dir/sys_err
	touch ../../results/$dir.txt
        #for program in P*
        #do
	marks=0
	program=$dir
		
	echo "Compiling $program"
    #cd $program
    #rm solution

	pname=P1
	#bash cmd.sh
 	ntests=2
	echo "Executing generated-binary 'solution' on $ntests test cases"
	# cmd.sh should contain the commands to run the Makefile
	bash cmd.sh
    for((num=0;num<$ntests;num++))
    do
        input=../../testcases/${pname}/input0${num}.txt
        output=../../actual_outputs/$dir/sys_out/${pname}_output0${num}.txt
        #echo "$input $output" > temp_file.txt

	  	./bin/solution < $input > $output  2> ../../actual_outputs/$dir/sys_err/${pname}_err${num}.txt
		expected=`cat ../../expected_outputs/${pname}/output0${num}.txt | tr -d '[:space:]'`
		actual=`cat ../../actual_outputs/$dir/sys_out/${pname}_output0${num}.txt | tr -d '[:space:]'`
			if [ "$actual" != "" -a "$expected" = "$actual" ]
			then
				echo "${pname}_inp${num}.txt : PASS : 0.5" >> ../../results/$dir.txt
		        echo "${pname}_inp${num}.txt : PASS : 0.5"
				marks=`echo "scale=2; $marks+0.5" | bc`
			else
				echo "${pname}_inp${num}.txt : FAIL : 0" >> ../../results/$dir.txt
				echo "${pname}_inp${num}.txt : FAIL : 0"
			fi
    done
	total=`echo "scale=2; $total+$marks" | bc`
	marks=`echo "scale=2; (${marks} * 100) / 100" | bc`
	echo "Marks for ${program}: ${marks}" >> ../../results/$dir.txt
	echo "Marks for ${program}: ${marks}"
    echo "***" >> ../../results/$dir.txt
    echo "***"
    echo $PWD
    cd ../
	#done
	# total=`echo "scale=2; (${total} * 100) / 100" | bc`
	# echo "$dir got $total marks." >> ../results/$dir.txt
	# echo "$dir got $total marks."
	# echo "$dir,$total" >> ../results/total.csv
 #        echo "******"
	#cd ../
done
cd ..
echo
echo "Evaluation completed!!!"
